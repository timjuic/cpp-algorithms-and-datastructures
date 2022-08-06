#include "./queue.h"
using namespace std;

int main() {
   Deque<int> deque;

   deque.Enqueue(1);
   deque.Enqueue(2);
   deque.Enqueue(3);

   deque.Push(4);
   deque.Push(5);
   deque.Push(6);

   deque.Print();

   cout << deque.Front() << endl;

   cout << deque.IsEmpty() << endl;

   return 0;
}