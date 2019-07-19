#include <bits/stdc++.h>

//will work only for integer
template <class T>
void count_sort(std::vector<T> &arr){
    T max_num = *(std::max_element(arr.begin(),arr.end()));
    std::vector<T> count (max_num+1);
    int i {0}, j{0};

    for(i = 0; i < arr.size(); i++)
        count[arr[i]]++;

    i = 0;
    while(i<count.size()){
        if(count[i]>0){
            arr[j++] = i;
            count[i]--;
        }
        else 
            i++;
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
    std::vector<int> arr {11,13,7,2,6,9,4,5,13,0,0,10,3};
    display(arr);
    count_sort(arr);
    display(arr);
}