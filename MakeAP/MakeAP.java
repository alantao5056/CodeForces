import java.util.Scanner;

public class MakeAP {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
//    Scanner sc = new Scanner(new java.io.File("1.in"));
    
    int T = sc.nextInt();
    for (int i = 0; i < T; i++) {
      if (checkIfValid(sc)) {
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
    }
    
    sc.close();
  }
  
  private static boolean checkIfValid(Scanner sc) {
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    
    // check a
    double constant = c - b;
    // a * m + constant = b;
    double m = (b - (int) constant) / (double) a;
    // check if m is bigger than 0 and is an integer
    if ((int) m > 0 && m % 1 == 0) {
      return true;
    }
    
    // check b
    constant = (c-a)/2.0;
    if (constant % 1 == 0) {
      // b * m + constant = c;
      m = (c - (int) constant) / (double) b;
      // check if m is bigger than 0 and is an integer
      if ((int) m > 0 && m % 1 == 0) {
        return true;
      }
    }
    
    // check c
    constant = b - a;
    if (constant % 1 == 0) {
      // c * m - constant = b;
      m = (b + (int) constant) / (double) c;
      // check if m is bigger than 0 and is an integer
      if ((int) m > 0 && m % 1 == 0) {
        return true;
      }
    }
    
    return false;
  }

}
