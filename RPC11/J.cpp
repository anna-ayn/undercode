#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        ans = max(ans, A[i]);
    }

    if (M >= N)
    {
        cout << ans << endl;
        return 0;
    }

    sort(A.begin(), A.end());

    int i = N - M - 1;
    int j = N - M;

    while (i >= 0)
    {
        ans = max(ans, A[i] + A[j]);
        i--;
        j++;
    }
    cout << ans << endl;

    return 0;
}