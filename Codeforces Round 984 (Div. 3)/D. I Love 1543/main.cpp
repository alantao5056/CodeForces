#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int t = 0; t < T; t++) {
    int N, M; cin >> N >> M;

    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < min(N, M)/2; i++) {
      string cur = "";

      // across (i, j)
      for (int j = i; j < M-i; j++) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[i][j];
        } else {
          cur += arr[i][j];
        }

        if (cur == "1543") {
          ans++;
        }
      }

      // down (j, M-i-1)
      for (int j = i+1; j < N-i; j++) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[j][M-i-1];
        } else {
          cur += arr[j][M-i-1];
        }

        if (cur == "1543") {
          ans++;
        }
      }

      // back (N-i-1, j)
      for (int j = M-i-2; j >= i; j--) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[N-i-1][j];
        } else {
          cur += arr[N-i-1][j];
        }

        if (cur == "1543") {
          ans++;
        }
      }

      // up (j, i) don't count last one
      for (int j = N-i-2; j > i; j--) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[j][i];
        } else {
          cur += arr[j][i];
        }

        if (cur == "1543") {
          ans++;
        }
      }

      int cnt = 0;
      // across (i, j)
      for (int j = i; j < M-i; j++) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[i][j];
        } else {
          cur += arr[i][j];
        }

        if (cur == "1543" && cnt < 3) {
          ans++;
        }
        cnt++;
      }

      if (cnt >= 3) continue;

      // down (j, M-i-1)
      for (int j = i+1; j < N-i; j++) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[j][M-i-1];
        } else {
          cur += arr[j][M-i-1];
        }

        if (cur == "1543" && cnt < 3) {
          ans++;
        }
        cnt++;
      }

      if (cnt >= 3) continue;

      // back (N-i-1, j)
      for (int j = M-i-2; j >= i; j--) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[N-i-1][j];
        } else {
          cur += arr[N-i-1][j];
        }

        if (cur == "1543" && cnt < 3) {
          ans++;
        }
        cnt++;
      }

      if (cnt >= 3) continue;

      // up (j, i) don't count last one
      for (int j = N-i-2; j > i; j--) {
        if (cur.size() == 4) {
          cur.erase(0, 1);
          cur += arr[j][i];
        } else {
          cur += arr[j][i];
        }

        if (cur == "1543" && cnt < 3) {
          ans++;
        }
        cnt++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}