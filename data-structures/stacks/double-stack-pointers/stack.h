#include <iostream>
#include <cstdlib>

#ifndef MAXDS
#define MAXDS 1000
#endif

template<typename elementType>
class DoubleStack {
   private:
   elementType elements[MAXDS];
   int top1, top2;

   public:
   DoubleStack() {
      top1 = MAXDS / 2;
      top2 = MAXDS / 2 + 1;
   }

   bool IsEmpty(int d) {
      if (d == 0) return top1 == MAXDS / 2;
      else if (d == 1) return top2 == MAXDS / 2 + 1;
   }

   elementType Top(int d) {
      if (IsEmpty(d)) {
         std::cout << "Stack " << d << " is empty!" << std::endl;
         exit(EXIT_FAILURE); 
      }

      if (d == 0) {
         return elements[top1 + 1];
      }
      else if (d == 1) {
         return elements[top2 - 1];
      }
   }

   void Push(int d, elementType x) {
      if (d == 0) {
         if (top1 <= 0) {
            std::cout << "Stack " << d << " is full!" << std::endl;
            exit(EXIT_FAILURE);
         }
         elements[top1] = x;
         top1--;
      }
      if (d == 1) {
         if (top2 >= MAXDS - 1) {
            std::cout << "Stack " << d << " is full!" << std::endl;
            exit(EXIT_FAILURE);
         }
         elements[top2] = x;
         top2++;
      }
   }

   void Pop(int d) {
      if (d == 0) {
         if (IsEmpty(d)) {
            std::cout << "Stack " << d << " is empty!" << std::endl;
            exit(EXIT_FAILURE); 
         }
         top1++;
      }
      if (d == 1) {
         if (IsEmpty(d)) {
            std::cout << "Stack " << d << " is empty!" << std::endl;
            exit(EXIT_FAILURE); 
         }
         top2--;
      }
   }
};