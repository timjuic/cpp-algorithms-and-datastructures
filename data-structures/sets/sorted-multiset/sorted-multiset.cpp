#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorted-multiset.h"

void example1() {
   Multiset<int> sortedMultiset;

   std::cout << sortedMultiset.IsEmpty() << std::endl; // true

   sortedMultiset.Insert(7);
   sortedMultiset.Insert(1);
   sortedMultiset.Insert(3);
   sortedMultiset.Insert(2);
   sortedMultiset.Insert(9);
   sortedMultiset.Insert(7);

   std::cout << sortedMultiset.IsEmpty() << std::endl; // false
   std::cout << sortedMultiset.Count(7) << std::endl; // 2
   std::cout << sortedMultiset.Count(2) << std::endl; // 1

   sortedMultiset.Delete(2);

   std::cout << sortedMultiset.Count(2) << std::endl;
}

void example2() {
   Multiset<int> sortedMultiset;

   srand(time(0));
   short randomNumbersToAdd = 10;

   for (int i = 0; i < randomNumbersToAdd; i++) {
      sortedMultiset.Insert(rand() % (randomNumbersToAdd + 1));
   }

   std::cout << "Number : " << "Occurencies" << std::endl;
   for (int i = 0; i < randomNumbersToAdd; i++) {
      std::cout << i << " : " << sortedMultiset.Count(i) << std::endl;
   }

   // for (int i = 0; i < randomNumbersToAdd; i++) {
   //    while(sortedMultiset.Count(i) > 0) {
   //       sortedMultiset.Delete(i);
   //    }
   // }
   sortedMultiset.DeleteAll();

   std::cout << "Number : " << "Occurencies" << std::endl;
   for (int i = 0; i < randomNumbersToAdd; i++) {
      std::cout << i << " : " << sortedMultiset.Count(i) << std::endl;
   }
}


int main() {
   
   std::cout << "Example 1" << std::endl;
   example1();

   std::cout << std::endl;

   std::cout << "Example 2" << std::endl;
   example2();



   return 0;
}