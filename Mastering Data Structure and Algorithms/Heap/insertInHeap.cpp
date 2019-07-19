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

int main(){
    std::vector<int> heap {30,20,15,5,10,12,6};
    display(heap);
    insert(heap,40);
    insert(heap,35);
    display(heap);
}