#include <bits/stdc++.h>

class Element{
public:
    int i;
    int j;
    int value;
};

class Sparse{
    int m; //row no
    int n; //column no
    int num; // No of non-zero element
    Element *ele;
public:
    Sparse(int row, int column, int n)
        : m {row}, n {column}, num {n}, ele {new Element [n]} {}
    ~Sparse(){
        delete [] ele;
    }
    void read(){
        std::cout<<"Enter non-zero elements(row,col,value) : ";
        for(int i {0}; i<num; i++)
            std::cin>>ele[i].i>>ele[i].j>>ele[i].value;
    }
    void display(){
        int k {0};
        for(int i {0}; i<m; i++){
            for(int j {0}; j<n; j++){
                if(ele[k].i == i && ele[k].j == j)
                    std::cout<<ele[k++].value<<" ";
                else 
                    std::cout<<"0 ";
            }
            std::cout<<'\n';
        }
    }
};

int main(){
    Sparse s1(5,5,5);
    s1.read();
    s1.display();
}