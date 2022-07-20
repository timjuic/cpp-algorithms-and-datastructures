#ifndef MAXS
#define MAXS 1000
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class Stack {
   private:
   elementType elements[MAXS];
   int top;

   public:

   Stack() {
      top = MAXS - 1;
   }

   bool IsEmpty() {
      return top == MAXS - 1;
   }

   elementType Top() {
      if (top == MAXS - 1) {
         std::cout << "Stack is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      return elements[top + 1];
   }

   void Push(elementType value) {
      if (top == 0) {
         std::cout << "Stack is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[top--] = value;
   }

   void Pop() {
      if (top == MAXS - 1) {
         std::cout << "Stack is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      top++;
   }
   
   void Print() {
      if (top < MAXS - 1) {
         for (int i = top; i < MAXS; i++) {
            std::cout << elements[i] << std::endl;
         }
      }
   }
};