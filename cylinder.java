import java.util.Scanner;

class Volume {
    private double radius;
    private double height;

    public Volume(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public double calculateVolume() {
        return Math.PI * radius * radius * height;
    }

    public void printVolume() {
        double volume = calculateVolume();
        System.out.println("Volume of the cylinder: " + String.format("%.2f", volume));
        System.out.println("Program by Tilakkumar Dadhania, Lab section #332, Lab Professor Shavit Lupo");
    }
}

public class Cylinder {
    public static void main(String[] args) {
        System.out.println("Welcome to my code:");
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter radius:");
        double radius = scan.nextDouble();
        System.out.println("Enter height:");
        double height = scan.nextDouble();
        
        Volume cylinder = new Volume(radius, height);
        cylinder.printVolume();
    }
}
