#include<bits/stdc++.h>
using namespace std;

void QuickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		QuickSort(a, i, r);
	}
	if (l < j){
		QuickSort(a, l, j);
	}
}

int main(){
    int n;
    cin >>n;
    int a[n];
    for ( int i=0 ; i<n;i++){
        cin >> a[i];
    }

    QuickSort( a,0,n-1);
    for ( auto it : a) cout << it << " ";
    return 0;
}