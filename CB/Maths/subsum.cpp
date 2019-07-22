#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> subset(vector<ll> A){
    ll n = A.size();
    vector<ll> ans;
    
    for(ll i=0; i<(1<<n); i++){
        ll num = i;
        ll j = 0,sum = 0;
        
        //extract set bit
        while(num > 0){
            if(num & 1){
                sum += A[j];
            }
            j++;
            num = num>>1;
        }
        ans.push_back(sum);
    }
    return ans;
}


int main(){
    vector<ll> A,B;
    ll n,a,b,data;
    cin>>n>>a>>b;
    cout<<"Enter "<<n<<" elements : ";
    ll n1 = n/2;
    ll n2 = n-n1;

    for(ll i=0; i<n1; i++){
        cin>>data;
        A.push_back(data);
    }
    for(ll i=0; i<n2; i++){
        cin>>data;
        B.push_back(data);
    }
    auto ss1 = subset(A);
    auto ss2 = subset(B);

    sort(ss2.begin(), ss2.end());

    ll ans = 0;
    for(ll i=0; i<ss1.size(); i++){
        ll low = a-ss1[i];
        ll high = b-ss1[i];

        auto it1 = lower_bound(ss2.begin(),ss2.end(),low);
        auto it2 = upper_bound(ss2.begin(),ss2.end(),high);

        int l = (it1-ss2.begin());
        int k = (it2-ss2.begin());

        ans += (k-l);
    }
    
    cout<<ans<<endl;
}