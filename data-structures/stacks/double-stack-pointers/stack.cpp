#include "./stack.h"
using namespace std;


int main() {

   DoubleStack<int> doubleStack;

   doubleStack.Push(0, 1);
   doubleStack.Push(0, 2);
   doubleStack.Push(0, 3);
   doubleStack.Push(0, 4);

   doubleStack.Print(0);

   doubleStack.Push(1, 10);
   doubleStack.Push(1, 11);
   doubleStack.Push(1, 12);
   doubleStack.Push(1, 13);

   doubleStack.Print(1);

   doubleStack.Pop(1);
   doubleStack.Print(1);

   return 0;
}