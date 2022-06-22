#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 200005;

int N, Q, t, a, b, k;
ll x, ds[maxN];

void update(int idx, ll val){
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

int main(){
    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>>x;
        update(i, x);
        update(i+1, -x);
    }
    for(int q = 0; q < Q; q++){
        cin>>t;
        if(t == 1){
            cin>>a>>b>>x;
            update(b+1, -x);
            update(a, x);
        } else if(t == 2){
            cin>>k;
            cout<<query(k)<<endll;
        }
    }
}