#include "./tree.h"
using namespace std;

void BinarySearchTreeSort(int arr[], int n) {
    BinarySearchTree<int> tree;

    for (int i = 0; i < n; i++) {
        tree.Insert(arr[i]);
    }

    cout << tree.Max() << endl;

    cout << tree.Min() << endl;

    cout << "Came to print" << endl;

    int i = 0;
    while (!tree.IsEmpty()) {
        int b = tree.Min();
        tree.Delete(b);
        arr[i++] = b;
        cout << "ran" << endl;
    }

    cout << "Came to print" << endl;

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {

    int arr[10] = {1,6,9,7,-3,5,2,10,8,-2};
    BinarySearchTreeSort(arr, sizeof(arr) / sizeof(arr[0]));

   return 0;
}
