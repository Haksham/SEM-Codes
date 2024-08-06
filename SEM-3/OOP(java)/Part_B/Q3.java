/*Write a program to create two threads t1, t2 which should prints odd numbers, and reverse of a number respectively and stops thread after creating 3 odd numbers. */

class A extends Thread {
  public void run() {
    boolean flag = false;
    int c = 0, i = 0;
    while (c < 3) {
      if (i % 2 != 0) {
        System.out.println(i);
        c++;
      }
      i++;
      if (c == 3) {
        flag = true;
        break;
      }
    }
    if (flag) {
      try {
        wait();
      } catch (Exception e) {
      }
    }
  }
}

class B extends Thread {
  int n;

  B(int n) {
    this.n = n;
  }

  public void run() {
    int reversed = 0;
    while (n != 0) {
      int digit = n % 10;
      reversed = reversed * 10 + digit;
      n /= 10;
    }
    System.out.println("Reversed Number: " + reversed);
  }
}

public class Q3 {
  public static void main(String[] args) {
    A a = new A();
    a.start();
    B b = new B(1234);
    b.start();
  }
}