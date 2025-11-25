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

  int T; cin >> T;

  while (T--) {
    int N, K, M; cin >> N >> K >> M;

    vector<bool> arr(N);
    int cnt = 0;
    for (int i = 0; i < M; i++) {
      int x; cin >> x; x--;
      arr[x] = true;
      cnt++;
    }

    int sub = K-1;
    int E = N-cnt;
    if (E % sub != 0) {
      cout << "NO" << endl;
      continue;
    }

    int prev = -1e9;
    cnt = 0;
    bool works = false;
    for (int i = 0; i < N; i++) {
      if (!arr[i]) {
        int dist = i - prev;

        if (cnt >= sub/2 && cnt <= E-sub/2 && dist > 1) {
          cout << "YES" << endl;
          works = true;
          break;
        }

        prev = i;
        cnt++;
      }
    }

    if (!works) {
      cout << "NO" << endl;
    }
  }

  return 0;
}