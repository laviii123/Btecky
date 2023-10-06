#include<bits/stdc++.h>
using namespace std;
/***************QUEUE USING TWO STACKS AND BY MAKING ENQUEUE OPERATION COSTLY*********/
class Queue1 {
private: 
    stack<int>s1;
    stack<int>s2;
public:
    Queue1() {
        
    }
    void enqueue(int x) {
       while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
       } 
       s1.push(x);
       while(!s2.empty()){
           s1.push(s2.top());
           s2.pop();
       }
    }
    
    int dequeue() {
        if(s1.size()==0){
            return -1;
        }
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if(s1.size()==0){
            return -1;
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/***************QUEUE USING TWO STACKS AND BY MAKING DEQUEUE OPERATION COSTLY*********/
class Queue2 {
public:
    stack<int> s1,s2;
    Queue2() {
        
    }
    
    void enqueue(int x) {
        s1.push(x);
    }
    
    int dequeue() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

