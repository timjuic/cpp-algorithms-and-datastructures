#include "./stack.h"
using namespace std;

int main() {

   Stack<int> stack;
   cout << stack.IsEmpty() << endl;

   
   stack.Push(1);
   stack.Push(2);
   stack.Push(3);
   stack.Push(4);

   cout << "Elements: " << endl;
   stack.Print();

   stack.Pop();
   stack.Pop();

   cout << "Elements: " << endl;
   stack.Print();

   cout << "Value on top " << stack.Top() << endl;;

   return 0;
}