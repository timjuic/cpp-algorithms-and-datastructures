#include "./tree.h"
using namespace std;


int main() {

    GeneralTree<int> tree;
    GeneralTree<int>::node node;
    
    tree.CreateRoot(1);
    
    node = tree.Root();
    cout << "Node: " << tree.Label(node) << endl;
    tree.CreateChild(node, 2);
    tree.CreateChild(node, 3);

    node = tree.FirstChild(node);
    cout << "Node: " << tree.Label(node) << endl;
    tree.CreateChild(node, 4);
    tree.CreateChild(node, 5);

    node = tree.NextSibling(node);
    cout << "Node: " << tree.Label(node) << endl;
    tree.CreateChild(node, 6);
    tree.CreateChild(node, 7);

    tree.Print();

    tree.Delete(tree.Root());

    return 0;
}