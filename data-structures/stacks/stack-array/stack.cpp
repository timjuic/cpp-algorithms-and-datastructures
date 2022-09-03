#include "./stack.h"
using namespace std;

int main() {

   Stack<int> stack;
   
   stack.Push(1);
   stack.Push(2);
   stack.Push(3);
   stack.Push(4);

   stack.Print();

   stack.Pop();
   stack.Pop();

   stack.Print();

   cout << "Value on top: " << stack.Top() << endl;;

   return 0;
}