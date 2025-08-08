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
    set<int> a;
    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      if(ai != -1)
        a.insert(ai);
    }

    if(sz(a) > 1 || a.find(0) != a.end()) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << "\n";
  }
}
