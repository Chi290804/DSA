#include <iostream>
#include <vector>
using namespace std;

class Tree
{
private:
    struct Node
    {
        int value;
        Node *left;
        Node *right;

        Node(int val)
        {
            value = val;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *root = nullptr;

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int getLeafHeight(Node *node, int a[]) {
        if (!node) return 1;
        int t = 0;
        while (node->left && node->right)
        {
            if (node->)
        }
        
    }
};

int main () {
    
    return 0;
}