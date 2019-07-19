#include <bits/stdc++.h>
using namespace std;

/*
    Given array of int, both -ve and +ve. You need to find the two elements such that
    their sum is closest to zero

    Approach: 
        sort the array, take two pointers, left = 0, right = n-1
        sum = a[left] + a[right]
        if sum is -ve, left++
        if sum is +ve, right--
        keep track of abs min sum
        repeat until left < right

    Time: O(nlogn)+O(n) = O(nlogn)
 */

void two_ele_sum_closest_to_zero(int a[], int n){
    sort(a,a+n);
    int left = 0, right = n-1;
    int abs_sum = INT_MAX, sum = 0, ele1,ele2;
    while(left < right){
        sum = a[left] + a[right];
        if(abs(sum) < abs_sum){
            abs_sum = abs(sum);
            ele1 = a[left];
            ele2 = a[right];
        }

        if(sum < 0) 
            left++;
        else if(sum > 0)
            right--;
        else // if sum becomes zero, break, no need to chek further
            break;
    }

    cout<<"Two element whose sum is closest to zero is "<<ele1<<" and "<<ele2<<'\n';
}

int main(){
    int a[] = {1,60,-10,70,10,-80,85};
    int n = sizeof(a)/sizeof(a[0]);
    two_ele_sum_closest_to_zero(a,n);

    return 0;
}