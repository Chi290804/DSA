#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Hàm tính tổng số lượng đồ thị có hướng phi chu trình chứa V đỉnh
int countDirectedCycles(int V) {
    int sum = 0;
    for (int k = 1; k <= V; k++) {
        sum += factorial(k);
    }
    return sum;
}

int main() {
    int V;
    cout << "Nhap so luong dinh V: ";
    cin >> V;

    int count = countDirectedCycles(V);
    cout << "Tong so luong do thi co huong phi chu trinh voi " << V << " dinh la: " << count << endl;

    return 0;
}