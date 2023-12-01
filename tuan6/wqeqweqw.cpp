#include <iostream>
#include <string>

using namespace std;

bool check(string t)
{
    int n = t.length();
    if (t.empty())
    {
        return true;
    }
    else
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (t[i] == '(' || t[i] == '[')
            {
                count++;
            }
            else if (t[i] == ')' || t[i] == ']')
            {
                count--;
            }

            if (count < 0)
            {
                return false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (t[i] == '(')
            {
                while (t[i] != ')')
                {
                    if (t[i] == '{' || t[i] == '}' || t[i] == '[' || t[i] == ']')
                        return false;
                    i++;
                }
            }

            else if (t[i] == '[')
            {
                while (t[i] != ']')
                {
                    if (t[i] == '{' || t[i] == '}')
                        return false;
                    i++;
                }
            }
            else
            {
                long count = 0;

                for (int i = 0; i < n; i++)
                {
                    if (t[i] == '(' || t[i] == '[')
                    {
                        count++;
                    }
                    else if (t[i] == ')' || t[i] == ']')
                    {
                        count--;
                    }

                    if (count < 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string t;
        cin >> t;
        if (check(t))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}