#include <iostream>
using namespace std;

void QuickSort(int a[], int left, int right) {
  int i = left;
  int j = right;
  int sidro = a[(left + right) / 2];

  while (i <= j) {
    while (a[i] < sidro) i++;
    while (a[j] > sidro) j--;

    if (i <= j) {
      int spremi = a[i];
      a[i] = a[j];
      a[j] = spremi;
      i = i + 1;
      j = j - 1;
    }
  }
  if (i < right) QuickSort(a, i, right);
  if (left < j) QuickSort(a, left, j);
}

typedef int tip;

int main() {
   int a[10] = {6, 1, 9, 12, -3, 7, 4, 6, 4, 10};
   int n = sizeof(a) / sizeof(a[0]);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   QuickSort(a, 0, n-1);

   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;

   return 0;
}
