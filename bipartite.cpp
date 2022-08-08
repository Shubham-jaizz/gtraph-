
#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> &vis, vector<int> graph[], int ind)
{
    queue<int> q;
    q.push(ind);
    vis[ind] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : graph[node])
        {
            if (vis[it] == -1)
            {
                vis[it] = 1 - vis[node];
                q.push(it);
            }
            else if (vis[it] == vis[node])
            {
                return false;
            }
        }
    }

    return true;
}
// Driver Code
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1, -1);
    vector<int> graph[n + 1];
    bool check = false;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            if (isBipartite(vis, graph, i))
                check = true;
        }
    }
    if (check)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << vis[i] << " ";
    }

    return 0;
}
