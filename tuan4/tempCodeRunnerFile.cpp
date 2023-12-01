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

    void preorderTreversal(Node *node, vector<int> &t)
    {
        if (node != nullptr)
        {
            t.push_back(node->value);
            preordertreversal(node->left, t);
            preordertreversal(node->right, t);
        }
    }

    void postorderTreversal(Node *node, vector<int> &t)
    {
        if (node != nullptr)
        {
            postorderTreversal(node->left, t);
            postorderTreversal(node->right, t);
            t.push_back(node->value);
        }
    }

    void inorderTreversal(Node *node, vector<int> &t)
    {
        if (node != nullptr)
        {
            inorderTreversal(node->left, t);
            t.push_back(node->value);
            inorderTreversal(node->right, t);
        }
    }

public:
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

    bool isBinaryTree(Node *node, int minVal, int maxVal)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->value < minVal || node->value > maxVal)
        {
            return false;
        }
        return (isBinaryTree(node->left, minVal, node->value - 1) &&
                isBinaryTree(node->right, node->value + 1, maxVal));
    }

    Node *find(Node *root, int u)
    {
        if (root->data == u)
        {
            return root;
        }
        return find(root->left, u);
        return find(root->right, u);
    }

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

    vector<int> getPreorder(Node *node)
    {
        vector<int> res;
        preorderTraversal(node, res);
        return res;
    }

    vector<int> getPostorder(Node *node)
    {
        vector<int> res;
        postorderTraversal(node, res);
        return res;
    }

    vector<int> getInorder(Node *node)
    {
        vector<int> res;
        inorderTraversal(node, res);
        return res;
    }

    void printTree(vector<int> a)
    {
        for (auto it : a)
            cout << it << " ";
        cout << endl;
    }

    void print()
    {
        cout << getHeight(root) << endl;
        vector<int> pre = getPreorder(root);
        printTree(pre);

        vector<int> post = getPostorder(root);
        printTree(post);

        if (isBinarySearchTree(root))
        {
            vector<int> in = getInorder(root);
            printTree(in);
        }
        else
            cout << "NOT BINARY TREE!";
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    Tree t1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        t1.insert(u, v);
    }
    t1.print();
}