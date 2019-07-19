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
void merge(std::vector<T> &arr,int low, int mid, int high){
    int i {low}, j {mid+1};
    std::vector<T> B;
    
    while(i<=mid && j<=high){
        if(arr[i] < arr[j])
            B.push_back(arr[i++]);
        else    
            B.push_back(arr[j++]);
    }

    for(; i<=mid; i++)
        B.push_back(arr[i]);
    
    for(; j<=high; j++)
        B.push_back(arr[j]);

    // display(B);
    j = 0;
    for(i=low; i<=high; i++)
        arr[i] = B[j++];
}

template <class T>
void recursiveMerge_sort(std::vector<T> &arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        recursiveMerge_sort(arr,low,mid);
        recursiveMerge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    std::vector<int> arr {11,13,7,2,6,9,4,5,10,3};
    display(arr);
    recursiveMerge_sort(arr,0,arr.size()-1);
    display(arr);
}