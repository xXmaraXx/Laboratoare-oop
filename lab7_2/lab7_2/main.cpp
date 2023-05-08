#include "Tree.h"

int main() {
    Tree<int>* root = new Tree<int>(10);

    root->add_node(new Tree<int>(12));
    root->add_node(new Tree<int>(2));
    root->add_node(new Tree<int>(3));

    root->first_child->next_sibling->add_node(new Tree<int>(9));
    root->first_child->next_sibling->add_node(new Tree<int>(17));

    std::cout << "Number of nodes in tree: " << root->count() << std::endl;

    Tree<int>* node5 = root->find([](const int& a, const int& b) { return a == b; }, 5);
    if (node5) {
        std::cout << "Found node with value 5" << std::endl;
    }
    else {
        std::cout << "Node with value 5 not found" << std::endl;
    }

    root->sort();

    root->dfs();

    root->delete_node();


    return 0;
}