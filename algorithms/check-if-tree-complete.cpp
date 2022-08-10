#include "../data-structures/trees/binary-tree-pointers/tree.h"
#include "../data-structures/queue/queue-pointers/queue.h"
using namespace std;

template<typename elementType>
bool CheckIfComplete(BinaryTree<elementType> &tree) {
   typename BinaryTree<elementType>::node node = tree.Root();
   Queue<typename BinaryTree<elementType>::node> queue;

   if (tree.IsEmpty()) return true;

   bool flag = false;
   queue.Enqueue(node);


   while (!queue.IsEmpty()) {
      node = queue.Front();
      queue.Dequeue();

      if (tree.LeftChild(node) != tree.lambda) {
         if (flag == true) return false;
         queue.Enqueue(tree.LeftChild(node));
      } else flag = true;

      if (tree.RightChild(node) != tree.lambda) {
         if (flag == true) return false;
         queue.Enqueue(tree.RightChild(node));
      } else flag = true;
   }
   return true;
}


int main() {

   BinaryTree<int> tree;
   BinaryTree<int>::node node;

   tree.CreateRoot(1);

   node = tree.Root();
   tree.CreateLeftChild(node, 2);
   tree.CreateRightChild(node, 3);

   node = tree.LeftChild(node);
   tree.CreateLeftChild(node, 4);
   tree.CreateRightChild(node, 5);


   tree.Print();

   if (CheckIfComplete(tree)) {
      cout << "Tree is complete!" << endl;
   } else cout << "Tree is NOT complete!" << endl;

   return 0;
}