#include "../../data-structures/queue/queue-pointers/queue.h"
using namespace std;


int main() {
   Queue<int> queue;

   const int MAX = 20;
   int n;

   cout << "Type natural number: ";
   cin >> n;

   while (n <= 0 || n > MAX) {
      cout << "Number must be between 1 and 20!" << endl;
      cout << "Type natural number: ";
      cin >> n;
   }
   

   for (int i = 0; i < n; i++) {
      cout << i+1 << ". = ";
      int value;
      cin >> value;
      queue.Enqueue(value);
   }

   for (int i = 0; i < n; i++) {
		int j = n-i-1;
		int m = queue.Front();
		queue.Dequeue();
		while (j > 0) {
			  if (queue.Front() >= m) 
			  	 queue.Enqueue(queue.Front());
			  else {
			  	   queue.Enqueue(m);
			  	   m = queue.Front();
			  }
			  queue.Dequeue();
			  j--;
		}

		for (int k = 0; k < i; k++) {
			queue.Enqueue(queue.Front());
			queue.Dequeue();
		}
		queue.Enqueue(m);
	}


	while (!queue.IsEmpty()) {
		  cout << queue.Front() << " ";
		  queue.Dequeue();
	}
	cout << endl;

   return 0;
}