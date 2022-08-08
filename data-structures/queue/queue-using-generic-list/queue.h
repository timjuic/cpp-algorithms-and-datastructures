#include <iostream>
#include <cstdlib>
#include "../../lists/generic-list-array/list.h"

template<typename elementType>
class Queue {
   private:
   List<elementType> list;

   public:
   bool IsEmpty() {
      return list.IsEmpty();
   }

   elementType Front() {
      return list.Retrieve(list.First());
   }

   void Enqueue(elementType x) {
      list.Insert(list.End(), x);
   }

   void Dequeue() {
      if (list.IsEmpty()) {
         std::cout << "Can't delete node! Queue is empty!" << std::endl;
         exit(EXIT_FAILURE);
      }
      list.Delete(list.First());
   }

   void Print() {
      List<int>::element element;
      element = list.First();
      while (list.Next(element) != list.lambda) {
         std::cout << list.Retrieve(element) << " ";
         element = list.Next(element);
      }
      std::cout << std::endl;
   }

   ~Queue() {
      while (!list.IsEmpty()) {
         list.Delete(list.First());
      }
   }
};