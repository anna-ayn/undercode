#include <bits/stdc++.h>

using namespace std;

int main()
{
    // n = number of comedy acts, c = number of clues
    int n, c;
    cin >> n >> c;

    // after[i][j] = 1 si i va después de j, en caso contrario, adj[i][j] = 0
    // adj[i][j] = 1 si i y j son adyacentes, en caso contrario, adj[i][j] = 0

    // inicializamos las matrices en 1s
    vector<vector<int>> after(n + 1, vector<int>(n + 1, 1));
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1));

    // leemos los clues
    for (int i = 0; i < c; i++)
    {
        int a;
        char x, y;
        cin >> a >> x >> y;
        x -= 'A';
        y -= 'A';

        switch (a)
        {
        case 1:              // after
            after[y][x] = 0; // si x va después de y, entonces y no va después de x
            break;
        case 2:              // before
            after[x][y] = 0; // si x va antes de y, entonces x no va después de y
            break;
        case 3:            // not
            adj[x][y] = 0; // ni x ni y son adyacentes
            adj[y][x] = 0;
            break;
        default:
            break;
        }
    }

    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(1 << (n + 1)));
    dp[n][1 << n] = 1; // caso base, solo existe una manera de tener ningun acto realizado

    // bitmask para todos los subconjuntos de 0 a n-1, donde cada bit i
    // representa si el acto i fue realizado o no
    int bitmask = (1 << n) + 1; // comienzo con al menos 1 acto en el bitmask

    // itero para cada posible combinacion posible
    // ejemplo: bitmask = 010011, significa que los actos 1, 2, y 5 ya fueron realizados
    for (int i = bitmask; i < (1 << (n + 1)); i++)
    {
        // supongamos que lastAct fue el ultimo acto realizado
        for (int lastAct = 0; lastAct < n; lastAct++)
        {
            // ignoro si el lastAct no fue realizado
            if (!((i >> lastAct) & 1))
                continue;

            bool flag = true;
            // Ahora si existe un acto no realizado donde lastAct no puede ir despues de el (o sea
            // lastAct va antes de el), entonces no considero esta combinacion
            // ya que consideramos que lastAct fue el ultimo acto realizado
            // Asi que, TODOS los actos que tienen que ir antes de lastAct deben estar en el bitmask
            for (int act3 = 0; act3 < n; act3++)
            {
                // lastAct NO va despues de Act3
                if (!((i >> act3) & 1) && !after[lastAct][act3])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;

            // supongamos que secondLastAct fue el penultimo acto realizado
            for (int secondLastAct = 0; secondLastAct <= n; secondLastAct++)
            {
                // si lastAct y secondLastAct son iguales no los considero
                if (lastAct == secondLastAct)
                    continue;

                // si el acto NO fue realizado, no lo considero
                if (!((i >> secondLastAct) & 1))
                    continue;

                // si lastAct y secondLastAct no son adyacentes, no los considero
                // ya que estoy considerando que lastAct va despues de secondLastAct
                if (!adj[lastAct][secondLastAct])
                    continue;

                // actualizo la cantidad de maneras de realizar los actos cuando
                // el ultimo acto realizado fue LastAct sumandole la cantidad de maneras
                // de realizar los actos cuando el ultimo acto realizado fue secondLastAct
                dp[lastAct][i] += dp[secondLastAct][i ^ (1 << lastAct)];
            }
            // si todos los actos ya fueron realizados, entonces sumamos la cantidad de maneras
            // de realizar los actos cuando el ultimo acto realizado fue lastAct
            if (i == (1 << (n + 1)) - 1)
                ans += dp[lastAct][i];
        }
    }
    cout << ans << endl;

    return 0;
}
