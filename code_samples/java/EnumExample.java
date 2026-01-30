/*The program declares a new enumeration type named LightState. The program then declares a new variable lightVal of that type. The loop updates lightVal based on the user's input.

The example illustrates the idea of a state machine that is sometimes used in programs, especially programs that interact with physical objects, wherein the program moves among particular situations ("states") depending on input; see What is: State machine.

A programmer must include both the enumeration type and the enumerator within that type, as in lightVal = LightState.RED;. A common error is to omit the enumeration type in an expression. For example, the statement lightVal = RED; results in a compilation error.

Different enumerated types may use some of the same enumerators. For example, the above program might also declare public enum Warnings {GREEN, ORANGE, RED}. The enumeration values are then accessed as Warnings.RED and LightState.RED.

One might ask why the light variable wasn't simply declared as a string, and then compared with strings "GREEN", "RED", and "YELLOW". Enumerations are safer. If using a string, an assignment like light = "ORANGE" would not yield a compiler error, even though ORANGE is not a valid light color. Likewise, light == "YELOW" would not yield a compiler error, even though YELLOW is misspelled.

One could instead declare final variables for strings like final String LS_GREEN = "GREEN"; or even integer values like final int LS_GREEN = 0; and then use those constants in the code, but an enumeration is clearer, requires less code, and is less prone to error.*/

import java.util.Scanner;

/* Manual controller for traffic light */
public class EnumExample {
   // enum type declaration occurs outside the main method
   public enum LightState {RED, GREEN, YELLOW, DONE}

   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      LightState lightVal;
      String userCmd;

      lightVal = LightState.RED;
      userCmd = "-";

      System.out.println("User commands: n (next), r (red), q (quit).\n");

      while (lightVal != LightState.DONE) {

         if (lightVal == LightState.GREEN) {
            System.out.print("Green light  ");
            userCmd = scnr.next();
            if (userCmd.equals("n")) { // Next
               lightVal = LightState.YELLOW;
            }
         }
         else if (lightVal == LightState.YELLOW) {
            System.out.print("Yellow light  ");
            userCmd = scnr.next();
            if (userCmd.equals("n")) { // Next
               lightVal = LightState.RED;
            }
         }
         else if (lightVal == LightState.RED) {
            System.out.print("Red light  ");
            userCmd = scnr.next();
            if (userCmd.equals("n")) { // Next
               lightVal = LightState.GREEN;
            }
         }

         if (userCmd.equals("r")) { // Force immediate red
            lightVal = LightState.RED;
         }
         else if (userCmd.equals("q")) { // Quit
            lightVal = LightState.DONE;
         }
      }

      System.out.println("Quit program.");
   }
}
