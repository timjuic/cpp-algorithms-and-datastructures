#include "./tree.h"
using namespace std;

int main() {

    DigitalTree tree;
    tree.Insert((char*)"test");
    tree.Insert((char*)"text");
    tree.Insert((char*)"programming");

    cout << tree.IsEmpty() << endl; // False

    cout << tree.IsElement((char*)"te") << endl; // True

    cout << tree.IsElement((char*)"programming") << endl; // True
    cout << tree.IsElement((char*)"program") << endl; // True
    cout << tree.IsElement((char*)"test2") << endl; // False
    cout << tree.IsElement((char*)"asd") << endl; // False


    return 0;
}