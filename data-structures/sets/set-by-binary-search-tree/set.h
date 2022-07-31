#include "../trees/binary-search-tree/tree.h"

#ifndef Comp
#define Comp(a, b) (a > b ? 1 : a == b ? 0 : -1)
#endif

template <typename elementType>
class Set {
    private:
    BinarySearchTree<elementType> S;

    bool IsEmpty() {
        return S.IsEmpty();
    }

    bool IsElement(elementType x) {
        return S.IsNode();
    }

    bool Insert(elementType x) {
        return S.Insert(x); 
    }

    bool Delete(elementType x) {
        return S.Delete(x);
    }


};