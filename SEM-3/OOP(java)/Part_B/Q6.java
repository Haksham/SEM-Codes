/*
 Write a Java program to display multiplication table of 8 & 9 using shared resources “synchronized displayTable(intnum)”. The table should be displayed with 1 sec delay between every number. First print multiplication table of 8 and then 9.
 */

class A {
  synchronized void displayTable(int n) {
    try {
      for (int i = 1; i <= 10; i++) {
        System.out.println(i * n);
        Thread.sleep(1000);
      }
    } catch (Exception e) {
    }
  }
}

class Mul extends Thread {
  A a;
  int n;

  Mul(A a, int n) {
    this.n = n;
    this.a = a;
  }

  public void run() {
    a.displayTable(n);
  }
}

public class Q6 {
  public static void main(String args[]) {
    A a = new A();
    Mul m = new Mul(a, 8);
    Mul m1 = new Mul(a, 9);
    m.start();
    m1.start();
  }
}