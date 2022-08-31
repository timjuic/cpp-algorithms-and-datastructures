#include "../../data-structures/trees/binary-search-tree/tree.h"
using namespace std;

int main() {

   BinarySearchTree<int> tree;

   int arr[10] = {7,4,2,5,6,12,-3,-8,3,1};

   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
      cout << arr[i] << " ";
   }
   cout << endl;

   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
      tree.Insert(arr[i]);
   }

   int i = 0;
   while (!tree.IsEmpty()) {
      arr[i] = tree.Min();
      tree.Delete(arr[i]);
      i++;
   }

   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}