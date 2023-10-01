package diceroller;

/*
 * DiceRoller takes a number of dice and the number of sides
 * on each dice, "rolls" them, and displays them in an array.
 * 
 * To use this program, enter the numbers in the console when
 * prompted to do so.
 */

import java.io.*;
import java.util.Random;

class DiceRoller {
    
    // Get number of sides on each die.
    private static int getDiceSides() {
        int sides = 0;
        
        System.out.print("How many sides are on the dice? ");
        try {
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(System.in));
            sides = Integer.parseInt(br.readLine());
        } catch(IOException exc) {
            System.out.println("I/OException: " + exc);
        }
        
        return sides;
    }
    
    // Get total number of dice to roll.
    private static int getNumberOfDice() {
        int dice = 0;
        
        System.out.print("How many dice to roll? ");
        try(BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in))) {
            dice = Integer.parseInt(br.readLine());
        } catch(IOException exc) {
            System.out.println("I/OException: " + exc);
        }
        
        return dice;
    }
    
    // Roll total number of dice within range of sides.
    private static int[] rollDice(int sides, int dice) {
        int[] numbers = new int[dice];
        Random rand = new Random();
        
        for(int i=0; i < dice; i++) {
            numbers[i] = rand.nextInt(sides);
        }
        
        return numbers;
    }
    
    // Display output from rolling dice given sides and number of dice.
    public static void main(String args[]) {
        int sides = getDiceSides();
        int dice = getNumberOfDice();
        
        int[] numbers = rollDice(sides, dice);
        
        System.out.print("Rolls: ");
        for(int n: numbers) {
            System.out.print(n + " ");
        }
    }
}
