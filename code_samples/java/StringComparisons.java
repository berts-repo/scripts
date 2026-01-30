public class StringComparisons{
	public static void main (String[] args){
	
	String str1 = "Alpha";
	String str2 = "Beta";
	String str3 = str1;
/*
 *	Comparing str1.compareTo(str2)
 *		str1 < str2 returns negative
 *		str1 == str returns 0
 *		str1 > str2 returns positive 
 *		
 */
	System.out.println(str1.compareTo(str2));	

/*
 *	Returns true if str1 == str3
 */
	System.out.println(str1.equals(str3));
	}
}
