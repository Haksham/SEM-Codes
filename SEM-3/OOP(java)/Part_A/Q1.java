package Part_A;
/* 
Write a java program that demonstrate Method overriding:
  a. Create a class Bank that provides method to get the rate of interest called “getRateOfinterest() which is of type float.

  b. The rate of interest varies according to banks. SBI, ICICI and AXIS banks could provide 8%, 7%, and 9% rate of interest.

  c. Create Inheritance mechanism where SBI, ICICI and AXIS bank child classes extends Bank parent class that contains getRateOfinterest() method.

  d. Override getRateOfinterest() method in the child classes with updated interests as 8%, 7%, and 9%.
  e. Finally create a driver class BankDetails that can display the rate of interest of all the banks.
*/

class SBI extends Bank {
  int getRateOfInterest() {
    return 8;
  }
}

class ICICI extends Bank {
  int getRateOfInterest() {
    return 7;
  }
}

class AXIS extends Bank {
  int getRateOfInterest() {
    return 9;
  }
}

// Test class to create objects and call the methods
class BankDetails {
  public static void main(String args[]) {
    SBI s = new SBI();
    ICICI i = new ICICI();
    AXIS a = new AXIS();
    System.out.println("SBI Rate of Interest: " + s.getRateOfInterest());
    System.out.println("ICICI Rate of Interest: " + i.getRateOfInterest());
    System.out.println("AXIS Rate of Interest: " + a.getRateOfInterest());
  }
}