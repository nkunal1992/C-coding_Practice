#include <bits/stdc++.h>
using namespace std;

/*
    Intervals : {{1,3},{2,4},{5,7},{6,8}}
    Output: {{1,4},{5,8}}

    Approach:
    1. Sort interval based on increasing order of starting time.
    2. Push the first element to stack.
    2. For each interval do the following
        a. If the current interval does not overlap with stack top, push it.
        b. If overlaps, then update TOS endtime = ending time of current interval,
    3. At the end, stack contains the merged intervals.
 */

//takes extra space : stack size
void MergeOverlappingIntervals(vector<pair<int,int>> &a){
    sort(a.begin(), a.end());

    stack<pair<int,int>> s;
    s.push(a[0]);
    for(int i=1; i<a.size(); i++){
        auto top = s.top();
        //if no overlapping
        if(top.second < a[i].first)
            s.push(a[i]);
        else if(top.second > a[i].first){
            s.top().second = a[i].second;
        }
    }

    a.clear();
    while(!s.empty()){
        auto top = s.top();
        a.push_back(top);
        s.pop();
    }
    reverse(a.begin(), a.end()); //O(no of item in a)

    for(auto i:a)
        cout<<i.first<<" , "<<i.second<<endl;
}

/* It's wrong, check it later
void fun(vector<pair<int,int>> a){
    int id = 0;
    for(int i=0; i<a.size(); i++){
        if(id!=0 && a[i-1].second <= a[i].first){
            while(id != 0 && a[id-1].second <= a[i].first){
                a[id-1].second = max(a[id-1].second,a[i].second);
                a[id-1].first = min(a[id-1].first,a[i].first);
                id--;
            }
        }
        else 
            a[id] = a[i];
        id++;
    }
    for(int i=0; i<id;i++)
        cout<<a[i].first<<","<<a[i].second<<endl;
}
*/


int main(){
    vector<pair<int,int>> a = {{1,3},{2,4},{9,15},{5,7},{6,8}};
    MergeOverlappingIntervals(a);
    //fun(a);
}
