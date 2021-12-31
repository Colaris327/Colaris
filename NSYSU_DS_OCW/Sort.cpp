#include <iostream>
#include <vector>

// http://alrightchiu.github.io/SecondRound/comparison-sort-insertion-sortcha-ru-pai-xu-fa.html
// Insertion sort
void InsertionSort(int *arr, int size)
{
    for (int current = 1; current < size; current++)
    {
        int key = arr[current];
        int finger = current - 1;
        while (key < arr[finger] && finger >= 0)
        {
            arr[finger + 1] = arr[finger];
            finger--;
        }
        arr[finger + 1] = key;
    }
}

// http://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html
// Quick sort
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int front, int end)
{
    int pivot = arr[end]; // start from the array's right side
    int i = front - 1;
    for (int j = front; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i; // the pivot's new position
}

void QuickSort(int *arr, int front, int end)
{
    if (front < end)
    {
        int pivot = partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

// http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
// Merge sort
const int MAX = 1000;

void Merge(std::vector<int> &Array, int front, int mid, int end)
{
    // + 1 is for putting infinite in sub. in order to compare
    std::vector<int> LeftSub(Array.begin() + front, Array.begin() + mid + 1); // put array[front:mid] in
    std::vector<int> RightSub(Array.begin() + mid + 1, Array.begin() + end + 1); // put array[mid+1:end] in

    LeftSub.insert(LeftSub.end(), MAX);
    RightSub.insert(RightSub.end(), MAX);

    int idxLeft = 0, idxRight = 0; // position
    for (int i = front; i <= end; i++)
    {
        if (LeftSub[idxLeft] <= RightSub[idxRight])
        {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(std::vector<int> &Array, int front, int end)
{
    if (front < end)
    {
        int mid = (front + end) / 2;
        MergeSort(Array, front, mid); // divide
        MergeSort(Array, mid + 1, end); // divide
        Merge(Array, front, mid, end); // conquer sorted array
    }
}

// http://alrightchiu.github.io/SecondRound/comparison-sort-heap-sortdui-ji-pai-xu-fa.html
// Heap sort
void swap(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(std::vector<int> &array, int root, int length)
{
    int left = root * 2;
    int right = root * 2 + 1;
    int largest;

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;
    if (right <= length && array[right] > array[largest]) // find max of root, leftchild, rightchild
        largest = right;
    
    if (largest != root)
    {
        swap(array[largest], array[root]);
        MaxHeapify(array, largest, length); // if we change the tree, continue to adjust the subtree
    }
}

void BuildMaxHeap(std::vector<int> &array)
{
    for (int root = (int)array.size() / 2; root >= 1; root--)
        MaxHeapify(array, root, array.size() - 1); // - 1 is for array starts from 1, so we don't compute array[0]
}

void HeapSort(std::vector<int> &array)
{
    array.insert(array.begin(), 0); // idle array[0]
    BuildMaxHeap(array);

    int size = array.size() - 1;
    for (int i = array.size() - 1; i >= 2; i--)
    {
        swap(array[1], array[size]); // excharge maximum to array's last position
        size--; // ignore last position
        MaxHeapify(array, 1, size); // reset maxheap
    }
    array.erase(array.begin()); // delele array[0]
}

// https://www.geeksforgeeks.org/radix-sort/
// radix sort
int getMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int *arr, int size, int exp) // exp = 1, 10, 100, 1000....
{
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++)
        count[arr[i] / exp % 10]++;

    for (i = 1; i < 10; i++) // caculate cumulative, now count[i] contains
        count[i] += count[i - 1]; // the actual position of this digit in output[]

    for (i = size - 1; i >= 0; i--) // insert to output[]
    {
        output[count[arr[i] / exp % 10] - 1] = arr[i];
        count[arr[i] / exp % 10]--;
    }

    for (i = 0; i < size; i++) // copy
        arr[i] = output[i];
}

void RadixSort(int *arr, int size)
{
    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

int main()
{
    int array[5] = {2, 3, 4, 2, 1};
    std::vector<int> arr = {2, 3, 4, 2, 1};
    RadixSort(array, 5);
    MergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        std::cout << array[i];
    for (int i = 0; i < 5; i++)
        std::cout << arr[i];
    return 0;
}