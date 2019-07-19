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
void insert(std::vector<T> &heap, T key){
    heap.push_back(key);

    int index = static_cast<int>(heap.size())-1;
    int parent = (index+1)/2-1;

    while((index > 0 )&& heap[parent] < key){
        heap[index] = heap[parent];
        index = parent;
        parent = (index+1)/2-1;
    }

    heap[index] = key;
}

template <class T>
void createHeap(std::vector<T> &heap, std::vector<T> &arr){
    for(int i=0; i<arr.size(); i++)
        insert(heap,arr[i]);
}

int main(){
    std::vector<int> heap, arr {10,20,30,25,5,40,35};
    display(heap);
    createHeap(heap,arr);
    display(heap);
}