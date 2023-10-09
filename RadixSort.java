public class RadixSort {
  
    public static void displayarr(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
  
    public static int findmax(int[] arr) {
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] > max)
            max = arr[i];
        }
        return max;
    }
  
    public static void countsort(int[] arr,int place) {
        int n = arr.length;
        int length = findmax(arr);
        int freq[] = new int[10];
        for(int i = 0; i < arr.length; i++) {
            freq[(arr[i]/place)%10]++;
        }
      
        //Prefix sum of the frequency array
        for(int i = 1; i < freq.length; i++) {
            freq[i] += freq[i - 1];
        }
        int output[] = new int[n];
      
        //find the correct positon and put in the original array from the output array
        for (int i = n-1; i >= 0; i--) {
            int idx = freq[(arr[i]/place)%10] - 1;
            output[idx] = arr[i];
            freq[(arr[i]/place)%10]--;
        }
        for(int i = 0;i < n; i++) {
            arr[i] = output[i];
        }
    }
  
    static void radixsort(int[] arr) {
        int max = findmax(arr);
        for(int place = 1; max/place > 0; place *= 10) {
            countsort(arr,place);
        }
    }
  
    public static void main(String[] args) {
        int arr[] = {170,45,75,90,802,2};
        radixsort(arr);
        displayarr(arr);
    }
}


// SAMPLE OUTPUT
// INPUT -> {170, 45, 75, 90, 802, 2}
// OUTPUT -> {2, 45, 75, 90, 170, 802}
