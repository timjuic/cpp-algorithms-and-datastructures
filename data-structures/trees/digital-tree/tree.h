#include "../general-tree-cursor/tree.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

class DigitalTree {
    private:
    struct NodeType {
        char letter;
        bool terminal;;
    };

    GeneralTree<NodeType> T;

    public:
    typedef GeneralTree<NodeType>::node node;
    GeneralTree<NodeType>::node lambda;


    DigitalTree() {
        lambda = T.lambda;
        NodeType n = {' ', false};
        T.CreateRoot(n);
    }

    bool IsEmpty() {
        return T.FirstChild(T.Root()) == T.lambda;
    }

    bool IsElement(char string[]) {
        GeneralTree<NodeType>::node root = T.Root();
        for (int i = 0; i < strlen(string); i++) {
            GeneralTree<NodeType>::node currentNode = T.FirstChild(root);
            while (currentNode != T.lambda && T.Label(currentNode).letter != string[i]) {
                currentNode = T.NextSibling(currentNode);
            }
            if (currentNode == T.lambda) return false;
            if (i == strlen(string) - 1) return T.Label(currentNode).terminal;
            root = currentNode;
        }
    }

    void Insert(char string[]) {
        GeneralTree<NodeType>::node n = T.Root();
        for (int i = 0; i < strlen(string); i++) {
            GeneralTree<NodeType>::node n1 = T.FirstChild(n);
            while (n1 != T.lambda && T.Label(n1).letter != string[i]) {
                n1 = T.NextSibling(n1);
            }
            if (n1 == T.lambda) {
                NodeType p;
                p.letter = string[i];
                p.terminal = false;
                T.CreateChild(n, p);
                n1 = T.FirstChild(n);
                while (T.Label(n1).letter != string[i]) {
                    n1 = T.NextSibling(n1);
                }
                n = n1;
            }
            NodeType p = T.Label(n);
            p.terminal = true;
            T.ChangeLabel(n, p);
        }
    }

    void Delete(char string[]) {
        GeneralTree<NodeType>::node n = T.Root();
        for (int i = 0; i < strlen(string); i++) {
            GeneralTree<NodeType>::node n1 = T.FirstChild(n);
            while (n1 != T.lambda && T.Label(n1).letter != string[i]) {
                n1 = T.NextSibling(n1);
            }
            if (n1 == T.lambda) return;
            n = n1;
        }
        NodeType p = T.Label(n);
        p.terminal = false;
        T.ChangeLabel(n, p);
        while (T.FirstChild(n) == T.lambda && !T.Label(n).terminal && n != T.Root()) {
            GeneralTree<NodeType>::node n1 = T.Parent(n);
            T.Delete(n);
            n = n1;
        }
    }
    
    private:
    void Prnt(GeneralTree<NodeType>::node n, char word[], int depth) {
        std::cout << "Adding letter: " << T.Label(n).letter <<  " at depth: " << depth << std::endl;
        word[depth] = T.Label(n).letter;

        if (T.Label(n).terminal) {
            std::cout << "word is: " << word << std::endl;
        }

        if (T.FirstChild(n) != T.lambda) {
            Prnt(T.FirstChild(n), word, ++depth);
        }

        if (T.NextSibling(n) != T.lambda) {
            Prnt(T.NextSibling(n), word, depth);
        }
    }

    public:
    void Print() {
        if (IsEmpty()) return;
        char str[100] = " ";
        Prnt(T.Root(), str, 1);
    }
};