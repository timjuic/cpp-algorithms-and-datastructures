#ifndef MAXT
#define MAXT 1000
#endif

#include <iostream>
#include <cstdlib>

template<typename nodeType>
class GeneralTree {
    private:
    struct Node {
        nodeType label;
        int child, sibling, parent;
    };

    Node elements[MAXT];
    int empty;

    public:
    typedef int node;
    const int lambda = -1;

    GeneralTree(nodeType x) {
        elements[0].label = x;
        elements[0].child = elements[0].sibling = elements[0].parent = lambda;
        for (int i = 1; i < MAXT - 1; i++) {
            elements[i].sibling = i + 1;
        }
        elements[MAXT - 1].sibling = lambda;
        empty = 1;
    }

    GeneralTree() {
        for (int i = 0; i < MAXT - 1; i++) {
            elements[i].sibling = i + 1;
        }
        elements[MAXT - 1].sibling = lambda;
        empty = 0;
    }

    bool IsEmpty() {
        return empty == 0;
    }

    nodeType Label(node n) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return elements[n].label;
    }

    node Root() {
        if (!IsEmpty()) return 0;
        else return lambda;
    }

    node Parent(node n) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return elements[n].parent;
    }

    node FirstChild(node n) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return elements[n].child;
    }

    node NextSibling(node n) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return elements[n].sibling;       
    }

    void ChangeLabel(node n, nodeType x) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        elements[n].label = x;
    }

    void CreateRoot(nodeType x) {
        if (!IsEmpty()) {
            std::cout << "Tree is not empty! Can't create root!" << std::endl;
            exit(EXIT_FAILURE);
        }
        empty = elements[0].sibling;
        elements[0].label = x;
        elements[0].parent = elements[0].child = elements[0].sibling = lambda;
    }

    void CreateChild(node n, nodeType x) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (empty == lambda) {
            std::cout << "Datastructure is full! Cant create new child!" << std::endl;
            exit(EXIT_FAILURE);
        }
        int i = empty;
        empty = elements[empty].sibling;
        elements[i].label = x;
        elements[i].child = lambda;
        elements[i].parent = n;
        elements[i].sibling = elements[n].child;
        elements[n].child = i;
    }

    private:
    void Del(node n) {
        if (elements[n].sibling != lambda) Del(elements[n].sibling);
        if (elements[n].child != lambda) Del(elements[n].child);
        elements[n].sibling = empty;
        empty = n; 
    }

    public:
    void Delete(node n) {
        if (n == lambda) {
            std::cout << "Node: " << n << " doesn't exist!" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (elements[n].child != lambda) Del(elements[n].child);
        if (elements[n].parent != lambda) {
            if (elements[elements[n].parent].child == n) {
                elements[elements[n].parent].child = elements[n].sibling;
            } else {
                int i = elements[elements[n].parent].child;
                while (elements[i].sibling != n) {
                    i = elements[i].sibling;
                }
                elements[i].sibling = elements[n].sibling;
            }
        }
        elements[n].sibling = empty;
        empty = n;
    }

    private:
    void Prnt(node n) {
        std::cout << elements[n].label << " ";
        if (elements[n].child != lambda) Prnt(elements[n].child);
        if (elements[n].sibling != lambda) Prnt(elements[n].sibling);
    }

    public:
    void Print() {
        if (!IsEmpty()) {
            std::cout << "Preorder traversal:" << std::endl;
            Prnt(0);
            std::cout << std::endl;
        }
    }
};