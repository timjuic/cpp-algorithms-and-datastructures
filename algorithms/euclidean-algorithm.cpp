#include <iostream>
using namespace std;

int euclidean(unsigned int a, unsigned int b) {
   if (a == 0) return b;
   return euclidean(b % a, a);
}

int main() {
   cout << euclidean(5, 10) << endl;
   cout << euclidean(12, 10) << endl;
   cout << euclidean(30, 100) << endl;

   return 0;
}