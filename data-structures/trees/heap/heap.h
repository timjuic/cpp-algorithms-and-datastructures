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

   Heap() {
      numOfElements = 0;
   }

   bool IsEmpty() {
      return numOfElements == 0;
   }

   nodeType RootLabel() {
      if (numberOfElements == 0) {
         std::cout << "Heap is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[1];
   }

   void Insert() {
      
   }
};