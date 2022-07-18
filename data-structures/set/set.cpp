#include "./set.h"
using namespace std;

int main() {
   Set<int> set;

   set.Insert(1);
   set.Insert(1); // This one wont be added because set can have only unique values
   set.Insert(3);
   set.Insert(5);
   set.Insert(4);

   cout << "Elements:" << endl;
   set.Print();

   cout << endl;

   cout << set.IsElement(3) << endl;

   cout << set.IsEmpty() << endl;

   set.DeleteAll();

   cout << set.IsEmpty() << endl;

   return 0;
}