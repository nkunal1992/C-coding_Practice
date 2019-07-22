#include <bits/stdc++.h>
using namespace std;

int nCrModpDP(int n, int r, int p) 
{ 
    // The array C is going to store last row of pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 

int nCrModPLucas(int n, int r, int p){
    if(r == 0)
        return 1;
    
    int ni = n%p;
    int ri = r%p;

    return nCrModPLucas(n/p,r/p,p)*nCrModpDP(ni,ri,p)%p;
}

int main(){
    int n,r,p;
    cin>>n>>r>>p;
    cout<<nCrModPLucas(n,r,p)<<endl;
}