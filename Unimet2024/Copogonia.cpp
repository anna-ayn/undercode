
#include <bits/stdc++.h>

using namespace std;

double euclidean_distance(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main()
{
    // n = nro de ciudades
    // k = nro de rutas potenciales para agregar
    // m = distancia maxima entre dos ciudades que aceptan los ciudadanos para ser felices
    int n, k, m;
    cin >> n >> k >> m;

    // Leer las coordenadas de las ciudades (xi, yi)
    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }

    // vector de distancias entre cada par de puntos
    vector<vector<double>> distances;

    // para cada ciudad i
    for (int i = 0; i < n; i++)
    {
        vector<double> distances_i;
        // para cada ciudad j
        for (int j = 0; j < n; j++)
        {
            // calcular distancia euclidiana entre ciudades i y j
            distances_i.push_back(euclidean_distance(cities[i], cities[j]));
        }
        // agregar distances_i al vector de distances
        distances.push_back(distances_i);
    }

    // leer las rutas potenciales para agregar
    vector<pair<pair<int, int>, int>> k_edges; // cada elemento es de la forma <(ciudad1, ciudad2), costo>
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; // restar 1 para que las ciudades empiecen en 0
        v--; // restar 1 para que las ciudades empiecen en 0
        k_edges.push_back(make_pair(make_pair(u, v), w));
    }

    // inicializamos la respuesta en un valor muy grande
    int ans = INT_MAX;

    // Intentar con todas las combinaciones posibles de rutas potenciales para agregar
    // si bitbitmask = 000101, entonces se agregan la primera y tercera ruta potencial
    for (int bitmask = 1; bitmask < (1 << k); bitmask++)
    {
        vector<vector<double>> floyd_warshall(n, vector<double>(n, INT_MAX));

        // inicializar la matriz de distancias de Floyd-Warshall
        for (int i = 0; i < n; i++)
        {
            // se coloca la distancia de una ciudad a si misma (que es 0)
            floyd_warshall[i][i] = distances[i][i];
            // se coloca tambien la distancia de una ciudad a sus dos vecinos adyacentes, ya que ellas estan conectadas
            // desde un principio
            floyd_warshall[i][(i + 1) % n] = distances[i][(i + 1) % n];
            floyd_warshall[(i + 1) % n][i] = distances[(i + 1) % n][i];
        }

        // agregar las rutas potenciales segun el bitmask actual
        int cost = 0;
        for (int i = 0; i < k; i++)
        {
            if (bitmask & (1 << i))
            {
                // agregar la ruta
                int u = k_edges[i].first.first;
                int v = k_edges[i].first.second;
                int w = k_edges[i].second;
                floyd_warshall[u][v] = distances[u][v];
                floyd_warshall[v][u] = distances[v][u];
                cost += w;
            }
        }

        // aplicar el algoritmo de Floyd-Warshall
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if ((floyd_warshall[i][k] != INT_MAX && floyd_warshall[k][j] != INT_MAX) && (floyd_warshall[i][j] > (floyd_warshall[i][k] + floyd_warshall[k][j])))
                        floyd_warshall[i][j] = floyd_warshall[i][k] + floyd_warshall[k][j];
                }

        // verificar si todas las distancias son menores o iguales a m
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (floyd_warshall[i][j] > m)
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }
        if (valid)
            ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}
