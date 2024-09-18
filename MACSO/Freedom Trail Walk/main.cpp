#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pil = pair<int, ll>;

const int MOD = 1e9 + 7;

int N, C;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> C;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<pil> dp(N, {1, 1});
  int ans = 1;
  for (int i = 0; i < N; i++) {
    pil curM = {1, 1};
    for (int j = 0; j < i; j++) {
      if (arr[j] >= arr[i]) continue;
      if (dp[j].first >= curM.first) {
        curM = dp[j];
        curM.first++;
      } else if (dp[j].first == curM.first-1) {
        curM.second += dp[j].second;
        curM.second %= MOD;
      }
    }

    ans = max(ans, curM.first);
    dp[i] = curM;
  }

  cout << ans << endl;

  if (C) {
    ll ans2 = 0;
    for (int i = 0; i < N; i++) {
      if (dp[i].first == ans) {
        ans2 += dp[i].second;
        ans2 %= MOD;
      }
    }

    cout << ans2 << endl;
  }

  return 0;
}