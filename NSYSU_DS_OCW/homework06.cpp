// find odd number of times
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class BST;

class TreeNode
{
    private:
        TreeNode *leftchild;
        TreeNode *rightchild;
        TreeNode *parent;
        int key;
    public:
        TreeNode(): leftchild(0), rightchild(0), parent(0), key(0) {}
        TreeNode(int a): leftchild(0), rightchild(0), parent(0), key(a) {}
        int getKEY() {return this->key;}
        friend class BST;
};

class BST
{
    private:
        TreeNode *root;
        TreeNode * LeftMost(TreeNode *current); // for delete
        TreeNode * Successor(TreeNode *current); // for delete
    public:
        BST(): root(0) {}
        TreeNode * Search(int key);
        void InsertBST(int key);
        vector< pair<int, int> > Inorder();
        void DeleteBST(int key);
};

int main()
{
    int input;
    cin >> input;
    while (input != EOF)
    {
        BST tree;
        
        while (input != -1)
        {
            if (tree.Search(input) != NULL)
                tree.DeleteBST(input);
            else
                tree.InsertBST(input);
            cin >> input;
        }

        cout << "node: ";
        vector< pair<int,int> > children = tree.Inorder();
        cout << "\nleft: ";
        for (auto it = children.begin(); it != children.end(); it++)
            cout << it->first << " ";
        cout << "\nright: ";
        for (auto it = children.begin(); it != children.end(); it++)
            cout << it->second << " ";
        cout << endl;
        cin >> input;
    }
    return 0;
}


TreeNode * BST::Search(int KEY)
{
    TreeNode *current = root;
    while (current && current->key != KEY)
    {
        if (KEY < current->key)
            current = current->leftchild;
        else
            current = current->rightchild;
    }
    return current; // if we didn't find, we will get nullptr
}

void BST::InsertBST(int KEY)
{
    TreeNode *newNode = new TreeNode(KEY);
    TreeNode *current = root;
    TreeNode *parentToBe = 0;

    while (current != NULL)
    {
        parentToBe = current;
        if (current->key > newNode->key)
            current = current->leftchild;
        else
            current = current->rightchild;
    }

    newNode->parent = parentToBe;
    if (newNode->parent == NULL)
        this->root = newNode;
    else if (newNode->key < parentToBe->key)
        parentToBe->leftchild = newNode;
    else
        parentToBe->rightchild = newNode;
}

TreeNode * BST::LeftMost(TreeNode *current)
{
    while (current->leftchild != NULL)
        current = current->leftchild;
    return current;
}

TreeNode * BST::Successor(TreeNode *current)
{
    if (current->rightchild != NULL)
        return LeftMost(current->rightchild);
    
    TreeNode *tempNode = current->parent;
    while (tempNode != NULL && current == tempNode->rightchild) // stop when current == current->parent->leftchild
    {
        current = tempNode;
        tempNode = tempNode->parent;
    }
    return tempNode;
}

void BST::DeleteBST(int KEY)
{
    TreeNode *deleteNode = Search(KEY);
    if (deleteNode == NULL)
        return;

    TreeNode *to_be_del = 0;
    TreeNode *child_of_del = 0;
    if (deleteNode->leftchild == NULL || deleteNode->rightchild == NULL)
        to_be_del = deleteNode;
    else
        to_be_del = Successor(deleteNode);

    if (to_be_del->leftchild != NULL)
        child_of_del = to_be_del->leftchild;
    else
        child_of_del = to_be_del->rightchild; // might be NULL

    if (child_of_del != NULL)
        child_of_del->parent = to_be_del->parent;

    if (to_be_del->parent == NULL) // if we delete root
        this->root = child_of_del;
    else if (to_be_del == to_be_del->parent->leftchild)
        to_be_del->parent->leftchild = child_of_del;
    else
        to_be_del->parent->rightchild = child_of_del;

    if (to_be_del != deleteNode) // we copy deletenode's successor to deletenode's pointer 
        deleteNode->key = to_be_del->key; // and then delete deletenode's successor's pointer

    delete to_be_del;
    to_be_del = NULL;
}

vector< pair<int, int> > BST::Inorder()
{
    vector< pair<int,int> > children;
    TreeNode *current = new TreeNode;
    current = LeftMost(root);
    while (current)
    {
        cout << current->key << " ";
        int left = !(current->leftchild) ? 0 : current->leftchild->key;
        int right = !(current->rightchild) ? 0 : current->rightchild->key;
        children.push_back(make_pair(left, right));
        current = Successor(current);
    }
    return children;
}