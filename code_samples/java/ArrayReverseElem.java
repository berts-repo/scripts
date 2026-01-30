/* the results are correct for an odd number of elements, because the middle element will just not move. */
import java.util.Scanner;

public class ArrayReverseElem {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      final int NUM_ELEMENTS = 8;             // Number of elements
      int[] userVals = new int[NUM_ELEMENTS]; // User numbers
      int i;                                  // Loop index
      int tempVal;                            // Temp variable for swapping

      // Prompt user to input values
      System.out.println("Enter " + NUM_ELEMENTS
              + " integer values...");
      for (i = 0; i < userVals.length; ++i) {
         System.out.print("Value: ");
         userVals[i] = scnr.nextInt();
      }

      // Reverse array's elements
      for (i = 0; i < (userVals.length / 2); ++i) {
         tempVal = userVals[i];                           // Temp for swap
         userVals[i] = userVals[userVals.length - 1 - i]; // First part of swap
         userVals[userVals.length - 1 - i] = tempVal;     // Swap complete
      }

      // Print numbers
      System.out.print("\nNew values: ");
      for (i = 0; i < userVals.length; ++i) {
         System.out.print(userVals[i] + " ");
      }
   }
}
