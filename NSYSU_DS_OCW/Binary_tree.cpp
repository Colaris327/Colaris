#include <iostream>
#include <queue> // for level-order tree

template <class T> class Tree; // forward declaration

template<class T>
class Treenode
{
    friend class Tree<T>;
    private:
        T data;
        Treenode<T> *leftChild;
        Treenode<T> *rightChild;
        Treenode<T> *parent; // for for-loop
};

template<class T>
class Tree
{
    private:
        Treenode<T> *root;
    public:
        void Visit(Treenode<T> *node) {std::cout << node->data << " ";}
        
        // using recursion
        void Preorder(Treenode<T> *currentNode);
        void Preorder();
        
        void Inorder(Treenode<T> *currentNode);
        void Inorder();
        
        void Postorder(Treenode<T> *currentNode);
        void Postorder();

        // using queue
        void Levelorder();

        // using for-loop
        // http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html#in_parent
        Treenode<T> * LeftMost(Treenode<T> *currentNode);
        Treenode<T> * InorderSuccessor(Treenode<T> *currentNode); // return current's next one
        void Inorder_by_parent(Treenode<T> *root);

};

template<class T>
void Tree<T>::Preorder()
{
    Preorder(root); // call workhorse for traversal intire tree
}

template<class T>
void Tree<T>::Preorder(Treenode<T> *currentNode)
{
    if (currentNode)
    {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

template<class T>
void Tree<T>::Inorder()
{
    Inorder(root); // call workhorse for traversal intire tree
}

template<class T>
void Tree<T>::Inorder(Treenode<T> *currentNode)
{
    if (currentNode)
    {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}

template<class T>
void Tree<T>::Postorder()
{
    Postorder(root); // call workhorse for traversal intire tree
}

template<class T>
void Tree<T>::Postorder(Treenode<T> *currentNode)
{
    if (currentNode)
    {
        Postorder(currentNode->leftChild);
        Postorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

template<class T>
void Tree<T>::Levelorder()
{
    std::queue< Treenode<T> *> q;
    Treenode<T> *currentnode = root;
    while (currentnode)
    {
        Visit(currentnode);
        if (currentnode->leftChild)
            q.push(currentnode->leftChild);
        if (currentnode->rightChild)
            q.push(currentnode->rightChild);
        if (q.empty())
            return;
        currentnode = q.front();
        q.pop();
    }
}

template<class T>
Treenode<T> * Tree<T>::LeftMost(Treenode<T> *current)
{
    while (current->leftChild != NULL)
        current = current->leftChild;
    return current;
}

template<class T>
Treenode<T> * Tree<T>::InorderSuccessor(Treenode<T> *current)
{
    if (current->rightChild != NULL)
        return LeftMost(current->rightChild);
    
    Treenode<T> *successor = current->parent;
    while (successor != NULL && current == successor->rightChild)
    {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}

template<class T>
void Tree<T>::Inorder_by_parent(Treenode<T> *root)
{
    Treenode<T> *current = new Treenode<T>;
    current = LeftMost(root);
    while (current)
    {
        std::cout << current->data << " ";
        current = InorderSuccessor(current);
    }
}