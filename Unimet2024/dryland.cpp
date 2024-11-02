
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++)
            arr[i][j] = s[j] - '0';
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                continue;

            int jj = j, minH = INT_MAX;
            while (jj < m && arr[i][jj] == 1)
            {
                int onesColumJJ = 0, ii = i;
                while (ii < n && arr[ii][jj] == 1)
                {
                    onesColumJJ++;
                    ii++;
                }
                minH = min(minH, onesColumJJ);
                ans = max(ans, minH * (jj + 1 - j));
                jj++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
