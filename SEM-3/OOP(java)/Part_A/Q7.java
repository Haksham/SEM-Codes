package Part_A;
/*
Write a Java Program that does the following 

  The Customer class models a customer is design as shown in the class diagram. Write the codes for the Customer class and a test driver to test all the public methods.

  The Invoice class, design as shown in the class diagram, composes a Customer instance (written earlier) as its member. Write the codes for the Invoice class and a test driver to test all the public methods.
 */

class Customer {
  private int ID;
  private String Name;
  private int discount;

  Customer(int ID, String Name, int discount) {
    this.Name = Name;
    this.ID = ID;
    this.discount = discount;
  }

  int getID() {
    return ID;
  }

  String getName() {
    return Name;
  }

  int getDiscount() {
    return discount;
  }

  void setDiscount(int discount) {
    this.discount = discount;
  }

  public String toString() {
    return Name + "(" + ID + ")";
  }
}

class Invoice {
  private int ID;
  private Customer customer;
  private double amount;

  Invoice(int ID, Customer customer, double amount) {
    this.ID = ID;
    this.customer = customer;
    this.amount = amount;
  }

  int getID() {
    return ID;
  }

  Customer getCustomer() {
    return customer;
  }

  void setCustomer(Customer customer) {
    this.customer = customer;
  }

  String getAmount() {
    return Double.toString(amount);
  }

  void setAmount(double amount) {
    this.amount = amount;
  }

  String getCustomerName() {
    return customer.getName();
  }

  double getAmountAfterDiscount() {
    return (amount * customer.getDiscount()) / 100;
  }
}

public class Q7 {
  public static void main(String[] args) {
    Customer c = new Customer(25, "Raju", 5);
    System.out.println("The details of first customer:");
    System.out.println(c.getID());
    System.out.println(c.getDiscount());
    System.out.println(c.getName());
    c.setDiscount(7);
    System.out.println("After discount:");
    System.out.println(c.getDiscount());
    System.out.println(c);
    Customer c1 = new Customer(26, "Ram", 9);
    Invoice i = new Invoice(28, c1, 60000);
    System.out.println("\nInvoice details:");
    System.out.println(i.getID());
    System.out.println(i.getCustomer());
    System.out.println(i.getAmount());
    i.setAmount(70000);
    System.out.println(i.getAmount());
    System.out.println(i.getCustomerName());
    System.out.println(i.getAmountAfterDiscount());
  }
}