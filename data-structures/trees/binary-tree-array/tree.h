#ifndef MAXB
#define MAXB 1000
#endif

#include <iostream>
#include <cstdlib>

template<typename nodeType>
class BinaryTree {
   private:
   struct Node {
      nodeType label;
      bool used;
   };
   Node elements[MAXB+1];

   public:
   typedef int node;
   const node lambda = 0;

   private:
   void Del(node n) {
      if (2 * n <= MAXB && elements[2 * n].used) Del(2 * n);
      if (2 * n + 1 <= MAXB && elements[2 * n + 1].used) Del(2 * n + 1);
      elements[n].used = false;
   }

   void Prnt(node n) {
      std::cout << elements[n].label << " ";
      if (2 * n <= MAXB && elements[2 * n].used) Prnt(2 * n);
      if (2 * n + 1 <= MAXB && elements[2 * n + 1].used) Prnt(2 * n + 1);
   }

   public:
   BinaryTree() {
      for (int i = 0; i <= MAXB; i++) {
         elements[i].used = false;
      }
   }

   BinaryTree(nodeType x) {
      elements[1].value = x;
      elements[1].used = true;
      for (int i = 2; i <= MAXB; i++) {
         elements[i].used = false;
      }
   }

   bool IsEmpty() {
      return elements[1].used == false;
   }

   nodeType Label(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[n].label;
   }

   node Root() {
      return elements[1].used ? 1 : lambda;
   }

   node Parent(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return n/2;
   }

   node LeftChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (2 * n <= MAXB && elements[2 * n].used) return 2*n;
      else return lambda;
   }

   node RightChild(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (2 * n + 1 <= MAXB && elements[2 * n + 1].used) return 2 * n + 1;
      else return lambda;
   }

   void ChangeLabel(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[n].label = x; 
   }

   void CreateRoot(nodeType x) {
      if (elements[1].used) {
         std::cout << "Tree is not empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[1].label = x;
      elements[1].used = true;
   }

   void CreateLeftChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n * 2 > MAXB) {
         std::cout << "Tree is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[2 * n].used) {
         std::cout << "Left node is used!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[2 * n].used = true;
      elements[2 * n].label = x;
   }

   void CreateRightChild(node n, nodeType x) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (n * 2 + 1 > MAXB) {
         std::cout << "Tree is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[2 * n + 1].used) {
         std::cout << "Right node is used!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[2 * n + 1].used = true;
      elements[2 * n + 1].label = x;
   }

   void Delete(node n) {
      if (n == lambda) {
         std::cout << "That node doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      Del(n);
   }

   void Print() {
      Prnt(1);
      std::cout << std::endl;
   }
};