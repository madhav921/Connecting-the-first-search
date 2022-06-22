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

#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define sz(x)  ((int)(x).size())
#define nl <<endl
#define co cout<<
#define ci cin>>
#define gap <<" "<<
#define vector v_
#define fr(i,a,b) for(int i=a ; i<b ; i++)
#define frn(i,a,b) for(int i=a ; i>=b ; i--)
#define all(x) (x).begin(),(x).end()
#define revsort(a, b) sort(a, b, greater<ll>())
#define found(container, element) (find(all(container), element) != container.end())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


class DSU {
   public:
    DSU(size_t n)
        : parent_(n, -1) {
    }
    int Find(int x) {
        if (parent_[x] < 0) {
            return x;
        }
        return parent_[x] = Find(parent_[x]);
    }
    int Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) {
            return -parent_[x];
        }
        if (parent_[x] > parent_[y]) {
            std::swap(x, y);
        }
        parent_[x] += parent_[y];
        parent_[y] = x;
        return -parent_[x];
    }

   private:
    std::vector<int> parent_;
};

using EdgeType = std::tuple<int, int, int>;

long long MinimalSpanningTree(const int n, std::vector<EdgeType> &edges) {
    const auto cmp = [](const EdgeType &e1, const EdgeType &e2) {
        return std::get<2>(e1) > std::get<2>(e2);
    };
    std::priority_queue<EdgeType, std::vector<EdgeType>, decltype(cmp)>
        queue{cmp, edges};
    DSU dsu(n + 1);

    long long res = 0;

    while (!queue.empty()) {
        const auto [u, v, w] = queue.top();
        queue.pop();
        if (dsu.Find(u) == dsu.Find(v)) {
            continue;
        }
        res += w;
        if (dsu.Union(u, v) >= n) {
            break;
        }
    }

    return res;
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        std::vector<EdgeType> edges;
        int from_, to_, weight_;
        while (m--) {
            std::cin >> from_ >> to_ >> weight_;
            edges.emplace_back(from_, to_, weight_);
        }
        std::cout << MinimalSpanningTree(n, edges) << std::endl;
    }
    return 0;
}

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();