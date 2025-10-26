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

  int N;
  cin >> N;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int low = arr[N-1]-arr[0]+1;
  int high = arr[0]+arr[1]-1;

  cout << max(0, (high-low+1)) << endl;

  return 0;
}