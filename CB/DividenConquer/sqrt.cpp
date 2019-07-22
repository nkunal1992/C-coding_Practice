#include <bits/stdc++.h>
using namespace std;

double sqrt(int num, int precision){
    int s = 1;
    int e = num/2;

    double ans = 0.0;

    while(s <= e){
        int mid = (s+e)/2;
        if(mid*mid == num){
            ans = mid;
            break;
        }

        if(mid*mid < num){
            ans = mid;
            s = mid+1;
        }
        else 
            e = mid-1;
    }

    double inc = 0.1;
    for(int i=1; i<=precision; i++){
        ans += inc;
        while(ans*ans < num)
            ans += inc;
        
        ans = ans-inc;
        inc = inc/10;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<setprecision(10)<<fixed<<sqrt(10,10)<<'\n';
}