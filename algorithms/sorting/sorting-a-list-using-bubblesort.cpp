#include "../data-structures/lists/generic-list-array/list.h"
using namespace std;

int main() {

   typedef int elementType;

   List<elementType> list;

   list.Insert(list.End(), 1);
   list.Insert(list.End(), 12);
   list.Insert(list.End(), 5);
   list.Insert(list.End(), 2);
   list.Insert(list.End(), 7);
   list.Insert(list.End(), 3);
   list.Insert(list.End(), 5);

   list.Print();

   List<elementType>::element current, next, sorted;
   sorted = list.End();

   for (sorted = list.End(); sorted != list.First(); sorted = list.Previous(sorted)) {
      for (current = list.First(), next = list.Next(current); list.Next(current) != sorted; current = list.Next(current), next = list.Next(next)) {
         if (list.Retrieve(current) > list.Retrieve(next)) {
            elementType temp = list.Retrieve(current);
            list.ChangeValue(current, list.Retrieve(next));
            list.ChangeValue(next, temp);
         }
      }
   }

   list.Print();
   
   return 0;
}