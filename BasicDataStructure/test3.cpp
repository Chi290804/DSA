#include <iostream>
#include <vector>
#include<set>
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
    void insert(int parentValue, int value)
    {
        if (root == nullptr)
        {
            root = new Node(parentValue);
            Node *newNode = new Node(value);
            root->left = newNode;
            return;
        }
        insert(root, value, parentValue);

    }

    void insert(Node *node, int value, int parentValue)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->data == parentValue)
        {
            if (node->left == nullptr)
            {
                node->left = new Node(value);
            }
            else
            {
                node->right = new Node(value);
            }
        }
        else
        {
            insert(node->left, value, parentValue);
            insert(node->right, value, parentValue);
        }
    }
    int getHeight(Node *node)
    {
        int minHeight = INT_MAX;
    vector<int> roots;
        if (node == nullptr)
        {
            return 0;
        }
        /* int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1; */
        int height = getHeight(node);
        if (height < minHeight) {
            minHeight = height;
            roots.clear();
            roots.push_back(i);
        } else if (height == minHeight) {
            roots.push_back(i);
        }
    }

};

int main()
{
    int N, M;
    cin >> N >> M;
    Tree t1;
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        t1.insert(u, v);
    }
    vector<int> t = t1.findRoot();
    for (int i : t)
        cout << i << "\n";
    return 0;
}