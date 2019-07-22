#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *a, int j, int n){
    if(n == 1)
        return;

    //one pass
    if(j == n-1)
        return bubble_sort(a,0,n-1); //if we don't put return, control will go to next line of code

    //recursive case
    if(a[j] > a[j+1])
        swap(a[j],a[j+1]);
    
    bubble_sort(a,j+1,n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {1,5,2,7,3,99,-87};
    int n = sizeof(a)/sizeof(a[0]);

    bubble_sort(a,0,n);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<'\n';

    return 0;
}