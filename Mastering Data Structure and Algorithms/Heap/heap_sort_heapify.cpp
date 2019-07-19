#include <bits/stdc++.h>

template <class T>
void display(const std::vector<T> &arr){
    std::cout<<"\nElements are : [ ";
    for(auto &item:arr){
        std::cout<<item<<" ";
    }
    std::cout<<"]\n";
}

template <class T>
void heapify(std::vector<T> &heap, int n, int largest){
    int root {largest}, max_child {largest};
    int lchild {largest*2+1}, rchild {largest*2+2};

    if(lchild < n && heap[lchild] > heap[rchild])
        max_child = lchild;
    else if(rchild < n && heap[lchild] < heap[rchild])
        max_child = rchild;

    if(heap[root] < heap[max_child]){
        std::swap(heap[root], heap[max_child]);
        heapify(heap,n,max_child);
    }
}


template <class T>
void heap_sort(std::vector<T> &arr){
    for (int i = arr.size() / 2 - 1; i >= 0; i--) 
        heapify(arr, arr.size(), i); 
        
    // One by one extract an element from heap 
    for (int i=arr.size()-1; i>=0; i--) 
    { 
        // Move current root to end 
        std::swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}

int main(){
    std::vector<int> heap, arr {10,20,30,25,5,40,35};
    display(arr);
    
    heap_sort(arr);
    display(arr);
}