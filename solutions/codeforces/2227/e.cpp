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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> mn(n + 1, INF);
    for(int i = n - 1; i > -1; i--) {
      mn[i] = min(mn[i+1], a[i]);
    }

    ll ret = 0;
    for(int i = n - 1; i > -1; i--) {
      ret += a[i] - mn[i];
    }

    ll add = 0;
    vector<int> stack;
    for(int i = 0; i < n; i++) {
      while(sz(stack) && a[stack.back()] >= a[i]) {
        stack.pop_back();
      }

      if(a[i] >= mn[i]) {
        if(sz(stack)) {
          add = max(add, (ll) ((i - stack[sz(stack)-1]) - 1));
        } else {
          add = max(add, (ll) i);
        }
      }

      stack.push_back(i);
    }
    cout << ret + add << "\n";
  }
}
