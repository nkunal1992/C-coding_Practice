#include <bits/stdc++.h>
using namespace std;

/*
    given: two array, one array is duplicate of other with 1 missing element
    output: find lost/missing element in any of the array

    Approach
    1. Use xor or both array element : O(n)
    2. use binary search --> will work only if elements are sorted
        1. Start binary search in bigger array and set mid = (low+high)/2
        2. if value from both array is same at mid then missing element must be in right part
            so set low = mid
        3. else set high = mid as missing item must be in left part of bigger array
        4. Special Case
            a. single element itself will be missing, if size of bigger array is 1
            b. if(a1[0] != a2[0]) then a1[0] is the missing element
 */

int findMissing(int a1[], int a2[], int m, int n){
    int start = 0,end = m-1;

    if(m == 1) return a1[0];
    if(a1[0] != a2[0]) return a1[0];

    while(start < end){
        int mid = (start + end)/2;

        if(a1[mid] == a2[mid])
            start = mid;
        else 
            end = mid;

        if(start == end-1)
            break;
    }
    return a1[end];
}

int main(){
    int a1[] = {1,2,3,4,5};
    int a2[] = {1,2,4,5};

    int m = sizeof(a1)/sizeof(a1[0]);
    int n = sizeof(a2)/sizeof(a2[0]);

    if(m==n+1)
        cout<<findMissing(a1,a2,m,n)<<endl;
    else if(n==m+1) 
        cout<<findMissing(a2,a1,n,m)<<endl;
    else
        cout<<"Invalid Input\n";
}