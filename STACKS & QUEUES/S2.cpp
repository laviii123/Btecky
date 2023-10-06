#include<bits/stdc++.h>
using namespace std;
/*****************IMPLEMENTATION OF STACKS USING TWO QUEUES******************/
class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }  
    void push(int x) {
        q2.push(x);
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
      
    }
    
     int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
/******************IMPLEMENTATION OF STACKS USING SINGLE QUEUES***********/
class Stack {
	 queue<int>q;

   public:
    Stack() {
        
    }

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int x) {
        int sze= q.size();
        q.push(x);
        for(int i=0;i<sze;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
       if(q.size()==0){
           return -1;
       }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        if(q.size()==INT_MAX||q.size()==0){
            return -1;
        }
        return q.front();
    }
};