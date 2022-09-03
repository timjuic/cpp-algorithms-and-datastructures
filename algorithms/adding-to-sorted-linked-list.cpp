#include <iostream>
#include "../data-structures/lists/generic-list-array/list.h"
using namespace std;

int main() {
   List<int> list;

   list.Insert(0, 1);
   list.Insert(1, 2);
   list.Insert(2, 4);
   list.Insert(3, 5);
   list.Insert(4, 6);
   list.Insert(5, 10);
   list.Insert(6, 13);

   list.Print();


   int add;
   cout << "Insert number to add: ";
   cin >> add; // add = 3

   int element = list.First();
   while (add > list.Retrieve(element) || element == list.Previous(list.End())) {
      cout << "ran" << endl;
      element = list.Next(element);
   }
   cout << "ran2" << endl;

   if (add > list.Retrieve(list.End())) {
      list.Insert(element, add);
   }

   if (add == list.Retrieve(element)) {
      int i = list.End();
      list.Insert(i, list.Retrieve(i));
      i--;
      while (i != element) {
         list.ChangeValue(i, list.Retrieve(i-1));
      }
   }

   if (list.Retrieve(element) != add) {
      list.Insert(element, add);
   }

   
   list.Print();


   return 0;
}