#include <bits/stdc++.h>
using namespace std;

class Tree
{
private:
    struct node
    {
        long data;
        node *lc, *rc;

        node(long data)
        {
            this->data = data;
            this->lc = nullptr;
            this->rc = nullptr;
        }
    };
    node *root;

public:
    Tree(){};
    void printTree(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                Node *current = q.front();
                q.pop();

                cout << current->data << " ";

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }

                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }

            cout << endl;
        }

        node *search(node * root, long data)
        {
            if (root->data == data)
                return root;
            else
            {
                while (root)
                {
                    if (root->data < data)
                    {
                        root = root->rc;
                        search(root, data);
                    }
                    else
                    {
                        root = root->lc;
                        search(root, data);
                    }
                }
            }
        }

        node *insert(node * root, long data)
        {
            node *newNode = search(root, data);
            Node = new node(data);
            if (data < newNode->data)
                newNode->lc = Node;
            else if (data > newNode->data)
                newNode->rc = Node;
            else
                data = newNode->data return;
            return root;
        }
    }
};

int main()
{
    node *root = nullptr;
    Tree t;
    t.insert(root, 2);
    t.printTree(root);
    return 0;
}