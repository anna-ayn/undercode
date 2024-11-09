#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

// Calculate distance from start_node to every other node using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<pair<int, int>>> &adj, int start_node)
{
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start_node));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;

        for (const auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

// Dijkstra's algorithm with a skip_node parameter
vector<int> dijkstra2(const vector<vector<pair<int, int>>> &adj, int start_node, int skip_node)
{
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start_node));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;

        for (const auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (v == skip_node || visited[v])
                continue;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int p, g;
    cin >> p >> g;
    p--;
    g--;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> ans(n, 0);
    vector<int> dist_from_p = dijkstra(adj, p);
    for (int i = 0; i < n; i++)
    {
        if (dist_from_p[i] == 2 * dist_from_p[g])
        {
            ans[i] = 1;
        }
    }

    vector<int> dist_from_p_skip_g = dijkstra2(adj, p, g);

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (i == g)
            continue;
        if (ans[i] && dist_from_p_skip_g[i] > 2 * dist_from_p[g])
        {
            cout << i + 1 << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "*";
    }

    cout << endl;

    return 0;
}
