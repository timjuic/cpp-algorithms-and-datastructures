#include "../../data-structures/trees/binary-tree-pointers/tree.h"
using namespace std;

template<typename elementType>
void InorderRec(BinaryTree<elementType> &tree, BinaryTree<int>::node node) {
   if (tree.LeftChild(node) != tree.lambda) InorderRec(tree, tree.LeftChild(node));
   cout << tree.Label(node) << " ";
   if (tree.RightChild(node) != tree.lambda) InorderRec(tree, tree.RightChild(node));
}


int main() {
   BinaryTree<int> tree;
   BinaryTree<int>::node node;

   tree.CreateRoot(1);
   tree.CreateLeftChild(tree.Root(), 2);
   tree.CreateRightChild(tree.Root(), 3);
   node = tree.Root();
   node = tree.LeftChild(node);
   tree.CreateLeftChild(node, 4);
   tree.CreateRightChild(node, 5);
   node = tree.LeftChild(node);
   tree.CreateLeftChild(node, 7);
   node = tree.Root();
   node = tree.RightChild(node);
   tree.CreateRightChild(node, 8);

   InorderRec(tree, tree.Root());
   cout << endl;

   return 0;
}