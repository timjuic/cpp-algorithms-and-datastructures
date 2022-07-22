#include "./doubly-list-cursor.h"
using namespace std;

int main() {
   DoublyListCursor<int> list;
   DoublyListCursor<int>::element node;

   cout << list.IsEmpty() << endl;

   list.Insert(list.End(), 1);
   list.Insert(list.End(), 2);
   list.Insert(list.End(), 3);
   list.Insert(list.End(), 4);
   list.Insert(list.End(), 5);

   list.Print();

   list.ChangeValue(list.First(), 100);

   node = list.End();
   node = list.Previous(node);
   list.Delete(node);

   list.Print();

   return 0;
}