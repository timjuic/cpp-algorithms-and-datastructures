#include "../../data-structures/trees/binary-tree-pointers/tree.h"
#include "../../data-structures/queue/queue-pointers/queue.h"
using namespace std;

template<typename elementType>
void LevelOrder(BinaryTree<elementType> &tree) {
   Queue<BinaryTree<int>::node> queue;
   BinaryTree<int>::node node = tree.Root();
   
   queue.Enqueue(node);

   while (!queue.IsEmpty()) {
      node = queue.Front();
      cout << tree.Label(node) << " ";
      queue.Dequeue();

      if (tree.LeftChild(node) != tree.lambda) queue.Enqueue(tree.LeftChild(node));
      if (tree.RightChild(node) != tree.lambda) queue.Enqueue(tree.RightChild(node));
   }
   cout << endl;
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

   LevelOrder(tree);

   return 0;
}