import java.io.File;
import java.util.*;

public class Main {
  static int N;
  static int M;
  static int T;

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("1.in"));
    // Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    M = sc.nextInt();
    T = sc.nextInt();

    Ant[] allAnts = new Ant[N];
    List<Ant> leftAnts = new ArrayList<>();
    List<Ant> rightAnts = new ArrayList<>();


    for (int i = 0; i < N; i++) {
      int pos = sc.nextInt();
      boolean direction = sc.next().charAt(0) == 'R';
      Ant ant = new Ant(pos, i, direction);
      if (direction) {
        rightAnts.add(ant);
      } else {
        leftAnts.add(ant);
      }

      allAnts[i] = ant;
    }

    T %= M;
    Collections.sort(leftAnts, (a, b) -> {return a.pos - b.pos;});
    Collections.sort(rightAnts, (b, a) -> {return a.pos - b.pos;});
    Arrays.sort(allAnts, new Comparator<Ant>() {
      public int compare(Ant a, Ant b) {
        return a.pos - b.pos;
      }
    });

    int curIdx = 0;
    for (Ant a : leftAnts) {
      a.carry = allAnts[curIdx];
      curIdx++;
    }

    curIdx = N-1;
    for (Ant a : rightAnts) {
      a.carry = allAnts[curIdx];
      curIdx--;
    }



    sc.close();
  }

  private static class Ant {
    int pos;
    int idx;
    Ant carry;
    boolean direction;

    public Ant (int pos, int idx, boolean direction) {
      this.pos = pos;
      this.idx = idx;
      this.direction = direction;
    }

    @Override
    public String toString() {
      return Integer.toString(pos);
    }
  }
}