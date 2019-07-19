#include <bits/stdc++.h>
using namespace std;

/*
    An array element is peak if it is not smaller than it's neighbors
    we need to return any one peak element

    Approach: binary search (Divide and Conquer)
    1. if mid element is not smaller than both of its neighbor, then we return it.
    2. if mid element is smaller than it's left neigbor, then there is always a peak in left half
    3. if mid element is smaller than it's right, then peak is always in right.
 */

int findPeak(int *a, int n){
    int start = 0; int end = n-1, mid;

    while(start <= end){
        mid = (start + end)/2;

        if(mid == 0 || a[mid-1] < a[mid] && mid == n-1 || a[mid+1] < a[mid])
            return a[mid];
        else if(a[mid-1] > a[mid])
            end = mid-1;
        else 
            start = mid+1;
    }
    return -1;
}

int main(){
    int arr[] = {5,10,20,15}; //{10,20,15,2,23,90,67};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findPeak(arr,n)<<endl;
}