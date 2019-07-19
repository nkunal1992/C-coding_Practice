#include<bits/stdc++.h>

//find multiple duplicates in range 1 to n-1
void find_duplicate(int *arr, int n){
    std::set<int> s;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]>0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            s.insert(abs(arr[i]));
    }
    for(auto e:s)
    std::cout<<e<<" ";
    std::cout<<std::endl;
}

void find_duplicate1(int *arr, int n){
    int m = arr[0];
    for(int i=1; i<n;i++)
        if(arr[i]>m)
            m=arr[i];

    int k = m+1;

    for(int i=0; i<n; i++){
        int temp = arr[i]%k;
        arr[temp] = arr[temp]+k;
    }

    for(int i=0;i<n; i++)
        if(arr[i]>=(2*k))
            std::cout<<arr[i]<<std::endl;
}
int main(){
    int a[] {1,2,3,3,2,5,3},t=0;
    std::cout<<"duplicate elements are : ";
    find_duplicate1(a,7);
}