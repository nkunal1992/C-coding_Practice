#include <bits/stdc++.h>
using namespace std;

/*
    Traverse array from left to right
    if any of two num is found, mark that index as 0

    Keep traversing from prev+1 untill all element is traversed
        1. if any of two num is found
        2. compare with arr[prev]
        3. if it is same, update prev = current index
        4. if it is different then
            1. update min distance if required
            2. prev = current index
 */
int findMinDistance(int *arr, int n, int x, int y){
    int min_dist = INT_MAX, prev;

    for(int i=0; i<n; i++){
        if(arr[i] == x || arr[i] == y)
            prev = i;
            break;
    }

    for(int i=prev+1; i<n; i++){
        if(arr[i] == x || arr[i] == y){
            if(arr[i] != arr[prev]){
                if(i-prev < min_dist)
                    min_dist = i-prev;

                prev = i;
            }
            else 
                prev = i;
        }
    }
    return min_dist;
}

int main(){
    int arr[] = {3,5,4,2,6,5,6,6,5,4,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=3,y=6;

    cout<<findMinDistance(arr,n,x,y)<<endl;
}