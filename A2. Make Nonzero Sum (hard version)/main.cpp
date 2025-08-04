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

  int t; cin >> t;
  
  while (t--) {
    int n; cin >> n;
    vector<int> arr(n+1);
    int a = 0; int b = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == 1) {
        a++;
      } else if (arr[i] == -1) {
        b++;
      }
    }

    int p = (a+b)/2;
    if ((a+b)%2 == 1) {
      cout << -1 << endl;
      continue;
    }

    if (a < b) {
      swap(a, b);
      for (int i = 1; i <= n; i++) {
        arr[i] *= -1;
      }
    } else if (a == b) {
      // take everything
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " " << i << endl;
      }

      continue;
    }

    // more 1's than -1's
    // 0: mark x, 1: no mark x
    vector<vector<pii>> dp(n+1, vector<pii>(2, {-1e9, 1}));

    dp[1][1].first = 0;

    int last = -1;
    for (int i = 2; i <= n; i++) {
      if (arr[i] == 1) {
        dp[i][0].first = dp[i-1][1].first+1;
        if (dp[i][0].first == a-p) {
          last = i;
          break;
        }
      }
      
      if (dp[i-1][0].first > dp[i-1][1].first) {
        dp[i][1] = {dp[i-1][0].first, 0};
      } else {
        dp[i][1] = {dp[i-1][1].first, 1};
      }
    }
    
    if (last == -1) { 
      cout << -1 << endl;
      continue;
    }

    vector<bool> ans(n+1, true);
    int cur = 0;
    while (last > 1) {
      if (cur == 0) {
        ans[last] = false;
      }
      cur = dp[last][cur].second;
      last--;
    }

    int start = 1;
    vector<pii> res;
    for (int i = 1; i < n; i++) {
      if (ans[i] && ans[i+1]) {
        res.push_back({start, i});
        start = i+1;
      }
    }

    res.push_back({start, n});
    cout << res.size() << endl;
    for (pii p : res) {
      cout << p.first << " " << p.second << endl;
    }
  }

  return 0;
}