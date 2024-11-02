#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        int zeros = 0, ones = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                zeros++;
            else
                ones++;
        }

        cout << ones % 2 << " " << 2 * n - max(zeros, ones) << endl;
    }

    return 0;
}