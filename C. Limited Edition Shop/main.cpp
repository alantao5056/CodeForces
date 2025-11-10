#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

ll solve(vector<int>& vals, vector<int>& arr1, vector<int>& arr2, int N) {
  vector<int> p2(N+1);
  for (int i = 1; i <= N; i++) {
    p2[arr2[i]] = i;
  }
  
  vector<vector<ll>> dp(N+1, vector<ll>(N+1, -1e15));
  dp[0][0] = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (i > 0) {
        if (p2[arr1[i]] > j) {
          // not taken yet
          dp[i][j] = max(dp[i][j], dp[i-1][j] + vals[arr1[i]]);
        } else {
          // taken
          dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
      }
      if (j > 0) {
        dp[i][j] = max(dp[i][j], dp[i][j-1]);
      }
    }
  }

  return dp[N][N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T;
  cin >> T;

  while (T--) {
    int N; cin >> N;
    vector<int> vals(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> vals[i];
    }
    vector<int> arr1(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> arr1[i];
    }
    vector<int> arr2(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> arr2[i];
    }

    cout << solve(vals, arr1, arr2, N) << endl;
  }

  return 0;
}