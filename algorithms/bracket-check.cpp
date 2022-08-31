#include "../data-structures/stacks/stack-pointers/stack.h"
using namespace std;

bool CheckBrackets(char string[]) {
   Stack<char> stack;

   for (int i = 0; i < strlen(string); i++) {
      if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
         stack.Push(string[i]);
      }

      if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
         if (stack.IsEmpty()) return false;
         if (string[i] == ')' && stack.Top() == '(' ||
             string[i] == ']' && stack.Top() == '[' ||
             string[i] == '}' && stack.Top() == '{') {
            stack.Pop();
         } else return false;
      }
   }

   if (stack.IsEmpty()) return true;
   else return false;
}


int main() {
   char str[100];
   cout << "Type Expression with brackets: ";
   cin >> str;

   if (CheckBrackets(str)) {
      cout << "Brackets match" << endl;
   } else cout << "Brackets don't match" << endl;

   return 0;
}