#include <bits/stdc++.h>

void bfs(const std::vector<std::vector<int>> &A, int source){
    std::vector<int> visited(A.size()+1);
    std::queue<int> q; //will push index of element
    std::cout<<source<<" ";
    visited[source] = 1;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v {1}; v<A.size(); v++){
            if(A[u][v] == 1 && visited[v] == 0){
                std::cout<<v<<" ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<std::vector<int>> A {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    for(int i=1; i<7; i++){
        std::cout<<"\nBFS for source vertex "<<i<<" : ";
        bfs(A,i);
    }
}