#include "../../data-structures/trees/binary-tree-pointers/tree.h"
#include "../../data-structures/stacks/stack-pointers/stack.h"
using namespace std;

template <typename elementType>
void DepthFirstInorder(BinaryTree<elementType> &tree) {
   Stack<BinaryTree<int>::node> stack;
   BinaryTree<int>::node node = tree.Root();

   if (tree.IsEmpty()) return;

      do {
         while(node != tree.lambda){
            stack.Push(node);
            node = tree.LeftChild(node);
         }
         node = stack.Top();
         cout << tree.Label(node) << " ";
         stack.Pop();
         node = tree.RightChild(node);
	   } while(!stack.IsEmpty() || node != tree.lambda);    
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

   DepthFirstInorder(tree);

   return 0;
}