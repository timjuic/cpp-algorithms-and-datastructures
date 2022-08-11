#include "./tree.h"
using namespace std;


int main() {

    BinarySearchTree<int> tree;

    int arr[17] = {54,36,52,44,78,45,92,72,11,38,51,77,68,86,59,76,39};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        tree.Insert(arr[i]);
    }

    tree.Delete(44);
    tree.Delete(38);
    tree.Delete(77);

    tree.Print();

   return 0;
}
