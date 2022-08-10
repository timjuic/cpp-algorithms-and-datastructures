#include "./tree.h"
using namespace std;


int main() {

    // Code for NO CLASS implementation

    // GeneralTree tree;
    // node node;

    // InitT(tree);

    // CreateRootT(tree, 1);

    // node = RootT(tree);
    // cout << "Node: " << LabelT(tree, node) << endl;
    // CreateChildT(tree ,node, 2);
    // CreateChildT(tree, node, 3);

    // node = FirstChildT(tree, node);
    // cout << "Node: " << LabelT(tree, node) << endl;
    // CreateChildT(tree, node, 4);
    // CreateChildT(tree, node, 5);

    // node = NextSiblingT(tree, node);
    // cout << "Node: " << LabelT(tree, node) << endl;
    // CreateChildT(tree, node, 6);
    // CreateChildT(tree, node, 7);

    // PrintT(tree);



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