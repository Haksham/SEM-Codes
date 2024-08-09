import java.util.Scanner;

public class TDM {
  public static void main(String args[]) {
    int n, i, frame, count = 0, temp, sq = 0, pt[], wt[], ct[], rem[];
    pt = new int[10];   //pt = processing time
    wt = new int[10];   //wt = waiting time
    ct = new int[10];   // ct = completion time
    rem = new int[10];  // rem = remaining time
    try (Scanner s = new Scanner(System.in)) {
      System.out.print("Enter the number of stations (maximum 10) = ");
      n = s.nextInt();
      System.out.print("Enter the processing time for each channel\n");
      for (i = 0; i < n; i++) {
        System.out.print("S" + i + " = ");
        pt[i] = s.nextInt();
        rem[i] = pt[i];
      }
      System.out.print("Enter the frame size: ");
      frame = s.nextInt();
    }


    while (true) {                                       // Main code starts here.
      for (i = 0, count = 0; i < n; i++) {
        temp = frame;
        if (rem[i] == 0) {
          count++;
          continue;
        }
        if (rem[i] > frame)
          rem[i] -= frame;
        else if (rem[i] >= 0) {
          temp = rem[i];
          rem[i] = 0;
        }
        sq += temp;     // sq = sequenceing
        ct[i] = sq;
      }
      if (n == count)
        break;                                      // Main code ends here
    }
    

    System.out.print("\n\nStation\t Processing Time\t Completion Time\t Waiting Time\n");
    for (i = 0; i < n; i++) {
      wt[i] = ct[i] - pt[i];
      System.out.print("\n \t" + (i + 1) + "\t \t" + pt[i] + "\t\t " + ct[i] + "\t\t\t " + wt[i] + "\n");
    }
  }
}