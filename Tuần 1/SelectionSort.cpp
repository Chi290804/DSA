#include<bits/stdc++.h>

using namespace std;

void SelectionSort ( int arr[], int n){
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
	min = i;
	for (j = i+1; j < n; j++)
	    if (arr[j] < arr[min])
		min = j;
        swap(arr[min], arr[i]);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for ( int i=0; i<n ; i++){
        cin >> a[i];
    }
    SelectionSort(a,n);
    printArray(a,n);
    return 0;
}