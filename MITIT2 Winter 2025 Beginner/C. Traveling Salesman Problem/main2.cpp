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
    int N; cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
      int x, y; cin >> x >> y;
      arr[i] = x + y;
    }

    sort(arr.begin(), arr.end());
    
    ll res = 0;
    res = (ll)2 * ((ll)arr[N-1] - arr[0]);
    cout << res << endl;
  }

  return 0;
}