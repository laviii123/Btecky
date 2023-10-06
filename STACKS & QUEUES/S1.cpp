#include <bits/stdc++.h> 
using namespace std;
/*******************IMPLEMENTATION OF STACKS USING ARRAYS***********************/
class Stack {
private:
    int size;
    int tops;
    int * a;
public:
    
    Stack(int capacity) {
        size=capacity;
        tops=-1;
        a = new int[size];
    }
    void push(int num) {
      if (tops < size) {
        tops++;
        a[tops] = num;
      }
    }
    int pop() {
      if (tops >= 0) {
        int x = a[tops];
        tops--;
        return x;
      }
      else{
          return -1;
      }
    }
    
    int top() {
      if (tops >= 0) {
        return a[tops];
      }
      else{
          return -1;
      }
    }
    
    int isEmpty() {
        if(tops<0){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(tops>=size-1){
            return 1;
        }
        return 0;
    }
    
};
/***********************IMPLEMENTATION OF STACK USING LINKED LIST*******************/
struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};
void MyStack ::push(int x) 
{
    StackNode *newstack= new StackNode(x);
    newstack->next=top;
    top=newstack;
}
int MyStack ::pop() 
{
    // Your Code
    if(top == NULL) return -1;
        StackNode *temp = top;
        int x = top->data;

    top = top->next;

    delete temp;

    return x;
}
