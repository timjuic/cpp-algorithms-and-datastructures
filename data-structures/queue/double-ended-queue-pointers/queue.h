#include <iostream>
#include <cstdlib>

template<typename elementType>
class Deque {
   private:
   struct Node {
      Node *next;
      elementType value;
   };

   Node *front, *rear;

   public:
   Deque() {
      Node *p = new Node;
      p->next = NULL;
      front = rear = p;
   }

   bool IsEmpty() {
      return front == rear;
   }

   elementType Front() {
      if (IsEmpty()) {
         std::cout << "Deque is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return front->next->value;
   }

   void Enqueue(elementType x) {
      Node *newNode = new Node;
      newNode->value = x;
      newNode->next = NULL;
      rear->next = newNode;
      rear = newNode;
   }

   void Push(elementType x) {
      Node *newNode = new Node;
      newNode->value = x;
      newNode->next = front->next;
      front->next = newNode;
   }

   void Dequeue() {
      if (IsEmpty()) {
         std::cout << "Deque is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      Node *toDelete = front;
      front = front->next;
      delete toDelete;
   }

   void Print() {
      Node *current = front;
      while (current->next != NULL) {
         std::cout << current->next->value << " ";
         current = current->next;
      }
      std::cout << std::endl;
   }

   ~Deque() {
      while (!IsEmpty()) {
         Node *toDelete = front;
         front = front->next;
         delete toDelete;
      }
   }






};