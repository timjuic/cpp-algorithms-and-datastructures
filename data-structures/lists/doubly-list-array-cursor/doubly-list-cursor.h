#ifndef MAXL
#define MAXL 1000
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class DoublyListCursor {
   private:
   struct elem {
      int next, prev;
      elementType value;
   };

   elem elements[MAXL];
   int empty;

   public:
   const int lambda = -1;
   typedef int element;

   DoublyListCursor() {
      elements[0].next = elements[0].prev = 0;
      for (int i = 1; i < MAXL-1; i++) {
         elements[i].next = i + 1;
      }
      elements[MAXL-1].next = lambda;
      empty = 1;
   }

   bool IsEmpty() {
      return elements[0].next == 0;
   }

   elementType Retrieve(element e) {
      if (e == lambda || elements[e].next == 0) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[elements[e].next].value;
   }

   element Next(element e) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (elements[e].next == 0) return lambda;
      return elements[e].next;
   }

   element Previous(element e) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (e == 0) return lambda;
      return elements[e].prev;
   }

   element First() {
      return 0;
   }

   element End() {
      return elements[0].prev;
   }

   
   void Insert(element e, elementType value) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (empty == lambda) {
         std::cout << "List is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      int nextUnused = elements[empty].next;
      elements[empty].value = value;
      elements[empty].next = elements[e].next;
      elements[empty].prev = e;
      elements[elements[e].next].prev = empty;
      elements[e].next = empty;
      empty = nextUnused;
   }

   void Delete(element e) {
      if (e == lambda || elements[e].next == 0) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      int nextUnused = elements[e].next;
      elements[e].next = elements[elements[e].next].next;
      elements[elements[elements[e].next].next].prev = e;
      elements[nextUnused].next = empty;
      empty = nextUnused;
   }

   void ChangeValue(element e, elementType newValue) {
      if (e == lambda || elements[e].next == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[elements[e].next].value = newValue;
   }

   void Print() {
      int index = 0;
      std::cout << "elements: " << std::endl;
      while (elements[index].next != 0) {
         index = elements[index].next;
         std::cout << elements[index].value << std::endl;
      }
   }
};