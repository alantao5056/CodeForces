#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  while (T--) {
    int N; cin >> N;

    vector<int> arr(N+1);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    arr[N] = -1;

    int start = arr[0];
    int res = 0;
    
    for (int i = 0; i < N; i++) {
      if (arr[i+1] <= arr[i]) {
        res = max(res, arr[i]-start);
        start = arr[i+1];
      }
    }

    cout << res << endl;
  }

  return 0;
}