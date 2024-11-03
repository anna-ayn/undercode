#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n, k;
    cin >> n >> k;

    /// k = 2:  s = 001001....11111111111111
    /// patrones: 0, 001
    /// k = 3:  s = 0001000100011000100010001100010001000111...11111111111111
    /// patrones: 0, 0001, 000100010001

    // block[i] = {idx (indice final de un patron), cantidad de 1s hasta idx}
    vector<pair<long long, long long>> blocks;

    long long idx = 1, count = 0, nro_patron = 0;
    // cuando idx = 1, la cantidad de 1s es 0, ya que s[idx] = s[0] = '0'

    while (idx <= n && nro_patron <= k)
    {
        blocks.push_back({idx, count});
        idx = idx * k + 1;
        count = count * k + 1;
        nro_patron++;
    }

    long long ans = 0;
    long long finalIdx = blocks[blocks.size() - 1].first;
    // luego de finalIdex, se tiene que todos los s[i] = 1 para i > finalIdx
    if (finalIdx < n && nro_patron == k + 1)
    {
        // le sumo la cantidad de 1s consecutivos
        ans += n - finalIdx;
        // ahora falta chequear los unos que hay antes del finalIdex
        n = finalIdx;
    }

    // iterar desde el patron mas grande al mas pequeño
    for (long long i = blocks.size() - 1; i >= 0; i--)
    {
        long long d = n / blocks[i].first;
        ans += d * blocks[i].second;
        n = n % blocks[i].first;
    }

    cout << ans << endl;
    return 0;
}