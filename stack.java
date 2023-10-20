import java.util.ArrayList;
import java.util.EmptyStackException;

public class Stack<T> {
    private ArrayList<T> stack = new ArrayList<>();

    // Push an item onto the stack
    public void push(T item) {
        stack.add(item);
    }

    // Pop an item from the stack
    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.remove(stack.size() - 1);
    }

    // Peek at the top item of the stack
    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.get(stack.size() - 1);
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    // Get the size of the stack
    public int size() {
        return stack.size();
    }

    // Clear the stack
    public void clear() {
        stack.clear();
    }

    // Override toString for easy printing
    @Override
    public String toString() {
        return stack.toString();
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Stack: " + stack);
        System.out.println("Size: " + stack.size());

        System.out.println("Pop: " + stack.pop());
        System.out.println("Stack: " + stack);
        System.out.println("Size: " + stack.size());

        System.out.println("Peek: " + stack.peek());
    }
}
