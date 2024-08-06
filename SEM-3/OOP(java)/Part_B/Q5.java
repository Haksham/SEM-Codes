/*
 Write a Java program to find area of a triangle with three sides a, b, c. A triangle can be formed only if a+b>c, b+c>a, c+a>b. First verify whether the above three conditions are satisfied. If any one of them is not satisfied then throw an exception called ValidateTriangle Exception
Enter the 3 sides of triangle:
7 4 10
Valid Triangle
Enter the 3 sides of triangle:
2 6 8
Not a valid triangle
 */

import java.util.*;

class Triangle extends Exception {
  public String toString() {
    return "Not an acceptable triangle";
  }
}

public class Q5 {
  public static void main(String args[]) throws Triangle {
    Scanner sc = new Scanner(System.in);
    int a, b, c;
    System.out.println("Enter the 3 sides of a triangle:");
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    try {
      if ((a < b + c) && (b < a + c) && (c < a + b))
        System.out.println("Valid Triangle");
      else
        throw new Triangle();
    } catch (Triangle e) {
      System.out.println(e);
    }
  }
}