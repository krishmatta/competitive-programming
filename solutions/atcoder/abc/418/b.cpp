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

  string s; cin >> s;
  double ret = 0.0;
  for(int i = 0; i < sz(s) - 2; i++) {
    if(s[i] == 't') {
      int count = 1;
      if(s[i+1] == 't') {
        count++;
      }

      for(int j = i+2; j < sz(s); j++) {
        if(s[j] == 't') {
          count++;
        }

        ret = max(ret, ((double) count - 2) / ((double) (j - i - 1)));
      }
    }
  }

  cout << fixed << setprecision(10) << ret << "\n";
}
