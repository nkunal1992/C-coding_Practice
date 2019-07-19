#include <bits/stdc++.h>
using namespace std;

/*
    Given an array A[0...n-1] consisting of n +ve integers, a subarray A[i...j] is bitonic
    if there is a k with i<=k<=j such that
        
        A[i] <= A[i+1]..<=A[k]>=A[k+1]>=..A[j-1]>=A[j]
    
    output: Max len of bitonic subarray
    Approach:
        1. Construct aux array inc[] from left to right such that inc[i] contains length
           of the nondecreasing subarray ending at arr[i].
           ex. for A[] = {12,4,78,90,45,23}, inc[] = {1,1,2,3,1,1}
        2. Construct another aux array dec[] from right to left such that dec[i] contains length
           of nonincreasing subarray starting at arr[i]
           ex. for A[] = {12,4,78,90,45,23}, dec[] = {2,1,1,3,2,1}
        3. Once we have the inc[] and dec[] arrays, all we need to do is find the maximum
           value of (inc[i]+dec[i]-1).

    Time: O(n), Space: O(n)
 */

void maxLenBitonicSubArray(int a[], int n){
    int inc[n],dec[n],count = 1;

    inc[0] = count;
    for(int i=1; i<n; i++){
        if(a[i] > a[i-1]){
            inc[i] = ++count;
        }
        else{
            inc[i] = 1;
            count = 1;
        }
    }

    count = 1;
    dec[n-1] = count;

    for(int i=n-2; i>=0; i--){
        if(a[i] > a[i+1]){
            dec[i] = ++count;
        }
        else{
            dec[i] = 1;
            count = 1;
        }
    }

    int max_len = 0, start, end;
    for(int i=0; i<n; i++){
        if(inc[i]+dec[i]-1 > max_len){
            max_len = inc[i]+dec[i]-1;
            start = i-(inc[i]-1);
            end = i+dec[i]-1;
        }
    }

    // for(int i=0; i<n;i++)
    //     cout<<inc[i]<<" ";
    // cout<<'\n';

    // for(int i=0; i<n;i++)
    //     cout<<dec[i]<<" ";
    // cout<<endl;
    
    cout<<"\nMaximum length of bitonic subarray is "<<max_len<<endl;
    cout<<"Subarray is : [";
    for(int i=start; i<=end; i++)
        cout<<a[i]<<" ";
    cout<<"]\n";
}

int main(){
    int a[] = {20,4,1,2,3,4,2,10}; //{12,4,78,90,45,23};
    int n = sizeof(a)/sizeof(a[0]);

    maxLenBitonicSubArray(a,n);

    return 0;
}