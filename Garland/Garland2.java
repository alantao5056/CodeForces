import java.util.Scanner;

public class Garland2 {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("1.in"));
    // Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();

    char[] garland = sc.next().toCharArray();
    int[] garlandInt = new int[N];

    int maxSame = 0;
    int same = 1;
    garlandInt[0] = (int) garland[0]-97;
    int lastInt = garlandInt[0];
    for (int i = 1; i < N; i++) {
      garlandInt[i] = (int) garland[i]-97;
      if (garlandInt[i] == lastInt) {
        same++;
      } else {
        maxSame = Math.max(maxSame, same);
        same = 1;
      }
      lastInt = garlandInt[i];
    }

    maxSame = Math.max(maxSame, same);
    
    int M = sc.nextInt();
    int[] plan1 = new int[M];
    int[] plan2 = new int[M];

    for (int i = 0; i < M; i++) {
      plan1[i] = sc.nextInt();
      plan2[i] = (int) sc.next().charAt(0)-97;
    }

    int[] result = new int[M];
    
    // sliding window
    for (int k = 0; k < N-maxSame; k++) {
      int i = 0;
      int j = maxSame + k;
      int length = j - i + 1;
      int[] curLetters = new int[26];
      for (int l = 0; l < j+1; l++) {
        curLetters[garlandInt[l]]++;
      }
      while (j < N) {
        for (int l = 0; l < M; l++) {
          if (plan1[l] + curLetters[plan2[l]] >= length) {
            result[l] = length;
          }
        }
        curLetters[garlandInt[i]]--;
        i++;
        j++;
        if (j == N) break;
        curLetters[garlandInt[j]]++;
      }
    }

    sc.close();
  }
}