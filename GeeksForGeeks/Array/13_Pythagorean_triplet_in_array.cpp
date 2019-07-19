#include <bits/stdc++.h>
using namespace std;

/*
    Write a function that returns true if there is a triplet (a,b,c) that satisfies a^2+b^2 = c^2

    Approach:
        square each element of array --> O(n)
        sort modified array --> O(nlogn)
        Do the following:
        a. Fix 'a' as last element of sorted array
        b. Now search for pair(b,c) in sub array b/w first element and 'a'.
            It can be done in O(n) time
        c. if no pair found for cuurent 'a', then move 'a' one position back and
            repeat step b.
 */

bool doesPythagoreabTripleExist(int *arr, int n){
    //square each element
    for(int i=0; i<n; i++)
        arr[i] = arr[i]*arr[i];

    //sort
    sort(arr,arr+n);

    for(int i=n-1; i>=2; i--){
        int a = arr[i];
        int start = 0, end = i-1;
        while(start<end){
            if(arr[start] + arr[end] == arr[i])
                return true;
            else if(arr[start] + arr[end] > arr[i])
                end--;
            else 
                start++;
        }
    }
    return false;
}

int main(){
    int arr[] = {10,4,6,12,5}; //{3,1,4,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<boolalpha<<doesPythagoreabTripleExist(arr,n)<<endl;
}