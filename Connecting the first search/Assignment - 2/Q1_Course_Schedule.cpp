//#include<bits/stdc++.h>
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
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    // vector<vector<int>> adj(n+1);
    vector<int> adj[N+1];
    vector<int> prereq(n+1,0), order;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y); // directed graph
        prereq[y]++;        // course x has to be completed before y, so y's pre-requisites increases
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!prereq[i])
            q.push(i); // push all those courses into queue that donot have any pre-requisites, i.e. independent vertices
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u); // iterate through independent courses one by one
        for (auto v : adj[u])
        { // reduce pre-requisites by 1 for all connected course for the course 'u'
            prereq[v]--;
            if (!prereq[v])
                q.push(v); // if courses's prequisites have been satisfied, now add them also into queue
        }
    }
    if (order.size() != n)
        cout << "IMPOSSIBLE"; // if all courses haven't completed yet, it isn't possible to complete all courses
    else
        for (int i = 0; i < n; i++)
            cout << order[i] << " ";
    cout << endl;
    return 0;
}