#include "../trees/binary-search-tree/tree.h"

template<typename elementType>
class PriorityQueue {
    private:
    BinarySearchTree<elementType> PQ;

    public:
    bool IsEmpty() {
        return PQ.IsEmpty();
    }

    elementType Max() {
        if (PQ.IsEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return PQ.Max();
    }

    void Insert(elementType x) {
        PQ.Insert(x);
    }

    void DeleteMax() {
        if (PQ.IsEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        PQ.Delete(PQ.Max());
    }
};