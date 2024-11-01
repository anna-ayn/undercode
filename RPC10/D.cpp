
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // If k = 1, then k will win against all other players, so the maximum number of rounds k can play is n
    if (k == 1)
    {
        cout << n << endl;
        return 0;
    }

    // If k = 2**n, then k will lose against all other players, so the maximum number of rounds k can play is 1
    if (k == (1 << n))
    {
        cout << 1 << endl;
        return 0;
    }

    // if n = 4 and k = 13... there are 2**4 = 16 players
    // In any scenary, k will lose with number 1 to 12... so to maximize the number of rounds k can play,
    // we will pair k against the highest number possible.... 3 vs 16 -> 13 wins (round 1)
    // Now, there are 8 players left. Now, to pair k with 14 or 15, one of them must have won in the previous round
    // 15 couldnt have won because he can only win against 16, and 16 was paired out with 13.... so 14 won against 15 in the first round
    // Then, 14 vs 13 -> 13 wins (round 2)... and there is no more players with lower number than 13.
    // So, the maximum number of rounds k can play is 2

    int diff = (1 << n) - k + 1; // number of players that have lower or equal ranking than k

    int rounds = 0;
    while (diff)
    {
        diff /= 2; // Each player with a ranking lower or equal than k will be matched with another player with a ranking lower than k
        rounds++;
    }

    cout << rounds << endl;

    return 0;
}
