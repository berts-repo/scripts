/*
 *
 *  Bert Darnell
 *  10-29-22
 *  CS252
 *  Unit 2
 *
 *  This program test and takes an array, and right shifts the indexes and swaps the last index with the first.
 *  It then returns the new array.
 *
 */

import java.util.Arrays;
public class ArraysRightShift {

	// Method: right shifts an array into a new array, and rotates last index to the first.

	public static int[] shiftRight( int[] oldArray ){

		int[] newArray = new int[oldArray.length];

		for (int i = 0; i < oldArray.length; ++i){
			
			if ( i == oldArray.length - 1 )		// Swaps last index with first
				newArray[0] = oldArray[i];
			else								// Right shifts			
				newArray[i + 1] = oldArray[i]; 
		}
		
		return newArray;
	}
	public static void main(String[] args) {

		// Testing: arrays

		int[] test1 = { 1, 2, 3, 4, 5 };
		int[] test2 = { 1, 2 };
		int[] test3 = { 20 };
		int[] test4 = {};
		int[] test5 = { -1, -2, -3, -4, -5 };

		// Testing: returned array from method
		
		int[] return1 = shiftRight( test1 );	
		int[] return2 = shiftRight( test2 );	
		int[] return3 =	shiftRight( test3 );	
		int[] return4 =	shiftRight( test4 );	
		int[] return5 =	shiftRight( test5 );	

		// Testing: print if oldArray == newArray

		if (Arrays.equals(return1, test1) ) 
			System.out.println( "Rightshift failed. Got " + Arrays.toString(return1) );
		else
			System.out.println( "Rightshift successful. Got " + Arrays.toString(return1) );

		if (Arrays.equals(return2, test2) ) 
			System.out.println( "Rightshift failed. Got " + Arrays.toString(return2) );
		else
			System.out.println( "Rightshift successful. Got " + Arrays.toString(return2) );

		if (Arrays.equals(return3, test3) ) 
			System.out.println( "Rightshift failed. Got " + Arrays.toString(return3) );
		else
			System.out.println( "Rightshift successful. Got " + Arrays.toString(return3) );

		if (Arrays.equals(return4, test4) ) 
			System.out.println( "Rightshift failed. Got " + Arrays.toString(return4) );
		else
			System.out.println( "Rightshift successful. Got " + Arrays.toString(return4) );

		if (Arrays.equals(return5, test5) ) 
			System.out.println( "Rightshift failed. Got " + Arrays.toString(return5) );
		else
			System.out.println( "Rightshift successful. Got " + Arrays.toString(return5) );
	}
}
