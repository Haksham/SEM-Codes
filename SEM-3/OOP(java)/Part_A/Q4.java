package Part_A;
/*
Write a Java Program that does the following
  a. Create a superclass, Student, and two subclasses, Undergrad and Grad.

  b. The superclass Student should have the following data members: name, ID, grade, age

  c. The superclass, Student should have at least one method: Boolean isPassed (double grade)

  d. The purpose of the isPassed method is to take one parameter, grade (value between 0 and 100) and check whether the grade has passed the requirement for passing a course.In the Student class this method should be empty as an abstract method.

  e. The two subclasses, Grad and Undergrad, will inherit all data members of the Student class and override the method isPassed. For the UnderGrad class, if the grade is above 70.0, then isPassedreturns true, otherwise it returns false. For the Grad class, if the grade is above 80.0, then isPassed returns true, otherwise returns false.

  f. Demonstrate "final" keyword in the above class.

  g. Create a test class for your three classes. In the test class, create one Grad object and one Undergrad object. For each object, provide a grade and display the results of the isPassed method.
 */

import java.util.*;

abstract class Student {
  private String Name;
  protected int ID;
  double grade;
  public int age;

  abstract boolean isPassed(double Grade);

  final void setter(String name) {
    Name = name;
  }

  String getter() {
    return Name;
  }
}

class Undergrad extends Student {
  void getData() {
    Scanner sc = new Scanner(System.in);
    System.out.println("\nEnter Name,ID,age");
    setter(sc.next());
    ID = sc.nextInt();
    age = sc.nextInt();
  }

  boolean isPassed(double Grade) {
    grade = Grade;
    if (grade <= 70)
      return false;
    else
      return true;
  }

  void display() {
    System.out.println("Name:" + getter() + "\nAge:" + age + "\nID:" + ID);
  }
  /*
   * void setter(String name)
   * {
   * }
   * Cannot override the final setter method
   */
}

class Grad extends Student {
  void getData() {
    Scanner sc = new Scanner(System.in);
    System.out.println("\nEnter Name,ID,age");
    setter(sc.next());
    ID = sc.nextInt();
    age = sc.nextInt();
  }

  boolean isPassed(double Grade) {
    grade = Grade;
    if (grade <= 80)
      return false;
    else
      return true;
  }

  void display() {
    System.out.println("Name:" + getter() + "\nAge:" + age + "\nID:" + ID);
  }
}

public class Q4 {
  public static void main(String[] args) {
    Undergrad u = new Undergrad();
    u.getData();
    if (u.isPassed(65))
      System.out.println("Student has passed\n");
    else
      System.out.println("Student has failed\n");
    u.display();
    Grad g = new Grad();
    g.getData();
    if (g.isPassed(90))
      System.out.println("Student has passed\n");
    else
      System.out.println("Student has failed\n");
    g.display();
  }
}