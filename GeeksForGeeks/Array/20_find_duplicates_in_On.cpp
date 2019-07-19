#include <bits/stdc++.h>
using namespace std;

/*
    Given array of n elements which contains elements from 0 to n-1, with repetition allowed
    Find repeating elements in O(n) using only O(1) space
    
    traverse the list for i=0 to n-1
    {
        check for sign of A[abs(A[i])];
        if positive then
            make it negative
        else
            ith element is a repetition
    }
 */

void findDuplicates(int a[], int n){
    for(int i=0; i<n; i++){
        bool positive = a[abs(a[i])]>0?true:false;
        if(positive)
            a[abs(a[i])] = -a[abs(a[i])];
        else 
            cout<<abs(a[i])<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,1,3,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    findDuplicates(arr,n);
}