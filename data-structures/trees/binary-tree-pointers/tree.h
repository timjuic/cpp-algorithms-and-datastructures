#include <iostream>
#include <cstdlib>

template <typename nodeType>
class BinaryTree {
   private:
   struct Tnode {
      Tnode *parent, *left, *right;
      nodeType label;
   };

   Tnode *B;

   public:
   typedef Tnode* node;
   const node lambda = NULL;

   void Del(node n) {
      if (n->left != NULL) Del(n->left);
      if (n->right != NULL) Del(n->right);
      delete n;
   }

   void Prnt(node n) {
      std::cout << n->label << " ";
      if (n->left != NULL) Prnt(n->left);
      if (n->right != NULL) Prnt(n->right);
   }

   BinaryTree() {
      B = NULL;
   }

   BinaryTree(nodeType x) {
      B = new Tnode;
      B->parent = B->left = B->right = NULL;
      B->label = x;
   }

   bool IsEmpty() {
      return B == lambda;
   }

   nodeType Label(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->label;
   }
   
   node Root() {
      return B;
   }

   node Parent(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->parent;
   }

   node LeftChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->left;
   }

   node RightChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n->right;
   }

   void ChangeLabel(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      n->label = x;
   }

   void CreateRoot(nodeType x) {
      if (!this->IsEmpty()) {
         std::cout << "Can't create root! Tree is not empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      B = new Tnode;
      B->parent = B->left = B->right = NULL;
      B->label = x;
   }

   void CreateLeftChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n->left != lambda) {
         std::cout << "Can't create left node! It already exists" << std::endl;
         exit(EXIT_FAILURE);
      }
      Tnode *newNode = new Tnode;
      newNode->left = newNode->right = NULL;
      newNode->parent = n;
      newNode->label = x;
      n->left = newNode;
   }

   void CreateRightChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n->right != lambda) {
         std::cout << "Can't create right node! It already exists" << std::endl;
         exit(EXIT_FAILURE);
      }
      Tnode *newNode = new Tnode;
      newNode->label = x;
      newNode->left = newNode->right = NULL;
      newNode->parent = n;
      n->right = newNode;
   }

   void Delete(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n->parent != NULL) {
         if (n->parent->left == n) n->parent->left = NULL;
         else n->parent->right = NULL;
         Del(n);
      }
      else {
         Del(n);
         B = NULL;
      }
   }

   void Print() {
      if (IsEmpty()) return;
      Prnt(B);
      std::cout << std::endl;
   }

   ~BinaryTree() {
      if (B != lambda) Del(B);
   }
};