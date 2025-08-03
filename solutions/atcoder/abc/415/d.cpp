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

  int n, m; cin >> n >> m;
  vector<pair<int, int>> ab;
  for(int i = 0; i < m; i++) {
    int ai, bi; cin >> ai >> bi;
    ab.push_back(make_pair(ai - bi, ai));
  }
  sort(all(ab));

  int curr = 0;
  int ret = 0;
  while(n && curr < m) {
    int diff = n - ab[curr].second + 1;
    if(diff > 0) {
      int num = diff / ab[curr].first;
      if(diff % ab[curr].first) {
        num++;
      }
      n -= ab[curr].first * num;
      ret += num;
    } else {
      curr++;
    }
  }

  cout << ret;
}
