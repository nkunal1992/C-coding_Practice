#include <bits/stdc++.h>
using namespace std;

/*
    Array may contain elements > 100
    use boolean array of size 100, mark true if present, then print false one
 */

void printMissing_0_to_99(int *a, int n){
    bool res[100];

    memset(res,false,sizeof(res));

    for(int i=0; i<n; i++)
        if(a[i] < 100)
            res[a[i]] = true;

    for(int i=0; i<100;i++){
        int start=-1,end=-1;
        if(res[i] == false)
            start = i;

        while(res[i] == false) i++;
        end = i-1;

        if(start !=-1 && end>start)
            cout<<start<<"-"<<end<<'\n';
        else if(start != -1)
            cout<<start<<'\n';
    }
}

int main(){
    int arr[] = {0,1,2,3,5,9,70,80,90,95};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMissing_0_to_99(arr,n);
}