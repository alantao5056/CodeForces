import java.util.Scanner;

public class WrongAddition {
  public static void main(String[] args) throws Exception {
//    Scanner sc = new Scanner(new java.io.File("1.in"));
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    
    for (int i = 0; i < T; i++) {
      char[] aStr = sc.next().toCharArray();
      char[] bStr = sc.next().toCharArray();
      
      int[] a = new int[aStr.length];
      for (int j = 0; j < aStr.length; j++) {
        a[j] = Character.getNumericValue(aStr[j]);
      }
      
      int[] b = new int[bStr.length];
      for (int j = 0; j < bStr.length; j++) {
        b[j] = Character.getNumericValue(bStr[j]);
      }
      
      System.out.println(solve(a, b));
    }
  }
  private static String solve(int[] a, int[] b) {
    int aIndex = a.length-1;
    int bIndex = b.length-1;
    
    StringBuilder result = new StringBuilder();
    
    while(aIndex >= 0 && bIndex >= 0) {
      int aDigit = a[aIndex];
      int bDigit = b[bIndex];
      if (aDigit <= bDigit) {
        result.append(bDigit - aDigit);
        aIndex--;
        bIndex--;
      } else if (b[bIndex-1] == 1) {
        result.append(10 + bDigit - aDigit);
        aIndex--;
        bIndex -= 2;
      } else {
        return "-1";
      }
    }
    if (aIndex > bIndex) return "-1";

    for (int i = 0; i < bIndex - aIndex; i++) {
      result.append(b[i]);
    }
    for (int i = result.length()-1; i >= 0; i--) {
      if (result.charAt(i) != '0') {
        result.setLength(i+1);
        break;
      }
    }
    
    return result.reverse().toString();
  }
}
