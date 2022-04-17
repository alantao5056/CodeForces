import java.util.Scanner;

public class NotShading {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    // Scanner sc = new Scanner(new java.io.File("1.in"));
    
    int T = sc.nextInt();
    
    for (int i = 0; i < T; i++) {
      System.out.println(solveCase(sc));
    }
    
    sc.close();
  }
  
  private static int solveCase(Scanner sc) {
    int N = sc.nextInt();
    int M = sc.nextInt();
    int R = sc.nextInt();
    int C = sc.nextInt();
    
    boolean zeroMove = false;
    boolean oneMove = false;
    boolean containsBlack = false;
    
    for (int i = 0; i < N; i++) {
      char[] curCharArr = sc.next().toCharArray();
      
      for (int j = 0; j < M; j++) {
        if (curCharArr[j] == 'B') containsBlack = true;
        if (i == R-1 && j == C-1 && curCharArr[j] == 'B') {
          zeroMove = true;
        } else if ((i == R-1 || j == C-1) && curCharArr[j] == 'B') {
          // same row or same column
          oneMove = true;
        }
      }
    }
    
    if (zeroMove) {
      return 0;
    }
    
    if (oneMove) {
      return 1;
    }
    if (containsBlack) {
      return 2;
    }
    return -1;
  }
}
