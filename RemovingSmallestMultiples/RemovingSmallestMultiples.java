import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class RemovingSmallestMultiples {
  // static StreamTokenizer st;
  static int T;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("removingsmallestmultiples.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // st = new StreamTokenizer(br);
    // PrintWriter pw = new PrintWriter(new File("removingsmallestmultiples.out"));
    T = Integer.parseInt(br.readLine());
    
    // solve
    for (int i = 0; i < T; i++) {
      int N = Integer.parseInt(br.readLine());
      char[] S = br.readLine().toCharArray();
      List<Integer> needToRemove = new ArrayList<>();
      for (int j = 0; j < N; j++) {
        if (S[j] == '0') {
          needToRemove.add(j+1);
        }
      }

      System.out.println(getCost(needToRemove));
    }

    br.close();
    // pw.close();
  }

  private static int getCost(List<Integer> needToRemove) {
    boolean[] visited = new boolean[needToRemove.size()];

    int result = 0;
    for (int i = 0; i < needToRemove.size(); i++) {
      if (visited[i]) continue;

      result += needToRemove.get(i);
      int cur = needToRemove.get(i) * 2;
      while (true) {
        int binarySearch = Collections.binarySearch(needToRemove, cur);
        if (binarySearch >= 0) {
          // found
          visited[binarySearch] = true;
          cur += needToRemove.get(i);
          result += needToRemove.get(i);
        } else {
          break;
        }
      }
    }

    return result;
  }

  // private static int nextInt() throws Exception {
  //   st.nextToken();
  //   return (int) st.nval;
  // }

  // private static String nextString() throws Exception {
  //   st.nextToken();
  //   return st.sval;
  // }
}