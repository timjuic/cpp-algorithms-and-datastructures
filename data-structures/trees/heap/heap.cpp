#ifndef MIN_OR_MAX
#define MIN_OR_MAX -1
#endif

#include "./heap.h"
using namespace std;

int main() {
    Heap<int> heap;

    int arr[17] = {54,36,52,44,78,45,92,72,11,38,51,77,68,86,59,76,39};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        heap.Insert(arr[i]);
    }

    heap.Print();

    heap.DeleteRoot();

    heap.Print();


    return 0;
}