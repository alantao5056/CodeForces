#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    string x, y; cin >> x >> y;
    int N = x.size();

    vector<int> xea;
    vector<int> xoa;
    vector<int> yea;
    vector<int> yoa;
    for (int i = 0; i < N; i++) {
      if (x[i] == 'A') {
        if (i % 2 == 0) {
          xea.push_back(i);
        } else {
          xoa.push_back(i);
        }
      }
    }
    for (int i = 0; i < N; i++) {
      if (y[i] == 'A') {
        if (i % 2 == 0) {
          yea.push_back(i);
        } else {
          yoa.push_back(i);
        }
      }
    }

    if (xea.size() != yea.size() || xoa.size() != yoa.size()) {
      cout << -1 << endl;
      continue;
    }

    int res = 0;
    for (int i = 0; i < xea.size(); i++) {
      res += abs(xea[i] - yea[i])/2;
    }
    for (int i = 0; i < xoa.size(); i++) {
      res += abs(xoa[i] - yoa[i])/2;
    }

    cout << res << endl;
  }

  return 0;
}