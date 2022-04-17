import java.util.Scanner;

public class TrianglesOnARectangle {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
//    Scanner sc = new Scanner(new java.io.File("1.in"));

    int T = sc.nextInt();
    
    for (int i = 0; i < T; i++) {
      System.out.println(getMaxArea(sc));
    }
    
    sc.close();
  }
  
  private static long getMaxArea(Scanner sc) {
    int W = sc.nextInt();
    int H = sc.nextInt();
    
    int downK = sc.nextInt();
    int downStart = sc.nextInt();
    for (int i = 0; i < downK-2; i++) {
      sc.nextInt();
    }
    int downEnd = sc.nextInt();
    long downSum = downEnd - downStart;
    
    int upK = sc.nextInt();
    int upStart = sc.nextInt();
    for (int i = 0; i < upK-2; i++) {
      sc.nextInt();
    }
    int upEnd = sc.nextInt();
    long upSum = upEnd - upStart;
    
    int leftK = sc.nextInt();
    int leftStart = sc.nextInt();
    for (int i = 0; i < leftK-2; i++) {
      sc.nextInt();
    }
    int leftEnd = sc.nextInt();
    long leftSum = leftEnd - leftStart;
    
    int rightK = sc.nextInt();
    int rightStart = sc.nextInt();
    for (int i = 0; i < rightK-2; i++) {
      sc.nextInt();
    }
    int rightEnd = sc.nextInt();
    long rightSum = rightEnd - rightStart;
    
    return Math.max(upSum * H, Math.max(downSum * H, Math.max(leftSum * W, rightSum * W)));
  }

}
