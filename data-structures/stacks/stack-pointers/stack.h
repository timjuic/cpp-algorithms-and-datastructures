#include <iostream>
#include <cstdlib>

template<typename elementType>
class Stack {
   private:
   struct Node {
      elementType value;
      Node *next;
   };
   
   Node *L;

   public:
   Stack() {
      L = new Node;
      L->next = NULL;
   }

   bool IsEmpty() {
      return L->next == NULL;
   }

   elementType Top() {
      if (L->next == NULL) {
         std::cout << "Stack is empty1" << std::endl;
         exit(EXIT_FAILURE);
      }
      return L->next->value;
   }

   void Push(elementType value) {
      Node *newElem = new Node;
      newElem->value = value;
      newElem->next = L->next;
      L->next = newElem;
   }

   void Pop() {
      if (L->next == NULL) {
         std::cout << "Stack is empty2" << std::endl;
         exit(EXIT_FAILURE);
      }
      Node *toDelete = L;
      L = L->next;
      delete toDelete;
   }

   void Print() {
      Node *iterator = L->next;
      while (iterator != NULL) {
         std::cout << iterator->value << " ";
         iterator = iterator->next;
      }
      std::cout << std::endl;
   }

   ~Stack() {
      while (L != NULL) {
         Node *p = L;
         L = L->next;
         delete p;
      }
   }


};