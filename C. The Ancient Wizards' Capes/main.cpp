#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int solve(int N, vector<int>& arr) {
  vector<int> res(N); // -1 is right, 1 is left

  for (int i = 1; i < N; i++) {
    if (arr[i] - arr[i-1] == 0) {
      if (res[i-1] != 0) {
        res[i] = -1 * res[i-1];
      }
    } else if (arr[i] - arr[i-1] == 1) {
      if (res[i-1] == -1) {
        return 0;
      } else if (res[i-1] == 0) {
        res[i-1] = 1;
      }
      res[i] = 1;
    } else if (arr[i] - arr[i-1] == -1) {
      if (res[i-1] == 1) {
        return 0;
      } else if (res[i-1] == 0) {
        res[i-1] = -1;
      }
      res[i] = -1;
    } else {
      return 0;
    }
  }

  if (res[N-1] == 0) {
    if (N%2==0) {
      if (arr[0] == N/2 || arr[0] == N/2+1) {
        return 1;
      } else {
        return 0;
      }
    } else {
      if (arr[0] == N/2+1) {
        return 2;
      } else {
        return 0;
      }
    }
  }

  for (int i = N-2; i >= 0; i--) {
    if (res[i] != 0) continue;
    res[i] = -1*res[i+1];
  }

  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (res[i] == -1) {
      cnt++;
    }
  }

  if (cnt == arr[0]) {
    return 1;
  }

  return 0;
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

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    cout << solve(N, arr) << endl;
  }

  return 0;
}