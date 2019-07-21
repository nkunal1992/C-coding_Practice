
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(a)/sizeof(a[0]);
    int num = count_if(a,a+n,[](int x){return x%2 != 0;});
    int b[num];
    auto it = remove_copy_if(a,a+n,b,[](int x){return x%2==0;}); //it will point to end of result
    n = sizeof(b)/sizeof(b[0]);
    for(auto i=0; i<n; i++) cout<<b[i]<<" ";
    cout<<endl;
}