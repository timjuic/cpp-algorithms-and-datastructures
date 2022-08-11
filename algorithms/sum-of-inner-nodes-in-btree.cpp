#include "../data-structures/trees/binary-tree-pointers/tree.h"
using namespace std;

int SumOfInnerNodes(BinaryTree<int> &tree, BinaryTree<int>::node node, int &sum) {
   cout << "iteration" << endl;
   if (tree.LeftChild(node) != tree.lambda || tree.RightChild(node) != tree.lambda) {
      cout << tree.Label(node) << endl;
      sum += tree.Label(node);
   }
   if (tree.LeftChild(node) != tree.lambda) SumOfInnerNodes(tree, tree.LeftChild(node), sum);
   if (tree.RightChild(node) != tree.lambda) SumOfInnerNodes(tree, tree.RightChild(node), sum);
}

int main() {
   BinaryTree<int> tree;
   BinaryTree<int>::node node;

   tree.CreateRoot(1);

   node = tree.Root();
   tree.CreateLeftChild(node, 2);
   tree.CreateRightChild(node, 3); // Leaf

   node = tree.LeftChild(node);
   tree.CreateLeftChild(node, 4); // Leaf
   tree.CreateRightChild(node, 5);

   node = tree.RightChild(node);
   tree.CreateRightChild(node, 6);

   node = tree.RightChild(node);
   tree.CreateRightChild(node, 7); // Leaf

   int sum = 0;
   SumOfInnerNodes(tree, tree.Root(), sum);
   cout << "Sum of leaves: " << sum << endl;

   return 0;
}