#ifndef Comp
#define Comp(a, b) (a > b ? 1 : a == b ? 0 : -1)
#endif

#ifndef MAXH
#define MAXH 1000
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
      while (n > 1 && Comp(elements[n], elements[n / 2]) == -1) {
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
         if (2 * n + 1 <= numOfElements && Comp(elements[2 * n + 1], elements[2 * n]) == -1) k = 2 * n + 1;
         else k = 2 * n;

         if (k <= numOfElements && Comp(elements[k], elements[n]) == -1) {
            nodeType p = elements[k];
            elements[k] = elements[n];
            elements[n] = p;
            next = true;
            n = k;
         } else next = false;
      } while (next);
   }
};