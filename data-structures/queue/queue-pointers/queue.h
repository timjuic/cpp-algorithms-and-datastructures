#include <iostream>
#include <cstdlib>


template<typename elementType> 
class Queue {
   private:
   struct Node {
      elementType value;
      Node *next;
   };

   Node *front, *rear;

   public:
   Queue() {
      Node *p = new Node;
      p->next = NULL;
      front = rear = p;
   }

   bool IsEmpty() {
      return front == rear;
   }

   elementType Front() {
      if (front == rear) {
         std::cout << "Queue is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return front->next->value;
   }

   void Enqueue(elementType value) {
      Node *newNode = new Node;
      newNode->value = value;
      newNode->next = NULL;
      rear->next = newNode;
      rear = newNode;
   }

   void Dequeue() {
      if (front == rear) {
         std::cout << "Queue is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      Node *toDelete = front;
      front = front->next;
      delete toDelete;
   }

   ~Queue() {
      while (front != rear) {
         Node *toDelete = front;
         front = front->next;
         delete toDelete;
      }
   }
};