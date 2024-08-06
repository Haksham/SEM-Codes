/*
Write a Java Program to implement Packages by performing following operations:
  a. Create a class TwoDim which contains private members as x and y coordinates in package P1. Define the default constructor, a parameterized constructor and override toString() method to display the co-ordinates.

  b. Reuse the class TwoDim and in package P2 create another class ThreeDim, adding a new dimension as z as its private member. Define the constructors for the subclass and override toString() method in the subclass also.

  c. Write a driver code that imports both packages and usage of classes TwoDim and ThreeDim by creating objects.
 */

package p1;

public class TwoDim {
  private int x;
  private int y;

  public TwoDim() {
    this.x = 0;
    this.y = 0;
  }

  public TwoDim(int x, int y) {
    this.x = x;
    this.y = y;
  }

  @Override
  public String toString() {
    return "Coordinate: x = " + x + " y = " + y;
  }
}

// After this package 2

package p2;

import p1.*;

public class ThreeDim extends TwoDim
{
private int z;
public ThreeDim()
{
super(0, 0);
this.z = 0;
}
public ThreeDim(int x, int y, int z)
{
super(x, y);
this.z = z;
}
@Override
public String toString()
{
return super.toString() + " z = " + z;
}
}
// In the current working directory create a file named as PkgDemo.java

import p1.*;
import p2.*;

public class PkgDemo {
  public static void main(String[] args) {
    TwoDim td = new TwoDim(1, 2);
    System.out.println(td);
    ThreeDim thd = new ThreeDim(3, 4, 5);
    System.out.println(thd);
  }
}

/*
 * To Execute follow the below steps:
 * 
 * (i)Compile the file of package p1 and p2 using the below command in current
 * working directory to create class files of TwoDim.java and ThreeDim.java
 * javac -classpath . p1/TwoDim.java
 * javac -classpath . p2/ThreeDim.java
 * 
 * (ii) Compile the source file PkgDemo.java and run the same:
 * javac PkgDemo.java
 * java PkgDemo
 * Coordinate: x = 1 y = 2
 * Coordinate: x = 3 y = 4 z = 5
 */