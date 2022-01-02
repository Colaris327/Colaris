// https://www.geeksforgeeks.org/introduction-of-b-tree-2/
#include <iostream>
using namespace std;

class BTree;

class BTreeNode
{
    private:
        friend class BTree;
        int *keys; // an array of keys
        int deg; // Minimum degree
        BTreeNode **Chi; // an array of child pointers
        int num; // current number of keys
        bool leaf; // True when node is leaf
    public:
        BTreeNode(int _d, bool _leaf);
        void Traverse();
        // return NULL when k doesn't find
        BTreeNode * Search(int k); 
        // insert into the node when the node is not full
        void InsertNonFull(int k); 
        // i: index of Chi[], y: Child y be called when node is full
        void SplitChild(int i, BTreeNode *y); 
        // return the index of the first greater or equal to key
        int Findkey(int k);
        // a wrapper function to delete key
        void Remove(int k);
        // remove the key when the node is leaf
        void Removefromleaf(int idx);
        // remove the key when the node is not leaf
        void Removefromnonleaf(int idx);
        // get the predecessor of the key
        int getPred(int idx);
        // get the successor of the key
        int getSucc(int idx);
        // fill up the child node in the idx-th position in the Chi[] array if the child has less than (deg - 1) keys
        void Fill(int idx);
        // borrow a key from the Chi[idx - 1]-th node and place it in Chi[idx]th node
        void BorrowFromPrev(int idx);
        // borrow a key from the Chi[idx + 1]-th node and place it in Chi[idx]th node
        void BorrowFromNext(int idx);
        // merge the idx-th child and (idx + 1)th child
        void Merge(int idx);

};

class BTree
{
    private:
        BTreeNode *root;
        int deg; // minimum degree
    public:
        BTree(int _d): root(NULL), deg(_d) {}
        void Traverse() {if (root != NULL) root->Traverse();}
        BTreeNode * Search(int k) {return (root == NULL) ? NULL : root->Search(k);}
        void Insert(int k);
        void Remove(int k);
};

BTreeNode::BTreeNode(int _d, bool _leaf)
{
    deg = _d;
    leaf = _leaf;

    keys = new int[2 * deg - 1];
    Chi = new BTreeNode *[2 * deg];

    num = 0;
}

void BTreeNode::Traverse()
{
    // there are n keys and n+1 children
    int i;
    for (i = 0; i < num; i++) // print first to n children
    {
        if (leaf == false)
            Chi[i]->Traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        Chi[i]->Traverse();
}

BTreeNode * BTreeNode::Search(int k)
{
    int i = 0;
    while (i < num && k > keys[i])
        i++;
    if (keys[i] == k)
        return this;
    if (leaf == true) // we didn't find the key
        return NULL;

    return Chi[i]->Search(k);
}

void BTree::Insert(int k)
{
    if (root == NULL)
    {
        root = new BTreeNode(k, true);
        root->keys[0] = k;
        root->num = 1;
    }
    else
    {
        if (root->num == 2 * deg - 1) // root is full
        {
            BTreeNode *s = new BTreeNode(deg, false);
            s->Chi[0] = root; // old root become new root's child
            s->SplitChild(0, root); // split old root and move one key to new root

            int i = 0;
            if (s->keys[i] < k) // new root has two children, decide which one has new key
                i++;
            s->Chi[i]->InsertNonFull(k);
            root = s; // change root
        }
        else // root is not full
            root->InsertNonFull(k);
    }
}

void BTreeNode::InsertNonFull(int k)
{
    int i = num - 1;

    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k) // find where to insert new key and move greater key to one place ahead
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        num++;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (Chi[i + 1]->num == 2 * deg - 1) // found child is full
        {
            SplitChild(i + 1, Chi[i + 1]);

            // after split, middle key of Chi[i] goes up and split into two
            // decide which one has new key
            if (keys[i + 1] < k)
                i++;
        }
        Chi[i + 1]->InsertNonFull(k);
    }
}

