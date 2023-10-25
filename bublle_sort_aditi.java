package Btecky;

public class bublle_sort_aditi {
    public static void main(String[] args) {
        int[] var1 = new int[] { 5, 8, 1, 2, 9 };
        int var2;
        for (var2 = 0; var2 < var1.length - 1; ++var2) {
            for (int var3 = 0; var3 < var1.length - 1 - var2; ++var3) {
                if (var1[var3] > var1[var3 + 1]) {
                    int var4 = var1[var3];
                    var1[var3] = var1[var3 + 1];
                    var1[var3 + 1] = var4;
                }
            }
        }
        for (var2 = 0; var2 < var1.length; ++var2) {
            System.out.println(var1[var2]);
        }

    }
}
