#include <bits/stdc++.h>
void Heapify(int A[], int index, int size)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < size && A[left] > A[index])
    {
        largest = left;
    }
    if (right < size && A[right] > A[largest])
    {
        largest = right;
    }
    if (index != largest)
    {
        swap(A[index], A[largest]);
        index = largest;
        Heapify(A, index, size);
    }
}
void BuildMaxHeap(int Array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(Array, i, n);
    }
}
void print(int Arr[], int heapSize)
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 10;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(arr, n);
    BuildMaxHeap(arr,n);
    print(arr, n);
    return 0;
}