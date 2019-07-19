#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &A, int source){
    std::vector<int> visited(A.size());
    std::stack<int> s;

    s.push(source);

    while(!s.empty()){
        int u = s.top();
        s.pop();

        if(visited[u] == 0){
            visited[u] = 1;
            std::cout<<u<<" ";
        }

        for(int v=1; v<A.size(); v++){
            if(A[u][v] == 1 && visited[v] == 0)
                s.push(v);
        }
    }
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
        dfs(A,i);
        std::cout<<std::endl;
    }
}