#include "./queue.h"
using namespace std;

int main() {

   Queue<int> queue;

   cout << queue.IsEmpty() << endl;
   cout << endl;

   queue.Enqueue(1);
   queue.Enqueue(2);
   queue.Enqueue(3);
   queue.Enqueue(4);


   // Printing queue elements
   Queue<int> queue2;
   while (!queue.IsEmpty()) {
      queue2.Enqueue(queue.Front());
      queue.Dequeue();
   }

   while (!queue2.IsEmpty()) {
      cout << queue2.Front() << endl;
      queue2.Dequeue();
   }

   return 0;
}