// Design an Event handling Program to implement the following

// importing necessary libraries
import java.awt.*;
import java.awt.event.*;

// Our class extends Frame class and implements ActionListener interface
public class Q4 extends Frame implements ActionListener {
  // creating instances of TextField and Button class
  TextField tf1, tf2, tf3;
  Button b1, b2;

  // instantiating using constructor
  Q4() {
    // instantiating objects of text field and button
    // setting position of components in frame
    tf1 = new TextField();
    tf1.setBounds(50, 50, 150, 20);
    tf2 = new TextField();
    tf2.setBounds(50, 100, 150, 20);
    tf3 = new TextField();
    tf3.setBounds(50, 150, 150, 20);
    tf3.setEditable(false);
    b1 = new Button("+");
    b1.setBounds(50, 200, 50, 50);
    b2 = new Button("-");
    b2.setBounds(120, 200, 50, 50);
    // adding action listener
    b1.addActionListener(this);
    b2.addActionListener(this);
    // adding components to frame
    add(tf1);
    add(tf2);
    add(tf3);
    add(b1);
    add(b2);
    // setting size, layout and visibility of frame
    setSize(300, 300);
    setLayout(null);
    setVisible(true);
  }

  // defining the actionPerformed method to generate an event on buttons
  public void actionPerformed(ActionEvent e) {
    String s1 = tf1.getText();
    String s2 = tf2.getText();
    int a = Integer.parseInt(s1);
    int b = Integer.parseInt(s2);
    int c = 0;
    if (e.getSource() == b1) {
      c = a + b;
    } else if (e.getSource() == b2) {
      c = a - b;
    }
    String result = String.valueOf(c);
    tf3.setText(result);
  }

  // main method
  public static void main(String[] args) {
    new Q4();
  }
}