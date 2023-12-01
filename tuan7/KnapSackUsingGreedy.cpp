#include <bits/stdc++.h>
using namespace std;

struct Object
{
    double weight;
    double profit;
};

bool compare(Object &a, Object &b)
{
    double _a = a.profit / a.weight;
    double _b = b.profit / b.weight;
    return _a > _b;
}

int knapsack(int w, vector<Object> &o)
{
    sort(o.begin(), o.end(), compare);
    int n = o.size();
    int totalProfit = 0;
    int totalWeight = 0;
    for (Object &a : o)
    {
        if (totalWeight + a.weight <= w)
        {
            totalProfit += a.profit;
            totalWeight += a.weight;
        }
        else
        {
            int remainingWeight = w - totalWeight;
            totalProfit += static_cast<double>(remainingWeight) / a.weight * a.profit;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int W = 10;
    vector<Object> o = {
        {2, 10},
        {3, 5},
        {5, 15},
        {7, 7},
        {1, 6}};

    int maxProfit = knapsack(W, o);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}