// Java code to illustrate What if Heterogeneous
// Objects are Inserted

// Importing all utility classes
import java.util.*;

// Main class
class GFG {

	// Main driver method
	public static void main(String[] args)
	{

		// Object creation
		Set<StringBuffer> ts = new TreeSet<>();

		// Adding elements to above object
		// using add() method
		ts.add(new StringBuffer("A"));
		ts.add(new StringBuffer("Z"));
		ts.add(new StringBuffer("L"));
		ts.add(new StringBuffer("B"));
		ts.add(new StringBuffer("O"));
		ts.add(new StringBuffer(1));

		// Note: StringBuffer implements Comparable
		// interface

		// Printing the elements
		System.out.println(ts);
	}
}
