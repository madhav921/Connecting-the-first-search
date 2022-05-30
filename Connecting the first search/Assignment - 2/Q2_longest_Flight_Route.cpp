#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

const int N = 5;
bool vis[N];
vector<int> adj[N + 1];

void dfs(int u, int val = 0)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (v != val && !vis[v])
            dfs(v, u);
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> deg(n + 1), dist(n + 1, -1), ans, path(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        deg[y]++;
    }
    dfs(1);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!deg[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] != -1 && dist[v] < dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                path[v] = u;
            }
            deg[v]--;
            if (!deg[v])
                q.push(v);
        }
    }
    int longest_path = dist[n] - dist[1] + 1;
    cout << longest_path << endl;
    for (int i = 0, v = n; i < longest_path; i++)
    {
        ans.push_back(v);
        v = path[v];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}