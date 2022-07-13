#ifndef MAX
#define MAX 1000
#endif

#ifndef Equal
#define Equal(a, b) (a == b ? true : false)
#endif

#ifndef Compare
#define Compare(a, b) (a > b ? 1 : (a == b ?  0 : -1))
#endif

#include <iostream>
#include <cstdlib>

template <typename elementtype>
class Multiset {
   protected:
   elementtype elements[MAX];
   unsigned short numOfElements;

   private:
   int BinSearch(elementtype x) {
      if (numOfElements == 0) return -1;
      int i = 0, j = numOfElements - 1, k = (i + j) / 2;
      while(i < j && Compare(elements[k], x)) {
         if (Compare(elements[k], x) == -1) {
            i = k + 1;
         } else {
            j = k - 1;
         }
         k = (i + j) / 2;
      }
      if (Compare(elements[k], x) == 0) return k;
      else return -1;
   }

   public:

   Multiset() {
      numOfElements = 0;
   }

   bool IsEmpty() {
      return numOfElements == 0;
   }

   bool IsElement(elementtype x) {
      return BinSearch(x) != -1;
   }

   unsigned int Count(elementtype x) {
      int index = BinSearch(x);
      int occurencies;
      if (index == -1) return 0;
      else {
         occurencies = 1;
         int j = index - 1;
         while (j >= 0 && Compare(elements[j], x) == 0) {
            occurencies++;
            j--;
         }

         j = index + 1;
         while (j < numOfElements && Compare(elements[j], x) == 0) {
            occurencies++;
            j++;
         }
      }
      return occurencies;
   }

   void Insert(elementtype x) {
      if (numOfElements == MAX) {
         std::cout << "Multiset is full!" << std::endl;
         exit(EXIT_FAILURE);
      }
      int i = numOfElements - 1;
      while (i >= 0 && Compare(elements[i], x) == 1) {
         elements[i + 1] = elements[i]; 
         i--;
      }
      elements[i + 1] = x;
      numOfElements++;
   }

   void Delete(elementtype x) {
      int index = BinSearch(x);
      if (index != -1) {
         while (index < numOfElements) {
            elements[index] = elements[index + 1];
            index++;
         }
         numOfElements--;
      }
   }

   void DeleteAll() {
      int i = numOfElements - 1;
      while (i >= 0) {
         elements[i] = elements[i + 1];
         i--;
         numOfElements--;
      }
   }
};