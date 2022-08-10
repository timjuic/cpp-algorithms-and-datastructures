#ifndef Comp
#define Comp(a, b) (a > b ? 1 : a == b ? 0 : -1)
#endif

#ifndef MAXH
#define MAXH 1000
#endif

// If this variable is set to 1, heap will be max heap
// If its set to -1, heap will be min heap
#ifndef MIN_OR_MAX
#define MIN_OR_MAX 1
#endif

#include <iostream>
#include <cstdlib>

template <typename nodeType>
class Heap {
   private:
   nodeType elements[MAXH+1];
   int numOfElements;

   public:
   Heap() {
      numOfElements = 0;
   }

   bool IsEmpty() {
      return numOfElements == 0;
   }

   nodeType RootLabel() {
      if (numOfElements == 0) {
         std::cout << "Heap is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[1];
   }

   void Insert(nodeType x) {
      if (numOfElements == MAXH) {
         std::cout << "Heap is full!" << std::endl;
         exit(EXIT_FAILURE);
      }

      elements[++numOfElements] = x;
      int n = numOfElements;
      while (n > 1 && Comp(elements[n], elements[n / 2]) == MIN_OR_MAX) {
         nodeType p = elements[n / 2];
         elements[n / 2] = elements[n];
         elements[n] = p;
         n /= 2;
      }
   }

   void DeleteRoot() {
      if (numOfElements == 0) {
         std::cout << "Heap is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      int n = 1;
      elements[1] = elements[numOfElements--];
      int k;
      bool next;
      do {
         if (2 * n + 1 <= numOfElements && Comp(elements[2 * n + 1], elements[2 * n]) == MIN_OR_MAX) k = 2 * n + 1;
         else k = 2 * n;

         if (k <= numOfElements && Comp(elements[k], elements[n]) == MIN_OR_MAX) {
            nodeType p = elements[k];
            elements[k] = elements[n];
            elements[n] = p;
            next = true;
            n = k;
         } else next = false;
      } while (next);
   }

   private:
   void Prnt(const std::string &prefix, int n, bool isLeft) {
      if ( n <= numOfElements ) {
         std::cout << prefix;

         std::cout << (isLeft ? "├──" : "└──" );

         // print the value of the node
         std::cout << elements[n] << std::endl;

         // enter the next tree level - left and right branch
         Prnt( prefix + (isLeft ? "│   " : "    "), n * 2, true);
         Prnt( prefix + (isLeft ? "│   " : "    "), n * 2 + 1, false);
      } 
   }

   public:
   void Print() {
      Prnt("", 1, false);
   }
};