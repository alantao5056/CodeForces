import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class AntsOnACircle {
  static StreamTokenizer st;
  static int N;
  static int M;
  static int T;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("antsonacircle.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    // PrintWriter pw = new PrintWriter(new File("antsonacircle.out"));
    N = nextInt();
    M = nextInt();
    T = nextInt();
    
    // solve
    int[][] ants = new int[N][2]; // 0 is pos, 1 is direction (0 is left, 1 is right)

    for (int i = 0; i < N; i++) {
      ants[i][0] = nextInt()-1;
      ants[i][1] = nextString().charAt(0) == 'L' ? 0 : 1;
    }

    Arrays.sort(ants, (a, b) -> a[0] - b[0]);

    // simulate M, focusing on cow[0];
    int targetPos = simulate(ants, M);

    // binary search where curPos ended up
    int l = 0, r = ants.length - 1;
    int offset = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
 
      if (ants[m][0] == targetPos) {
        offset = m;
        break;
      }
            
      if (ants[m][0] < targetPos) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    int timesRepeated = T / M;

    int totalOffset = (offset * timesRepeated) % N;

    int finalPos = simulate(ants, T % M);

    int[] finalPositions = new int[N];
    for (int i = 0; i < N; i++) {
      if (ants[i][1] == 0) {
        int temp = ants[i][0] - (T % M);
        finalPositions[i] = temp < 0 ? temp + M : temp;
      } else {
        finalPositions[i] = (ants[i][0] + (T % M)) % M;
      }
    }

    Arrays.sort(finalPositions);

    int index0 = Arrays.binarySearch(finalPositions, finalPos);
    for (int i = 0; i < N; i++) {
      System.out.println(finalPositions[(index0 + i)%N]);
    }

    br.close();
    // pw.close();
  }

  private static int simulate(int[][] ants, int totalTime) {
    ArrayDeque<Integer> left = new ArrayDeque<>();
    ArrayDeque<Integer> right = new ArrayDeque<>();
    
    for (int i = 1; i < N; i++) {
      if (ants[i][1] == 0) {
        // left
        left.add(ants[i][0]);
      }
      if (N-i-1 != 0 && ants[N-i-1][1] == 1) {
        // right
        right.add(ants[N-i-1][0]);
      }
    }

    int time = 0;
    int targetPos = ants[0][0];
    int targetDirection = ants[0][1];

    while (true) {
      int collisionTime = 0;
      if (targetDirection == 0) {
        // collision with right
        int rightAntPos = (right.poll() + time)%M;
        collisionTime = checkWhenCollide(rightAntPos, targetPos);
        if (time + collisionTime >= totalTime) {
          // done
          targetPos -= totalTime-time;
          if (targetPos < 0) {
            targetPos += M;
          }
          break;
        }
        targetPos -= collisionTime;
        if (targetPos < 0) {
          targetPos += M;
        }
        targetDirection = 1;
        left.add(rightAntPos);
      } else {
        // collision with left
        int leftAntPos = left.poll() - time;
        if (leftAntPos < 0) {
          leftAntPos += M;
        }
        collisionTime = checkWhenCollide(targetPos, leftAntPos);
        if (time + collisionTime >= totalTime) {
          // done
          targetPos += totalTime-time;
          targetPos %= M;
          break;
        }
        targetPos += collisionTime;
        targetPos %= M;
        targetDirection = 0;
        right.add(leftAntPos);
      }
      time += collisionTime;
    }

    return targetPos;
  }

  private static int checkWhenCollide(int right, int left) {
    if (right < left) {
      // normal collision
      return (int) Math.ceil((double) (left - right) / 2);
    }
    // not normal (crosses 0 and N-1)
    return (int) Math.ceil((double) ((M-right) + (left)) / 2);
  }

  private static int nextInt() throws Exception {
    st.nextToken();
    return (int) st.nval;
  }

  private static String nextString() throws Exception {
    st.nextToken();
    return st.sval;
  }
}