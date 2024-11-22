#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll ret = 0;
    ll prev = 0;
    for(int i = 0; i < n; i++) {
      ll curr; cin >> curr;
      if(curr < prev) {
	ret += prev - curr;
      }
      prev = max(prev, curr);
    }
    cout << ret;
}
