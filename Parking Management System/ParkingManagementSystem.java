import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import java.time.LocalTime;
import java.time.LocalDate;

import java.text.ParseException;
import java.util.InputMismatchException;
import java.text.SimpleDateFormat;

class ParkingManagementSystem {

    static class Parking {

        public static int[][] two_wheeler = new int[4][10]; // for 2 wheeler vehicles with 4 rows and 10 cols
        public static int[][] four_wheeler = new int[10][10]; // for four wheeler vehicles with 10 rows and 10 cols

        static void filled() {
            // Assigning 1 at random positions, denoting the slots are full
            for (int i = 0; i < two_wheeler.length; i++) {
                for (int j = 0; j < two_wheeler[i].length; j++) {
                    int f = (int) (Math.random() * 10);           // Math.random() gives a value from [0,1), making f to be any random value in range [0,10).
                    if (f > 3)
                        two_wheeler[i][j] = 1;                           // denotes this slot is filled
                }
            }

            for (int i = 0; i < four_wheeler.length; i++) {
                for (int j = 0; j < four_wheeler[i].length; j++) {
                    int f = (int) (Math.random() * 10);
                    if (f > 4)
                        four_wheeler[i][j] = 1;
                }
            }
        }


        static void enter() {
            System.out.println("\n \n Vehicle entered... System Starting!");

            Scanner sc = new Scanner(System.in);

            System.out.println("Enter Vehicle Type: 2 Wheeler/4 Wheeler");
            char type = sc.next().charAt(0);

            System.out.println("Enter the Vehicle Plate number");
            String plate_no = sc.next();

            System.out.println("Enter Vehicle Owner's name");
            String name = sc.next();

            String slot = null; 

            if (type == '2') {
                slot = getVacantSlot(two_wheeler);                      // Assign the return value of the getVacantSlot method to variable 'slot'
                // if int [][]two_wheeler is written instead of tow _wheeler then why error is there??????
            } 
            else if (type == '4') {
                slot = getVacantSlot(four_wheeler);                     // Assign the return value of the getVacantSlot method to variable 'slot'
            }

            // If 'slot' is null, it means there is no vacant slot available. 
            if (slot == null) {
                System.out.println("No vacant slot available for parking.");
                return;                                                   // ends the method
            }

            //If slot is Vancant then proceed to generate a Ticket for the customer
            LocalTime entry_time = LocalTime.now();
            LocalDate date = LocalDate.now();

            Ticket ticket = new Ticket(name, plate_no, slot, type, entry_time, date); // constructor of class Ticket
            System.out.println("\nTicket generated:");
            System.out.println(ticket);

            // After the slot is alloted to the customer and Ticket is generated, update the Vacant slots. (assigned slot must be marked 1) 
            updateSlot(slot, type);
        }

        static void updateSlot(String slot, char type) {  
             // After the slot is alloted to the customer and Ticket is generated, assigned slot must be marked 1 
            int[][] array;
            if (type == '2') {
                array = two_wheeler;
            } else if (type == '4') {
                array = four_wheeler;
            } else {
                return;
            }

            int x = slot.charAt(0) - 65;
            int y = Character.getNumericValue(slot.charAt(1)) - 1;
            array[x][y] = 1; // slot marked as filled
            System.out.println(slot + " is marked filled");                            // slot marked as filled

            System.out.println("\n Opening the Barrier. \nPlease park your Vehicle at " + slot);
        }

        static String getVacantSlot(int array[][]) {                        // Start tarversing the array and find the Vacant Slot

            for (int a = 0; a < array.length; a++) {
                for (int b = 0; b < array[a].length; b++) {
                    if (array[a][b] == 0) {

                        String slotrow = String.valueOf((char) (a + 65));
                        String slotcol = String.valueOf((b + 1));
                        String slot = slotrow + slotcol;
                        System.out.println("\n slot found is " + slot);

                        return slot;                                         // the nearest (first) Vacant slot is returned as A4,C1,D5,etc.
                    }

                }

            }

            return null;
        }

        // When car is leaving the Parking, change the Vacant slot
        static void change_slot_value(String exiting_slot) throws ParseException, ArrayIndexOutOfBoundsException {
            Scanner fsc = new Scanner(System.in);
            int x = 0;
            int y = 0;

            // TO EXTRACT ONE CHARACTER AND ONE NUMBER FROM A STRING
            for (int i = 0; i < exiting_slot.length(); i++) {
                char te = exiting_slot.charAt(i);
                if (i == 0) {
                    x = (int) te - 65;
                } else {
                    y = (int) te - 49;
                }

            }

            System.out.println("Is it a 2 wheeler or 4 wheeler");
            int exitingVehicleType = fsc.nextInt();

            if (exitingVehicleType == 2) {
                two_wheeler[x][y] = 0;                                // slot from where the vehicle came is now marked empty
            } else {
                four_wheeler[x][y] = 0;
            }

            System.out.println("\n " + exiting_slot + " is empty now");

            System.out.println("\n Enter out_time of Vehicle as HH:MM:SS");
            String out_time = fsc.next();

            System.out.println("Press 1 to generate Ticket");
            int price_choice = fsc.nextInt();

            if (price_choice == 1) {
                pricecalc(out_time);
            }
        }

