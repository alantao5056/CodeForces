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

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    vector<int> res(N);
    for (int i = 0; i < N; i++) {
      res[i] = N-arr[i]+1;
    }

    for (int i = 0; i < N-1; i++) {
      cout << res[i] << " ";
    }

    cout << res[N-1] << endl;
  }

  return 0;
}