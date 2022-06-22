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

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef map <int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;
typedef priority_queue<int> pqi;

const ld pi=acos(-1);
const int M = 1e9+7;
const ll INF = 1e18;
const double eps=1e-6;

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

class UnionFind {
   public:
    UnionFind(size_t n)
        : parent_(n, -1) {
    }
    int Find(const int x) {
        if (parent_[x] < 0) {
            return x;
        }
        return parent_[x] = Find(parent_[x]);
    }
    void Union(const int x, const int y) {
        auto x_root = Find(x), y_root = Find(y);
        if (x_root == y_root) {
            return;
        }
        if (std::abs(parent_[x_root]) < std::abs(parent_[y_root])) {
            std::swap(x_root, y_root);
        }
        parent_[x_root] += parent_[y_root];
        parent_[y_root] = x_root;
    }

   private:
    vector<int> parent_;
};

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        UnionFind uf(n + 1);
        std::string op;
        int x, y;
        while (m--) {
            std::cin >> op >> x >> y;
            if (op == "union") {
                uf.Union(x, y);
            } else {
                if (uf.Find(x) == uf.Find(y)) {
                    std::cout << "YES" << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
    }
    return 0;
}

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();