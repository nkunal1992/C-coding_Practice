#include <bits/stdc++.h>
using namespace std;

#define mod 1000000000
typedef long long ll;
typedef vector< vector<long long> > vec2d;

//assuming given dimesion is character
vec2d multiply(vec2d a, vec2d b){
    ll k = a.size();
    vec2d c(k,vector<ll>(k));

    for(ll i=0; i<k; i++){
        for(ll j=0; j<k; j++){
            for(int p=0; p<k; p++)
                c[i][j] = (c[i][j]+(a[i][p]*b[p][j])%mod)%mod;
        }
    }
    return c;
}

vec2d pow(vec2d a, ll n){
    if(n == 1) return a;
    if(n&1) //odd
        return multiply(a,pow(a,n-1));
    else{
        vec2d res = pow(a,n/2);
        return multiply(res,res);
    }
}

//find nth sequence
ll solve(vector<ll> F1, vector<ll> coeff, ll n, ll k){
    if(n < k)
        return F1[n];

    vec2d T(k,vector<ll>(k));
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(i < k-1){ //except last row
                if(j == i+1)
                    T[i][j] = 1;
            }
            else{ //last row
                T[i][j] = coeff[k-j-1];
            }
        }
    }

    
    // ans = T^n-1 * F1
    vec2d  pow1= pow(T,n);

    ll ans = 0;
    for(int i=0; i<1;i++){
        for(int j=0; j<pow1.size();j++)
            ans += (pow1[i][j]*F1[j])%mod;
    }

    return ans%mod;
}

int main(){
    int test_case;
    cin>>test_case;

    while(test_case--){
        int k;
        cin>>k;
        vector<ll> b,c;
        ll data;
        for(int i=0; i<k; i++){
            cin>>data;
            b.push_back(data);
        }
        for(int i=0; i<k; i++){
            cin>>data;
            c.push_back(data);
        }
        int n;
        cin>>n;
        cout<<solve(b,c,n-1,k)<<endl;
    }
}