
#include <bits/stdc++.h>

using namespace std;
bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int N, vector < int > adj[]) {
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            // cout << i << endl;
            if (checkCycle(i, adj, vis, dfsVis)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int>graph[n + 1];
    bool check;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }

    check = isCyclic(n, graph);
    if (check) {
        cout << "yes" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
