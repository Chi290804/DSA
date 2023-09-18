#include <bits/stdc++.h>
using namespace std;

int Max(int a[], int n){
    int max = a[0];
    for ( int i=0 ; i<n ; i++){
        if ( a[i] > max) max = a[i];
    }
    return max;
}

void FindPair(int a[], int n){
    int m = Max(a,n) , t=0;
    int b[m+1];
    for ( int i=0 ; i<m+1 ; i++){
        b[i] = 0;
    }
    for ( int i=0 ; i<n ; i++){
        b[a[i]] ++;
    }
    for ( int i=0 ; i<m+1 ; i++){
        if (b[i] > 0){
            if ( b[i] %2 == 0 ) t+=b[i];
            else t = t+ b[i]-1;
        }
    }
    cout << t;
}

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i=0 ;i<n;i++){
        cin >>a[i];
    }
    FindPair(a,n);
}