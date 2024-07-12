import java.util.Scanner;

public class TDM {
  public static void main(String args[]) {
    int n, i, qt, count = 0, temp, sq = 0, bt[], wt[], tat[], rem_bt[];
    // float awt = 0, atat = 0;                                             // I dont know where these were used
    bt = new int[10];
    wt = new int[10];
    tat = new int[10];
    rem_bt = new int[10];
    try (Scanner s = new Scanner(System.in)) {
      System.out.print("Enter the number of stations (maximum 10) = ");
      n = s.nextInt();
      System.out.print("Enter the processing time for each channel\n");
      for (i = 0; i < n; i++) {
        System.out.print("S" + i + " = ");
        bt[i] = s.nextInt();
        rem_bt[i] = bt[i];
      }
      System.out.print("Enter the frame size: ");
      qt = s.nextInt();
    }


    while (true) {                                       // Main code starts here.
      for (i = 0, count = 0; i < n; i++) {
        temp = qt;
        if (rem_bt[i] == 0) {
          count++;
          continue;
        }
        if (rem_bt[i] > qt)
          rem_bt[i] = rem_bt[i] - qt;
        else if (rem_bt[i] >= 0) {
          temp = rem_bt[i];
          rem_bt[i] = 0;
        }
        sq = sq + temp;
        tat[i] = sq;
      }
      if (n == count)
        break;                                      // Main code ends here
    }
    

    System.out.print("\n\nStation\t Processing Time\t Completion Time\t Waiting Time\n");
    for (i = 0; i < n; i++) {
      wt[i] = tat[i] - bt[i];
      // awt = awt + wt[i];                                                   // I dont know where these were used
      // atat = atat + tat[i];
      System.out.print("\n \t" + (i + 1) + "\t \t" + bt[i] + "\t\t " + tat[i] + "\t\t\t " + wt[i] + "\n");
    }
  }
}