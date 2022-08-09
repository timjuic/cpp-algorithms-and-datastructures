#include <iostream>
#include <cstdlib>
using namespace std;

typedef int elementType;

struct Node {
	   elementType value;
	   Node *next;
};

struct Deque {
	Node *front, *rear;
	typedef Node *element;
};

void InitDQ(Deque &D) {
	Node *p = new Node;
   p->next = NULL;
   D.front = D.rear = p;
}

bool IsEmptyDQ(Deque &D) {
	return D.front == D.rear;
}

elementType FrontDQ(Deque &D) {
	return D.front->value;
}

void EnqueueDQ(Deque &D, elementType x) {
	Node *newNode = new Node;
	newNode->value = x;
	newNode->next = NULL;
	D.rear->next = newNode;
	D.rear = newNode;
}

void PushDQ(Deque &D, elementType x) {
	Node *newNode = new Node;
	newNode->value = x;
	newNode->next = D.front->next;
	D.front->next = newNode;
}

void DequeueDQ(Deque &D) {
	Node *toDelete = D.front;
	D.front = D.front->next;
	delete toDelete;
}

void DisposeDQ(Deque &D) {
	Node *toDelete;
	while (!IsEmptyDQ(D)) {
		toDelete = D.front;
		D.front = D.front->next;
		delete toDelete;
	}
}

void PrintDQ(Deque &D) {
	Node *current = D.front;
	while (current != D.rear) {
		current = current->next;
		std::cout << current->value << " ";
	}
	std::cout << std::endl;
}