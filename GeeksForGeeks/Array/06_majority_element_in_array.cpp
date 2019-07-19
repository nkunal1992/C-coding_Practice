#include <bits/stdc++.h>
using namespace std;

/*
    A majority element in an array A[] of size n is an element that appers
    more than n/2 times ( and hence there is atmost one such element)

    Moore's voting algorithm
    1. Find candidate element
        i. assume 0th element as majority and count = 1
        ii. if next element is same as majority then count++
        iii. else count--
        iv. if count == 0
            a. majority element = ith element
            b. count = 1
        v. In the end we will have one majority/candidate element
    2. Just check if majority element is occuring more than n/2 times 
 */

int findCandidate(int *a, int n){
    int majority = a[0], count = 1;

    for(int i=1; i<n; i++){
        if(a[i] == majority) 
            count++;
        else 
            count--;

        if(count == 0){
            majority = a[i];
            count = 1;
        }
    }
    return majority;
}

int findMajority(int *a, int n){
    int candidate = findCandidate(a,n);
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] == candidate) 
            count++;
    }

    if(count > (n/2)) 
        return candidate;
    else 
        return -1;
}

int main(){
    int arr[] = {2,2,3,5,2,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = findMajority(arr,n);
    if(res == -1)
        cout<<"None\n";
    else 
        cout<<res<<'\n';

    return 0;
}