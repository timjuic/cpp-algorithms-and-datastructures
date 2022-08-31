#include <iostream>
using namespace std;

void InsertionSort(int a[], int n) {
   int temp, i, j;

   for (i = 1; i < n; i++) {
      temp = a[i];
      for (j = i; j > 0 && temp < a[j - 1]; j--) a[j] = a[j - 1];
      a[j] = temp;
   }
}

int main() {
   int a[10] = {6,1,9,12,-3,7,4,6,4,10};
   int n = sizeof(a) / sizeof(a[0]);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   InsertionSort(a, n);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   return 0;
}

