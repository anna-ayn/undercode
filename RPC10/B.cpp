#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag[10] = {false};
    char c;
    int ans = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> c;
        if (c != '-')
        {
            int d = c - '0';
            if (!flag[d])
            {

                flag[d] = true;
                ans++;
            }
        }
    }
    cout << ans << endl;
}