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

  int T;
  cin >> T;
  while (T--) {
    int N; cin >> N;

    if (N == 3) {
      for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == 1) {
          cout << 2 << " ";
        } else if (x == 2) {
          cout << 1 << " ";
        } else {
          cout << 3 << " ";
        }
      }

      cout << endl;
      continue;
    }

    vector<int> arr(N);
    vector<int> res(N);
    int x = (N+1)/2;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      if (arr[i] % (x) == 0) {
        res[i] = arr[i];
      } else {
        int base = arr[i]-arr[i]%x;
        res[i] = base + (x-arr[i]%x);
      }
    }


    for (int i = 0; i < N-1; i++) {
      cout << res[i] << " ";
    }

    cout << res[N-1] << endl;
  }

  return 0;
}