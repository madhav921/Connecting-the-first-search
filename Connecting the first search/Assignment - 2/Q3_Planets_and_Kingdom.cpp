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
vector<int> adj[N + 1],adjR[N+1],top_order,comp;

void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs1(v);
    top_order.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    comp.push_back(u);
    for(int v : adjR[u])
        if(!vis[v])
            dfs2(v);
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> comp_index(n+1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs1(i);
    
    int comp_val = 0;
    fill(vis+1, vis+n+1, false);
    reverse(top_order.begin(), top_order.end());
    for(int u : top_order){
        if(!vis[u]){
            dfs2(u);
            comp_val++;
            for(int v : comp)
                comp_index[v] = comp_val;
            comp.clear();
        }
    }
    cout<<comp_val<<endl;
    for(int i=1 ; i<=n ; i++) cout<<comp_index[i]<<" ";
    cout<<endl;
    return 0;
}