#include <bits/stdc++.h>
#define I INT_MAX

template <class T>
void prims(const std::vector<std::vector<T>> &cost){
    
    std::vector<int> near(cost.size(),I);

    std::vector<std::vector<int>> result(2);
    result[0] = std::vector<int>(cost.size()-2);
    result[1] = std::vector<int>(cost.size()-2);

    int u,v,min {I};

    //find min cost edge
    for(int i=1; i<cost.size(); i++)
        for(int j=i; j<cost.size(); j++)
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i;
                v = j;
            }

    result[0][0] = u;
    result[1][0] = v;

    near[u] = near[v] = 0;

    //update near
    for(int i=1; i<cost.size(); i++)
        if(near[i]!=0){
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else 
                near[i] = v;
        }

    std::cout<<min<<" "<<u<<" "<<v<<" Hi\n";
    for(int i=1; i<cost.size()-2; i++){
        min = I;
        int k;
        //find next min cost edge from near vector
        for(int j=1; j<near.size(); j++)
            if(near[j]!=0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                k = j;
            }
        result[0][i] = k;
        result[1][i] = near[k];

        near[k] = 0;

        //update near vector
        for(int j=1; j<cost.size(); j++)
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
    }
    
    //display spanning tree edges with cost
    for(int j=0; j<result[0].size(); j++){
        u = result[0][j];
        v = result[1][j];
        std::cout<<u<<"-->"<<v<<" : "<<cost[u][v]<<"\n";
    }
}

int main(){
    std::vector<std::vector<int>> cost { {I,I,I,I,I,I,I,I},
                                         {I,I,25,I,I,I,5,I},
                                         {I,25,I,12,I,I,I,10},
                                         {I,I,12,I,8,I,I,I},
                                         {I,I,I,8,I,16,I,14},
                                         {I,I,I,I,16,I,20,18},
                                         {I,5,I,I,I,20,I,I},
                                         {I,I,10,I,14,18,I,I}};
                                
    prims(cost);
}