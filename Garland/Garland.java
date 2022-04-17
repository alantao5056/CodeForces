import java.util.Scanner;

public class Garland {
  public static void main(String[] args) throws Exception {
    // Scanner sc = new Scanner(new java.io.File("1.in"));
    Scanner sc = new Scanner(System.in);

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
    int[] curLetters = new int[26];

    // brute force
    int i = 0;
    int j = 1;
    while (i < N) {
      curLetters = new int[26];
      curLetters[garlandInt[i]]++;
      j=i+1;
      while (j < N) {
        curLetters[garlandInt[j]]++;
        // check
        int length = j-i+1;
        for (int k = 0; k < M; k++) {
          int amount = plan1[k];
          int letter = plan2[k];
          if (length - curLetters[letter] <= amount) {
            result[k] = Math.max(result[k], length);
          }
        }
        j++;
      }
      i++;
    }

    for (int r : result) {
      if (r == 0) {
        System.out.println(maxSame);
      } else {
        System.out.println(r);
      }
    }

    sc.close();
  }
}