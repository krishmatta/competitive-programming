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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string z; cin >> z;
    vector<int> num_zeros(4, 0);
    num_zeros[0] = n;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') {
        num_zeros[1]++;
      }

      if(z[i] == '1') {
        num_zeros[2]++;
      }

      if((s[i] == '1' && z[i] != '1') || (s[i] != '1' && z[i] == '1')) {
        num_zeros[3]++;
      }
    }

    ll ret = 0;
    ll num_groups = ((1 << k) + 1) / 3;
    ll r = ((1 << k) + 1) % 3;
    vector<vector<int>> group = {{1,2,3},{1,3,2}};

    for(int i = 1; i < 4; i++) {
      ret += num_groups * (ll) ((((ll) num_zeros[i]) * (ll) (n - num_zeros[i])));
    }

    for(int i = 0; i < r; i++) {
      ret += (ll) (((ll) num_zeros[group[k&1][i]]) * (ll) (n - num_zeros[group[k&1][i]]));
    }

    cout << ret << "\n";
  }
}
