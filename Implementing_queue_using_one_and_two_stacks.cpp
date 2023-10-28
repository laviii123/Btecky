#include <bits/stdc++.h>
using namespace std;

// using 2 stacks

class Queue{
  public:
  stack<int> st1,st2;
   void enqueue(int data);
   void dequeue();


};

void Queue::enqueue(int data)
{
   st1.push(data);
   cout<<"Pushed: "<< st1.top()<<endl;
}

void Queue::dequeue()
{
    if(st1.empty())
    {
        cout<<"Underflow"<<endl;
        return;
    }
    while(!st1.empty())
    {
      st2.push(st1.top());
      st1.pop();
    }

    cout<<"Popped: "<< st2.top()<<endl;
    st2.pop();
    while(!st2.empty())
    {
      st1.push(st2.top());
      st2.pop();
    }

}


int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}


// Using 1 stack only...

class Queue{
  public:
  stack<int> st;
   void enqueue(int data);
   int dequeue();
 
  

};


void Queue::enqueue(int data)
{
  st.push(data);
  cout<<data<<": pushed"<<endl;
}

int Queue::dequeue()
{
    if(st.empty())
    {
        cout<<"UnderFlow"<<endl;
        return -1;
    }

    int top=st.top();
    st.pop();

    if(!st.empty())
    {
       int deque_ele=dequeue();
       st.push(top);
       return deque_ele; 
    }
    
    return top;
    


}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
   cout<< q.dequeue()<<" :Popped"<<endl;
   cout<< q.dequeue()<<" :Popped"<<endl;
   cout<< q.dequeue()<<" :Popped"<<endl;
   cout<< q.dequeue()<<" :Popped"<<endl;
   cout<< q.dequeue()<<" :Popped"<<endl;

}
