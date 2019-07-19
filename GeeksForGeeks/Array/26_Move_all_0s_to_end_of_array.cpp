#include <bits/stdc++.h>
using namespace std;

/*
    Given an array of random numbers, push all 0s of array to the end of the array. The order of 
    all other elements should be same. Expected time: O(n), Space: O(1)

    Approach:
    Traverse array from left to right. Maintain count of non-zero element. count = 0
    - For every non-zero element a[i], put the element at a[count] and count++
    - After complete traversal, all non-zero elements have already been shifted to front abd
        count is set as index of first 0.
    - Now run a loop and set all element as zero from count to n-1.
 */

void push_zero_to_end(int a[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] != 0){
            a[count] = a[i];
            count++;
        }
    }
    for(int i=count; i<n; i++)
        a[i] = 0;

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int a[] = {5,10,0,7,0,81,6,0,0,4,2,1,0,0};
    int n = sizeof(a)/sizeof(a[0]);
    push_zero_to_end(a,n);
}