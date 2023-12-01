#include<bits/stdc++.h>
using namespace std;

struct node{
    long data;
    node* left,*right;
    node(){
        data=0,left=NULL,right=NULL;
    }
    node* newNode(long val){
        node *t = new node();
        t->data = val;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    node* Search(node* root, long val){
        if ( root == NULL || root->data == val){
            return root;
        }

        if (root->data < val){
            return Search(root->right, val);
        }

        return Search(root->left, val);
    }

    node* insert(node* node, long val){
        struct node *n = Search(node, val);
        struct node *x = newNode(val);
        if (val < n->data) n->left = x;
        if (val > n->data) n->right = x;
        if (val = n->data) return;
    }

    void print(node*t){
        if ( t->left) print (t->left);
        cout << t->data <<endl;
        if ( t->right) print(t->right);
    }

    node* Delete(node* root, int k){
            // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k) {
        root->left = Delete(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = Delete(root->right, k);
        return root;
    }
 
    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        node* succParent = root;
 
        // Find successor
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        delete succ;
        return root;
    }
    }

};

