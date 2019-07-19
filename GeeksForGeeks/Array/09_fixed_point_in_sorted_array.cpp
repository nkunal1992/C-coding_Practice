#include <bits/stdc++.h>
using namespace std;

/*
    Given: Sorted array in ascending order
    Fixed Point in an array is an index i such that arr[i] = i
    if no fixed point return -1

    Approach: use binary search
 */

int findFixedPoint(int *a, int n){
    int start = 0, end = n-1, mid;

    while(start<=end){
        mid = (start+end)/2;
        if(a[mid] == mid)
            return mid;
        else if(a[mid] > mid)
            end = mid-1;
        else 
            start = mid+1;
    }
    return -1;
}

int main(){
    int arr[] = {0,2,5,8,17};//{-10,-5,0,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findFixedPoint(arr,n)<<endl;

    return 0;
}