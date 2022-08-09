#include "./no-class.h"
using namespace std;

int main() {
   Deque deque;

   InitDQ(deque);

   EnqueueDQ(deque, 1);
   EnqueueDQ(deque, 2);
   EnqueueDQ(deque, 3);
   EnqueueDQ(deque, 4);

   PushDQ(deque, 5);
   PushDQ(deque, 6);
   PushDQ(deque, 7);

   PrintDQ(deque);

   DequeueDQ(deque);
   DequeueDQ(deque);

   PrintDQ(deque);

   DisposeDQ(deque);

   return 0;
}