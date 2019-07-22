#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValidConfig(ll *book, ll n, ll k, ll ans){
    ll student = 1;
    ll pages = 0;

    for(ll i=0; i<n; i++){
        if(pages+book[i] > ans){
            student++;
            pages = book[i];
            if(student > k){
                return false;
            }
        }
        else{
            pages += book[i];
        }
    }
    return true;
}

ll binarySearchBooks(ll *book, ll n, ll k){
    ll s = book[n-1];
    ll e = accumulate(book, book+n, 0);

    ll ans = 0;

    while(s <= e){
        ll mid = (s+e)/2;
        if(isValidConfig(book,n,k,mid)){
            ans = mid;
            e = mid-1; //search in left part as we have to minimize the no of pages
        }
        else{
            s = mid+1;
        }
    }

    return ans;
}

int main(){
    ll book [] = {10,20,30,40};
    ll n = sizeof(book)/sizeof(book[0]);
    ll k =2;

    cout<<binarySearchBooks(book,n,k)<<endl;
}