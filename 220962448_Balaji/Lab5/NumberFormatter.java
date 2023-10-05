import java.util.*;

public class NumberFormatter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Give input: ");
        String input = sc.nextLine(); // Replace with your input string
        String formattedNumber = format(input);
        System.out.println("Input String: " + input);
        System.out.println("Output String: " + formattedNumber);
        sc.close();
    }

    static String format(String number) {
        int counter = 0;
        String temp = "";
        int n = number.length();
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1 && counter == 0) {
                temp += ",";
            }
            counter = (counter + 1) % 3;
            temp += number.charAt(n - i - 1);
        }
        return temp;
    }
}