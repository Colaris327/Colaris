// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node *left;
        Node *right;
        int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHEIGHT(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

Node * Newnode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node * RightRotate(Node *current)
{
    Node *x = current->left; // x will become new root
    Node *y = x->right;

    current->left = y;  // rotate, why we don't adjust current's parent
    x->right = current; // see insert function

    current->height = max(getHEIGHT(current->left), getHEIGHT(current->right)) + 1;
    x->height = max(getHEIGHT(x->left), getHEIGHT(x->right)) + 1;

    return x; // return it to set parent's child
}

Node * LeftRotate(Node *current)
{
    Node *x = current->right; // x will become new root
    Node *y = x->left;

    current->right = y;  // rotate, why we don't adjust current's parent
    x->left = current; // see insert function

    current->height = max(getHEIGHT(current->left), getHEIGHT(current->right)) + 1;
    x->height = max(getHEIGHT(x->left), getHEIGHT(x->right)) + 1;

    return x; // return it to set parent's child
}

int getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return getHEIGHT(N->left) - getHEIGHT(N->right); // leftchild's height - rightchild's height
}

Node * Insert(Node *current, int key) // return root
{
    if (current == nullptr)
        return Newnode(key);
    
    if (key > current->key)
        current->right = Insert(current->right, key); // set new child
    else if (key < current->key)
        current->left = Insert(current->left, key);
    else // same key
        return current;

    // if current get rotate, the height will reset at rotate function
    current->height = 1 + max(getHEIGHT(current->left), getHEIGHT(current->right));
    int balance = getBalance(current);

    // case LL
    if (balance > 1 && key < current->left->key)
        return RightRotate(current);
    // case RR
    if (balance < -1 && key > current->right->key)
        return LeftRotate(current);
    // case LR
    if (balance > 1 && key > current->left->key)
    {
        current->left = LeftRotate(current->left);
        return RightRotate(current);
    }
    // case RL
    if (balance < -1 && key < current->right->key)
    {
        current->right = RightRotate(current->right);
        return LeftRotate(current);
    }

    return current; // unchange
}

Node * LeftMost(Node *current)
{
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node * Delete(Node *root, int key) // return root
{
    // STEP 1: BST delete
    if (root == nullptr)
        return root;
    
    if (root->key < key)
        root->left = Delete(root->left, key);
    else if (root->key > key)
        root->right = Delete(root->right, key);
    else // find node
    {
        if (root->left == nullptr || root->right == nullptr) // one or zero child
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr) // no child, delete root
            {
                temp = root;
                root = nullptr;
            }
            else // one child, copy our child's information and then delete child
                *root = *temp;
            delete temp;
        }
        else // two children
        {
            Node *temp = LeftMost(root->right);
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    // STEP 2: update height
    root->height = max(getHEIGHT(root->left), getHEIGHT(root->right)) + 1;

    // STEP 3: time to balance
    int balance = getBalance(root);
    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return RightRotate(root);
    // LR
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return LeftRotate(root);
    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
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

    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);
    
    Inorder(root);
    cout << endl;

    root = Delete(root, 30);
    Inorder(root);
    return 0;
}