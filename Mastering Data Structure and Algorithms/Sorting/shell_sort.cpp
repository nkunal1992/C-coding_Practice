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
void shell_sort(std::vector<T> &arr){
    T temp;
    int n = static_cast<int>(arr.size());

    for(int gap=n/2; gap>=1; gap = gap/2){
        for(int i {gap}; i<n; i++){
            int j {i-gap};
            temp = arr[i];
            while(j>=0 && arr[j] > temp){
                arr[j+gap] = arr[j];
                j = j-gap;
            }
            arr[j+gap] = temp;
        }
    }
}

int main(){
    std::vector<int> arr {11,13,7,12,16,9,24,5,10,3};
    display(arr);
    shell_sort(arr);
    display(arr);
}