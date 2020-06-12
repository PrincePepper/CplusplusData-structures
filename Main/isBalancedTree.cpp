//
// Created by Semen Sereda on 12.06.2020.
//
#include <iostream>
#include <vector>

using namespace std;
class Node {
    long long int key;
    long long int h;
    Node *left;
    Node *right;
public:
    explicit Node(long long int k);

    static long long int height(Node *p); //высота
    static long long int balanceFactor(Node *p);//вычисляет коэффициент сбалансированности узла
    static void fixheight(Node *p); //корректирует значение поля h, затронутое в процессе балансировки.
    static Node *rotateright(Node *x); // правый малый поворот
    static Node *rotateleft(Node *y); // левый малый поворот
    static Node *balance(Node *p); // балансировка узла
    Node *insert(Node *p, long long int k); // вставка ключа k в дерево с корнем p
    Node *findmin(Node *p); // поиск узла с минимальным ключом
    Node *deleteMin(Node *p); // удаление узла с минимальным ключом из дерева p
    Node *remove(Node *p, long long int k); // удаление ключа k из дерева p
    void print(Node *p);
};

Node::Node(long long int k) {
    key = k;
    left = nullptr;
    right = nullptr;
    h = 0;
}

long long int Node::height(Node *p) {
    if (p) return p->h;
    else return 0;
}

long long int Node::balanceFactor(Node *p) {
    return height(p->right) - height(p->left);
}

void Node::fixheight(Node *p) {
    unsigned char hleft = height(p->left);
    unsigned char hright = height(p->right);
    if (hleft > hright) {
        p->h = hleft + 1;
    } else {
        p->h = hright + 1;
    }
}

Node *Node::rotateright(Node *p) // правый поворот вокруг p
{
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node *Node::rotateleft(Node *q) // левый поворот вокруг q
{
    Node *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node *Node::balance(Node *p) {
    fixheight(p);
    if (balanceFactor(p) == 2) {
        if (balanceFactor(p->right) < 0) p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (balanceFactor(p) == -2) {
        if (balanceFactor(p->left) > 0) p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

Node *Node::insert(Node *p, long long int k) {
    if (!p) return new Node(k);
    if (k == p->key) return p;
    if (k < p->key)
        p->left = insert(p->left, k);
    else
        p->right = insert(p->right, k);
    return balance(p);
}

Node *Node::findmin(Node *p) {
    return p->left ? findmin(p->left) : p;
}

Node *Node::deleteMin(Node *p) {
    if (p->left == nullptr)
        return p->right;
    p->left = deleteMin(p->left);
    return balance(p);
}

Node *Node::remove(Node *p, long long int k) {
    if (!p) return nullptr;
    if (k < p->key)
        p->left = remove(p->left, k);
    else if (k > p->key)
        p->right = remove(p->right, k);
    else if (k == p->key) {
        Node *q = p->left;
        Node *r = p->right;
        delete p;
        if (!r) return q;
        Node *min = findmin(r);
        min->right = deleteMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}


void Node::print(Node *p) {
    if (p != nullptr) { //Пока не встретится пустой узел
        print(p->left);
        cout << p->key << " ";  //Отображаем корень дерева
        print(p->right);
    }
}

int main() {
    int mass[6]={5,-1,6,-5,5,0};
    Node *root = nullptr;
    Node *node;
    for (int mas : mass) {
        if (mas > 0)
            root = node->insert(root, mas);
        else if (mas < 0)
            root = node->remove(root, abs(mas));
        else if (mas == 0) break;
    }
    node->print(root);
}