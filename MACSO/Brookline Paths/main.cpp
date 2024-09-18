#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M, K;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> M >> K;

  vector<vector<vector<ll>>> dp(K+1, vector<vector<ll>>(N+1, vector<ll>(M+1)));
  dp[0][0][0] = 1;

  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= M; k++) {
        if (i > 0 && j > 0 && k > 0) {
          dp[i][j][k] += dp[i-1][j-1][k-1];
        }

        if (j > 0) {
          dp[i][j][k] += dp[i][j-1][k];
        }

        if (k > 0) {
          dp[i][j][k] += dp[i][j][k-1];
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i <= K; i++) {
    ans += dp[i][N][M];
  }

  cout << ans << endl;

  return 0;
}