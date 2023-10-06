#include<bits/stdc++.h>
using namespace std;
/*********************QUEUE USING LINKED LIST***************/
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* temp = new QueueNode(x);
        if(front == NULL){
           front = rear = temp;
            return;
          }
        rear->next=temp;
        rear=temp;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code 
        int val;
         QueueNode* temp=front;
        if(front==NULL){
            return -1;
        }
       else {
           front=front->next;
           val= temp->data;
           delete temp;
           return val;
       }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
 }

