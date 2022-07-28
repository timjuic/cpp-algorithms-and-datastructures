#ifndef Comp
#define Comp(a, b) (a < b ? -1 : (a == b) ? 0 : 1)
#endif

#include <iostream>
#include <cstdlib>

template<typename nodeType>
class BinarySearchTree {
    private:
    struct Node {
        nodeType label;
        Node *parent, *left, *right;
    };

    Node *root;

    public:
    BinarySearchTree() {
        root = NULL;
    }

    bool IsEmpty() {
        return root == NULL;
    }

    bool IsNode(nodeType x) {
        Node *p = root;
        while (p != NULL && Comp(p->label, x) != 0) {
            if (Comp(p->label, x) == -1) p = p->right;
            else p = p->left;
        }
        return p != NULL;
    }

    nodeType Min() {
        if (root == NULL) {
            std::cout << "Tree is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        Node *p = root;
        while (p->left != NULL) {
            p = p->left;
        }
        return p->label;
    }

    nodeType Max() {
        if (root == NULL) {
            std::cout << "Tree is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        Node *p = root;
        while (p->right != NULL) {
            p = p->right;
        }
        return p->label;
    }

    void Insert(nodeType x) {
        if (root == NULL) {
            root = new Node;
            root->label = x;
            root->left = root->right = root->parent = NULL;
        } else {
            Node *p = root;
            bool next = true;
            do {
                if (Comp(p->label, x) == 1 && p->left != NULL) {
                    p = p->left;
                } else if (Comp(p->label, x) == -1 && p->right != NULL) {
                    p = p->right;
                } else {
                    next = false;
                }
            } while (next);

            if (Comp(p->label, x) != 0) {
                Node *n = new Node;
                n->left = n->right = NULL;
                n->parent = p;
                n->label = x;
                if (Comp(p->label, x) == -1) p->right = n;
                else p->left = n;
            }
        }
    }

    void Delete(nodeType x) {
        Node *n = root, *p;
        while (n != NULL && Comp(n->label, x) != 0) {
            if (Comp(n->label, x) == 1) n = n->left;
            else n = n->right;
        }

        if (n != NULL) {
            if (n->left != NULL && n->right != NULL) {
                p = n->right;
                while (p->left != NULL) p = p->left;
                n->label = p->label;
                n = p;
            }
            if (n->left != NULL) p = n->left;
            else p = n->right;
            if (p != NULL) p->parent = n->parent;

            if (n->parent != NULL) {
                if (n->parent->left == n) n->parent->left = p;
                else n->parent->right = p;
            } else {
                root = p;
                if (p != NULL) p->parent = NULL;
            }
            delete n;
        }
    }

    private:
    void Del(Node *n) {
        if (n->left != NULL) Del(n->left);
        if (n->right != NULL) Del(n->right);
        delete n;
    }

    public:
    ~BinarySearchTree() {
        if (root != NULL) Del(root);
    }
};