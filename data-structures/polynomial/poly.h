#ifndef MAXDEG
#define MAXDEG 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementType>
class Poly {
   protected:
   elementType coefficients[MAXDEG];
   int degree;

   public:
   Poly() {
      degree = -1;
   }

   bool IsNull() {
      return degree == -1;
   }

   elementType Coef(unsigned short n) {
      if (n > degree) return 0;
      return coefficients[n];
   }

   unsigned short Deg() {
      return degree;
   }

   void ChangeCoef(unsigned short n, elementType x) {
      if (n >= MAXDEG) {
         std::cout << "Too large coefficient" << std::endl;
         exit(EXIT_FAILURE);
		}
      coefficients[n] = x;
      if ((int)n == degree && x == 0)
         while (degree > -1 && coefficients[degree]==0) degree--;
               
      if ((int)n > degree && x != 0) {
         for (int i = degree + 1; i < (int)n; i++) {
            coefficients[i] = 0;
         }     
         degree = n;
      }
   }
};