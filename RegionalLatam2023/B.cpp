#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    map<int, int> freq;
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    for (auto &p : freq)
    {
        if (p.second % 3 != 0)
        {
            cout << "Y" << endl;
            return 0;
        }
    }

    cout << "N" << endl;
    return 0;
}