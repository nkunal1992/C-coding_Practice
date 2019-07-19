#include <bits/stdc++.h>

class Diagonal{
    int size;
    int *A;

public:
    Diagonal()
        : size {2}, A {new int [2]} {}
    Diagonal(int n)
        : size {n}, A {new int [size]} {}
    ~Diagonal(){
        delete [] A;
    }
    void set(int row, int column, int data);
    int get(int row, int column);
    void display();
};

void Diagonal::set(int row, int column, int data){
    if( row != column || row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return;
    }
    if(row == column)
        A[row] = data;
}

int Diagonal::get(int row, int column){
    if(row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return -1;
    }
    if(row == column)
        return A[row];
    else 
        return 0;
}

void Diagonal::display(){
    for(int i {0}; i<size; i++){
        for(int j{0}; j<size; j++){
            if(i==j)
                std::cout<<A[i]<<" ";
            else 
                std::cout<<"0 ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    Diagonal d = Diagonal();
    // d.set(0,0,1);
    // d.set(1,1,2);
    d.display();
}