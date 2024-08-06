package Part_A;
/*
Write a Java Program that does the following:
  a. Create an abstract class called ‘Shape’ which contains Two instance variables color (String) and filled (boolean).  Two constructors: a no-arg (no-argument) constructor that initializes the color to "green" and filled to true, and a constructor that initializes the color and filled to the given values.  Getter and setter for all the instance variables. By convention, the getter for a boolean variable xxx is called isXXX() (instead of getXxx() for all the other types).  A toString() method that returns "A Shape with color of xxx and filled/Not filled".  An abstract method getArea()  Demonstrate the error when attempt is made to create objects of ‘Shape’.
  
  b. Write two subclasses of Shape called Circle and Rectangle. Rectangle is a final class. Demonstrate the error when attempt is made to inherit from ‘Rectangle’.

  c. Write a class called Square, as a subclass of Rectangle. Convince yourself that Square can be modeled as a subclass of Rectangle. Square has no instance variable, but inherits the instance variables width and length from its superclass Rectangle.
 */

abstract class Shape {
  String color;
  boolean filled;

  abstract double getArea();

  Shape() {
    color = "green";
    filled = true;
  }

  Shape(String c, boolean f) {
    color = c;
    filled = f;
  }

  boolean isFILLED() {
    return filled;
  }

  String getColor() {
    return color;
  }

  void setFILLED(boolean b) {
    this.filled = b;
  }

  void setColor(String c) {
    this.color = c;
  }

  public String toString() {
    if (this.filled == false)
      return "A Shape with color " + this.color + " and not filled";
    else
      return "A Shape with color " + this.color + " and filled";
  }
}

class Circle extends Shape {
  int r;

  Circle(int r1) {
    super();
    r = r1;
  }

  Circle(String c, boolean f, int r1) {
    super(c, f);
    r = r1;
  }

  double getArea() {
    return 3.14 * r * r;
  }

  void display() {
    System.out.println("\nDisplaying the details of Circle:");
    System.out.println(isFILLED());
    System.out.println(getColor());
    System.out.println("\n");
  }

  void change(String c, boolean b) {
    setColor(c);
    setFILLED(b);
  }
}

final class Rectangle extends Shape {
  int a, b;

  Rectangle(int a1, int b1) {
    super();
    a = a1;
    b = b1;
  }

  Rectangle(String c, boolean f, int a1, int b1) {
    super(c, f);
    a = a1;
    b = b1;
  }

  double getArea() {
    return a * b;
  }
}

/*
 * class Square extends Rectangle
 * { Square()
 * {
 * super(5,6);
 * }
 * void display()
 * {
 * System.out.println(a + " " + b);
 * }
 * }
 * Cannot inherit a final class
 */
public class Q3 {
  public static void main(String[] args) {
    /*
     * Shape s=new Shape();
     * Cannot create instance of an abstact class
     */
    Circle c = new Circle("blue", false, 5);
    Rectangle r = new Rectangle("red", true, 2, 4);
    System.out.println(c);
    System.out.println(r);
    System.out.println("\n");
    System.out.println("Area of Circle:" + c.getArea());
    System.out.println("Area of Rectangle:" + r.getArea());
    c.display();
    c.change("brown", true);
    c.display();
  }
}