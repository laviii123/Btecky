import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the element to search for: ");
        int target = scanner.nextInt();

        int result = linearSearch(arr, target);

        if (result == -1) {
            System.out.println("Element " + target + " not found in the array.");
        } else {
            System.out.println("Element " + target + " found at index " + result);
        }

        scanner.close();
    }

    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // Return the index of the target element if found
            }
        }
        return -1; // Return -1 if the target element is not found in the array
    }
}
