#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int T;

double dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

// double dist2(int x, int y, ll a, ll b, ll c) {
//   return ((double) abs(a*x + b*y + c)) / (sqrt(pow(a, 2) + pow(b, 2)));
// }

double getT(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (double) ((x3-x1)*(x2-x1)+(y3-y1)*(y2-y1)) / (pow((x2-x1),2)+pow((y2-y1),2));
}

bool bigger(int x1, int y1, double m, int x2, int y2) {
  return y2 > m * (x2-x1) + y1;
}

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    vector<int> cx(N);
    vector<int> cy(N);

    for (int j = 0; j < N; j++) {
      cin >> cx[j] >> cy[j];
    }

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double m = ((double) (y2-y1)) / (x2-x1);
    bool xd = x1 < x2; // true: right, false: left
    bool yd = y1 < y2; // true: up, false: down

    ll a = y1-y2;
    ll b = x2-x1;
    ll c = ((ll)(x1-x2)) * y1 + ((ll)(y2-y1)) * x1;
    double d = dist(x1, y1, x2, y2);

    double k = -1;
    bool works = true;
    for (int j = 0; j < N; j++) {
      double t = getT(x1, y1, x2, y2, cx[j], cy[j]);
      double dx = x1 + t * (x2-x1);
      double dy = y1 + t * (y2-y1);

      if (xd && yd) {
        if (bigger(x1, y1, k/m, cx[j], cy[j]) && !bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], dx, dy) <= dist(x1, y1, dx, dy)) {
            works = false;
            break;
          }
        } else if (bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], x2, y2) <= d) {
            works = false;
            break;
          }
        }
      } else if (xd && !yd) {
        if (!bigger(x1, y1, k/m, cx[j], cy[j]) && bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], dx, dy) <= dist(x1, y1, dx, dy)) {
            works = false;
            break;
          }
        } else if (!bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], x2, y2) <= d) {
            works = false;
            break;
          }
        }
      } else if (!xd && yd) {
        if (bigger(x1, y1, k/m, cx[j], cy[j]) && !bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], dx, dy) <= dist(x1, y1, dx, dy)) {
            works = false;
            break;
          }
        } else if (bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], x2, y2) <= d) {
            works = false;
            break;
          }
        }
      } else {
        if (!bigger(x1, y1, k/m, cx[j], cy[j]) && bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], dx, dy) <= dist(x1, y1, dx, dy)) {
            works = false;
            break;
          }
        } else if (!bigger(x2, y2, k/m, cx[j], cy[j])) {
          if (dist(cx[j], cy[j], x2, y2) <= d) {
            works = false;
            break;
          }
        }
      }
    }

    if (works) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  
  return 0;
}