#include "./stack.h"
#include <cstring>
#include <cmath>
using namespace std;

void infixToPostfix(char input[]) {
   Stack<char> stack;
   int length = strlen(input), o = 0;
   cout << length << endl;
   cout << input << endl;
   char output[] = "";

   for (int i = 0; i < length; i++) {
      switch(input[i]) {
         case '^':
         case '(':
            stack.Push(input[i]);
            break;
         case '*':
         case '/':
            while (!stack.IsEmpty() && stack.Top() == '^') {
               output[o++] = stack.Top();
               stack.Pop();
            }
            stack.Push(input[i]);
            break;
         case '+':
         case '-':
            while (!stack.IsEmpty() && 
               (stack.Top() == '*' ||
               stack.Top() == '/' ||
               stack.Top() == '^')) {
                  output[o++] = stack.Top();
                  stack.Pop();   
            }
            stack.Push(input[i]);
            break;
         case ')':
            while (stack.Top() != '(') {
               output[o++] = stack.Top();
               stack.Pop();
            }
            stack.Pop();
            break;
         default:
            output[o++] = input[i];
      }
   }
   while (!stack.IsEmpty()) {
         output[o++] = stack.Top();
         stack.Pop();
      }
      // output[o] = '\0';
   cout << output << endl;
}

int main() {

   char infix[] = "3*((x+1)*2)/(2*x+1)";
   infixToPostfix(infix);

   return 0;
}