import java.util.Arrays;
public class HelloWorld{
	public static void main(String[] args){
	
		int[]x = {10,4,15,2};
		test(x);
	}
	public static void test(int[] nums) {
		for (int i=0; i<nums.length-1; i++) {
			int index = i;
				for (int j=i+1; j<nums.length; j++){
					if (nums[index] < nums[j])
						index = j;}

							  // process
							  int tmp = nums[index];
							  nums[index] = nums[i];
			nums[i] = tmp;
		}
		System.out.println( Arrays.toString(nums) );
	}
}
