// https://www.geeksforgeeks.org/splay-tree-set-1-insert/
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        Node *left, *right;
};

Node * NewNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node * Rightrotate(Node *current)
{
    Node *y = current->left;
    current->left = y->right;
    y->right = current;
    return y;
}

Node * Leftrotate(Node *current)
{
    Node *y = current->right;
    current->right = y->left;
    y->left = current;
    return y;
}

Node * Splay(Node *root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (root->key > key)
    {
        // key is not in tree
        if (root->left == nullptr)
            return root;

        // LL
        if (root->left->key > key)
        {
            root->left->left = Splay(root->left->left, key);
            // first rotate, second rotate will do after else
            root = Rightrotate(root);
        }
        else if (root->left->key < key) // LR
        {
            root->left->right = Splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = Leftrotate(root->left);
        }
        // Do second rotate
        return (root->left == nullptr) ? root : Rightrotate(root);
    }
    else // key lies in right subtree
    {
        if (root->right == nullptr)
            return root;

        // RR
        if (root->right->key < key)
        {
            root->right->right = Splay(root->right->right, key);
            root = Leftrotate(root);
        }
        else if (root->right->key > key) // RL
        {
            root->right->left = Splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = Rightrotate(root->right);
        }
        return (root->right == nullptr) ? root : Leftrotate(root);
    }
}

Node * Search(Node *root, int key)
{
    return Splay(root, key);
}

Node * Insert(Node *root, int key)
{
    if (root == nullptr)
        return NewNode(key);

    root = Splay(root, key); // move most close to the key to root

    if (root->key == key) // new root's key == what we want to insert
        return root;

    Node *InsertNode = NewNode(key);

    if (root->key > key)
    {
        InsertNode->right = root;
        InsertNode->left = root->left;
        root->left = nullptr;
    }
    else
    {
        InsertNode->left = root;
        InsertNode->right = root->right;
        root->right = nullptr;
    }
    return InsertNode; // InsertNOde becomes new root
}

void Inorder(Node *root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    root = Insert(root, 3);
    root = Insert(root, 45);
    root = Insert(root, 11);
    root = Insert(root, 2);
    root = Insert(root, 30);
    Inorder(root);
    Node *temp = Search(root, 11);
    cout << endl << temp->key;
    return 0;
}