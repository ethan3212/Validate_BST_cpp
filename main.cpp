#include <iostream>
#include <climits>
using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    explicit BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// O(n) time | O(depth) space
bool helper(BST *node, int minimumValue, int maximumValue) {
    if(node->value < minimumValue || node->value >= maximumValue) {// O(1) time
        return false;
    }
    if(node->left != nullptr && !helper(node->left, minimumValue, node->value)) {// O(n) time | O(depth) space
        return false;
    }
    if(node->right != nullptr && !helper(node->right, node->value, maximumValue)) {// O(n) time | O(depth) space
        return false;
    }
    return true;
}

// O(n) time | O(depth) space
bool validateBst(BST *tree) {
    return helper(tree, INT_MIN, INT_MAX);// O(n) time | O(depth) space
}

int main() {
    return 0;
}
