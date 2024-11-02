#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1)
        {
            cout << "1\n1\n";
            continue;
        }
        else if (k == 1 || k == n)
        {
            cout << -1 << endl;
            continue;
        }

        cout << 3 << endl;
        if (k % 2 == 0)
        {
            cout << 1 << " " << k << " " << k + 1 << endl;
        }
        else
        {
            cout << 1 << " " << k - 1 << " " << k + 2 << endl;
        }
    }
    return 0;
}