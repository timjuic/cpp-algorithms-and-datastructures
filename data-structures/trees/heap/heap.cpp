#include "./heap.h"
using namespace std;

int main() {

    Heap<int> heap;

    cout << heap.IsEmpty() << endl;

    int arr[10] = {1,9,2,6,-5,4,8,8,1,3};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        heap.Insert(arr[i]);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        arr[i] = heap.RootLabel();
        heap.DeleteRoot();
    }
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}