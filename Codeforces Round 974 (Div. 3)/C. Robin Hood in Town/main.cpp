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

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    ll sum = 0;
    vector<int> arr(N);
    for (int j = 0; j < N; j++) {
      cin >> arr[j];
      sum += arr[j];
    }

    if (N == 1 || N == 2) {
      cout << "-1" << endl;
      continue;
    }

    sort(arr.begin(), arr.end());

    int mid = (N)/2;
    cout << max(0LL, (ll)arr[mid] * N * 2 - sum + 1) << endl;
  }

  return 0;
}