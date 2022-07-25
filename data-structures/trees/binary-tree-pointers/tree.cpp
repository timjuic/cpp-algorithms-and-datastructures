#include "./tree.h"
using namespace std;

int main() {
   BinaryTree<int> tree;
   BinaryTree<int>::node node;

   cout << tree.IsEmpty() << endl;

   tree.CreateRoot(1);

   node = tree.Root();
   tree.CreateLeftChild(node, 2);
   tree.CreateRightChild(node, 3);

   node = tree.LeftChild(node);
   tree.CreateLeftChild(node, 4);
   tree.CreateRightChild(node, 5);

   tree.Print();

   tree.ChangeLabel(node, 100);

   tree.Print();

   node = tree.Root();
   tree.Delete(node);

   tree.Print();

   return 0;
}
