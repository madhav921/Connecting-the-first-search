#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adj; // Graph represented as adjacency list
    int n;                   // number of nodes in graph

    vector<int> time_in, time_out, color, low;
    vector<bool> visited;

    Graph(vector<vector<int>> adjacent, int nodes)
    {
        adj = adjacent;
        n = nodes;

        time_in = vector<int>(n);
        time_out = vector<int>(n);
        color = vector<int>(n);
        visited = vector<bool>(n);
        low = vector<int>(n);
    }

    // DFS with timer and vertex color

    void dfs(int v, vector<int> &time_in, vector<int> &time_out, vector<bool> &visited)
    {
        static int dfs_timer = 0;
        time_in[v] = dfs_timer++;
        color[v] = 1;
        for (int u : adj[v])
            if (color[u] == 0)
                dfs(u);
        color[v] = 2;
        time_out[v] = dfs_timer++;
    }

    // Identify Tree or Back Edge in the graph

    void identify_edge(int u, int v)
    {
        vector<int> time_in(n),time_out(n);
        vector<bool> visited(n);
        dfs(u,time_int, time_out, visited);
        if (time_in[v] - time_in[u] == 1)
        {
            cout << "Tree Edge";
        }
        else if (time_in[v] < time_in[u] && time_out[v] > time_out[u])
        {
            cout << "Back Edge";
        }
    }


    // BFS Algorithm - calculate distance and print path

    vector<int> bfs(int s)
    {
        queue<int> q;
        vector<bool> used(n);
        vector<int> d(n, -1), p(n);
        used[s] = true;
        p[s] = -1;
        d[s] = 0;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : adj[v])
            {
                if (!used[u])
                {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }

        // print path from source vertex s to vertex u

        if (!used[u])
        {
            cout << "No path!";
        }
        else
        {
            vector<int> path;
            for (int v = u; v != -1; v = p[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int v : path)
                cout << v << " ";
        }
        cout<<endl;
        return d;
    }
    

    // Find connected components and give them unique id

    void fin_comps_dfs(int v, vector<bool> &visited, int id, vector<int> &comp_id)
    {
        visited[v] = true;
        comp_id.push_back(make_pair(cc, id));
        cout << id << ":" << v << "";
        for (int u : adj[v])
        {
            if (!visited[u])
                fin_comps_dfs(u, visited, id);
        }
    }

    vector<int> find_comps()
    {
        int cc = 0;
        vector<bool> visited(n, false);
        vector<pair<int, int>> comp_id(n);
        for (int v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                fin_comps_dfs(v, visited, cc, comp_id);
                cc++;
                cout << "\n";
            }
        }
        sort(com_id.begin(), comp_id.end());
        return comp_id;
    }


    // check if graphs contains a cycle

    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v] = true;
        for (i : adj[v])
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, v))
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }

    bool isCyclic()
    {
        vector<bool> visited(n, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
                if (isCyclicUtil(u, visited, -1))
                    return true;
        }
        return false;
    }


    // Find bridges in the graph and list them.

    void modified_dfs(int v, int p, vector<pair<int, int>> &bridges)
    {
        static int dfs_timer = 0;
        visited[v] = true;
        time_in[v] = low[v] = dfs_timer++;
        for (int u : adj[v])
        {
            if (u == p)
                continue;
            if (visited[u])
            {
                low[v] = min(low[v], time_in[u]);
            }
            else
            {
                modified_dfs(u, v, bridges);
                low[v] = min(low[v], low[u]);
                if (low[u] > time_in[v])
                    bridges.push_back({v, u});
            }
        }
    }

    void find_bridges()
    {
        vector<pair<int, int>> bridges;
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                modified_dfs(i, -1, bridges);
            }
        }

        for (pair<int, int> t : bridges)
        {
            cout << t.first << " " << t.second << endl;
            cout << t.second << " " << t.first << endl;
        }
    }
};