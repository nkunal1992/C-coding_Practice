#include <bits/stdc++.h>
using namespace std;

/*
    Consider an array with n items and value of all item is zero. We can perform following
    operations on the array.
        1. Increment : Choose 1 element from the array and increments it's value by 1
        2. Doubling : Double the values of all elements of array

    We are given desired array target[] containing n elements. Compute and return the smallest
    possible no of operations needed to change the array from all zeros to desired array.

    Approach:
    change target to zero
    1. Take target array first, inititalize ans = 0
    2. If all are even, divide all by 2 and ans++
    3. Find all odd elements, make them even by reducing by 1. for every reduction,
        increment ans by 1
    4. Finally we get all zeros in target array.
 */

 int countMinOp(int target[], int n){
     int ans = 0;
     while(1){
        int zero_count = 0, i;
        for(i=0; i<n; i++){
            if(target[i] & 1)//odd
                break;
            else if(target[i] == 0)
                zero_count++;
        }
        if(zero_count == n)
            return ans;
        if(i==n){ // all are even
            for(int j=0;j<n; j++)
                target[j] /= 2;
            ans++;
        }
        else{
            for(int j=i; j<n; j++){
                if(target[j] & 1){
                    target[j] -= 1;
                    ans++;
                }
            }
        }
     }

     return ans;
 }

 int main(){
     int arr[] = {16,16,16};
     int n = sizeof(arr)/sizeof(arr[0]);

     cout<<countMinOp(arr,n)<<endl;
 }
