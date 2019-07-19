#include <bits/stdc++.h>

typedef struct array{
    int *A;
    int size {0};
    int length {0};
}Array;

void display(const Array *arr){
    std::cout<<"[ "; 
    for(int i {0}; i<arr->length; i++)
        std::cout<<arr->A[i]<<" ";
    std::cout<<"]\n";
}

Array* Union(Array &arr1, Array &arr2){
    Array *arr3 = new Array;
    arr3->A = new int[arr1.length+arr2.length];
    int i {0}, j {0}, k {0};
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];
        else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    for(;i<arr1.length;i++)
        arr3->A[k++] = arr1.A[i];

    for(;j<arr2.length;j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = arr1.length+arr2.length;
    return arr3;
}

Array* Intersection(Array &arr1, Array &arr2){
    Array *arr3 = new Array;
    int size = (arr1.length > arr2.length) ? arr1.length : arr2.length;
    arr3->A = new int[size];
    int i {0}, j {0}, k {0};
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = size;
    return arr3;
}

Array* Difference(Array &arr1, Array &arr2){
    Array *arr3 = new Array;
    arr3->A = new int[arr1.length];
    int i {0}, j {0}, k {0};
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1.length;i++)
        arr3->A[k++] = arr1.A[i];

    arr3->length = k;
    arr3->size = arr1.length;
    return arr3;
}

int main(){
    int size {20}, length {5};
    Array arr1,arr2;
    arr1.A = new int [size];
    arr2.A = new int [size];
    std::cout<<"Enter 5 element of array1 : ";
    for(int i {0}; i<length; i++)
        std::cin>>arr1.A[i];
    arr1.length = length;

    std::cout<<"Enter 5 element of array2 : ";
    for(int i {0}; i<length; i++)
        std::cin>>arr2.A[i];
    arr2.length = length;
    std::cout<<"Elements of array 1 : ";
    display(&arr1);
    std::cout<<"Elements of array 2 : ";
    display(&arr2);

    Array *arr3 = Union(arr1,arr2);
    std::cout<<"Union of array 1 and array 2 : ";
    display(arr3);

    arr3 = Intersection(arr1,arr2);
    std::cout<<"Intersection of array 1 and array 2 : ";
    display(arr3);

    arr3 = Difference(arr1,arr2);
    std::cout<<"Difference of array 1 and array 2 : ";
    display(arr3);
}