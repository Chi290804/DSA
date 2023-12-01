#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int resemble(string s)
{
    int len = 0;
    int n = s.length();
    int lps[n];
    lps[0] = 0;
    int i = 1, k = 0;
    for (int i = 1; i < n; i++)
    {
        if ( s[i] == lps[i-1])
        {
            len++;
            k++;
        }
        else if (k == 0)
        {
            lps[i] = 0;
        }
        else
        {

            continue;
        }
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        string s;
        cin >> s;
        cout << resemble(s) << endl;
        n--;
    }
}
