#include <bits/stdc++.h>

int main(){
    int a[] = {1,3,4,2,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    for(int i=0; i<n; i+=2){
        //check left element
        if(i>0 && (a[i-1] > a[i]))
            std::swap(a[i],a[i-1]);

        //check right element
        if(i<n-1 && (a[i+1] > a[i]))
            std::swap(a[i],a[i+1]); 
    }

    for(int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}