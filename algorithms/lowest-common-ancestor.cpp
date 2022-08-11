#include "../data-structures/trees/general-tree-cursor/tree.h"
#include <cmath>
using namespace std;

template<typename nodeType>
typename GeneralTree<nodeType>::node LowestCommonAncestor(GeneralTree<nodeType> &tree, typename GeneralTree<nodeType>::node node1, typename GeneralTree<nodeType>::node node2) {
   int node1DistanceFromRoot = 0, node2DistanceFromRoot = 0;
   typename GeneralTree<nodeType>::node node1Copy = node1, node2Copy = node2;

   while (node1Copy != tree.Root()) {
      node1Copy = tree.Parent(node1Copy);
      node1DistanceFromRoot++;
   }

   while (node2Copy != tree.Root()) {
      node2Copy = tree.Parent(node2Copy);
      node2DistanceFromRoot++;
   }

   if (node1DistanceFromRoot == node2DistanceFromRoot) {
      while (node1 != node2) {
         node1 = tree.Parent(node1);
         node2 = tree.Parent(node2);
      }
   } else {
      if (node1DistanceFromRoot > node2DistanceFromRoot) {
         for (int i = 0; i < abs(node1DistanceFromRoot - node2DistanceFromRoot); i++) {
            node1 = tree.Parent(node1);
         }
      } else {
         for (int i = 0; i < abs(node2DistanceFromRoot - node1DistanceFromRoot); i++) {
            node2 = tree.Parent(node2);
         }
      }
      while (node1 != node2) {
         node1 = tree.Parent(node1);
         node2 = tree.Parent(node2);
      }
   }
   cout << tree.Label(node1) << " " << tree.Label(node2) << endl;
   return node1;
}


int main() {
   GeneralTree<int> tree;
   GeneralTree<int>::node node, node2;

   tree.CreateRoot(1);
    
   node = tree.Root();
   tree.CreateChild(node, 2);
   tree.CreateChild(node, 3);

   node = tree.FirstChild(node);
   tree.CreateChild(node, 4);
   tree.CreateChild(node, 5);

   node = tree.FirstChild(node);
   tree.CreateChild(node, 8);
   tree.CreateChild(node, 9);

   node = tree.NextSibling(node);
   tree.CreateChild(node, 6);
   tree.CreateChild(node, 7);

   node = tree.FirstChild(node);
   node = tree.NextSibling(node);
   tree.CreateChild(node, 10);
   tree.CreateChild(node, 11);
   tree.CreateChild(node, 12);

   node = tree.FirstChild(node);
   node = tree.NextSibling(node);
   tree.CreateChild(node, 13);

   node = tree.FirstChild(node);
   tree.CreateChild(node, 14);
   tree.CreateChild(node, 15);

   node = tree.FirstChild(node);
   node = tree.NextSibling(node);
   cout << "Node: " << tree.Label(node) << endl;

   node2 = tree.Root();
   node2 = tree.FirstChild(node2);
   node2 = tree.FirstChild(node2);
   node2 = tree.FirstChild(node2);
   node2 = tree.NextSibling(node2);
   cout << "Node2: " << tree.Label(node2) << endl;

   GeneralTree<int>::node lowestCommonAncestor;
   lowestCommonAncestor = LowestCommonAncestor(tree, node, node2);

   cout << "Closest common ancestor: " << tree.Label(lowestCommonAncestor) << endl;

   return 0;
}
