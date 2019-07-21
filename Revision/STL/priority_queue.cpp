#include <bits/stdc++.h>
using namespace std;

int main(){
    //defaylt is max heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(7);

    cout<<pq.top()<<endl;

    //min heap
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(5);
    pq1.push(4);
    pq1.push(7);

    cout<<pq1.top()<<endl;
}