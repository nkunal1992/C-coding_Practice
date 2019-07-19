#include <bits/stdc++.h>

template <class T>
void display(const std::vector<T> &arr){
    std::cout<<"\nElements are : [ ";
    for(auto &item:arr){
        std::cout<<item<<" ";
    }
    std::cout<<"]\n";
}

//will work only for integer
template <class T>
void bin_sort(std::vector<T> &arr){
    T max_num = *(std::max_element(arr.begin(),arr.end()));
    std::vector<std::list<T>> bins(max_num+1);

   for(int i {0}; i < arr.size(); i++){
       bins[arr[i]].push_back(arr[i]);
   }

    int j {0};
    for(auto i : bins){
        while(!i.empty()){
            arr[j++] = i.front();
            i.pop_front();
        }
    }
}

int main(){
    std::vector<int> arr {11,13,13,6,2,3,7,2,6,9,4,5,10,3};
    display(arr);
    bin_sort(arr);
    display(arr);
}