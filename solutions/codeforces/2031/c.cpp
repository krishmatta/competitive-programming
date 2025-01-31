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

    if(n % 2) {
      if(n < 27) {
	cout << -1;
      } else {
	vector<int> ret(n, 0);
	ret[0] = 1;
	ret[1] = 2;
	ret[10] = 2;
	ret[25] = 1;
	ret[26] = 2;

	int curr = 3;
	for(int i = 0; i < n; i++) {
	  if(ret[i] == 0) {
	    ret[i] = curr;
	    ret[i + 1] = curr;
	    curr++;
	  }
	}

	for(int i = 0; i < n; i++) {
	  cout << ret[i] << " ";
	}
      }
    } else {
      for(int i = 0; i < n; i += 2) {
	cout << i + 1 << " ";
	cout << i + 1 << " ";
      }
    }

    cout << "\n";
  }
}
