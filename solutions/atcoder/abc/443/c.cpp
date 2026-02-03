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

  int n, t; cin >> n >> t;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(t);

  int ret = 0;
  int on = true;
  int prev = 0;
  int next = INF;
  for(int i = 0; i <= n; i++) {
    if(!on) {
      if(a[i] > next) {
        on = true;
        prev = next;
        next = INF;
      }
    }

    if(on) {
      ret += a[i] - prev;
      on = false;
      next = a[i] + 100;
    }
  }

  cout << ret;
}
