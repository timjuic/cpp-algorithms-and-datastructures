#include <iostream>
#include "./poly.h"
using namespace std;

int main() {
   Poly<float> P,Q,R;
	int n,m;
	float p;

	std::cout << "Stupanj polinoma P: ";
	std::cin >> m;

	for (int i = m; i>=0; i--) {
		std::cout << "P[" << i << "] = ";
		std::cin >> p;
		P.ChangeCoef(i,p);
	}

	std::cout << "Stupanj polinoma Q: ";
	std::cin >> n;

	for (int i = n; i>=0; i--) {
		std::cout << "Q[" << i << "] = ";
		std::cin >> p;
		Q.ChangeCoef(i,p);
	}

	int max = P.Deg() > Q.Deg() ? P.Deg() : Q.Deg();

	for (int i = 0; i <= max; i++)
		R.ChangeCoef(i,P.Coef(i)+Q.Coef(i));
		
	for (int i = R.Deg();i>=0;i--) {
		std::cout << R.Coef(i) << "*x^" << i;
		if (i>0) 
		   std::cout << " + ";
	}

   return 0;
}