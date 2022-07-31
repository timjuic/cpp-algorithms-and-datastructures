#ifndef MAXPQ
#define MAXPQ 1000
#endif

#ifndef Comp
#define Comp(a, b) (a > b ? 1 : a == b ? 0 : -1)
#endif

#include <iostream>
#include <cstdlib>

template<typename elementType>
class PriorityQueue {
    private:
    elementType elements[MAXQ];
    int numOfElements;

    public:
    PriorityQueue() {
        numOfElements = 0;
    }

    bool IsEmpty() {
        return numOfElements == 0;
    }

    elementType Max() {
        if (numOfElements == 0) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return elements[numOfElements - 1];
    }

    void Insert(elementType x) {
        if (numOfElements == MAXPQ) {
            std::cout << "Queue is full!" << std::endl;
            exit(EXIT_FAILURE);
        }
        int i = numOfElements - 1;
        while (i > 0 && Comp(elements[i], x) == 1) {
            elements[i + 1] = elements[i--];
        }
        elements[i + 1] = x;
        numOfElements++;
    }

    void DeleteMax() {
        if (numOfElements == 0) {
            std::cout << "Queue is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        numOfElements--;
    }
    
};