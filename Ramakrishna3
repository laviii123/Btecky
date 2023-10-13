import java.util.*;
public class ArrayStack < E > {

    public static final int CAPACITY = 1000; // default array capacity
    private int topIndex; // index of the top element in stack
    private E[] data; // generic array used for storage
    

    public ArrayStack() {
        this(CAPACITY);
    } // constructs stack with default capacity

    public ArrayStack(int capacity) { // constructs stack with given capacity
        topIndex = -1;
        data = (E[]) new Object[capacity]; // safe cast; compiler may give warning
    }

    public int size() {
        return (topIndex + 1);
    }

    public boolean empty() {
        return (topIndex == -1);
    }

    public void push(E e) throws IllegalStateException {
        if (size() == data.length) throw new IllegalStateException("Stack is full");
        data[++topIndex] = e; // increment topIndex before storing new item
    }

    public E peek() throws EmptyStackException {
        if (empty()) throw new EmptyStackException();
        return data[topIndex];
    }

    public E pop() throws EmptyStackException {
        if (empty()) throw new EmptyStackException();
        E answer = data[topIndex];
        data[topIndex] = null; // dereference to help garbage collection
        topIndex--;
        return answer;
    }

    public static void main(String args[]) {
        ArrayStack < Integer > mystack = new ArrayStack<>();
        mystack.push(9); //a
        mystack.push(3); //b    
        mystack.push(8); //c 
        System.out.println("Element at the top is :" + mystack.peek()); //d
        System.out.println("Element removed is : " + mystack.pop()); //e
        System.out.println("The size of the stack is : " + mystack.size()); //f
        System.out.println("Element removed is : " + mystack.pop()); //g
        System.out.println("Element at the top is : " + mystack.peek()); //h 
        mystack.push(10); //i
        System.out.println("Stack is empty :  " + mystack.empty()); //j
    /*Note: In output charecters of the comments are written to correspond the 
    output, they won't be printed.*/
    }
}
