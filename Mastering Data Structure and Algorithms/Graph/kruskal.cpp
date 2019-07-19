#include <bits/stdc++.h>
#define I INT_MAX

int find(const std::vector<int> &set, int u){
    int parent {u};
    while(set[parent] > 0)
        parent = set[parent];

    return parent;
}

void UNION(std::vector<int> &set, int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }
    else{
        set[v] += set[u];
        set[u] = v;
    }
}

void kruskal(const std::vector<std::vector<int>> &edge){
    int edge_0_max = *(std::max_element(edge[0].begin(), edge[0].end()));
    int edge_1_max = *(std::max_element(edge[1].begin(), edge[1].end()));

    int n = std::max(edge_0_max, edge_1_max); //no of vertices. start vertex is 1
    int e = edge[0].size(); //no of edges

    std::vector<int> set(n+1, -1); //since start vertex is 1, that's why n+1
    std::vector<bool> included(e, false);
    
    std::vector<std::vector<int>> result(3);
    result[0] = std::vector<int>(n-1); //we have to store n-1 edges
    result[1] = std::vector<int>(n-1);
    result[2] = std::vector<int>(n-1);

    int i {0}, u, v;
    //select n-1 edges
    while(i<(n-1)){
        int min {I}, min_index;

        //find min cost edge
        for(int j {0}; j<e; j++){
            if(!included[j] && edge[2][j] < min){
                min = edge[2][j];
                min_index = j;  //index of min edge
                u = edge[0][j]; //1st end point of min edge
                v = edge[1][j]; //2nd end point of min edge
            }
        }

        //include if there is no cycle
        if(find(set,u) != find(set,v)){
            result[0][i] = u;
            result[1][i] = v;
            result[2][i] = edge[2][min_index];
            UNION(set, find(set,u), find(set,v));
            i++;
        }

        included[min_index] = true;
    }

    //display spanning tree edges with cost
    for(int j=0; j<result[0].size(); j++){
        u = result[0][j];
        v = result[1][j];
        std::cout<<u<<"-->"<<v<<" : "<<result[2][j]<<"\n";
    }
}

int main(){
    //start vertex is 1
    std::vector<std::vector<int>> edge { {1,1,2,2,3,4,4,5,5},
                                         {2,6,3,7,4,5,7,6,7},
                                         {25,5,12,10,8,16,14,20,18}};
                                
    kruskal(edge);
}