#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int firstMex = 0;
    bool rep = false;
    vector<bool> isRep(N+1);
    if (arr[0] == 0) {
      for (int i = 1; i <= N; i++) {
        if (i == N) {
          firstMex = arr[N-1]+1;
          break;
        }

        if (arr[i] - arr[i-1] > 1) {
          firstMex = arr[i-1]+1;
          break;
        } else if (arr[i] - arr[i-1] == 0) {
          rep = true;
          isRep[arr[i]] = true;
        }
      }
    } else {
      cout << 0 << endl;
      continue;
    }

    ll sum2 = 0;
    for (int i = 0; i < N; i++) {
      // if (!isRep[arr[i]] && arr[i] < firstMex && secondMex == 0) {
      //   secondMex = arr[i]+1;
      // }
      if (isRep[arr[i]] || arr[i] > firstMex) {
        sum2 += firstMex;
      } else {
        sum2 += arr[i];
      }
    }

    ll secondMex = 0;
    if (!isRep[0]) {
      for (int i = 1; i < N; i++) {
        if (isRep[arr[i]] || arr[i] - arr[i-1] != 1) {
          secondMex = arr[i-1]+1;
          break;
        }
        secondMex = arr[i]+1;
      }
    }

    
    if (K == 1) {
      cout << sum2 << endl;
      continue;
    }

    if (isRep[0]) {
      cout << 0 << endl;
      continue;
    }

    int odd, even, howmany;
    ll prefSum = 0;
    if (!rep) {
      odd = firstMex;
      even = firstMex+1;
      howmany = N-firstMex;
      prefSum = (ll)firstMex * (firstMex-1) / 2;
    } else {
      even = secondMex;
      odd = secondMex+1;
      howmany = N-secondMex;
      prefSum = (ll)secondMex * (secondMex-1) / 2;
    }
    
    if (K%2 == 1) {
      if (!rep && howmany == 1) {
        cout << prefSum + firstMex << endl;
      } else {
        cout << prefSum + (ll) odd * howmany << endl;
      }
    } else {
      if (!rep && howmany == 1) {
        cout << prefSum + firstMex << endl;
      } else {
        cout << prefSum + (ll) even * howmany << endl;
      }
    }
  }

  return 0;
}