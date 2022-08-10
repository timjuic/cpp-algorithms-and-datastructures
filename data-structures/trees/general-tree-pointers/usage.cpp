#include "./class.h"
using namespace std;

int main() {

   GeneralTree<int> tree;
   GeneralTree<int>::node node;
    
   tree.CreateRoot(1);
   
   node = tree.Root();
   tree.CreateChild(node, 2);
   tree.CreateChild(node, 3);

   node = tree.FirstChild(node);
   tree.CreateChild(node, 4);
   tree.CreateChild(node, 5);

   node = tree.NextSibling(node);
   tree.CreateChild(node, 6);
   tree.CreateChild(node, 7);

   tree.Print();

   node = tree.Root();
   node = tree.FirstChild(node);
   node = tree.NextSibling(node);
   tree.Delete(node);

   tree.Print();
   return 0;
}