#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

int op(int a, int b) { return a + b; }
int e() { return 0; }

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  ll curr = 0;
  segtree<int, op, e> seg(m);
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++) {
    int ai; cin >> ai;

    curr += (ll) seg.prod(ai + 1, m);
    int curr_count = seg.prod(ai, ai + 1);
    seg.set(ai, curr_count + 1);

    pq.push(make_pair(ai, i));
  }

  for(int i = 0; i < m; i++) {
    vector<int> rm;
    while(sz(pq) && ((pq.top().first + i) % m) == 0) {
      rm.push_back(pq.top().second);
      pq.pop();
    }

    reverse(all(rm));
    for(int i = 0; i < sz(rm); i++) {
      int before = i;
      int after = sz(rm) - i - 1;
      curr += (ll) (rm[i] - before);
      curr -= (ll) (n - rm[i] - 1 - after);
    }

    cout << curr << "\n";
  }
}
