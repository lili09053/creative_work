#include "binarytree.h"

#include <QtCore/qmath.h>
//QString line;

/*==============================*/

int x, y;                                   // x - номер элемента на уровне, y - номер уровня
int offset = 250;                           // Отступ от краев сцены
double R = 0;                               // Рисуемый радиус узла дерева
double node_x = 0, node_y = 0;              // Координаты узла
double text_x = 0, text_y = 0;              // Координаты текста
int theight = 0;                            // Число уровней дерева
double x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;  // Начальные и конечные координаты линии
int coefficient;                            // Коэффициент используется в формуле расчета координат начала линии. Значения равны 1 и -1 в зависимости от того, влево рисуется линия или вправо
double height = 0, width = 0;               // Размеры сцены
bool isCurrentNodeLeft;                     // Флажок нужен для определения значения коэффициента

/*==============================*/

Node::Node(int val)
{
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}

bool BinaryTree::is_empty()
{
    return root == nullptr;
}

void BinaryTree::_clear(Node* leaf)
{
    if (leaf != nullptr)
    {
        _clear(leaf->left);
        _clear(leaf->right);
        delete leaf;
        leaf = nullptr;
    }
}

int BinaryTree::_depth(Node *leaf)
{
    if (leaf != nullptr)
    {
        return qMax(_depth(leaf->right), _depth(leaf->left)) + 1;
    }
    else
    {
        return 0;
    }
}

void BinaryTree::_visualise(Node*& leaf, int leaf_number, QGraphicsScene* scene, int mode)
{
    if (leaf == nullptr)
    {
        return;
    }
    y++;
    x = leaf_number;

    R = (width - offset) / qPow(2, theight);

    nodeshape = new NodeShape();
    node_x = width * (2 * x - 1) / qPow(2, y);
    node_y = height * (qSqrt(y * y * (y * 1.315))) / qPow(2, theight);

    if (y == 1)
    {
        x_1 = node_x;
        y_1 = node_y;
    }
    else
    {
        x_2 = node_x;
        y_2 = node_y;

        double D = qSqrt(qPow(x_2 - x_1, 2) + qPow(y_2 - y_1, 2));      // AC
        double d = D - R;                                               // AK
        double big_triangle_cathetus = qSqrt(qPow(x_2 - x_1, 2));       // AB

        /*    sinC = AB / AC; sinC = AH / AK    */

        double small_triangle_cathetus = big_triangle_cathetus * d / D; // AH

        if (isCurrentNodeLeft)
        {
            coefficient = 1;
        }
        else
        {
            coefficient = -1;
        }

        double new_x_1 = x_2 + coefficient * small_triangle_cathetus;   // K(x2 +|AH|; t)

        /*    AK = sqrt((x2 + |AH| - x2)^2 + (y2 - t)^2), где t = новые координаты y1    */

        double new_y_1 = y_2 - qSqrt(d * d - qPow(small_triangle_cathetus, 2));     // t = y2 - sqrt(AK^2-AH^2)

        x_1 = new_x_1;
        y_1 = new_y_1;

        QGraphicsItem* edge;
        if (mode == 0)
        {
            edge = scene->addLine(x_1, y_1, x_2, y_2, QPen(Qt::black));  // Ребро
        }
        else
        {
            edge = scene->addLine(y_1, x_1, y_2, x_2, QPen(Qt::black));  // Ребро
        }
        scene->addItem(edge);

        x_1 = x_2;
        y_1 = y_2;
    }

    if (mode == 0)
    {
        nodeshape->SetNodeCoords(node_x, node_y);
    }
    else
    {
        nodeshape->SetNodeCoords(node_y, node_x);
    }
    QString line = QString::number(leaf->data);
    text_x = node_x - R / 6 * line.length();
    text_y = node_y - 3 * R / 8;

    nodeshape->SetNodeRadius(R);
    scene->addItem(nodeshape);
    nodeshape->setPos(0, 0);

    QFont font("Times", R / 3);
    QGraphicsTextItem* text = scene->addText(QString::number(leaf->data), font);

    if (mode == 0)
    {
        text->setPos(text_x, text_y);
    }
    else
    {
        text->setPos(text_y, text_x);
    }

    isCurrentNodeLeft = true;
    _visualise(leaf->left, 2 * leaf_number - 1, scene, mode);
    isCurrentNodeLeft = false;

    // Находим координаты узла-родителя перед входом в правую ветку

    x_1 = width * ( 2 * leaf_number) / qPow(2, y);                              // node_x или leaf_number
    y_1 = height * (qSqrt(y * y * (y * 1.315))) / qPow(2, theight);             // node_y

    _visualise(leaf->right, 2 * leaf_number, scene, mode);

    y--;
    if (y == 1)
    {
        x = 1;
        x_1 = width * (2 * x - 1) / qPow(2, y);                                 // node_x
        y_1 = height * (qSqrt(y * y * (y * 1.315))) / qPow(2, theight);         // node_y
    }
}

QString BinaryTree::_forward(Node* node)
{
    QString row = "";
    if (node != nullptr)
    {
        row += QString::number(node->data) + " ";
        row += _forward(node->left);
        row += _forward(node->right);
    }
    return row;
}

QString BinaryTree::_symmetric(Node* node)
{
    QString row = "";
    if (node != nullptr)
    {
        row += _symmetric(node->left);
        row += QString::number(node->data) + " ";
        row += _symmetric(node->right);
    }
    return row;
}

QString BinaryTree::_reverse(Node* node)
{
    QString row = "";
    if (node != nullptr)
    {
        row += _reverse(node->left);
        row += _reverse(node->right);
        row += QString::number(node->data) + " ";
    }
    return row;
}

vector<int> BinaryTree::_make_vector(Node*& node)
{
    vector<int> vals = vector<int>();
    if (node != nullptr)
    {
        vector<int> left = _make_vector(node->left);
        vector<int> right = _make_vector(node->right);

        vals.insert(vals.end(), left.begin(), left.end());
        vals.push_back(node->data);
        vals.insert(vals.end(), right.begin(), right.end());
    }
    return vals;
}

Node* BinaryTree::_make_balanced(vector<int> vals, int start, int end)
{
    Node* node = nullptr;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        node = new Node(vals[mid]);

        node->left = _make_balanced(vals, start, mid - 1);
        node->right = _make_balanced(vals, mid + 1, end);
    }
    return node;
}

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::BinaryTree(Node& node)
{
    root = &node;
}

BinaryTree::~BinaryTree()
{
    clear();
}

void BinaryTree::clear()
{
    _clear(root);
}

QString BinaryTree::print(short choice)
{
    QString row = "";
    switch (choice)
    {
    case 1:
        row += _forward(root);
        break;

    case 2:
        row += _symmetric(root);
        break;

    case 3:
        row += _reverse(root);
        break;

    default:
        break;
    }
    return row;
}

Node* BinaryTree::balance()
{
    vector<int> vals = _make_vector(root);
    return _make_balanced(vals, 0, vals.size() - 1);
}

void BinaryTree::visualise(QGraphicsScene *scene, int mode)
{
    x = 0;
    y = 0;
    theight = _depth(root);
    width = scene->width();
    height = scene->height();
    _visualise(root, 1, scene, mode);
}
