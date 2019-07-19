#include <bits/stdc++.h>

template <class T>
void bubble_sort(std::vector<T> &arr){
    int flag;
    for(auto i {0}; i<arr.size()-1; i++){
        flag = 0;
        for(auto j {0}; j<arr.size()-1-i; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
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
    std::vector<std::string> arr {"Narayan", "Manish", "Abhishek","Himanshu","Yogesh"};
    display(arr);
    bubble_sort(arr);
    display(arr);
}