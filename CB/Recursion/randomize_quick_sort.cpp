#include <bits/stdc++.h>
using namespace std;

// Worst case time for randomized quick sort : O(nlogn)

void shuffle(int *a, int s, int e){
    srand(time(NULL));
    for(int i=e; i>=s; i--){ //always start from end
        int j = rand()%(i+1);
        swap(a[j],a[i]);
    }
}

int partition(int *a, int s, int e){
    int i = s-1;
    int j = s;
    int pivot = a[e];

    for(;j<e; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);

    return i+1;
}

void quick_sort(int *a, int s, int e){
    if(s >= e) return;

    int p = partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);

    shuffle(a,0,n-1);
    quick_sort(a,0,n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<'\n';

    return 0;
}