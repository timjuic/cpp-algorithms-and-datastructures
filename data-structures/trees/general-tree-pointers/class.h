#include <iostream>
#include <cstdlib>

template<typename nodeType>
class GeneralTree {
   private:
   struct Node {
      nodeType value;
      Node *child, *sibling, *parent;
   };

   Node *root;

   public:
   typedef Node *node;
   const node lambda = NULL;

   GeneralTree() {
      root = NULL;
   }

   GeneralTree(nodeType x) {
      root = new Node;
      root->parent = root->child = root->sibling = NULL;
      root->label = x;
   }

   bool IsEmpty() {
      return root == lambda;
   }

   nodeType Label(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->value;
   }

   node Root() {
      return root;
   }

   node Parent(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->parent;
   }

   node FirstChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->child;
   }

   node NextSibling(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->sibling;
   }

   void ChangeLabel(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      n->value = x;
   }

   void CreateRoot(nodeType x) {
      if (!IsEmpty()) {
         std::cout << "Can't create root! Tree is not empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      root = new Node;
      root->value = x;
      root->child = root->parent = root->sibling = lambda;
   }

   void CreateChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      Node *newNode = new Node;
      newNode->value = x;
      newNode->parent = n;
      newNode->sibling = n->child;
      n->child = newNode;
      newNode->child = lambda;
   }

   private:
    void Del(node n) {
      if (n->sibling != lambda) Del(n->sibling);
      if (n->child != lambda) Del(n->child);
      delete n;
   }

   public:
   void Delete(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n->child != lambda) Del(n->child);
      if (n->parent != lambda) { // If node is not root
         if (n->parent->child == n) { // If node is first child
            n->parent->child = n->sibling;
         } else {
            Node *i = n->parent->child;
            while (i->sibling != n) {
               i = i->sibling;
            }
            i->sibling = n->sibling;
         }
      } else root = lambda;

      n->sibling = n->child = lambda;
   }

   private:
   void Prnt(node n) {
      std::cout << n->value << " ";
      if (n->sibling != lambda) Prnt(n->sibling);
      if (n->child != lambda) Prnt(n->child);
   }

   public:
   void Print() {
      if (IsEmpty()) return;
      Prnt(root);
      std::cout << std::endl;
   }

};