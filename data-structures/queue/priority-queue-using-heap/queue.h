int MIN_OR_MAX = 1;

#include "../trees/heap/heap.h"

template<typename elementType>
class PriorityQueue {
    private:
    Heap<elementType> PQ;

    public:
    bool IsEmpty() {
        return PQ.IsEmpty();
    }

    elementType Max() {
        if (PQ.IsEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return PQ.RootLabel();
    }

    void Insert(elementType x) {
        PQ.Insert(x);
    }

    void DeleteMax() {
        if (PQ.IsEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        PQ.DeleteRoot();
    }
};