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

    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
      v[i] = (int) (s[i] == '1');
    }

    bool good = true;
    for(int i = 0; i < n; i++) {
      if(v[i]) {
        if(i + k < n) {
          v[i] = 0;
          v[i+k] = 1 - v[i+k];
        } else {
          good = false;
        }
      }
    }

    if(good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
