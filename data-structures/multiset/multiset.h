#ifndef MAX
#define MAX 1000
#endif

#ifndef Equal
#define Equal(a, b) (a == b ? true : false)
#endif

#include <cstdlib>
#include <iostream>

template <typename elementtype>
class Multiset {
   protected:
   elementtype elements[MAX];
   unsigned short numberOfElements;

   // Needed for Union, Intersect and Subtract
   struct elem {
      elementtype value;
      bool used;
   }

   public:
   Multiset() {
      numberOfElements = 0;
   }

   bool IsEmpty() {
      return numberOfElements == 0;
   }

   bool IsElement(elementtype x) {
      int i;
      for (i = 0; i < numberOfElements && !Equal(elements[i], x); i++);
      return i < numberOfElements;
   }

   unsigned int Count(elementtype x) {
      unsigned int occurencies = 0;
      for (int i = 0; i < numberOfElements; i++) {
         if (Equal(elements[i], x)) occurencies++;
      }
      return occurencies;
   }

   void Insert(elementtype x) {
      if (numberOfElements == MAX) {
         std::cout << "Multiset is full" << std::endl;
         exit(EXIT_FAILURE);
      }
      elements[numberOfElements++] = x;
   }

   void Delete(elementtype x) {
      int i;
      for (i = 0; i < numberOfElements && !Equal(elements[i], x); i++);
      for (; i < numberOfElements; i++) {
         elements[i] = elements[i + 1];
      }
      numberOfElements--;
   }



   void Intersect(List<elementtype> &M, List<elementtype> &N) {
      elem b[MAXB];   
      NoEl = 0;
      for (int i = 0; i < N.NoEl; i++) b[i] = {N.el[i],false};

      for (int m = 0; m < M.NoEl; m++) {
         int n = 0;
         while (n < N.NoEl && (b[n].used || !EqualB(b[n].val, M.el[m])))
                  n++;
         if (n < N.NoEl) {
            el[NoEl++] = M.el[m];
            b[n].used = true;
         }         	   
      }
   }
};