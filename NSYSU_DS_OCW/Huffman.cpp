// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data; // input character
    unsigned freq; // frequency of the character
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare // for priority queue
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void PrintCode(MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << endl;
    
    PrintCode(root->left, str + "0");
    PrintCode(root->right, str + "1");
}

void HuffmanCode(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    PrintCode(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {5, 9, 3, 6, 7};
    HuffmanCode(arr, freq, 5);
    return 0;
}