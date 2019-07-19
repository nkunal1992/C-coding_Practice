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
int no_of_digit(T num){
    int count {0};
    while(num>0){
        count++;
        num /= 10;
    }
    return count;
}

//will work only for integer
template <class T>
void radix_sort(std::vector<T> &arr){
    T max_num = *(std::max_element(arr.begin(),arr.end()));
    std::vector<std::queue<T>> bins(10);
    int d = no_of_digit(max_num);

    for(int i {0}; i<d; i++){
        int j;
        //inserting into bins
        for(j=0; j<arr.size(); j++){
            int index = (arr[j]/static_cast<int>(std::pow(10,i)))%10;
            bins[index].push(arr[j]);
        }

        j=0;
        //FIFO pop out from bins
        for(int k {0}; k<10; k++){
            while(!bins[k].empty()){
                arr[j++] = bins[k].front();
                bins[k].pop();
            }

        }
    }
}

int main(){
    std::vector<int> arr {11,13,13,6,2,3,7,2,6,9,4,5,10,3};
    display(arr);
    radix_sort(arr);
    display(arr);
}