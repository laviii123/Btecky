import java.util.Scanner;
import java.util.Random;
public class guessgame{
    public static void main(String args[]){
        Scanner scanner=new Scanner(System.in);
        Random random = new Random();
        int lowerlimit=1;
        int upperlimit=100;
        int attempts=0;
        int correct= random.nextInt(upperlimit - lowerlimit + 1) + lowerlimit;
        System.out.println("Welcome to guess game");
        System.out.println("please enter numbers between 1 to 100 only to guess");
        while(true){
                System.out.println("Enter your guessed number:");
                if (scanner.hasNextInt()){
                     int userguess=scanner.nextInt();
                     attempts++;
                     if(userguess < lowerlimit || userguess > upperlimit){
                        System.out.println("please Enter a number between" + lowerlimit + "and" + upperlimit + ".");
                     }
                     else if (userguess < correct){
                        System.out.println("Too low! Try again");

                     }
                     else if(userguess > correct){
                        System.out.println("Too high! Try again");
                     }
                     else{
                        System.out.println("Congratulations You are Guessed correct number" + "("+correct+")" + "in"  + attempts + "attempts");
                        break;
                    }

                }
                else{
                    System.out.println("Please enter a valid number.");
                    scanner.nextLine();
                }
        }
        scanner.close();

    }
}
