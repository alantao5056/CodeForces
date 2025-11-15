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

  int N, M;
  cin >> N >> M;

  vector<vector<int>> grid(N+2, vector<int>(M+2, -1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> grid[i][j];
    }
  }


  vector<vector<int>> vert(N+2, vector<int>(M+2));
  vector<vector<int>> hori(N+2, vector<int>(M+2));
  vector<vector<int>> squ(N+2, vector<int>(M+2));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i][j+1]) {
        hori[i][j]++;
      }
      if (grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i+1][j]) {
        vert[i][j]++;
      }
      if (grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+1][j+1]) {
        squ[i][j]++;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      vert[i][j] += vert[i-1][j] + vert[i][j-1] - vert[i-1][j-1];
      hori[i][j] += hori[i-1][j] + hori[i][j-1] - hori[i-1][j-1];
      squ[i][j] += squ[i-1][j] + squ[i][j-1] - squ[i-1][j-1];
    }
  }

  int Q; cin >> Q;

  for (int i = 0; i < Q; i++) {
    int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2; i2++; j2++;

    i1++; i2--;
    if (i2-i1 >= 1 && (vert[i2][j2] - vert[i1][j2] - vert[i2][j1] + vert[i1][j1] > 0)) {
      cout << "NO" << endl; continue;
    }
    i1--; i2++;
    j1++; j2--;
    if (j2-j1 >= 1 && (hori[i2][j2] - hori[i1][j2] - hori[i2][j1] + hori[i1][j1] > 0)) {
      cout << "NO" << endl; continue;
    }
    j1--; j2++;

    i2--; j2--;
    if (squ[i2][j2] - squ[i1][j2] - squ[i2][j1] + squ[i1][j1] > 0) {
      cout << "NO" << endl; continue;
    }

    cout << "YES" << endl;
  }

  return 0;
}