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

  int n; cin >> n;
  string t; cin >> t;
  vector<int> count(2, 0); count[1]++;
  int curr = 1;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    int ti = t[i] - '0';
    if(curr == ti) {
      curr = 1;
    } else {
      curr = 0;
    }
    ret += (ll) count[curr];
    count[curr]++;
  }
  cout << ret << "\n";
}
