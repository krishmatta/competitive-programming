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

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<ll> a(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    unordered_map<ll, pair<ll, ll>> count; count[1] = make_pair(0, 0);
    for(int i = 0; i < n; i++) {
      ll curr = 0;
      bool was_one = (a[i] == 1);
      while(a[i] > 1) {
        if(count.find(a[i]) == count.end()) {
          count[a[i]] = make_pair(0, 0);
        }

        count[a[i]] = make_pair(count[a[i]].first + 1, count[a[i]].second + curr);
        curr++;

        if(a[i] & 1) {
          a[i]++;
        } else {
          a[i] /= 2;
        }
      }

      count[1] = make_pair(count[1].first + 1, count[1].second + curr);

      if(was_one) {
        count[2] = make_pair(count[2].first + 1, count[1].second + 1);
      }
    }

    ll ret = INF;
    for(auto const& pair : count) {
      if(pair.second.first == n) {
        ret = min(ret, pair.second.second);
      }
    }

    cout << ret << "\n";
  }
}
