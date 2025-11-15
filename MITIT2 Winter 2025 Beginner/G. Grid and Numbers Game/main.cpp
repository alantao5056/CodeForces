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

  int T;
  cin >> T;

  while (T--) {
    int N, M; cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<int>> sorted;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> grid[i][j];
        sorted.push_back({grid[i][j], i, j});
      }
    }

    sort(sorted.begin(), sorted.end());

    vector<vector<int>> end(N, vector<int>(M, -1));
    ll s = 0;
    for (int i = 0; i < sorted.size(); i++) {
      int ii = sorted[i][1];
      int jj = sorted[i][2];

      int m = -1;
      if (ii > 0) {
        m = max(m, end[ii-1][jj]);
      }
      if (ii < N-1) {
        m = max(m, end[ii+1][jj]);
      }
      if (jj > 0) {
        m = max(m, end[ii][jj-1]);
      }
      if (jj < M-1) {
        m = max(m, end[ii][jj+1]);
      }
      end[ii][jj] = m+1;
      s += grid[ii][jj] - end[ii][jj];
    }
    
    if (s % 2 == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}