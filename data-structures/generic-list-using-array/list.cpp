#include <iostream>
#include "./list.h"
using namespace std;

int main() {

   List<int> list;

   cout << list.IsEmpty() << endl; // true

   list.Insert(list.End(), 1);
   list.Insert(list.End(), 2);
   list.Insert(list.End(), 3);
   list.Insert(list.End(), 4);
   list.Insert(list.End(), 5);

   list.ChangeValue(2, 100); // Changing value on index 2 to new value of 100

   list.Delete(list.End() - 1); // Deleting last value (5)
   
   cout << list.IsEmpty() << endl; // false

   // Iterating through all elements
   int i = list.First();
   while (i < list.End()) {
      cout << "index: " << i << " Value: " << list.Retrieve(i) << endl;
      i = list.Next(i);
   }

   // Deleting all elements (their values)
   int listLength = list.End();
   for (i = 0; i < listLength; i++) {
      list.Delete(list.End() - 1);
   }

   // List is now empty
   cout << list.IsEmpty() << endl;

   return 0;
}