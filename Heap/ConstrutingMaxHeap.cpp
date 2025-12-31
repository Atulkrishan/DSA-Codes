#include <bits/stdc++.h>
class MaxHeap{
public:
    int* arr ;
    int heapSize;
    int totalSize;

    MaxHeap(int n){
        this->arr = new int[n];
        this->heapSize = 0;
        this->totalSize = n;
    }
    bool isEmpty(){
        return heapSize == 0;
    }
    bool IsFull(){
        return heapSize >= totalSize;
    }
    void Heapify(int idx){
        // when a node is voilating the max heap property due to its children.
        int left = 2 * idx + 1;
        int right = 2 * idx + 2 ;
        int largest = idx;
        if(left < heapSize && arr[left] > arr[idx]){
            largest = left;
        }
        if(right < heapSize  && arr[right] > arr[largest]){
            largest = right;
        }
        if(idx != largest){
            swap(arr[idx],arr[largest]);
            idx = largest; 
            Heapify(idx);
        }
    }
    void ItreativeHeapify(int idx){
        // when a node is voilating the max heap property due to its children.
        int left = 2 * idx + 1;
        int right = 2 * idx + 2 ;
        int largest = idx;
        while(true){
            left = 2 * idx + 1;
            right = 2 * idx + 2 ;
            largest = idx;
            if(left < heapSize && arr[left] > arr[idx]){
                largest = left;
            }
            if(right < heapSize  && arr[right] > arr[largest]){
                largest = right;
            }
            if(idx != largest){
                swap(arr[idx],arr[largest]);
                idx = largest; 
            }
            else break;
        }
    }
    void DeleteMax(){
        if(isEmpty()){
            cout << "heap Underflow\n";
            return;
        }
        int top = 0;
        int temp = heapSize - 1;
        swap(arr[temp],arr[top]);
        heapSize--;
        ItreativeHeapify(top);
    }
    void Insert(int val){
        if(IsFull()){
            cout << "heap Overflow\n";
            return;
        }
        else{
            arr[heapSize] = val;
            int idx = heapSize;
            heapSize++;
            int parent = (idx - 1 )/ 2 ;
            while(idx > 0 && arr[idx] > arr[parent]){
                swap(arr[idx] , arr[parent]);
                idx = parent;
                parent = (idx - 1 )/ 2 ;
            }
        }
    }
    void print(){
        for(int i = 0 ; i < heapSize ; i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap Mh1(6);
    Mh1.Insert(1);
    Mh1.Insert(3);
    Mh1.Insert(2);
    Mh1.Insert(5);
    Mh1.Insert(10);
    Mh1.Insert(9);
    Mh1.print();
    Mh1.DeleteMax();
    Mh1.print();
    return 0;
}