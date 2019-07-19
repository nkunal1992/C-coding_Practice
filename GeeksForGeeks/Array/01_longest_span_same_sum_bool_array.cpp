#include <bits/stdc++.h>
using namespace std;

int longestSpan(bool *a1, bool *a2, int n){
    int diff_array[2*n+1];
    memset(diff_array,-1, sizeof(diff_array));

    int prefix_Sum1 = 0, prefix_Sum2 = 0;
    int len = 0, max_len = 0;

    for(int i=0; i<n; i++){
        prefix_Sum1 += a1[i];
        prefix_Sum2 += a2[i];

        int curr_diff = prefix_Sum1 - prefix_Sum2;

        int diff_index = n+curr_diff;

        // if current difference b/w prefix sum is 0, means it is maximum length so far
        if(curr_diff == 0)
            max_len = i+1;
        //if diff_index seen first time(i.e diff_array[diff_index]=-1) update starting index of diff_array
        else if(diff_array[diff_index] == -1)
            diff_array[diff_index] = i; 
        else{
            len = i-diff_array[diff_index]; //calculate length
            if(len > max_len)
                max_len = len;
        }
    }

    return max_len;
}

int main(){
    bool a1[] = {0,1,0,1,1,1,1};
    bool a2[] = {1,1,1,1,1,0,1};

    int n = sizeof(a1)/sizeof(a1[0]);

    cout<<longestSpan(a1,a2,n)<<endl;

    return 0;
}