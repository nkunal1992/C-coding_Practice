#include <bits/stdc++.h>

template <class T>
void insertion_sort(std::vector<T> &arr){
    T temp;
    for(auto i {1}; i<arr.size(); i++){
        int j {i-1};
        temp = arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    std::vector<double> arr {1.33,1.29,5.9,3.141,7.0,6.34};
    display(arr);
    insertion_sort(arr);
    display(arr);
}