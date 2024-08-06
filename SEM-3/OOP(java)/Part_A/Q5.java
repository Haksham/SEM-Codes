package Part_A;
/*
Write a Java Program that does the following
  a. Create a super class called Car. The Car class has the following fields and methods.
 int speed; double regularPrice; String color; double getSalePrice();

b. Create a sub class of Car class and name it as Truck. The Truck class has the following fields and methods.
 int weight; double getSalePrice();
 //Ifweight>2000,10% discount. Otherwise,20%discount.

c. Create a subclass of Car class and name it as Ford. The Ford class has the following fields and methods
 int year; intmanufacturerDiscount; double getSalePrice();
 //From the sale price computed from Carclass, subtract the manufacturer Discount.

d. Create a subclass of Car class and name it as Sedan. The Sedan class has the following fields and methods.
 int length; double getSalePrice();
 //If length>20feet, 5% discount, Otherwise, 10% discount.

e. Create MyOwnAutoShop class which contains the main() method. Perform the following within the main() method.
 Create an instance of Sedan class and initialize all the fields with appropriate values.
 Use super(...) method in the constructor for initializing the fields of the superclass.
 Create an instance of the Ford class and initialize all the fields with appropriate values
 Use super(...) method in the constructor for initializing the fields of the super class.
 Create an instance of Car class and initialize all the fields with appropriate
*/

class Car {
  int speed;
  double regularPrice;
  String color;

  Car(int s, double price, String c) {
    speed = s;
    regularPrice = price;
    color = c;
  }

  double getSalePrice() {
    return regularPrice;
  }
}

class Truck extends Car {
  int weight;

  Truck(int s, double price, String c, int w) {
    super(s, price, c);
    weight = w;
  }

  double getSalePrice() {
    if (weight > 2000) {
      regularPrice = regularPrice * 0.9;
      return regularPrice;
    } else {
      regularPrice = regularPrice * 0.8;
      return regularPrice;
    }
  }
}

class Ford extends Car {
  int manufacturerDiscount, year;

  Ford(int s, double price, String c, int m) {
    super(s, price, c);
    manufacturerDiscount = m;
  }

  double getSalePrice() {
    regularPrice -= manufacturerDiscount;
    return regularPrice;
  }
}

class Sedan extends Car {
  int length;

  Sedan(int s, double price, String c, int l) {
    super(s, price, c);
    length = l;
  }

  double getSalePrice() {
    if (length > 20) {
      regularPrice = regularPrice * 0.95;
      return regularPrice;
    } else {
      regularPrice = regularPrice * 0.9;
      return regularPrice;
    }
  }
}

public class Q5 {
  public static void main(String[] args) {
    Truck t = new Truck(65, 2500000, "Red", 3000);
    System.out.println("Price of truck is " + t.getSalePrice());
    Car c = new Car(100, 800000, "Black");
    System.out.println("Price of Car is " + c.getSalePrice());
    Ford f = new Ford(120, 2200000, "Yellow", 120000);
    System.out.println("Price of ford is " + f.getSalePrice());
    Sedan s = new Sedan(100, 3500000, "Blue", 22);
    System.out.println("Price of Sedan is " + s.getSalePrice());
  }
}