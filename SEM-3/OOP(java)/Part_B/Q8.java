/*
 Write a java program to accept a string. Convert the string to uppercase. Count and output the number of double letter sequences that exist in the string.
Sample Input: “SHE WAS FEEDING THE LITTLE RABBIT WITH AN APPLE”
Sample Output: 4
 */

import java.util.*;

public class Q8 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String s;
    System.out.println("Enter string");
    s = sc.nextLine();
    int c = 0;
    char ch = s.charAt(0);
    for (int i = 1; i < s.length(); i++) {
      if (s.charAt(i) == ch)
        c++;
      ch = s.charAt(i);
    }
    System.out.println(c);
  }
}