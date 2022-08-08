#include "./linked-list.h"
using namespace std;


int main() {
   LinkedList<int> list;
   LinkedList<int>::element node;
   
   cout << list.IsEmpty() << endl;
   node = list.First();

   list.Insert(node, 1);
   node = list.End();
   list.Insert(node, 2);
   node = list.End();
   list.Insert(node, 3);
   list.Insert(list.First(), 10);

   list.Print();

   // Deleting all nodes
   node = list.First();
   while (node->next != NULL) {
      list.Delete(node);
      node = list.First();
   }

   cout << list.IsEmpty() << endl;

   return 0;
}