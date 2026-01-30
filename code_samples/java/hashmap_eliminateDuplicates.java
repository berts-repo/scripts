import java.util.*;

public class hashmap_eliminateDuplicates{
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 2, 4, 5, 1, 6, 4);

        // Create a HashMap to eliminate duplicates
        Map<Integer, Integer> uniqueMap = new HashMap<>();
        for (Integer number : numbers) {
            // The value can be set to any constant or null since we only care about the keys
            uniqueMap.put(number, null);
        }

        // Retrieve the unique elements
        List<Integer> uniqueNumbers = new ArrayList<>(uniqueMap.keySet());

        System.out.println("Original list: " + numbers);
        System.out.println("Unique list: " + uniqueNumbers);
    }
}
