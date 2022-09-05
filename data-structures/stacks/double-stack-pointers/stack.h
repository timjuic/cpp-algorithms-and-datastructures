#include <iostream>
#include <cstdlib>

template<typename elementType>
class DoubleStack {
   private:
   struct Node {
      elementType value;
      Node *next;
   };

   Node *L1, *L2;

   public:
   DoubleStack() {
      L1 = new Node;
      L2 = new Node;
      L1->next = L2->next = NULL;
   }

   bool IsEmpty(int d) {
      if (d == 0) return L1->next == NULL;
      else if (d == 1) return L2->next == NULL;
   }

   elementType Top(int d) {
      if (IsEmpty(d)) {
         std::cout << "Stack " << d << " is empty!" << std::endl;
         exit(EXIT_FAILURE); 
      }

      if (d == 0) {
         return L1->next->value;
      }
      else if (d == 1) {
         return L2->next->value;
      }
   }

   void Push(int d, elementType x) {
      if (d == 0) {
         Node *newNode = new Node;
         newNode->value = x;
         newNode->next = L1->next;
         L1->next = newNode;
      }
      if (d == 1) {
         Node *newNode = new Node;
         newNode->value = x;
         newNode->next = L2->next;
         L2->next = newNode;
      }
   }

   void Pop(int d) {
      if (IsEmpty(d)) {
         std::cout << "Stack " << d << " is empty!" << std::endl;
         exit(EXIT_FAILURE); 
      }
      
      if (d == 0) {
         Node *toDelete = L1;
         L1 = L1->next;
         delete toDelete;
      }
      if (d == 1) {
         Node *toDelete = L2;
         L2 = L2->next;
         delete toDelete;
      }
   }

   void Print(int d) {
      Node *iterator;
      if (d == 0) iterator = L1->next;
      else if (d == 1) iterator = L2->next;

      while (iterator != NULL) {
         std::cout << iterator->value << " ";
         iterator = iterator->next;
      }
      std::cout << std::endl;
   }
};