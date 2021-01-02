#include <iostream>
#include <stdlib.h>

using namespace std;

class Queue {
    int rear,Size;
    int* arr;

 public:
    Queue(int s = 5){
        this->Size = s;
        arr = new int[this->Size];
        rear = -1;
    }

    int isFull(){
        return ( rear == this->Size - 1 );
    }

    int isEmpty(){
        return ( rear == -1 );
    }

    void enqueue(int d){
        if ( isFull() ){
            cout << "sorry the Queue is full" << endl;
            return;
        }
        else{
            rear++;
            arr[rear] = d;
        }
    }

    int dequeue( int & z ){
        if ( isEmpty() ){
            cout << "the queue is empty" << endl;
            return 0;
        }
        else{
            z = arr[0];
            for (int i = 0;i <= rear;i++){
                arr[i] = arr[i+1];
            }
            rear--;
        }
    return 1;
    }

    void display(){
        if ( isEmpty() ){
            cout << "sorry the queue is empty" << endl;
            return;
        }
        else{
            for (int i = 0;i <= rear;i++){
                cout << arr[i] <<endl;
            }
        }
    }

};

int main()
{
    int Size = 0,d = 0,z = 0;
    char ch;

    cout << "please enter number of elements" << endl;
    cin>> Size;
    Queue myQueue(Size);

    do {
            cout << "Add('Enqueue') \nDequeue \nShowData \nExit \n" <<endl;
            cin >> ch;
            system("CLS");
            switch ( ch ){
                    case 'a':
                        cout << "enter the element" << endl;
                        cin >> d;
                        myQueue.enqueue(d);
                        break;
                    case 'd':
                        myQueue.dequeue(z);
                        cout << "the deleted element = " << z <<endl;
                        break;
                    case 's':
                        myQueue.display();
                        break;
                    case 'e':
                        exit(0);
                }

    } while ( ch != 'e' );

    return 0;
}