        static void pricecalc(String endtime) throws ParseException {    // Calculate the price to be charged on the basis of number of hours (12 Rs. per hour)
            LocalTime t1 = LocalTime.now();
            System.out.println("\n in time is " + t1);
            String startTime = String.valueOf(t1);

            // Customize time format
            SimpleDateFormat format = new SimpleDateFormat("hh:mm:ss");
            Calendar c = Calendar.getInstance();

            c.setTime(format.parse(startTime));
            long startMillis = c.getTimeInMillis();

            c.setTime(format.parse(endtime));
            long endMillis = c.getTimeInMillis();

            System.out.println("\n Parking time is " + ((endMillis - startMillis) / 1000) / 60 + " minutes. Or "  + ((endMillis - startMillis) / 1000) / 3600 + " hours");
            double price = (((endMillis - startMillis) / 1000) / 60) * 0.2;
            System.out.println("\nPay Rs." + price + " \n  ... Thank you for using our Services!");

        }

    }





    static class Ticket {                                                    //Ticket with necessary info to generate the ticket
        String name, plate_no, slot;
        char type;
        LocalTime entry_time;
        LocalDate date;

        Ticket(String n, String p, String s, char t, LocalTime et, LocalDate d) {
            name = n;
            plate_no = p;
            slot = s;
            type = t;
            entry_time = et;
            date = d;
        }

        @Override
        public String toString() {
            return "Ticket Details: \n" + "Name: " + name + "\n" + "Plate Number: " + plate_no + "\n" +
                    "Slot: " + slot + "\n" + "Type: " + type + " Wheeler\n" + "Entry Time: " + entry_time + "\n" +
                    "Date: " + date + "\n";
        }                                                                      // Printing the ticket when called upron vehicle entry
    }
/*Contribted by VANSHAJB10*/
    public static void main(String[] args) throws ParseException {

        Parking.filled();                            // Fill the parking slot randomly (assigning dummy vehicles for program enhancement)

        Map<String, String> mp = new HashMap<>();    // A hashmap to map the plate_number with the slot number on which this vehicle is parked
        String a, b;
        int totalentries;
        /*Contribted by VANSHAJB10*/

        while (true) {
            Scanner sc = new Scanner(System.in);
            System.out.println(
                    "\n Press 1 to enter Ticket Mode \n Press 2 to enter data entry mode \n Press 3 to Exit the vehicle \n Press any other key to exit System.");
            
            int mode;
            try{
            mode = sc.nextInt();
            }
            catch (InputMismatchException e) {
                System.out.println("Invalid input. Exiting the system.");
                break;
            }

            if (mode == 1) {
                int number_entering_parking;
                System.out.println("How many vehicles are entering?");

                try{
                 number_entering_parking = sc.nextInt();
                }
                catch (InputMismatchException e) {
                    System.out.println("Invalid input. Exiting the system.");
                    break;
                }

                for (int i = 0; i < number_entering_parking; i++) {
                    Parking.enter();
                }

            } 
            
            else if (mode == 2) {
                System.out.println("How many vehicles Just entered?");
                try{
                totalentries = sc.nextInt();
                }
                catch (InputMismatchException e) {
                    System.out.println("Invalid input. Exiting the system.");
                    break;
                }

                for (int v = 0; v < totalentries; v++) {
                    System.out.println("Enter Plate_Number of vehicle " + (v + 1) + " and press Enter Key");
                    a = sc.next().toUpperCase(); 

                    System.out.println("Enter Slot_Number of vehicle " + (v + 1));
                    b = sc.next().toUpperCase();

                    mp.put(a, b);                                             // put the key-value pair into hashmap

                    System.out.println("Data recorded Successfully!");

                }
            } 


            else if (mode == 3) { 
                System.out.println("Enter plate number");
                try{
                String Plate = sc.next().toUpperCase();
                String temp = mp.get(Plate);                               // get the value for the key entered (Plate_number) and assignit to temp
                Parking.change_slot_value(temp); 
                }
                catch(Exception e){
                    System.out.println("No such vehicle exist");
                }
            } 
            else {
                System.exit(0);                                     // To exit the menu
            }
        }
    }
}
