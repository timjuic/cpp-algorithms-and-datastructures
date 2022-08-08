#include "./stack.h"
using namespace std;


int main() {

   DoubleStack<int> doubleStack;

   doubleStack.Push(0, 1);
   doubleStack.Push(0, 2);
   doubleStack.Push(0, 3);
   doubleStack.Push(0, 4);

   while (!doubleStack.IsEmpty(0)) {
      cout << doubleStack.Top(0) << " ";
      doubleStack.Pop(0);
   }
   cout << endl;

   doubleStack.Push(1, 10);
   doubleStack.Push(1, 11);
   doubleStack.Push(1, 12);
   doubleStack.Push(1, 13);

   while (!doubleStack.IsEmpty(1)) {
      cout << doubleStack.Top(1) << " ";
      doubleStack.Pop(1);
   }
   cout << endl;

   return 0;
}