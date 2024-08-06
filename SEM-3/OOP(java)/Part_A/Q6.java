package Part_A;
/*
Write a Java Program that implements the following
  Define a class SavingsAccount with following characteristics.
  
  Use a static variable annualInterestRate to store the annual interest rate for all account holders.  

  Private data member savingsBalance indicating the amount the saver currently has on deposit.  Method calculateMonthlyInterest to calculate the monthly interest as (savingsBalance * annualInterestRate / 12). After calculation, the interest should be added to savingsBalance.  Static method modifyInterestRate to set annualInterestRate.  Parameterized constructor with savingsBalance as an argument to set the value of that instance.

  Test the class SavingsAccount to instantiate two savingsAccount objects, saver1 and saver2, with balances of Rs.2000.00 and Rs3000.00, respectively. Set annualInterestRate to 4%, then calculate the monthly interest and print the new balances for both savers. Then set the annualInterestRate to 5%, calculate the next month’s interest and print the new balances for both savers.
 */

class SavingsAccount {
  static int annualInterestRate;
  private double savingsBalance;

  SavingsAccount(double s) {
    savingsBalance = s;
  }

  static void modifyInterestRate(int x) {
    annualInterestRate = x;
  }

  void calculateMonthlyInterest() {
    double d = (savingsBalance * annualInterestRate) / 12;
    savingsBalance = savingsBalance + d;
  }

  void display() {
    System.out.println(savingsBalance);
  }
}

public class Q6 {
  public static void main(String[] args) {
    SavingsAccount saver1 = new SavingsAccount(2000);
    SavingsAccount saver2 = new SavingsAccount(3000);
    SavingsAccount.modifyInterestRate(4);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.display();
    saver2.display();
    SavingsAccount.modifyInterestRate(5);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.display();
    saver2.display();
  }
}