#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;


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

// Merge sort
const int MAX = 100000;

void Merge(int *Array, int front, int mid, int end)
{
    int LeftSize = mid - front + 1;
    int RightSize = end - mid;
    int *LeftSub = new int[LeftSize + 1];// + 1 is for putting infinite in sub. in order to compare
    int *RightSub = new int[RightSize + 1];

    copy(Array + front, Array + mid + 1, LeftSub);
    copy(Array + mid + 1, Array + end + 1, RightSub);
    // memcpy(LeftSub, Array + front, LeftSize * sizeof(int));
    // memcpy(RightSub, Array + mid + 1, RightSize * sizeof(int));
    LeftSub[LeftSize] = MAX;
    RightSub[RightSize] = MAX;

    // LeftSub.insert(LeftSub.end(), MAX);
    // RightSub.insert(RightSub.end(), MAX);

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

    delete [] LeftSub;
    delete [] RightSub;
}

void MergeSort(int *Array, int front, int end)
{
    if (front < end)
    {
        int mid = (front + end) / 2;
        MergeSort(Array, front, mid); // divide
        MergeSort(Array, mid + 1, end); // divide
        Merge(Array, front, mid, end); // conquer sorted array
    }
}

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

// Heap sort
// start from arr[0], so leftchild and rightchild is different from starting from arr[1]
void Heapify(int *arr, int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(&arr[root], &arr[largest]);
        Heapify(arr, size, largest);
    }
}

void HeapSort(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) // build heap
        Heapify(arr, size, i);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

pair<int *, int> Readindex()
{
    ifstream infile("input_1.txt", ifstream::in);
    int size;
    infile >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        infile >> arr[i];
    infile.close();
    return make_pair(arr, size);
}

void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void WriteTOFile(int *arr, int size)
{
    ofstream ofile;
    ofile.open("test.txt", ios::out);
    for (int i = 0; i < size; i++)
        ofile << arr[i] << endl;
    ofile.close();
}

int main()
{
    pair<int *, int> Index = Readindex();
    int *arr = Index.first;
    int size = Index.second;

    int Testarray[size];
    copy(arr, arr + size, Testarray);

    cout << "Insertion Sort:\n";
    InsertionSort(Testarray, size);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "Quick Sort:\n";
    QuickSort(Testarray, 0, size - 1);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "Merge Sort:\n";
    MergeSort(Testarray, 0, size - 1);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "Radix Sort:\n";
    RadixSort(Testarray, size);
    PrintArray(Testarray, size);
    WriteTOFile(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "Heap Sort:\n";
    HeapSort(Testarray, size);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "sort:\n";
    sort(Testarray, Testarray + size);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    cout << "qsort:\n";
    qsort(Testarray, size, sizeof(int), cmpfunc);
    PrintArray(Testarray, size);
    copy(arr, arr + size, Testarray);

    return 0;
}