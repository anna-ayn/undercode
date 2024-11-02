
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
            arr[i][j] = s[j] - '0'; // convierto el caracter a entero
    }

    int ans = 0;

    // itero para cada elemento de la matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // ignorar si el elemento es 0
            if (arr[i][j] == 0)
                continue;

            // voy hacia la derecha mientras haya un 1
            int jj = j, minH = INT_MAX;
            while (jj < m && arr[i][jj] == 1)
            {
                // desde la fila i, cuento la cantidad de unos consecutivos que hay debajo de mi (en la misma columna jj)
                int onesColumJJ = 0, ii = i;
                while (ii < n && arr[ii][jj] == 1)
                {
                    onesColumJJ++;
                    ii++;
                }
                // para cada columna jj voy a actualizar el minimo de unos
                minH = min(minH, onesColumJJ);
                // actualizo la respuesta
                ans = max(ans, minH * (jj + 1 - j));
                jj++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
