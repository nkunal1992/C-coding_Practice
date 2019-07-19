/*
#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1e9+7;
map<unsigned long long , unsigned long long > F;
unsigned long long fib(unsigned long long n){
    if(F.count(n)) return F[n];

    unsigned long long k = n/2;
    if(n%2 == 0)
        return F[n] = ((fib(k)*fib(k))%MOD+(fib(k-1)*fib(k-1))%MOD)%MOD;
    else 
        return F[n] = ((fib(k)*fib(k+1))%MOD+(fib(k-1)*fib(k))%MOD)%MOD;
}

int main(){
    unsigned long long  n = 92;
    F[0] = 1; F[1] = 1;
    fib(n-1); //it will find fib of n+1
    
    for(auto i:F){
        cout<<"F["<<i.first<<"] = "<<i.second<<'\n';
    }
    cout<<"count : "<<F.size()<<'\n';
}
*/
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const long M = 1000000007; // modulo

map<long, long> F;
vector<long> T[1234];

long f(long n, int Depth) {
	T[Depth].push_back(n);
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k, Depth+1)*f(k, Depth+1) + f(k-1, Depth+1)*f(k-1, Depth+1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k, Depth+1)*f(k+1, Depth+1) + f(k-1, Depth+1)*f(k, Depth+1)) % M;
	}
}

main(){
	long n;
	F[0]=F[1]=1;
	if (cin >> n) {
		if (n==0) 
			cout << 0 << endl;
		else 
			cout << f(n-1, 0) << endl;
	}
	for (int i=0; i<1234; i++) if (T[i].size()) {
		sort(T[i].begin(), T[i].end());
		T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());
		printf("Depth[%d] : ", i);
		for (int j=0; j<T[i].size(); j++) printf("%lld ", T[i][j]);
		printf("\n");
	}
}