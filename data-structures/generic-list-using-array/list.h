#ifndef MAXL
#define MAXL 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementType>
class List {
   public:
   static const int lambda = -1;
   typedef int element;

   protected:
   elementType elements[MAXL];
   int noEl;

   public:
   
   // Constructor
   List() {
      noEl = 0;
   }

   // Methods for getting information about the list
   bool IsEmpty() {
      return noEl == 0;
   }

   elementType Retrieve(element e) {
      if (e >= noEl || e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[e];
   }


   // Methods for iterating through the list
   element Next(element e) {
      if (e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (e < noEl) return e + 1;
      else return lambda;
   }

   element Previous(element e) {
      if (e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      } else {
         return e - 1;
      }
   }

   element First() {
      return 0;
   }

   element End() {
      return noEl;
   }


   // Methods for changing the list
   void Insert(element e, elementType value) {
      if (e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (noEl == MAXL) {
         std::cout << "List is full!" << std::endl;
         exit(EXIT_FAILURE);
      }

      for (int i = noEl - 1; i >= e; i--) {
         elements[i + 1] = elements[i];
      }
      elements[e] = value;
      noEl++;
   }

   void Delete(element e) {
      if (e >= noEl || e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      
      for (int i = e; i < noEl; i++) {
         elements[i] = elements[i + 1];
      }
      noEl--;
   }

   void ChangeValue(element e, elementType newValue) {
      if (e >= noEl || e <= lambda) {
         std::cout << "Element with index: " << e << " doesn't exist!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[e] = newValue;
   }
};