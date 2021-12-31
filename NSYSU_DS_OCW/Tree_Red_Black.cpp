// http://alrightchiu.github.io/SecondRound/red-black-tree-introjian-jie.html
#include <iostream>
#include <string>
using namespace std;
class RBT;

class TreeNode
{
    private:
        TreeNode *leftchild;
        TreeNode *rightchild;
        TreeNode *parent;
        int key;
        int color; // 0:red, 1:black
        string str;
        friend RBT;
    public:
        TreeNode(int k, string s): key(k), str(s), color(0), leftchild(0), rightchild(0), parent(0) {}
        TreeNode(): key(0), str(""), color(0), leftchild(0), rightchild(0), parent(0) {}
        int getKEY() {return key;}
        string getSTR() {return str;}
};

class RBT
{
    private:
        TreeNode *root;
        TreeNode *neel; // NIL, means tree's leafnode
        TreeNode * LeftMost(TreeNode *currentNode);
        TreeNode * Successor(TreeNode *currentNode);
        void LeftRotation(TreeNode *x);
        void RightRotation(TreeNode *x);
        void DeleteRBTFixedUp(TreeNode *current);
        void InsertFixedUpRBT(TreeNode *current);
    public:
        RBT();
        TreeNode * Search(int key);
        void InsertRBT(int key, string str);
        void DeleteRBT(int key);
        void Print(TreeNode *current);
        TreeNode * getROOT() {return this->root;}
};

RBT::RBT()
{
    neel = new TreeNode;
    neel->color = 1;
    root = neel;
    root->parent = neel;
}

TreeNode * RBT::Search(int key)
{
    TreeNode *current = root;
    while (current != neel && current->key != key)
    {
        if (current->key < key)
            current = current->rightchild;
        else
            current = current->leftchild;
    }
    if (current == neel)
        cout << "data not found...\n";
    return current;
}

void RBT::LeftRotation(TreeNode *x)
{
    TreeNode *y = x->rightchild;
    x->rightchild = y->leftchild;

    if (y->leftchild != neel)
        y->leftchild->parent = x;

    y->parent = x->parent;

    if (x->parent == neel)
        root = y;
    else if (x == x->parent->leftchild)
        x->parent->leftchild = y;
    else
        x->parent->rightchild = y;

    y->leftchild = x;
    x->parent = y;
}

void RBT::RightRotation(TreeNode *y)
{
    TreeNode *x = y->leftchild;
    y->leftchild = x->rightchild;

    if (x->rightchild != neel)
        x->rightchild->parent = y;

    x->parent = y->parent;
    if (y->parent == neel)
        root = x;
    else if (y == y->parent->leftchild)
        y->parent->leftchild = x;
    else
        y->parent->rightchild = x;

    x->rightchild = y;
    y->parent = x;
}

void RBT::InsertRBT(int key, string str) // in the first, just like BST
{
    TreeNode *y = neel;
    TreeNode *x = root;
    TreeNode *insert_node = new TreeNode(key, str);
    while (x != neel)
    {
        y = x;
        if (x->key < key)
            x = x->rightchild;
        else
            x = x->leftchild;
    }

    insert_node->parent = y;

    if (y == neel)
        this->root = insert_node;
    else if (insert_node->key > y->key)
        y->rightchild = insert_node;
    else
        y->leftchild = insert_node;

    // RBT
    insert_node->leftchild = neel;
    insert_node->rightchild = neel;
    insert_node->color = 0; // red

    InsertFixedUpRBT(insert_node);
}

void RBT::InsertFixedUpRBT(TreeNode *current)
{
    // case 0: parent is black, we don't need to adjust RBT
    while (current->parent->color == 0)
    {
        // check whether parent is grandparent's leftchild or not
        if (current->parent == current->parent->parent->leftchild)
        {
            TreeNode *uncle = current->parent->rightchild;
            if (uncle->color == 0) // case 1: uncle is red
            {
                // change parent, uncle, grandparent's color and then set current to grandparent
                current->parent->color = 1;
                uncle->color = 1;
                current->parent->parent->color = 0;
                current = current->parent->parent;
            }
            else // case 2 & 3: uncle is black
            {
                if (current == current->parent->rightchild) // case 2
                {
                    current = current->parent;
                    LeftRotation(current);
                }
                // case 3
                current->parent->color = 1;
                current->parent->parent->color = 0;
                RightRotation(current->parent->parent);
            }
        }
        else // parent is grandparent's rightchild
        {
            TreeNode *uncle = current->parent->parent->leftchild;
            if (uncle->color == 0)
            {
                current->parent->color = 1;
                current->parent->parent->color = 0;
                uncle->color = 1;
            }
            else
            {
                if (current == current->leftchild)
                {
                    current = current->parent;
                    RightRotation(current);
                }
                current->parent->color = 1;
                current->parent->parent->color = 0;
                LeftRotation(current->parent->parent);
            }
        }
    }
    root->color = 1;
}

TreeNode * RBT::LeftMost(TreeNode *current)
{
    while (current->leftchild != neel)
        current = current->leftchild;
    return current;
}

