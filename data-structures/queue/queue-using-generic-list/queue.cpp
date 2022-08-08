#include "./queue.h"
using namespace std;


int main() {
   Queue<int> queue;

   queue.Enqueue(1);
   queue.Enqueue(2);
   queue.Enqueue(3);
   queue.Enqueue(4);

   queue.Print();
   queue.Dequeue();

   queue.Print();

   return 0;
}