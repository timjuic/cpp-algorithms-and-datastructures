#ifndef MAXT
#define MAXT 1000
#endif

#include <iostream>
#include <cstdlib>


struct Node {
   int label;
   int child, sibling, parent;
};

struct GeneralTree {
   Node elements[MAXT];
   int empty;
};


typedef int node;
const int lambda = -1;

void InitT(GeneralTree &T, int x) {
   T.elements[0].label = x;
   T.elements[0].child = T.elements[0].sibling = T.elements[0].parent = lambda;
   for (int i = 1; i < MAXT - 1; i++) {
      T.elements[i].sibling = i + 1;
   }
   T.elements[MAXT - 1].sibling = lambda;
   T.empty = 1;
}

void InitT(GeneralTree &T) {
   for (int i = 0; i < MAXT - 1; i++) {
      T.elements[i].sibling = i + 1;
   }
   T.elements[MAXT - 1].sibling = lambda;
   T.empty = 0;
}

bool IsEmptyT(GeneralTree &T) {
   return T.empty == 0;
}

int LabelT(GeneralTree &T, node n) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   return T.elements[n].label;
}

node RootT(GeneralTree &T) {
   if (!IsEmptyT(T)) return 0;
   else return lambda;
}

node ParentT(GeneralTree &T, node n) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   return T.elements[n].parent;
}

node FirstChildT(GeneralTree &T, node n) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   return T.elements[n].child;
}

node NextSiblingT(GeneralTree &T, node n) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   return T.elements[n].sibling;       
}

void ChangeLabelT(GeneralTree &T, node n, int x) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   T.elements[n].label = x;
}

void CreateRootT(GeneralTree &T, int x) {
   if (!IsEmptyT(T)) {
      std::cout << "Tree is not empty! Can't create root!" << std::endl;
      exit(EXIT_FAILURE);
   }
   T.empty = T.elements[0].sibling;
   T.elements[0].label = x;
   T.elements[0].parent = T.elements[0].child = T.elements[0].sibling = lambda;
}

void CreateChildT(GeneralTree &T, node n, int x) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   if (T.empty == lambda) {
      std::cout << "Datastructure is full! Cant create new child!" << std::endl;
      exit(EXIT_FAILURE);
   }
   int i = T.empty;
   T.empty = T.elements[T.empty].sibling;
   T.elements[i].label = x;
   T.elements[i].child = lambda;
   T.elements[i].parent = n;
   T.elements[i].sibling = T.elements[n].child;
   T.elements[n].child = i;
}

void Del(GeneralTree &T, node n) {
   if (T.elements[n].sibling != lambda) Del(T,  T.elements[n].sibling);
   if (T.elements[n].child != lambda) Del(T, T.elements[n].child);
   T.elements[n].sibling = T.empty;
   T.empty = n; 
}

void DeleteT(GeneralTree &T, node n) {
   if (n == lambda) {
      std::cout << "Node: " << n << " doesn't exist!" << std::endl;
      exit(EXIT_FAILURE);
   }
   if (T.elements[n].child != lambda) Del(T, T.elements[n].child);
   if (T.elements[n].parent != lambda) { // If node is not root
      if (T.elements[T.elements[n].parent].child == n) { // If node is first child
            T.elements[T.elements[n].parent].child = T.elements[n].sibling;
      } else {
            int i = T.elements[T.elements[n].parent].child;
            while (T.elements[i].sibling != n) {
               i = T.elements[i].sibling;
            }
            T.elements[i].sibling = T.elements[n].sibling;
      }
   }
   T.elements[n].sibling = T.empty;
   T.empty = n;
}


void Prnt(GeneralTree &T, node n) {
   std::cout << T.elements[n].label << " ";
   if (T.elements[n].child != lambda) Prnt(T, T.elements[n].child);
   if (T.elements[n].sibling != lambda) Prnt(T, T.elements[n].sibling);
}

void PrintT(GeneralTree &T) {
   if (!IsEmptyT(T)) {
      std::cout << "Preorder traversal:" << std::endl;
      Prnt(T, 0);
      std::cout << std::endl;
   }
}