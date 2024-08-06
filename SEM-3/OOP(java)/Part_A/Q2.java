package Part_A;
/*
Write a Java Program that does the following related to Inheritance:
  a. Create an abstract class called ‘Vehicle’ which contains the 'hashelmet',‘year of manufacture’ and two abstract methods ‘getData()’ and ‘putData()’. Demonstrate the error when attempt is made to create objects of ‘Vehicle’.
  b. Have two derived classes ‘TwoWheeler’ and ‘FourWheeler’. ‘FourWheeler’ is a final class. Demonstrate the error when attempt is made to inherit from ‘FourWheeler’.
  c. Your abstract class should haveoverloadedconstructors that initializes 'hashelmet' and ‘year of manufacture for TwoWheeler and FourWheeler respectively.
  d. ‘TwoWheeler’ has data elements ‘Brand’, ‘Cost’, ‘EngineType’ (possible values “2 stroke”, “4 stroke”), and ‘Color’ which are private, protected, ‘friendly/default’ and public respectively. Demonstrate the various ways in which the two abstract methods can be dealt ‘getData()’ and ‘putData()’ can be dealt with by the derived classes, ‘TwoWheeler’ and ‘FourWheeler’.
*/

import java.util.*;

abstract class Vehicle {
  boolean hashelmet;
  int yom;

  abstract void getData();

  abstract void putData();

  Vehicle(boolean h, int n) {
    hashelmet = h;
    yom = n;
  }
}

class TwoWheeler extends Vehicle {
  private String Brand;
  protected int Cost;
  String EngineType;
  public String Color;

  TwoWheeler(int n) {
    super(true, n);
  }

  void getData() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter Two Wheeler details: Its Brand name,Cost,EngineType and Colour");
    Brand = sc.next();
    Cost = sc.nextInt();
    EngineType = sc.next();
    Color = sc.next();
  }

  void putData() {
    System.out.println("\n");
    System.out.println("The details of Two Wheeler");
    System.out.println("Brand:" + Brand + "\nCost:" + Cost + "\nEngineType:" + EngineType + "\nColor:" + Color
        + "\nYear of Manufacture:" + yom + "\nHas helmet:" + hashelmet);
  }
}

final class FourWheeler extends Vehicle {
  FourWheeler(int n) {
    super(false, n);
  }

  void getData() {
  }

  void putData() {
    System.out.println("\n");
    System.out.println("The details of Four Wheeler");
    System.out.println("Year of Manufacture:" + yom + "\nHas helmet:" + hashelmet);
  }
}

/*
 * class A extends FourWheeler
 * {
 * A()
 * {
 * super(5);
 * }
 * }
 */
public class Q2 {
  public static void main(String[] args) {
    // Vehicle v=new Vehicle();
    // Cannot Create instance of an abstract class
    TwoWheeler t1 = new TwoWheeler(1995);
    FourWheeler f1 = new FourWheeler(2006);
    t1.getData();
    t1.putData();
    f1.putData();
  }
}