void BTreeNode::SplitChild(int i, BTreeNode *y)
{
    // create a new node which is goung to store (deg - 1) keys of y
    BTreeNode *z = new BTreeNode(y->deg, y->leaf);
    z->num = deg - 1;
    // copy last (deg - 1) keys
    for (int j = 0; j < deg - 1; j++)
        z->keys[j] = y->keys[j + deg];
    // copy last deg children to z
    if (leaf == false)
    {
        for (int j = 0; j < deg; j++)
            z->Chi[j] = y->Chi[j + deg];
    }
    // reduce number of keys in y
    y->num = deg - 1;
    // create space for new child
    for (int j = num; j >= i + 1; j--)
        Chi[j + 1] = Chi[j];
    // link new child to this node
    Chi[i + 1] = z;

    // a key will move to this node, find location and move greater key to one space ahead
    for (int j = num - 1; j >= i; j--) 
        keys[j + 1] = keys[j];
    keys[i] = y->keys[deg - 1];

    num++;
}

// int main()
// {
//     BTree tree(3); // degree = 3
//     tree.Insert(10);
//     tree.Insert(20);
//     tree.Insert(11);
//     tree.Insert(25);
//     tree.Insert(6);
//     tree.Insert(2);
//     tree.Insert(88);
//     tree.Insert(36);
//     tree.Insert(40);

//     tree.Traverse();
//     cout << endl;
//     (tree.Search(20) != NULL) ? cout << "exist" : cout << "not exist";
//     return 0;
// }

int BTreeNode::Findkey(int k)
{
    int idx = 0;
    while (idx < num && keys[idx] < k)
        idx++;
    return idx;
}

void BTreeNode::Remove(int k)
{
    int idx = Findkey(k);

    // the key is in the node
    if (idx < num && keys[idx] == k)
    {
        if (leaf)
            Removefromleaf(idx);
        else
            Removefromnonleaf(idx);
    }
    else
    {
        if (leaf)
        {
            cout << "The key " << k << " is not exist\n";
            return;
        }

        // check if the idx is last child
        bool flag = (idx == num) ? true : false;

        // if the child where the key is supposed to exist less 
        // that deg keys, we fill that child
        if (Chi[idx]->num < deg)
            Fill(idx);

        // If the last child has been merged, it must have merged with the previous
        // child and so we recurse on the (idx-1)th child. Else, we recurse on the
        // (idx)th child which now has atleast deg keys
        if (flag && idx > num)
            Chi[idx - 1]->Remove(k);
        else
            Chi[idx]->Remove(k);
    }
    return;
}

void BTreeNode::Removefromleaf(int idx)
{
    for (int i = idx + 1; i < num; i++)
        keys[i - 1] = keys[i];
    num--;
    return;
}

void BTreeNode::Removefromnonleaf(int idx)
{
    int k = keys[idx];
    
    // If the child that precedes k (C[idx]) has atleast t keys,
    // find the predecessor 'pred' of k in the subtree rooted at
    // C[idx]. Replace k by pred. Recursively delete pred
    // in Chi[idx]
    if (Chi[idx]->num >= deg)
    {
        int pred = getPred(idx);
        keys[idx] = pred;
        Chi[idx]->Remove(pred);
    }
    // If the child C[idx] has less that t keys, examine C[idx+1].
    // If C[idx+1] has atleast t keys, find the successor 'succ' of k in
    // the subtree rooted at C[idx+1]
    // Replace k by succ
    // Recursively delete succ in C[idx+1]
    else if  (Chi[idx + 1]->num >= deg)
    {
        int succ = getSucc(idx);
        keys[idx] = succ;
        Chi[idx+1]->Remove(succ);
    }
    // If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1]
    // into C[idx]
    // Now C[idx] contains 2t-1 keys
    // Free C[idx+1] and recursively delete k from C[idx]
    else
    {
        Merge(idx);
        Chi[idx]->Remove(k);
    }
    return;
}

int BTreeNode::getPred(int idx)
{
    // find most right
    BTreeNode *curr = Chi[idx];
    while (curr->leaf)
        curr = curr->Chi[curr->num];
    return curr->keys[curr->num - 1];
}

int BTreeNode::getSucc(int idx)
{
    // find most left
    BTreeNode *curr = Chi[idx + 1];
    while (curr->leaf)
        curr = curr->Chi[0];
    return curr->keys[0];
}

