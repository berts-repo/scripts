import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class WordCount {
    public static void main(String[] args) {
        String fileName = "some.txt";
        int lineCount = 0;
        int wordCount = 0;
        int charCount = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lineCount++;
                charCount += line.length();
                String[] words = line.split("\\s+");
               // NOTE: "\\s" is a regular expression that represents a whitespace character and "+" is a quantifier that specifies that the preceding pattern (\\s) should appear one or more times consecutively. So, "\\s+" represents one or more consecutive whitespace characters.
                for (String word : words) {
                    if (!word.isEmpty() && Character.isLetterOrDigit(word.charAt(0))) { // If the word is not empty and the first character is a letter or digit
                        wordCount++;
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }

        System.out.println("File: " + fileName);
        System.out.println("Lines = " + lineCount);
        System.out.println("Words = " + wordCount);
        System.out.println("Chars = " + charCount);
    }
}

