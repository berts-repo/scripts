/*
 * RecursiveSample.java
 * Compile: javac recursive_sample.java
 * Run:     java RecursiveSample
 */
class RecursiveSample {

    // Find the largest number in an array using recursion.
    public static int largest(int[] numbers, int index) {
        if (index == 0) {
            return numbers[0];
        }
        return Math.max(numbers[index], largest(numbers, index - 1));
    }

    // Multiply two positive integers using repeated addition.
    public static int multiply(int x, int y) {
        if (x == 0 || y == 0) {
            return 0;
        }
        return multiply(x - 1, y) + y;
    }

    // Compute the greatest common divisor (Euclid's algorithm).
    public static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    // Compute log base b of n, assuming n is a power of b.
    public static int logBase(int b, int n) {
        if (n == 1) {
            return 0;
        }
        return 1 + logBase(b, n / b);
    }

    // Sum the values from 1 to k.
    public static int sumToK(int k) {
        if (k <= 0) {
            return 0;
        }
        return k + sumToK(k - 1);
    }

    // Sum all positive odd numbers less than or equal to n.
    public static int addOdd(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n % 2 != 0) {
            return n + addOdd(n - 1);
        }
        return addOdd(n - 1);
    }

    // Sum the digits of a non-negative integer.
    public static int sumOfDigits(int number) {
        if (number < 10) {
            return number;
        }
        return number % 10 + sumOfDigits(number / 10);
    }

    // Count how many times "A" appears in the string.
    public static int countChr(String str) {
        if (str.length() == 0) {
            return 0;
        }
        int count = str.startsWith("A") ? 1 : 0;
        return count + countChr(str.substring(1));
    }

    public static void main(String[] args) {
        int[] nums = {3, 5, 2, 9, 1};
        System.out.println("Largest: " + largest(nums, nums.length - 1));
        System.out.println("Multiply 4*6: " + multiply(4, 6));
        System.out.println("GCD(48, 18): " + gcd(48, 18));
        System.out.println("logBase(2, 8): " + logBase(2, 8));
        System.out.println("Sum to 5: " + sumToK(5));
        System.out.println("Add odd <= 9: " + addOdd(9));
        System.out.println("Sum of digits 1234: " + sumOfDigits(1234));
        System.out.println("Count of 'A' in 'ABRACADABRA': " + countChr("ABRACADABRA"));
    }
}
