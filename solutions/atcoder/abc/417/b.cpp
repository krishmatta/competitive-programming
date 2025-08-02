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

  int n, m; cin >> n >> m;
  vector<int> a(n, 0);
  map<int, int> b;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    int bi; cin >> bi;
    if(b.find(bi) == b.end()) {
      b[bi] = 0;
    }
    b[bi]++;
  }

  for(int i = 0; i < n; i++) {
    if(b.find(a[i]) == b.end() || b[a[i]] == 0) {
      cout << a[i] << " ";
    } else {
      b[a[i]]--;
    }
  }
}
