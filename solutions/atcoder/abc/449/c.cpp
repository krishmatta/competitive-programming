#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l, r; cin >> n >> l >> r;
  string s; cin >> s;
  map<char, pair<deque<int>, deque<int>>> m;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    if(m.find(s[i]) != m.end()) {
      auto& [f, b] = m[s[i]];

      while(sz(b)) {
        int u = b.front();
        int d = i - u;
        if(l <= d) {
          b.pop_front();
          f.push_back(u);
        } else {
          break;
        }
      }

      while(sz(f)) {
        int u = f.front();
        int d = i - u;
        if(r < d) {
          f.pop_front();
        } else {
          break;
        }
      }

      ret += (ll) sz(f);
      b.push_back(i);
    } else {
      deque<int> f;
      deque<int> b; b.push_back(i);
      m[s[i]] = make_pair(f, b);
    }
  }
  cout << ret;
}
