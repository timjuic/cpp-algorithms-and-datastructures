#include <iostream>
#include <cstdlib>

#ifndef MAXB
#define MAXB 1000
#endif

template<typename nodeType>
class BinaryTree {
   struct Node {
      nodeType label;
      int parent, left, right;
   };

   Node elements[MAXB];
   int empty;

   public:
   typedef int node;
   const node lambda = -1;

   private:
   void Del(node n) {
      if (elements[n].left != lambda) Del(elements[n].left);
      if (elements[n].right != lambda) Del(elements[n].right);
      elements[n].parent = empty;
      empty = n;
   }

   void Prnt(node n) {
      if (elements[n].left != lambda) Prnt(elements[n].left);
      if (elements[n].right != lambda) Prnt(elements[n].right);
      std::cout << elements[n].label << " ";
   }

   public:
   BinaryTree() {
      for (int i = 0; i < MAXB - 1; i++) {
         elements[i].parent = i + 1;
      }
      elements[MAXB - 1].parent = lambda;
      empty = 0;
   }

   BinaryTree(nodeType x) {
      elements[0].label = x;
      elements[0].parent = elements[0].left = elements[0].right = lambda;
      for (int i = 0; i < MAXB - 1; i++) {
         elements[i].parent = i + 1;
      }
      elements[MAXB - 1].parent = lambda;
      empty = 1;
   }

   bool IsEmpty() {
      return empty == 0;
   }

   node Label(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[n].label;
   }

   node Root() {
      return empty == 0 ? lambda : 0;
   }

   node Parent(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[n].parent;
   }

   node LeftChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[n].left;
   }

   node RightChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[n].right;
   }

   void ChangeLabel(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[n].label = x;
   }

   void CreateRoot(nodeType x) {
      if (!IsEmpty()) {
         std::cout << "Can't create root! Tree is not empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      empty = elements[0].parent;
      elements[0].label = x;
      elements[0].parent = elements[0].left = elements[0].right = lambda;

   }

   void CreateLeftChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[n].left != lambda) {
         std::cout << "Can't create left child! It already exists!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (empty == lambda) {
         std::cout << "Tree is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      int p = empty;
      empty = elements[empty].parent;
      elements[p].label = x;
      elements[p].left = elements[p].right = lambda;
      elements[p].parent = n;
      elements[n].left = p;
   }

   void CreateRightChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[n].right != lambda) {
         std::cout << "Can't create left child! It already exists!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (empty == lambda) {
         std::cout << "Tree is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      node p = empty;
      empty = elements[empty].parent;
      elements[p].label = x;
      elements[p].left = elements[p].right = lambda;
      elements[p].parent = n;
      elements[n].right = p;
   }

   void Delete(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[n].parent != lambda) {
         if (elements[elements[n].parent].left == n) elements[elements[n].parent].left = lambda;
         else elements[elements[n].parent].right = lambda;
      }
      Del(n);
   }

   void Print() {
      Prnt(0);
      std::cout << std::endl;
   }
};