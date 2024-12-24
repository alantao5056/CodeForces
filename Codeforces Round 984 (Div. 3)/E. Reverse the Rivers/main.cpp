#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, K, Q;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> K >> Q;

  vector<vector<int>> arr(K, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      cin >> arr[j][i];
    }
  }

  for (int i = 0; i < K; i++) {
    for (int j = 1; j < N; j++) {
      arr[i][j] |= arr[i][j-1];
    }
  }

  for (int i = 0; i < Q; i++) {
    int M; cin >> M;
    int low = 0;
    int high = N-1;
    for (int j = 0; j < M; j++) {
      int reg, target; char op; cin >> reg >> op >> target; reg--;

      if (op == '<') {
        int idx = upper_bound(arr[reg].begin(), arr[reg].end(), target) - arr[reg].begin() - 1;
        high = min(high, idx);
      } else {
        int idx = upper_bound(arr[reg].begin(), arr[reg].end(), target) - arr[reg].begin();
        low = max(low, idx);
      }
    }

    if (high < low) {
      cout << -1 << endl;
    } else {
      cout << low+1 << endl;
    }
  }

  return 0;
}