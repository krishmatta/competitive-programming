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
    int n, x; cin >> n >> x; x--;
    int l = x;
    int r = x;
    string s; cin >> s;
    while(l && s[l-1] != '#') {
      l--;
    }
    while(r < n - 1 && s[r+1] != '#') {
      r++;
    }

    if(l < n - r - 1 && x != l) {
      l = x;
    } else if (x != r) {
      r = x;
    }

    cout << min(l, n - r - 1) + 1 << "\n";
  }
}
