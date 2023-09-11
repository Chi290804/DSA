#include<bits/stdc++.h>
using namespace std;
void Merge( int arr[] , int l, int m , int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for ( int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for ( int i = 0; i< n2; i++){
        R[i] = arr[m+1+i];
    }

    int k=l, i=0, j=0;
    while ( n1 !=i && n2 != j ){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
     while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
}
void MergeSort( int arr[], int l, int r){
    if ( r>l){
    int mid = l+(r-l)/2;
    MergeSort ( arr, l, mid);
    MergeSort (arr,mid + 1, r );
    Merge(arr,l,mid,r);
}}
int main(){
    int n;
    cin >> n;
    int a[n];
    for ( int i=0; i<n;i++){
        cin >> a[i];
    }
    MergeSort(a,0,n-1);
    for ( int i=0; i<n;i++){
        cout <<  a[i] <<" ";
    }
    return 0;
}