void BTreeNode::Fill(int idx)
{
    // If the previous child(C[idx-1]) has more than deg-1 keys, borrow a key
    // from that child
    if (idx != 0 && Chi[idx-1]->num >= deg)
        BorrowFromPrev(idx);
  
    // If the next child(C[idx+1]) has more than deg-1 keys, borrow a key
    // from that child
    else if (idx != num && Chi[idx + 1]->num >= deg)
        BorrowFromNext(idx);
  
    // Merge C[idx] with its sibling
    // If C[idx] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling
    else
    {
        if (idx != num)
            Merge(idx);
        else
            Merge(idx-1);
    }
    return;
}

void BTreeNode::BorrowFromPrev(int idx)
{
  
    BTreeNode *child=Chi[idx];
    BTreeNode *sibling=Chi[idx - 1];
  
    // The last key from C[idx-1] goes up to the parent and key[idx-1]
    // from parent is inserted as the first key in C[idx]. Thus, the  loses
    // sibling one key and child gains one key
  
    // Moving all key in C[idx] one step ahead
    for (int i = child->num - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];
  
    // If C[idx] is not a leaf, move all its child pointers one step ahead
    if (!child->leaf)
    {
        for(int i=child->num; i >= 0; --i)
            child->Chi[i+1] = child->Chi[i];
    }
  
    // Setting child's first key equal to keys[idx-1] from the current node
    child->keys[0] = keys[idx - 1];
  
    // Moving sibling's last child as C[idx]'s first child
    if(!child->leaf)
        child->Chi[0] = sibling->Chi[sibling->num];
  
    // Moving the key from the sibling to the parent
    // This reduces the number of keys in the sibling
    keys[idx-1] = sibling->keys[sibling->num - 1];
  
    child->num += 1;
    sibling->num -= 1;
  
    return;
}

void BTreeNode::BorrowFromNext(int idx)
{
  
    BTreeNode *child=Chi[idx];
    BTreeNode *sibling=Chi[idx+1];
  
    // keys[idx] is inserted as the last key in C[idx]
    child->keys[(child->num)] = keys[idx];
  
    // Sibling's first child is inserted as the last child
    // into C[idx]
    if (!(child->leaf))
        child->Chi[(child->num) + 1] = sibling->Chi[0];
  
    //The first key from sibling is inserted into keys[idx]
    keys[idx] = sibling->keys[0];
  
    // Moving all keys in sibling one step behind
    for (int i=1; i<sibling->num; ++i)
        sibling->keys[i-1] = sibling->keys[i];
  
    // Moving the child pointers one step behind
    if (!sibling->leaf)
    {
        for(int i=1; i<=sibling->num; ++i)
            sibling->Chi[i-1] = sibling->Chi[i];
    }
  
    // Increasing and decreasing the key count of C[idx] and C[idx+1]
    // respectively
    child->num += 1;
    sibling->num -= 1;
  
    return;
}

void BTreeNode::Merge(int idx)
{
    BTreeNode *child = Chi[idx];
    BTreeNode *sibling = Chi[idx+1];
  
    // Pulling a key from the current node and inserting it into (deg-1)th
    // position of C[idx]
    child->keys[deg - 1] = keys[idx];
  
    // Copying the keys from C[idx+1] to C[idx] at the end
    for (int i = 0; i < sibling->num; ++i)
        child->keys[i + deg] = sibling->keys[i];
  
    // Copying the child pointers from C[idx+1] to C[idx]
    if (!child->leaf)
    {
        for(int i = 0; i <= sibling->num; ++i)
            child->Chi[i + deg] = sibling->Chi[i];
    }
  
    // Moving all keys after idx in the current node one step before -
    // to fill the gap created by moving keys[idx] to C[idx]
    for (int i = idx+1; i < num; ++i)
        keys[i - 1] = keys[i];
  
    // Moving the child pointers after (idx+1) in the current node one
    // step before
    for (int i = idx+2; i <= num; ++i)
        Chi[i - 1] = Chi[i];
  
    // Updating the key count of child and the current node
    child->num += sibling->num + 1;
    num--;
  
    // Freeing the memory occupied by sibling
    delete(sibling);
    return;
}