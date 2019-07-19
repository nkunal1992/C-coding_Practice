#include <bits/stdc++.h>

class UpperTri{
    int size;
    int *A;

public:
    UpperTri()
        : size {2}, A {new int [2*(2+1)/2]} {}
    UpperTri(int n)
        : size {n}, A {new int [n*(n+1)/2]} {}
    ~UpperTri(){
        delete [] A;
    }
    void set(int row, int column, int data);
    int get(int row, int column);
    void display();
    int rindex(int row, int column){ // get row major index for m[row][column]
        /*
            index of M[i][j] in RMO = n*i - i*(i-1)/2 + (j-i) where n*n is dimension
         */
        return size*row - row*(row-1)/2 + (column - row);
    }
    int cindex(int row, int column){ // get column major index for m[row][column]
        /*
            index of M[i][j] in CMO = j*(j+1)/2 + i 
         */
            return column*(column+1)/2+row;
    }
};

void UpperTri::set(int row, int column, int data){
    if( row > column || row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return;
    }
    if(row <= column)// index of m[i][j] = i*(i+1)/2 + j for row major
        A[cindex(row,column)] = data;
}

int UpperTri::get(int row, int column){
    if(row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return -1;
    }
    if(row <= column)
        return A[cindex(row,column)];
    else 
        return 0;
}

void UpperTri::display(){
    for(int i {0}; i<size; i++){
        for(int j{0}; j<size; j++){
            if(i<=j)
                std::cout<<A[cindex(i,j)]<<" ";
            else 
                std::cout<<"0 ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    UpperTri d = UpperTri(3);
    d.set(0,0,1);
    d.set(0,1,2);
    d.set(0,2,3);
    d.display();
}