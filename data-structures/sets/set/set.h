#ifndef MAXS
#define MAXS 1000
#endif

#ifndef Equal
#define Equal(a, b) (a == b ? true : false)
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class Set {
   private:
   elementType elements[MAXS];
   unsigned short numberOfElements;

   public:
   Set() {
      numberOfElements = 0;
   }

   bool IsEmpty() {
      return numberOfElements == 0;
   }

   bool IsElement(elementType x) {
      bool found = false;
      for (int i = 0; i < numberOfElements; i++) {
         if (Equal(elements[i], x)) found = true;
      }
      return found;
   }

   void Insert(elementType x) {
      if (numberOfElements == MAXS) {
         std::cout << "Set is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (IsElement(x)) return;
      elements[numberOfElements++] = x;
   }

   void Delete(elementType x) {
      int i;
      for (i = 0; i < numberOfElements && Equal(elements[i], x); i++);
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

