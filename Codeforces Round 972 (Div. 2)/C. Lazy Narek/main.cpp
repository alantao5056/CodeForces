#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> T;

  string temp = "narek";
  for (int z = 0; z < T; z++) {
    int N, M; cin >> N >> M;

    vector<string> vs(N+1);
    vector<int> prefix(N+1);
    for (int j = 1; j <= N; j++) {
      string s; cin >> s;
      string ss = "";
      for (int k = 0; k < M; k++) {
        if ((s[k] == 'n') || (s[k] == 'a') || (s[k] == 'r') || (s[k] == 'e') || (s[k] == 'k')) {
          ss += s[k];
        }
      }

      vs[j] = ss;
      prefix[j] = prefix[j-1] + ss.size();
    }

    vector<vector<pii>> dp(N+1, vector<pii>(5, {0, 1e9})); // score, length
    dp[0][0] = {0, 0};
    for (int i = 1; i <= N; i++) {
      vector<pii> cur(5);
      for (int j = 0; j < 5; j++) {
        int look = j;
        int found = 0;
        for (int k = 0; k < vs[i].size(); k++) {
          if (vs[i][k] == temp[look]) {
            look++;
            if (look == 5) {
              found++;
              look = 0;
            }
          }
        }

        cur[j] = {found * 5, look};
      }

      for (int j = 0; j < i; j++) {
        for (int k = 0; k < 5; k++) {
          int old = dp[i][cur[k].second].first*2 - dp[i][cur[k].second].second;
          int n = (dp[j][k].first + cur[k].first) * 2 - dp[j][k].first - vs[i].size();

          if (n > old) {
            dp[i][cur[k].second].first = (dp[j][k].first + cur[k].first);
            dp[i][cur[k].second].second = dp[j][k].first + vs[i].size();
          }
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
      ans = max(ans, dp[i][0].first*2 - dp[i][0].second);
    }

    cout << ans << endl;
  }

  return 0;
}