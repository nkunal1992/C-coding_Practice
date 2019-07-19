#include <bits/stdc++.h>
using namespace std;

/*
    floor(x) : largest element in array smaller than x
    ceil(x) : smallest element in array greater than x

    Approach : use binary search
 */

int ceil(int *a, int n, int x){
    int start = 0, end = n-1, mid;

    while(start <= end){
        mid = (start + end)/2;

        if(x < a[start]) // first element itself is ceil
            return a[start];

        if(x > a[end]) //ceil doesn't exist 
            return -1;

        if(a[mid] == x) //element itself is ceil
            return a[mid];

        else if(x < a[mid]){ //ceil lies in left part
            if(mid-1 <= start && x >= a[mid-1])
                return a[mid];
            else
                end = mid-1;
        }
        else{ //ceil lies in right part
            if(mid+1 <= end && x < a[mid+1])
                return a[mid+1];
            else
                start = mid+1;
        }
    }
}

int floor(int *a, int n, int x){
    int start = 0, end = n-1, mid;

    while(start <= end){

        if(x < a[start]) return -1;
        if(x > a[end]) return a[end];

        mid = (start + end)/2;

        if(a[mid] == x)
            return a[mid];
        else if(x < a[mid]){ //floor lies in left side
            if(mid-1 >= start && x > a[mid-1])
                return a[mid-1];
            else
                end = mid-1;
        }
        else{// floor lies on right side
            if(mid+1 <= end && x <= a[mid+1])
                return a[mid];
            else
                start = mid+1;
        }
    }
}

int main(){
    int arr[] = {1,2,8,10,10,12,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<floor(arr,n,5)<<endl;
}