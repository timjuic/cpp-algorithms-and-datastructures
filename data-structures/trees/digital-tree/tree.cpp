#include "./tree.h"
using namespace std;

int main() {

    DigitalTree tree;
    tree.Insert((char*)"test");
    tree.Insert((char*)"text");
    tree.Insert((char*)"programming");

    // cout << tree.IsElement((char*)"te") << endl; // True

    // cout << tree.IsElement((char*)"programming") << endl; // True
    // cout << tree.IsElement((char*)"program") << endl; // True
    // cout << tree.IsElement((char*)"test2") << endl; // False
    // cout << tree.IsElement((char*)"asd") << endl; // False

    

    DigitalTree tree2;

    tree2.Insert((char*)"BRAT");
    tree2.Insert((char*)"BURA");
    // tree2.Insert((char*)"KEKEK");

    // tree2.Insert((char*)"rat");
    // tree2.Insert((char*)"brat");
    // tree2.Insert((char*)"rata");
    // tree2.Insert((char*)"tata");
    // tree2.Insert((char*)"tat");
    // tree2.Insert((char*)"mama");
    // tree2.Insert((char*)"mir");
    // tree2.Insert((char*)"mi");
    // tree2.Insert((char*)"sir");
    // tree2.Insert((char*)"struna");
    // tree2.Insert((char*)"kuna");
    // tree2.Insert((char*)"kura");
    // tree2.Insert((char*)"bura");
    // tree2.Insert((char*)"bure");
    // tree2.Insert((char*)"rame");
    // tree2.Insert((char*)"remen");
    // tree2.Insert((char*)"siv");

    tree2.Print();

    return 0;
}