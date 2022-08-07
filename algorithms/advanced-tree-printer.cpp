#include "../data-structures/trees/binary-tree-pointers/tree.h"
#include "../data-structures/queue/queue-pointers/queue.h"
#include "../data-structures/lists/doubly-linked-list/doubly-linked-list.h"
using namespace std;

template<typename elementType>
void LevelOrder(BinaryTree<elementType> &tree) {
   Queue<BinaryTree<int>::node> queue;
   BinaryTree<int>::node node = tree.Root();
   int depth = 0, size = 0;
   
   DoublyLinkedList<int> output[50];
   queue.Enqueue(node);

   while (!queue.IsEmpty()) {
      size = 0;
      Queue<BinaryTree<int>::node> queue2;
      while (!queue.IsEmpty()) {
         queue2.Enqueue(queue.Front());
         queue.Dequeue();
         size++;
      }
      cout << "Depth: " << depth << endl;
      while (!queue2.IsEmpty()) {
         queue.Enqueue(queue2.Front());
         queue2.Dequeue();
      }

      while (size-- != 0) {
         node = queue.Front();
         cout << "depth: " << depth<< " ";
         output[depth].Insert(output[depth].End(), tree.Label(node));
         cout << tree.Label(node) << " " << endl;
         queue.Dequeue();

         if (tree.LeftChild(node) != tree.lambda) queue.Enqueue(tree.LeftChild(node));
         if (tree.RightChild(node) != tree.lambda) queue.Enqueue(tree.RightChild(node));
      }
      depth++;
   }
   cout << endl;

   for (int i = 0; i < sizeof(output) / sizeof(output[0]); i++)
   {
      cout << "Index: " << i << endl;
      output[i].Print();
   }
   
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