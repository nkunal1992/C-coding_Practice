#include <bits/stdc++.h>
using namespace std;

/*
    Given an array of distinct element, rearrange the elements of array in Zig-Zag fashion.
    Converted array should be in the form a<b>c<d>e<f

    Approach: use modified one pass of bubble sort
    Manintain a falg for representing which order(< or >) currently we need.
    if current two elements are not in that order then swap those.
 */

void ZigZag(int a[], int n){
    bool less = true; // true indicates <, false indicates > 
    for(int i=0; i<n-1; i++){
        if(less){
            if(a[i] > a[i+1])
                swap(a[i],a[i+1]);
        }
        else{
            if(a[i] < a[i+1])
                swap(a[i],a[i+1]);
        }
        less = !less; //flip
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<'\n';
}

int main(){
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    ZigZag(a,n);
}

