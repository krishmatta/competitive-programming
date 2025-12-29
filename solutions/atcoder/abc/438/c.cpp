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
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<int, int>> s;
  int ret = n;
  for(int i = 0; i < n; i++) {
    if(sz(s) == 0 || s[sz(s)-1].first != a[i]) {
      s.push_back(make_pair(a[i], 1));
    } else {
      s[sz(s)-1] = make_pair(s[sz(s)-1].first, s[sz(s)-1].second + 1);
    }

    if(s[sz(s)-1].second == 4) {
      ret -= 4;
      s.pop_back();
    }
  }

  cout << ret;
}
