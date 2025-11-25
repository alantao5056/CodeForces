#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

bool works(vector<int>& fires, int totTime, int numFires) {
  if (numFires == 0) return true;

  int i = 0;
  int j = totTime-numFires;

  while (i < fires.size() && j < totTime) {
    if (fires[i] <= j) {
      i++;
      j++;
    } else {
      return false;
    }
  }

  if (j == totTime) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int M, N, a, b; cin >> M >> N >> a >> b;

    vector<int> fires(N);
    for (int i = 0; i < N; i++) {
      cin >> fires[i];
    }

    sort(fires.begin(), fires.end());

    int totTime;
    if (a < b) {
      totTime = b-1;
    } else {
      totTime = N-b;
    }

    int maxFires = abs(b-a)-1;

    int low = 0;
    int high = min((int)fires.size(), maxFires);
    
    while (low < high) {
      int mid = low + (high - low + 1) / 2;
      if (works(fires, totTime, mid))
        low = mid;
      else
        high = mid - 1;
    }

    cout << low << endl;
  }

  return 0;
}