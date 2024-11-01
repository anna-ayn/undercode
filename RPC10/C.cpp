#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<bool> inJava(n, false);
    vector<bool> inCpp(n, false);
    for (int i = 0; i < m; i++)
    {
        int p, L;
        cin >> p >> L;
        if (L == 1)
            inCpp[p - 1] = 1;
        if (L == 2)
            inJava[p - 1] = 1;
    }

    for (int i = 0; i < n; i++)
        if (inCpp[i] && inJava[i])
            cout << i + 1 << endl;
    return 0;
}