#include <bits/stdc++.h>
using namespace std;

struct Object
{
    double weight;
    double profit;
};
int knapsack(int w, vector<Object> &o)
{
    int n = o.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (o[i - 1].weight <= j)
            {
                int k1 = dp[i - 1][j];
                int k2 = o[i - 1].profit + dp[i - 1][j - o[i - 1].weight];
                dp[i][j] = max(k1, k2);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
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