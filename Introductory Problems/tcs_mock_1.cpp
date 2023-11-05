#include <bits/stdc++.h>
using namespace std;
int minClicks = INT_MAX;

void dfs(int src, vector<vector<int>> &graph, int dest, vector<bool> &visited, int clicks)
{
    if (src == dest)
    {
        minClicks = min(minClicks, clicks);
        return;
    }

    visited[src] = true;
    for (int neighbor : graph[src])
    {
        if (!visited[neighbor])
            dfs(neighbor, graph, dest, visited, clicks + 1);
    }
    visited[src] = false;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; i++)
    {
        string connections;
        getline(cin, connections);
        istringstream iss(connections);
        int v;
        while (iss >> v)
        {
            graph[i].push_back(v);
        }
    }

    string sourceDest;
    getline(cin, sourceDest);
    int source = stoi(sourceDest.substr(0, sourceDest.find(' ')));
    int dest = stoi(sourceDest.substr(sourceDest.find(' ') + 1));
    vector<bool> visited(n + 1, false);
    dfs(source, graph, dest, visited, 0);

    if (minClicks != INT_MAX)
        cout << minClicks << endl;
    else
        cout << -1 << endl;

    return 0;
}
