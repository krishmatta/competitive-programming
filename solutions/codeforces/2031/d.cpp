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
    vector<int> a;
    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
    }

    vector<int> mx;
    mx.push_back(a[0]);
    for(int i = 1; i < n; i++) {
      mx.push_back(max(mx[i-1], a[i]));
    }

    reverse(all(a));
    reverse(all(mx));

    vector<int> ret;
    ret.push_back(mx[0]);

    vector<int> mn;
    mn.push_back(-a[0]);

    for(int i = 1; i < n; i++) {
      int j = lower_bound(all(mn), -mx[i]+1) - mn.begin();

      if(j < sz(mn) && mn[j] > -mx[i]) {
	ret.push_back(max(mx[i], ret[j]));
      } else {
	ret.push_back(mx[i]);
      }
      mn.push_back(max(mn[i-1], -a[i]));
    }

    reverse(all(ret));
    for(int i = 0; i < n; i++) {
      cout << ret[i] << " ";
    }
    cout << "\n";
  }
}
