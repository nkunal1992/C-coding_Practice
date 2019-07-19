#include <bits/stdc++.h>
using namespace std;

/* 
    An element is leader if it's greater than all elements to its right side.
    Rightmost element is always leader

    scan from right to left and keep track of maximum so far
*/

void printLeader(int *arr, int n){
    int leader = arr[n-1];
    cout<<leader<<" ";
    for(int i=n-2; i>=0; i--){
        if(arr[i] > leader){
            cout<<arr[i]<<" ";
            leader = arr[i];
        }
    }
    cout<<'\n';
}

int main(){
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeader(arr,n);

    return 0;
}