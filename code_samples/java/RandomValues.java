/*
 *	the Random class genereates numbers between (-2^31) to (-2^31 - 1) 
 *
 *
 *
 */

import java.util.Random;

public class RandomValues {
	public static void main(String[] args) {
	
		Random randGen = new Random(); // you can set Random(<seed>)
		
		System.out.println(randGen.nextInt());
		System.out.println(randGen.nextInt());
		System.out.println(randGen.nextInt());
/*
 *	Values in the range of 0 to 5
 */
		System.out.println( randGen.nextInt(5+1));
		System.out.println( randGen.nextInt(5+1));
		System.out.println( randGen.nextInt(5+1));
/*
 *	Values between 10 and 25
 */	
		System.out.println( randGen.nextInt(15+1)+ 10);
		System.out.println( randGen.nextInt(15+1) + 10);
		System.out.println( randGen.nextInt(15+1) + 10);
/*
 *	Values between -3 to 3
 */	
		System.out.println( randGen.nextInt(6+1) + -3 );
		System.out.println( randGen.nextInt(6+1) + -3 );
		System.out.println( randGen.nextInt(6+1) + -3 );

	}
}
