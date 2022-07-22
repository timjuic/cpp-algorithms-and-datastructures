#include "./sorted-set.h"
using namespace std;

int main() {
   SortedSet<int> set;

   set.Insert(4);
   set.Insert(9);
   set.Insert(1);
   set.Insert(-4);
   set.Insert(9); // Not gonna be added because set can have only unique values

   cout << "Elements:" << endl;
   set.Print();

   cout << endl;
   cout << set.IsElement(3) << endl; // Returns 0 / false (3 doesnt exist)
   cout << set.IsEmpty() << endl; // Returns 0 / false (set is not empty at this point)

   set.DeleteAll();

   cout << set.IsEmpty() << endl; // Returns 1 / true (set is now empty)

   return 0;
}