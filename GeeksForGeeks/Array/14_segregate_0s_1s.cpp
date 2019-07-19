#include <bits/stdc++.h>
using namespace std;

/*
    1. Maintain two index. left = 0, right = n-1
    2. Do following while left < right
        a. keep incrementing index left while there are 0s at it
        b. keep decrementing index right while there are 1s at it.
        c. if left < right, swap them

    other approach: count 0s and put them in front, remaining places put 1
 */

void segregate_0s_1s(int *arr, int n){
    int left = 0, right = n-1;
    while(left < right){
        while(arr[left] == 0) left++;
        while(arr[right] == 1) right--;

        if(left < right)
            swap(arr[left], arr[right]);
    }

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {0,1,0,1,0,0,1,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregate_0s_1s(arr,n);

    return 0;
}