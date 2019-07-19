#include <bits/stdc++.h>

template <class T>
int partition(std::vector<T> &arr,int low, int high){
    int pivot {low};
    int greater {high}, smaller {low};

    do{
        do{smaller++;} while(arr[smaller]<=arr[pivot]);
        do{greater--;} while(arr[greater]>arr[pivot]);

        if(smaller < greater)
            std::swap(arr[smaller],arr[greater]);
    }while(smaller < greater);

    std::swap(arr[pivot],arr[greater]);
    return greater;
}

template <class T>
void quick_sort(std::vector<T> &arr, int low, int high){
    if(low < high){
        int j = partition(arr,low,high);
        quick_sort(arr,low,j);
        quick_sort(arr,j+1,high);
    }
}

template <class T>
void display(const std::vector<T> &arr){
    std::cout<<"\nElements are : [ ";
    for(auto &item:arr){
        std::cout<<item<<" ";
    }
    std::cout<<"]\n";
}

int main(){
    std::vector<int> arr {11,13,7,2,6,9,4,5,10,3};
    display(arr);
    quick_sort(arr,0,arr.size());
    display(arr);
}