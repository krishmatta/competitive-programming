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
    string s; cin >> s;

    set<char> vis; vis.insert(s[0]); vis.insert(s[n-1]);
    bool good = false;
    for(int i = 1; i < n - 1; i++) {
      char curr = s[i];
      if(vis.find(curr) != vis.end()) {
        good = true;
        break;
      }

      vis.insert(curr);
    }

    if(good) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << "\n";
  }
}
