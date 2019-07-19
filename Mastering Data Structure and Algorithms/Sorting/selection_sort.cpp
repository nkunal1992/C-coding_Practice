#include <bits/stdc++.h>

template <class T>
void selection_sort(std::vector<T> &arr){
    int flag;
    for(auto i {0}; i<arr.size()-1; i++){
        int min {i};
        for(auto j {i}; j<arr.size(); j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
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
    selection_sort(arr);
    display(arr);
}