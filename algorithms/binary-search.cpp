#include <iostream>

template <typename elementtype>
elementtype binarySearch(elementtype array[], int arraySize, elementtype value) {
   if (arraySize == 0) return -1;
   int i = 0, j = arraySize, k = (i + j) / 2;
   while (i < j && array[k] != value) {
      if (array[k] < value) i = k + 1;
      else j = k - 1;
      k = (i + j) / 2;
   }
   if (array[k] == value) return k;
   else return -1;
}


int main() {

   int array1[7] = {1,2,4,6,6,7,9};
   int size = sizeof(array1) / sizeof(array1[0]); 
   int indexOf7 = binarySearch(array1, size, 7);
   int indexOf4 = binarySearch(array1, size, 4);
   std::cout << "Index of value 7 is: " << indexOf7 << std::endl;
   std::cout << "Index of value 4 is: " << indexOf4 << std::endl;

   return 0;
}