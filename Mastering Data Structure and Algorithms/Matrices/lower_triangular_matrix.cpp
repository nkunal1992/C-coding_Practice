#include <bits/stdc++.h>

class LowerTri{
    int size;
    int *A;

public:
    LowerTri()
        : size {2}, A {new int [2*(2+1)/2]} {}
    LowerTri(int n)
        : size {n}, A {new int [n*(n+1)/2]} {}
    ~LowerTri(){
        delete [] A;
    }
    void set(int row, int column, int data);
    int get(int row, int column);
    void display();
    int rindex(int row, int column){ // get row major index for m[row][column]
        /*
            index of M[i][j] in RMO = i*(i+1)/2 + j
         */
        return row*(row+1)/2+column;
    }
    int cindex(int row, int column){ // get column major index for m[row][column]
        /*
            index of M[i][j] in CMO = n*j - j*(j-1)/2 + (i-j) where n*n is dimension
         */
            return size*column-(column-1)*column/2+(row - column);
    }
};

void LowerTri::set(int row, int column, int data){
    if( row < column || row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return;
    }
    if(row >= column)// index of m[i][j] = i*(i+1)/2 + j for row major
        A[cindex(row,column)] = data;
}

int LowerTri::get(int row, int column){
    if(row >= size || column >= size){
        std::cout<<"Invalid position\n";
        return -1;
    }
    if(row >= column)
        return A[cindex(row,column)];
    else 
        return 0;
}

void LowerTri::display(){
    for(int i {0}; i<size; i++){
        for(int j{0}; j<size; j++){
            if(i>=j)
                std::cout<<A[cindex(i,j)]<<" ";
            else 
                std::cout<<"0 ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    LowerTri d = LowerTri(8);
    d.set(0,0,1);
    d.set(1,0,2);
    d.set(1,1,3);
    d.display();
}