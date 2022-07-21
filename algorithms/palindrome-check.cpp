#include "../data-structures/queue/queue-pointers/queue.h"
#include "../data-structures/stack-pointers/stack.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
   Queue<char> queue;
   Stack<char> stack;
   char input[20];
   cout << "Type a word: ";
   cin >> input;
   for (int i = 0; i < strlen(input); i++) {
      queue.Enqueue(input[i]);
      stack.Push(input[i]);
   }

   while (!stack.IsEmpty() && queue.Front() == stack.Top()) {
      stack.Pop();
      queue.Dequeue();
   }

   if (stack.IsEmpty()) {
      cout << "Word is a palindrome!" << endl;
   } else cout << "Word is NOT a palindrome!" << endl;

   return 0;
}