// Java Program to show Internal Working
// of TreeMap in Java

// Importing Map and TreeMap classes
// from java.util package
import java.util.Map;
import java.util.TreeMap;

// Standard Comparable
public class Key implements Comparable<Key> {

	// Custom input
	final int data = 118;
	private String key;

	// Constructor of this class
	public Key(String key)
	{
		// Super keyword refers immediate parent class
		// object
		super();

		// This keyword is a reference variable
		// referring to current object
		this.key = key;
	}

	// Print Key method
	public String printKey() { return this.key; }

	// Override compareTo method
	@Override public int compareTo(Key obj)
	{
		return key.compareTo(obj.key);
	}
}

// Main Class
class GFG {

	// Main driver method
	public static void main(String[] args)
	{
		// Initialize TreeMap
		// Declaring object of String type
		Map<Key, String> treemap = new TreeMap<>();

		// Adding the elements in object of TreeMap
		// Custom inputs
		treemap.put(new Key("Key1"), "Alice");
		treemap.put(new Key("Key4"), "Zeya");
		treemap.put(new Key("Key3"), "Geek");
		treemap.put(new Key("Key2"), "Bob");

		// Iterate over object elements using for-each loop
		for (Map.Entry<Key, String> entry :
			treemap.entrySet())

			// Print elements in TreeMap object
			System.out.println(
				"[" + entry.getKey().printKey() + " = "
				+ entry.getValue() + "]");
	}
}
