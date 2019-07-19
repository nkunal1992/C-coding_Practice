#include <bits/stdc++.h>
using namespace std;

/*
    Given an array of integer, count no of sub arrays(of size more than one)
    that are strictly increasing

    Approach:
    1. Method_1
        if sub array arr[i:j] is not strictly increasing, then subarray arr[i:j+1], arr[i:j+2],..
        arr[i:n-1] cannot be strictly increasing;

        Time : O(n+m), where n = size of array, m = no of strictly increasing subarray

    2. Method_2
        Idea is based on fact that a sorted subarray of length 'len' adds
        len*(len-1)/2 to the result( in count of subarray).

        Time : O(n)
*/

int method1(int *a, int n){
    int lcount=0, count=0;
    for(int i=0; i<n; i++){
        lcount++;
        for(int j=i+1; j<n; j++){
            lcount++;
            if(a[j]>a[j-1])
                count++;
            else 
                break;
        }
    }
    //cout<<"Time complexity(count) : "<<lcount<<endl;
    return count;
}

int method2(int *a, int n){
    int count=0, len = 1;

    for(int i=0; i<n-1; i++){
        if(a[i+1] > a[i]){
            len++;
        }
        else{
            count += (len)*(len-1)/2;
            len = 1;
        }
    }
    if(len > 1)
        count += (len)*(len-1)/2;
    
    return count;
}

int main(){
    int arr[] = {10,20,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"\nNo of Strictly Increasing Sub array : "<<method2(arr,n)<<endl;
}