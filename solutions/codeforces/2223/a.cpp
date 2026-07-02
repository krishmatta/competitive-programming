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
    string a; cin >> a;
    string b; cin >> b;

    int as = 0;
    int bs = 0;
    bool good = true;
    for(int i = 0; i < n; i++) {
      if(a[i] == b[i]) {
        if(a[i] == '(') {
          as++;
          bs++;
        } else {
          as--;
          bs--;
        }
      } else {
        if(as >= bs) {
          as--;
          bs++;
        } else {
          as++;
          bs--;
        }
      }

      if(as < 0 || bs < 0) {
        good = false;
        break;
      }
   }

    if(as != 0 || bs != 0) {
      good = false;
    }

    if(good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
