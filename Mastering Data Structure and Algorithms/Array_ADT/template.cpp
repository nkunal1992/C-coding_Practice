#include <bits/stdc++.h>

template <class T>
class Array{

private:
    T *A;
    int size;
    int length;
public:
    Array(){
        size = 10;
        A = new T [size];
        length = 0;
    }
    Array(int size){
        this->size = size;
        A = new T [this->size];
        length = 0;
    }
    ~Array(){
        delete [] A;
    }
    void display();
    void input(int len);
    Array* Union(Array &arr2);
    Array* Intersection(Array &arr2);
    Array* Difference(Array &arr2);
};

template <class T>
void Array<T>::display(){
    std::cout<<"[ "; 
    for(int i {0}; i<length; i++)
        std::cout<<A[i]<<" ";
    std::cout<<"]\n";
}

template <class T>
void Array<T>::input(int len){
    std::cout<<"Enter "<<len<<" element of array : ";
    for(int i {0}; i<len && i<size; i++)
        std::cin>>A[i];
    length = len;
}

template <class T>
Array<T>* Array<T>::Union(Array &arr2){
    Array<T> *arr3 = new Array(length+arr2.length);
    int i {0}, j {0}, k {0};
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if(A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++] = A[i];

    for(;j<arr2.length;j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    
    return arr3;
}

template <class T>
Array<T>* Array<T>::Intersection(Array &arr2){
    int size = (length > arr2.length) ? length : arr2.length;
    Array<T> *arr3 = new Array(size);
    int i {0}, j {0}, k {0};

    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j])
            i++;
        else if(A[i] > arr2.A[j])
            j++;
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    
    return arr3;
}

template <class T>
Array<T>* Array<T>::Difference(Array &arr2){
    Array<T> *arr3 = new Array(length);
    int i {0}, j {0}, k {0};

    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if(A[i] > arr2.A[j])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    
    return arr3;
}

int main(){
    int size {20}, length {5};
    Array<std::string> arr1(size),arr2(size);

    arr1.input(length);
    arr2.input(length);

    std::cout<<"Elements of array 1 : ";
    arr1.display();
    std::cout<<"Elements of array 2 : ";
    arr2.display();

    Array<std::string> *arr3 = arr1.Union(arr2);
    std::cout<<"Union of array 1 and array 2 : ";
    arr3->display();

    arr3 = arr1.Intersection(arr2);
    std::cout<<"Intersection of array 1 and array 2 : ";
    arr3->display();

    arr3 = arr1.Difference(arr2);
    std::cout<<"Difference of array 1 and array 2 : ";
    arr3->display();
}