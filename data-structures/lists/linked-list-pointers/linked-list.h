#include <iostream>
#include <cstdlib>

template<typename elementType>
class LinkedList {
   private:
   struct node {
      elementType value;
      node* next;
   };
   
   public:
   typedef node *element;

   private:
   element L;
   const element lambda = NULL;

   public:
   LinkedList() {
      L = new node();
      L->next = NULL;
   }

   bool IsEmpty() {
      return L->next == NULL;
   }

   elementType Retrieve(element e) {
      if (e == lambda || e->next == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      return e->next->value;
   }

   element Next(element e) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      return e->next;
   }

   element Previous(element e) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (e == L) return lambda;
      element p = L;
      while (p->next != e) {
         p = p->next;
      }
      return p;
   }

   element First() {
      return L;
   }

   element End() {
      element current = L;
      while (current->next != lambda) {
         current = current->next;
      }
      return current;
   }


   void Insert(element e, elementType value) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      element newNode = new node;
      newNode->next = e->next;
      e->next = newNode;
      newNode->value = value;
   }

   void Delete(element e) {
      if (e == lambda || e->next == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      element p = e->next;
      e->next = e->next->next;
      delete p;
   }

   void ChangeValue(element e, elementType newValue) {
      if (e == lambda || e->next == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      e->next->value = newValue;
   }

   void Print() {
      element current = L->next;
      int index = 0;
      while (current != lambda) {
         std::cout << current->value << " ";
         current = current->next;
         index++;
      }
      std::cout << std::endl;
   }

   ~LinkedList() {
      while (L != lambda) {
         element p = L;
         L = L->next;
         delete p;
      }
   }

};