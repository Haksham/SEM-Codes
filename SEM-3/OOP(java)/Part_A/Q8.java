package Part_A;
/*
We are required to model students and teachers in our application. We can define a superclass called Person to store common properties such as name and address, and subclasses Student and Teacher for their specific properties. For students, we need to maintain the courses taken and their respective grades; add a course with grade, print all courses taken and the average grade. Assume that a student takes no more than 30 courses for the entire program. For teachers, we need to maintain the courses taught currently, and able to add or remove a course taught. Assume that a teacher teaches not more than 5 courses concurrently.
 */

class Person {
  private String name;
  private String address;

  Person(String name, String address) {
    this.name = name;
    this.address = address;
  }

  String getName() {
    return name;
  }

  String getAddress() {
    return address;
  }

  void setAddress(String address) {
    this.address = address;
  }

  public String toString() {
    return name + "(" + address + ")";
  }
}

class Student1 extends Person {
  int numCourses = 0;
  String courses[] = new String[30];
  int grades[] = new int[30];

  Student1(String name, String address) {
    super(name, address);
  }

  void addCourseGrade(String course, int grade) {
    if (numCourses <= 29) {
      courses[numCourses] = course;
      grades[numCourses] = grade;
      numCourses++;
    } else {
      System.out.println("Maximum number of courses");
    }
  }

  void printGrades() {
    for (int i = 0; i < numCourses; i++)
      System.out.println("Course:" + courses[i] + " Grade:" + grades[i]);
  }

  double getAverageGrades() {
    double d = 0;
    for (int i = 0; i < numCourses; i++)
      d = d + grades[i];
    d = d / numCourses;
    return d;
  }

  public String toString() {
    return getName() + "(" + getAddress() + ")";
  }
}

class Teacher extends Person {
  int numCourses = 0;
  String courses[] = new String[5];

  Teacher(String name, String address) {
    super(name, address);
  }

  boolean addCourse(String course) {
    if (numCourses <= 4) {
      for (int i = 0; i < numCourses; i++)
        if (courses[i].equals(course))
          return false;
      courses[numCourses] = course;
      numCourses++;
      return true;
    } else
      return false;
  }

  boolean removeCourse(String course) {
    if (numCourses != 0) {
      for (int i = 0; i < numCourses; i++)
        if (courses[i].equals(course)) {
          courses[i] = " ";
          return true;
        }
      return false;
    }
    return false;
  }

  public String toString() {
    return getName() + "(" + getAddress() + ")";
  }
}

public class Q8 {
  public static void main(String[] args) {
    Student1 s = new Student1("Raju", "Bangalore");
    System.out.println(s);
    s.addCourseGrade("Maths", 85);
    s.addCourseGrade("OOPS", 80);
    s.addCourseGrade("DS", 75);
    s.addCourseGrade("DMS", 70);
    s.printGrades();
    System.out.println(s.getAverageGrades());
    Teacher t = new Teacher("CC", "DD");
    if (t.addCourse("Maths"))
      System.out.println("Course added");
    else
      System.out.println("Max limit reached/course already exists");
    if (t.addCourse("Maths"))
      System.out.println("Course added");
    else
      System.out.println("Max limit reached/course already exists");
    if (t.addCourse("OOPS"))
      System.out.println("Course added");
    else
      System.out.println("Max limit reached/course already exists");
    if (t.addCourse("DS"))
      System.out.println("Course added");
    else
      System.out.println("Max limit reached/course already exists");
    if (t.removeCourse("Maths"))
      System.out.println("Course removed");
    else
      System.out.println("Zero courses/course does not exist");
    if (t.removeCourse("TOC"))
      System.out.println("Course removed");
    else
      System.out.println("Zero courses/course does not exist");
  }
}