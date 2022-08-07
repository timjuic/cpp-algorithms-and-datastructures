#include <iostream>
#include <cstdlib>

template<typename elementType>
class DoublyLinkedList {
   private:
   struct Node {
      Node *prev;
      Node *next;
      elementType value;
   };

   public:
   typedef Node *element;
   const element lambda = NULL;

   private:
   element L;

   public:
   DoublyLinkedList() {
      L = new Node;
      L->prev = L;
      L->next = L;
   }

   bool IsEmpty() {
      return L->next == L;
   }

   elementType Retrieve(element e) {
      if (e == lambda || e->next == L) {
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
      if (e->next == L) return lambda;
      return e->next;
   }

   element Previous(element e) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      if (e->prev == L) return lambda;
      return e->prev;
   }

   element First() {
      return L;
   }

   element End() {
      return L->prev;
   }

   void Insert(element e, elementType value) {
      if (e == lambda) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      element p = new Node;
      p->next = e->next;
      e->next->prev = p;
      e->next = p;
      p->prev = e;
      p->value = value;
   }

   void Delete(element e) {
      if (e == lambda || e->next == L) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      element p = e->next;
      e->next = p->next;
      p->next->prev = e;
      delete p;     
   }

   void ChangeValue(element e, elementType newValue) {
      if (e == lambda || e->next == L) {
         std::cout << "That element doesn't exist" << std::endl;
         exit(EXIT_FAILURE);
      }
      e->next->value = newValue;
   }

   void Print() {
      element current = L;
      int index = 0;
      if (IsEmpty()) return;
      while (current->next != L) {
         std::cout << this->Retrieve(current) << " ";
         current = this->Next(current);
         index++;
      }
      std::cout << std::endl;
   }

   ~DoublyLinkedList() {
      element current, k = L->prev;
      while (L != k) {
         current = L;
         L = L->next;
         delete current;
      }
      delete L;
   }




   



};