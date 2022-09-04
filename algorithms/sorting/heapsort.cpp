#ifndef MIN_OR_MAX
#define MIN_OR_MAX -1
#endif
#include "../../data-structures/trees/heap/heap.h"
#include <iostream>
using namespace std;



void heapsort(int a[], int n) {
    Heap<int> heap;
    for (int i = 0; i < n; i++) {
        heap.Insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] = heap.RootLabel();
        heap.DeleteRoot();
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void heapsortInPlace(int a[], int n) {

    for (int i = 2; i <= n; i++) {
        int j = i;
        while (j > i && a[j] > a[j / 2]) {
            int p = a[j / 2];
            a[j / 2] = a[j];
            a[j] = p;
            j /= 2;
        }
    }

    for (int i = n; i > 1; i--) {
        int p =  a[1];
        a[1] = a[i];
        a[i] = p;
        int j = 1, k;
        bool next;
        do {
            if (2 * j + 1 < i && a[2 * j + 1] > a[2 * j]) k = 2 * j + 1;
            else k = 2 * j;

            if (k < i && a[k] > a[j]) {
                int p = a[k];
                a[k] = a[j];
                a[j] = p;
                j = k;
                next = true;
            } else {
                next = false;
            }
        } while (next);
    }

    for (int i = 0; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[9] = {1,7,5,5,3,1,2,9,-5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsortInPlace(arr-1, n);
    heapsort(arr, n);

    return 0;
}
