#ifndef MAXQ
#define MAXQ 1000
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class Queue {
   private:
   elementType elements[MAXQ];
   int front, rear;
   bool empty;

   int AddOne(int a) {
      return a == MAXQ - 1 ? 0 : a+1;
   }

   public:
   Queue() {
      front = 0;
      rear = MAXQ - 1;
      empty = true;
   }

   bool IsEmpty() {
      return (AddOne(rear) == front && empty);
   }

   elementType Front() {
      if (this->IsEmpty()) {
         std::cout << "Queue is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[front];
   }

   void Enqueue(elementType value) {
      if (AddOne(rear) == front && !empty) {
         std::cout << "Queue is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      rear = AddOne(rear);
      elements[rear] = value;
      empty = false;
   }

   void Dequeue() {
      if (AddOne(rear) == front && empty) {
         std::cout << "Queue is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      front = AddOne(front);
      empty = true;
   }
};