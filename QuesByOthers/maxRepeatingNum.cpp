#include<bits/stdc++.h>

void find_max_repeating_num(int *arr, int n){
    int m = arr[0];
    for(int i=1; i<n;i++)
        if(arr[i]>m)
            m=arr[i];

    int k = m+1;

    for(int i=0; i<n; i++){
        int temp = arr[i]%k;
        arr[temp] = arr[temp]+k;
    }

    m = 0;

    for(int i=1; i<n;i++)
        if(arr[i]>arr[m])
            m=i;

    std::cout<<"\nMax repeating num is : "<<m<<std::endl;
}

int main(){
    int a[] {1,2,3,3,2,5,3},t=0;
    find_max_repeating_num(a,7);
}