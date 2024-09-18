#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    vector<int> arr(N);
    for (int j = 0; j < N; j++) {
      cin >> arr[j];
    }

    sort(arr.begin(), arr.end());

    cout << arr[N/2] << endl;
  }

  return 0;
}