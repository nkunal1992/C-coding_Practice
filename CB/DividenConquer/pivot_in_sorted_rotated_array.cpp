#include <bits/stdc++.h>
using namespace std;

/*
    Pivot : it is the only element which is smaller than it's next element
 */

int findPivot(int *a, int n){
    int s = 0;
    int e = n-1;

    while(s <= e){
        int mid = (s+e)/2;

        if(mid < e and a[mid] > a[mid+1])
            return mid;

        if(mid > s and a[mid-1] > a[mid])
            return mid-1;
        // pivot element is always in unsorted part
        if(a[s] > a[mid]) //left part is un-sorted
            e = mid-1;
        else //right part is unsorted
            s = mid+1;
    }
    return -1;
}

int main(){
    int a[] = {4,5,6,8,9,10,1,2,3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<findPivot(a,n)<<endl;
}