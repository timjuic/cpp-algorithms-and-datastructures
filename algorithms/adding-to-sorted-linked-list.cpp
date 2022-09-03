#include <iostream>
#include "../data-structures/lists/generic-list-array/list.h"
using namespace std;

int main() {
  
   int n;
   int a;
   List<int> list;

   cout << "N = ";
   cin >> n;

   for (int i = 0; i < n; i++) {
      List<int>::element e = list.End();
      cout << "Insert number to add to sorted list: ";
      cin >> a;
      while (e != list.First() && a < list.Retrieve(list.Previous(e))) {
         e = list.Previous(e);
      }
      list.Insert(e, a);
   }

   List<int>::element current = list.First();
   while (current != list.End()) {
      cout << list.Retrieve(current) << " ";
      current = list.Next(current);
   }
   cout << endl;

   return 0;
}