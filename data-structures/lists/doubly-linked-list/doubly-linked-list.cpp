#include "./doubly-linked-list.h"
using namespace std;


int main() {
   DoublyLinkedList<int> list;
   DoublyLinkedList<int>::element node;
   
   cout << list.IsEmpty() << endl;

   node = list.First();
   list.Insert(node, 1);
   node = list.End();
   list.Insert(node, 2);
   node = list.End();
   list.Insert(node, 3);
   node = list.End();
   list.Insert(node, 4);

   node = list.End();
   node = list.Previous(node);
   list.ChangeValue(node, 100);

   cout << "List nodes:" << endl;
   list.Print();

   node = list.End();
   node = list.Previous(node);
   list.Delete(node);

   cout << "List nodes:" << endl;
   list.Print();

   return 0;
}