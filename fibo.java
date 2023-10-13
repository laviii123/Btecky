import java.util.*;

class fibbo 
{
    int a;
    int b;

    fibbo() 
    {
        // Default constructor
        a = 0;
        b = 0;
    }

    fibbo(int x, int y) 
    {
        // Parameterized constructor
        a = x;
        b = y;
    }

    public int fibterm() 
    {
        int c = a + b;
        a = b;
        b = c;
        return c;
    }
}

public class fibbonaci 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of terms");
        int n = sc.nextInt();
        fibbo ob = new fibbo(0,1);
        System.out.println("The fibbonacci terms are:");
        if (n == 1 ) 
        {
            System.out.println(ob.a);
        }
        if (n == 2 || n>2) 
        {
            System.out.println(ob.a);
            System.out.println(ob.b);
        }
        if(n>2)
        {
            for (int i = 3; i <= n; i++) 
            {
                System.out.println(ob.fibterm());
            }
        }
        sc.close();
    }
}
