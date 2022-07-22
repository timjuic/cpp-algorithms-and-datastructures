#include "./stack.h"
using namespace std;

int main() {

   Stack<int> stack;

   stack.Push(1);
   stack.Push(2);
   stack.Push(3);
   stack.Push(4);

   cout << "elements: ";
   stack.Print();

   stack.Pop();

   cout << "elements: ";
   stack.Print();

   cout << "element on top: " << stack.Top() << endl;

   return 0;
}