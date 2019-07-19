#include <bits/stdc++.h>
using namespace std;

/*
    The idea is to find the pivot point, divide the array in two sub-arrays and call binary search.
    For a sorted and rotated array, pivot element is the only element for which next element to it 
    is smaller than it.

    1) Find out pivot point and divide the array in two sub-array
    2) Now call binary search for one of the two sub-arrays
        a. if key is greater than 0th element, then search in left array
        b. else search in right sub-array
    3) If key is found in selected sub-array then return index else return -1.
 */

int findPivot(int a[], int low, int high){
    //base case
    if(high < low) return -1;
    if(low == high) return low;

    int mid = (low + high)/2;

    if(mid < high && a[mid] > a[mid+1])
        return mid;
    if(mid > low && a[mid-1] > a[mid])
        return mid-1;

    if(a[low] >= a[mid]) //pivot should be in left part
        return findPivot(a,low,mid-1);
    else
        return findPivot(a,mid+1,high);
}

int pivotedBinarySearch(int a[], int n, int key){
    int pivot = findPivot(a,0,n-1);

    //if pivot = -1 then array is not rotated at all
    if(pivot == -1){
        //return binary_search(a,0,n-1,key);
        auto it = lower_bound(a,a+n,key);
        return (it-&a[0]);
    }
    if(a[pivot] == key)
        return pivot;

    if(a[0] <= key){
        //search in left part i.e return binary_search(a,0,pivot-1,key)
        auto it = lower_bound(a,a+pivot,key);
        return (it-&a[0]);
    }
    else{
        auto it = lower_bound(a+pivot+1,a+n,key);
        return (it-&a[0]); //we should always substract &a[0] as we want index from start
    }
}

/*
    Improved approach: we can search key in one pass of binary serach
    1. Find middle point, mid = (low + high)/2
    2. if a[mid] == key, return mid
    3. Else if a[l...mid] is sorted ( if a[l] <= a[mid], a[l..mid] is sorted)
        a. if key lies in range a[l] to a[mid], recur for a[l..mid-1]
        b. Else recur for a[mid+1..h]
    4. Else if a[mid+1...r] is sorted
        a. if key lies in a[mid] to a[h], recur for a[mid+1..r]
        b. Else recur for a[l..mid]
 */

int improved_serach(int a[], int low, int high, int key){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(a[mid] == key) return mid;

    //if a[low..mid] is sorted
    if(a[low] <= a[mid]){
        if(key >= a[low] && key <= a[mid])
            return improved_serach(a,low,mid-1,key);
        else 
            return improved_serach(a,mid+1,high,key);
    }
    else{
        if(key >= a[mid] && key <= a[high])
            return improved_serach(a,mid+1, high,key);
        else 
            return improved_serach(a,low,mid-1,key);
    }
}

int main(){
    int a[] = {5,6,7,8,9,10,1,2,3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<pivotedBinarySearch(a,n,1)<<endl;
    cout<<improved_serach(a,0,n-1,1)<<endl;
}