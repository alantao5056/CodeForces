import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class MeetingPlace {
  static int N;
  public static void main(String[] args) throws Exception {
    // Scanner sc = new Scanner(new java.io.File("1.in"));
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    Friend[] friends = new Friend[N];
    for (int i = 0; i < N; i++) {
      friends[i] = new Friend(sc.nextInt());
    }

    for (int i = 0; i < N; i++) {
      friends[i].speed = sc.nextInt();
    }

    Arrays.sort(friends, new Comparator<Friend>() {
      public int compare(Friend a, Friend b) {
        return a.pos - b.pos;
      }
    });

    // binary search time
    double low = 0;
    double high = Math.pow(10, 9);

    while (low + 0.000001 < high) {
      double mid = (low+high)/2;
      if (check(friends, mid)) {
        high = mid;
      } else {
        low = mid;
      }
    }

    System.out.println(Math.min(low, high));

    // System.out.println(check(friends, 1));

    sc.close();
  }

  private static boolean check(Friend[] friends, double time) {
    double low = 0;
    double high = Math.pow(10, 9);
    for (int i = 0; i < N && low <= high; i++) {
      double leftMax = friends[i].pos - friends[i].speed * time;
      double rightMax = friends[i].pos + friends[i].speed * time;
      if (leftMax > 0) {
        low = Math.max(low, leftMax);
      }
      if (rightMax < 1_000_000_000) {
        high = Math.min(high, rightMax);
      }
    }
    return low <= high;
  }

  public static class Friend {
    int pos;
    int speed;
    public Friend (int pos) {
      this.pos = pos;
    }
    @Override
    public String toString() {
      return Integer.toString(pos);
    }
  }
}