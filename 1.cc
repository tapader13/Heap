#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Kisu t nai heap r modde." << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndx = i * 2;
            int rightIndx = 2 * i + 1;
            if (leftIndx < size && arr[leftIndx] > arr[i])

            {
                swap(arr[i], arr[leftIndx]);
                i = leftIndx;
            }
            else if (rightIndx < size && arr[rightIndx] > arr[i])
            {
                swap(arr[i], arr[rightIndx]);
                i = rightIndx;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
void heapfiy(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapfiy(arr, size, largest);
    }
}
void heapSort(int *arr, int size)
{
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapfiy(arr, size, 1);
    }
}
int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(6);
    h.insert(8);
    h.print();
    cout << endl;
    h.deleteHeap();
    h.print();
    cout << endl;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapfiy(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}