#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long L, H;
    cin >> L >> H;

    long long costs[3], quantity[3];

    for (int i = 0; i < 3; i++)
        cin >> costs[i];

    for (int i = 0; i < 3; i++)
        cin >> quantity[i];

    double ans = 0;

    vector<vector<vector<double>>> dp(quantity[0] + 1, vector<vector<double>>(quantity[1] + 1, vector<double>(quantity[2] + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i <= quantity[0]; i++)
    {
        for (int j = 0; j <= quantity[1]; j++)
        {
            for (int k = 0; k <= quantity[2]; k++)
            {
                long long current_cost = costs[0] * i + costs[1] * j + costs[2] * k;
                if (current_cost >= L && current_cost <= H)
                {
                    ans += dp[i][j][k];
                    continue;
                }

                if (current_cost > H)
                    continue;

                double current_cheaps_to_choose = quantity[0] - i, current_normal_to_choose = quantity[1] - j, current_expensive_to_choose = quantity[2] - k;
                double current_plants_total_to_choose = current_cheaps_to_choose + current_normal_to_choose + current_expensive_to_choose;

                // cada planta que queda de tipo x tiene una probabilidad de ser escogida 1/current_plants_total_to_choose
                if (current_cheaps_to_choose != 0)
                    dp[i + 1][j][k] += dp[i][j][k] * (current_cheaps_to_choose / (current_plants_total_to_choose));

                if (current_normal_to_choose != 0)
                    dp[i][j + 1][k] += dp[i][j][k] * (current_normal_to_choose / (current_plants_total_to_choose));

                if (current_expensive_to_choose != 0)
                    dp[i][j][k + 1] += dp[i][j][k] * (current_expensive_to_choose / (current_plants_total_to_choose));
            }
        }
    }

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}