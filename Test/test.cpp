#include <iostream>
using namespace std;

int merge(int *a, int s, int m, int e){
    int i=s, j=m+1, ans=0,k=0;
    int *b = new int[e-s+1]; 

    while(i<=m && j<=e){
        if(a[i] > a[j]){
            ans += (m-i+1);
            b[k++] = a[j++];
        }
        else{
            b[k++] = a[i++];
        }
    }
    for(; i<=m; i++) b[k++] = a[i];
    for(; j<=e; j++) b[k++] = a[j];
    k=0;
    for(int i=s; i<=e; i++){
        a[i] = b[k++];    
    }

    return ans;
}

int merge_sort(int *a, int s, int e){
    //base case
    if(s>=e) return 0;

    int mid = (s+e)/2;
    return merge_sort(a,s,mid) + merge_sort(a,mid+1,e) + merge(a,s,mid, e);
}
int main() {

    int a[] = {4,6,1,2,7,3};
    cout<<merge_sort(a,0,5)<<endl;
}




/* 
#include <bits/stdc++.h>
#define MAX std::numeric_limit<T>::max()

bool is_dec(int j,std::vector<int> &A){
    int len = static_cast<int>(A.size());
    for(int i=j; i<len-1; i++){
        if(A[i] < A[i+1]) return false;
    }
    return true;
}
int next_greatest(int key,int j, std::vector<int> &A){
    int len = static_cast<int>(A.size());
    int t;
    for(int i=j; i<len; i++){
        if(A[i] > key) t = i;
    }
    return t;
}

void next_permute(std::vector<int> &A){
    //std::unordered_set<int> s(A.begin(), A.end());
    int len = static_cast<int>(A.size()), flag = -1;
    for(int i=0; i<len-1; i++){
        if(A[i] < A[i+1]){
            flag = 1;
            break;
        }
    }
    if(flag == -1){
        //means last permutation
        std::sort(A.begin(), A.end());
        return;
    }
    for(int i=0; i<A.size()-1; i++){
        //s.remove(A[i]);
        bool f = is_dec(i+1,A);
        if(f){
            int it = next_greatest(A[i],i+1,A);
            std::swap(A[it],A[i]);
            if(is_dec(i+1,A))
                std::reverse(A.begin()+i+1,A.end());
            break;
        }
    }
}

int ArrayMaxProd(std::vector<int> A){
    long long res = 0ll;
    int leftSpecial = 0, rightSpecial = 0;
    
    for(int i=0; i<A.size(); i++){
        leftSpecial = 0;
        rightSpecial = 0;
        int lcurrent = i-1, rcurrent = i+1, lmax = i, rmin = i, flag = 0, vmax = -1, vmin = A.size();
        while(lcurrent >= 0){
            if(A[lcurrent] > A[i]){
                if(vmax < lcurrent){
                    lmax = lcurrent;
                    vmax = lmax;
                    flag = 1;
                }
            }
            lcurrent--;
        }
        if(flag == 0){
            leftSpecial = 0;
        }
        else{
            leftSpecial = lmax;
        }
        //std::cout<<"left : "<<leftSpecial<<'\n';
        flag = 0;
        while(rcurrent <A.size()){
            if(A[rcurrent] > A[i]){
                // std::cout<<A[rcurrent]<<"\n";
                // std::cout<<rcurrent<<"\n";
                if(vmin > rcurrent){
                    rmin = rcurrent;
                    vmin = rmin;
                    flag = 1;
                }
            }
            rcurrent++;
        }
        if(flag == 0){
            rightSpecial = 0;
        }
        else{
            rightSpecial = rmin;
        }
        
        //std::cout<<"\nright : "<<rightSpecial<<'\n';
        if(res < (long long)(leftSpecial*rightSpecial))
            res = (long long)(leftSpecial*rightSpecial);
            
        // std::cout<<"res : "<<res<<'\n';
    }
    return (int)res;
}

int main(){
    // std::cout<<std::log2(64)<<std::endl;
    // std::cout<<std::log10(64)<<std::endl;
    // std::cout<<std::log(2.71829)<<std::endl; //natural log
    // std::cout<<std::fabs(-98.99)<<std::endl;
    // std::cout<<std::ceil(-98.99)<<std::endl;

    // std::map<int, int> dict {std::make_pair(1,11)};
    // std::cout<<dict[1]<<"\n";

    // int id {0};
    // std::cout<<typeid(id).name()<<"\n";
    // std::string A {"NaraN"};
    // auto x = [](std::string A){int i=0,j=A.size()-1; while(i<=j){if(A[i]!=A[j]){return false;}i++;j--;}return true;};
    // std::cout<<x(A)<<'\n';
    std::vector<int> A ={5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};
    // next_permute(A);
    // for(auto i:A) std::cout<<i<<" ";
    // std::cout<<'\n';
    ArrayMaxProd(A);
}
*/