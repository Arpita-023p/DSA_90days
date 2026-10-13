import java.util.Arrays;

public class Secondlargest {
    public static void main(String[] args) {
        int arr[] = { 45, 12, 45, 67, 23, 67, 43 };
        int largest = Integer.MIN_VALUE;
        int secondlargest = Integer.MIN_VALUE;
        
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            if (num > largest) {
                secondlargest = largest;
                largest = num;
            } else if (num < largest && num > secondlargest) {
                secondlargest = num;
            }
        }
        System.out.println("the second largest number is " + secondlargest);
    }
}