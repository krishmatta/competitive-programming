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

    string s; cin >> s;

    int mx = 0;
    int curr_mx = 0;
    int prev = -1;
    for(int i = 0; i < sz(s); i++) {
      int curr = s[i] - 'A';
      if(curr != prev) {
	curr_mx = 0;
      }
      curr_mx++;
      mx = max(mx, curr_mx);
      prev = curr;
    }

    cout << mx;
}
