/*
 * FloatComparison.java
 * Compile: javac FloatComparison.java
 * Run:     java FloatComparison
 *
 * Prints "Equal" if sensorReading is close enough to targetValue.
 * Uses epsilon = 0.0001 for comparison.
 */

import java.lang.Math;
import java.util.Scanner;
public class FloatComparison {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      double targetValue;
      double sensorReading;

      targetValue = scnr.nextDouble();
      sensorReading = scnr.nextDouble();

      if (Math.abs(targetValue - sensorReading) < 0.0001) {
         System.out.println("Equal");
      }
      else {
         System.out.println("Not equal");
      }
   }
}
