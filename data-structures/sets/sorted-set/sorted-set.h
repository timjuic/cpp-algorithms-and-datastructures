#ifndef MAXS
#define MAXS 1000
#endif

#ifndef Equal
#define Equal(a, b) (a == b ? true : false)
#endif

#ifndef Comp
#define Comp(a, b) (a > b ? 1 : a == b ? 0 : -1)
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class SortedSet {
   private:
   elementType elements[MAXS];
   unsigned short numberOfElements;

   int BinarySearch(elementType x) {
      if (numberOfElements == 0) return -1;
      int i = 0, j = numberOfElements, k = (i + j) / 2;
      while (i < j && elements[k] != x){
         if (elements[k] < x) i = k + 1;
         else j = k - 1;
         k = (i + j) / 2;
      }
      if (elements[k] == x) return x;
      else return -1;
   }

   public:
   SortedSet() {
      numberOfElements = 0;
   }

   bool IsEmpty() {
      return numberOfElements == 0;
   }

   bool IsElement(elementType x) {
      int i = BinarySearch(x);
      if (i == -1) return false;
      else return true;
   }

   void Insert(elementType x) {
      if (numberOfElements == MAXS) {
         std::cout << "Set is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      int i = this->BinarySearch(x);
      if (i != -1) return;
      for (i = numberOfElements - 1; i >=  0 && Comp(elements[i], x) == 1; i--) {
         elements[i + 1] = elements[i];
      }
      elements[i + 1] = x;
      numberOfElements++;
   }

   void Delete(elementType x) {
      int i = BinarySearch(x);
      if (i == -1) return;
      for (; i < numberOfElements; i++) {
         elements[i] = elements[i + 1];         
      }
      numberOfElements--;
   }

   void DeleteAll() {
      int i = numberOfElements - 1;
      while (i >= 0) {
         elements[i] = elements[i + 1];
         i--;
         numberOfElements--;
      }
   }

   void Print() {
      for (int i = 0; i < numberOfElements; i++) {
         std::cout << elements[i] << std::endl;
      }
   }
};