TreeNode * RBT::Successor(TreeNode *current)
{
    if (current->rightchild != neel)
        return LeftMost(current->rightchild);

    TreeNode *newNode = current->parent;
    while (newNode != neel && current == newNode->rightchild)
    {
        current = newNode;
        newNode = newNode->parent;
    }
    return newNode;
}

// TreeNode* RBT::LeftMost(TreeNode *current){
    
//     while (current->leftchild != NULL){
//         current = current->leftchild;
//     }
//     return current;
// }
// TreeNode* RBT::Successor(TreeNode *current){
    
//     if (current->rightchild != NULL){
//         return LeftMost(current->rightchild);
//     }
    
//     TreeNode *new_node = current->parent;
    
//     while (new_node != NULL && current == new_node->rightchild) {
//         current = new_node;
//         new_node = new_node->parent;
//     }
    
//     return new_node;
// }

void RBT::DeleteRBT(int key)
{
    TreeNode *delete_node = Search(key);
    if (delete_node == neel)
        return;

    TreeNode *y = nullptr; // delete node
    TreeNode *x = nullptr; // delete node's child

    if (delete_node->leftchild == neel || delete_node->rightchild == neel)
        y = delete_node;
    else
        y = Successor(delete_node);

    if (y->leftchild != neel)
        x = y->leftchild;
    else
        x = y->rightchild;

    x->parent = y->parent; // even x is neel, we still need to set its parent for fixing

    if (y->parent == neel) // delete root
        this->root = x;
    else if (y == y->parent->leftchild)
        y->parent->leftchild = x;
    else
        y->parent->rightchild = x;

    if (y != delete_node)
    {
        delete_node->key = y->key;
        delete_node->str = y->str;
    }

    if (y->color == 1) // when we delete black node, it will cause unbalance RBT
        DeleteRBTFixedUp(x);
    
    delete y;
}

void RBT::DeleteRBTFixedUp(TreeNode *current)
{
    // case 0: current is red, paint it to black
    //       : current is black, paint it to black
    while (current != root && current->color == 1)
    {
        if (current == current->parent->leftchild)
        {
            TreeNode *sibling = current->parent->rightchild;
            // case 1: if sibling is red
            if (sibling->color == 0)
            {
                sibling->color = 1;
                current->parent->color = 0;
                LeftRotation(current->parent);
                sibling = current->parent->rightchild;
            }
            // case2: sibling's two child are black
            if (sibling->leftchild->color == 1 && sibling->rightchild->color == 1)
            {
                sibling->color = 0;
                current = current->parent;
            }
            else // case 3 & 4: one of sibling's cjild is black
            {
                // case 3: sibling's right child is black, left child is red
                if (sibling->rightchild->color == 1)
                {
                    sibling->color = 0;
                    sibling->leftchild->color = 1;
                    RightRotation(sibling);
                    sibling = current->parent->rightchild;
                }
                // after case 3, we must get into case 4
                // case 4: sibling's right child is red
                sibling->color = current->parent->color;
                current->parent->color = 1;
                sibling->rightchild->color = 1;
                LeftRotation(current->parent);
                current = root;
            }
        }
        else // current is right child
        {
            TreeNode *sibling = current->parent->leftchild;
            // case 1: if sibling is red
            if (sibling->color == 0)
            {
                sibling->color = 1;
                current->parent = 0;
                RightRotation(current->parent);
                sibling = current->parent->leftchild;
            }
            // case 2: siibling's two child are black
            if (sibling->leftchild->color == 1 && sibling->rightchild->color == 1)
            {
                sibling->color = 0;
                current = current->parent;
            }
            else // case 3 & 4
            {
                // case 3: sibling's left child is black, right child is red
                if (sibling->leftchild->color == 1)
                {
                    sibling->color = 0;
                    sibling->rightchild->color = 1;
                    LeftRotation(sibling);
                    sibling = current->parent->leftchild;
                }
                // case 4: sibling's left child is red, right child is blac
                sibling->color = current->parent->color;
                current->parent->color = 1;
                sibling->leftchild->color = 1;
                RightRotation(current->parent);
                current = root; // stop loop
            }
        }
    }
    current->color = 1;
}

void RBT::Print(TreeNode *current)
{
    if (current == neel)
        return;

    if (current->leftchild)
        Print(current->leftchild);

    cout << current->key << ": " << current->str << endl;
            
    if (current->rightchild)
        Print(current->rightchild);
}

int main()
{
    RBT tree;
    tree.InsertRBT(12, "candy");
    tree.InsertRBT(30, "orange");
    tree.InsertRBT(20, "water");
    tree.InsertRBT(10, "apple");
    tree.InsertRBT(22, "melon");
    tree.InsertRBT(5, "kit");

    // TreeNode *temp = tree.Search(20);
    // cout << temp->getKEY() << ": " << temp->getSTR() << endl;

    tree.DeleteRBT(12);
    // TreeNode *temp = tree.Search(30);
    // cout << temp->getKEY() << ": " << temp->getSTR();
    tree.Print(tree.getROOT());

    return 0;
}