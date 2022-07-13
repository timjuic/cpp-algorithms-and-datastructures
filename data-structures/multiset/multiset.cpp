

#include <iostream>
#include "multiset.h"

int main() {

   // Multiset of integers
   Multiset<int> multiset;

   std::cout << multiset.IsEmpty() << std::endl; // True

   multiset.Insert(1);
   multiset.Insert(2);
   multiset.Insert(3);
   multiset.Insert(1);

   std::cout << multiset.IsEmpty() << std::endl; // False
   std::cout << multiset.Count(1) << std::endl; // 2
   std::cout << multiset.IsElement(2) << std::endl; // True

   multiset.Delete(2);
   std::cout << multiset.IsElement(2) << std::endl; // False
   std::cout << multiset.Count(2) << std::endl; // 0

   std::cout << std::endl;

   // Multiset of chars
   Multiset<char> multiset2;

   std::cout << multiset2.IsEmpty() << std::endl; // True

   multiset2.Insert('a');
   multiset2.Insert('a');
   multiset2.Insert('b');
   multiset2.Insert('c');

   std::cout << multiset2.IsEmpty() << std::endl; // False
   std::cout << multiset2.Count('a') << std::endl; // 2
   std::cout << multiset2.IsElement('b') << std::endl; // True

   multiset2.Delete('b');
   std::cout << multiset2.IsElement('b') << std::endl; // False
   std::cout << multiset2.Count('b') << std::endl; // 0
   

   return 0;
}