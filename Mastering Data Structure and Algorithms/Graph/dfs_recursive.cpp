#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &A, int source){
    static std::vector<int> visited(A.size());
    //for reseting visited vector to zero for new start vertex
    if (std::all_of(visited.begin()+1, visited.end(), [](int i){ return i == 1; })){
        std::fill(visited.begin(),visited.end(), 0);
    }

    if(visited[source]==0){
        std::cout<<source<<" ";
        visited[source] = 1;
        for(int v=1; v<A.size(); v++){
            if(A[source][v] == 1 && visited[v] == 0)
                dfs(A,v);
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