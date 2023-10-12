#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int rear, front, size;
    int *cqueue;

public:
    Queue(int c)
    {
        front = rear = -1;
        size = c;
        cqueue = new int[c];
    }

    bool(isfull())
    {

        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool(isempty())
    {
        return front == -1;
    }

    void cqueueEnqueue(int value)
    {
        if (isfull())
        {
            printf("Queue is Full\n");
            return;
        }

        else if (front == -1)
        {
            front = rear = 0;
            cqueue[rear] = value;
        }

        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            cqueue[rear] = value;
        }

        else
        {
            rear++;
            cqueue[rear] = value;
        }
    }

    void cqueueDequeue()
    {
        if (isempty())
        {
            printf("Queue is Empty\n");
            return;
        }

        int data = cqueue[front];
        cqueue[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;

        cout << "Element deleted:" << data << endl;
    }

    void cqueuedisplay()
    {
        if (isempty())
        {
            printf("Queue is Empty\n");
            return;
        }
        printf("\nElements in Circular Queue are: ");
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", cqueue[i]);
            cout << endl;
        }
        else
        {
            for (int i = front; i < size; i++)
                printf("%d ", cqueue[i]);

            for (int i = 0; i <= rear; i++)
                printf("%d ", cqueue[i]);
            cout << endl;
        }
    }
};
int main()
{
    int n, ch = 0, ele;
    cout << "Enter the size of the queue" << endl;
    cin >> n;
    Queue q(n);
    cout << "Menu\n1 for insertion\n2 for deletion\n3 for display\n4 to check if the queue is empty\n5 to check if the queue is full\n6 for exit\n ";

    while (1)
    {
        cout << "Enter your choice\n";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the element you want to insert\n";
            cin >> ele;
            q.cqueueEnqueue(ele);
        }
        else if (ch == 2)
        {
            q.cqueueDequeue();
            // cout<<"Element deleted:"<<q.cqueueDequeue()<<endl;
        }
        else if (ch == 3)
        {
            q.cqueuedisplay();
        }
        else if (ch == 4)
        {
            if (q.isempty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        }
        else if (ch == 5)
        {
            if (q.isfull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
        }
        else
            break;
    }
    return 0;
}