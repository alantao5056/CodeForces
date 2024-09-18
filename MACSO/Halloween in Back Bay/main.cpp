#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, M, C;

vector<vector<int>> key = {{1, 1, 2, 2},
                           {1, 2, 1, 2},
                           {1, 2, 2, 1},
                           {2, 2, 1, 1},
                           {2, 1, 1, 2},
                           {2, 1, 2, 1}};

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> M >> C;

  if (N > M) swap(N, M);
  if (C == 3) return 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << key[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}