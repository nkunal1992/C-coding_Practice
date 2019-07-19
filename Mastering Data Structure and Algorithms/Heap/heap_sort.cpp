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

template <class T>
void Delete(std::vector<T> &heap, int n){
    T root = heap[0];
    T last_ele = heap[n-1];

    heap[0] = last_ele;

    int i {0},lchild {2*i+1}, rchild {2*i+2}, max_child {lchild};
    while(lchild < n-2){
        if(heap[lchild] < heap[rchild])
            max_child = rchild;
        else 
            max_child = lchild;

        if(heap[i] < heap[max_child]){
            std::swap(heap[i], heap[max_child]);
            i = max_child;
            lchild = 2*i+1;
            rchild = 2*i+2;
        }
        else 
            break;
    }
    heap[n-1] = root;
}

template <class T>
void heap_sort(std::vector<T> &heap){
    for(int i=heap.size(); i>1; i--)
        Delete(heap,i);
}

int main(){
    std::vector<int> heap, arr {10,20,30,25,5,40,35};
    display(heap);
    createHeap(heap,arr);
    display(heap);
    heap_sort(heap);
    display(heap);
}