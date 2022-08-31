#include <iostream>
using namespace std;

void SelectionSort(int a[], int n) {
   int smallestInd, temp, i, j;

   for (i = 0; i < n - 1; i++) {
      smallestInd = i;
      for (j = i + 1; j < n; j++) {
         if (a[j] < a[smallestInd]) smallestInd = j;
      }

      if (a[i] > a[smallestInd]) {
        temp = a[i];
        a[i] = a[smallestInd];
        a[smallestInd] = temp;
      }
   }
}

int main() {
   int a[10] = {6,1,9,12,-3,7,4,6,4,10};
   int n = sizeof(a) / sizeof(a[0]);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   SelectionSort(a, n);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   return 0;
}


