import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Garland {
  static int N;
  static char[] garland;
  static int Q;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("test/01.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter("test/01.out");
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    garland = br.readLine().toCharArray();
    Q = Integer.parseInt(br.readLine());
    
    // solve
    long result = 0;
    for (int i = 0; i < Q; i++) {
      st = new StringTokenizer(br.readLine());

      int M = Integer.parseInt(st.nextToken());
      char target = st.nextToken().charAt(0);

      int l = 0;
      int r = 0;
      int amountOfTarget = garland[0] == target ? 1 : 0;
      int maxLength = 0;

      while (true) {
        if (r-l+1 - amountOfTarget > M) {
          // cant do
          amountOfTarget -= garland[l] == target ? 1 : 0;
          l++;
        } else {
          // can do
          maxLength = Math.max(maxLength, r-l+1);
          r++;
          if (r == N) break;
          amountOfTarget += garland[r] == target ? 1 : 0;
        }
      }

      // pw.println(maxLength);
      result += maxLength;
    }

    pw.println(result);

    br.close();
    pw.close();
  }
}