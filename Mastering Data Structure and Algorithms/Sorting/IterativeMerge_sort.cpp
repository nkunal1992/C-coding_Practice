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
void IterativeMerge_sort(std::vector<T> &arr){
    int p;
    for(p=2; p<=arr.size(); p=p*2){
        for(int i {0}; i+p-1 < arr.size(); i += p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            merge(arr,low,mid,high);
        }
    }
    if(p/2 < arr.size())
        merge(arr,0,p/2-1,arr.size()-1);
}

int main(){
    std::vector<int> arr {11,13,7,2,6,9,4,5,10,3};
    display(arr);
    IterativeMerge_sort(arr);
    display(arr);
}