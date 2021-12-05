// Jack Carson
// CPSC 1070
// Project 3
// 25 October 2021

# ifndef QUEUE_H
# define QUEUE_H

/* Queue defines a linked list structure along with a nodeCount 
counter, and maxSize of 100. pointers to the head and tail of the
Queue are used to perform operations such as enqueue, dequeue, and check
the size of the Queue. */
class Queue {
    private:
    /* Queue struct contains a QueueNode *next pointer that creates
    a self-referencing data structure that points to itself using 
    the next pointer */
        struct QueueNode {
            int data; 
            QueueNode *next;
            QueueNode(int data1, QueueNode *next1 = nullptr) {
                data = data1;
                next = next1;
            }
        }; 
        QueueNode *head; 
        QueueNode *tail; 
        int nodeCount;
        int maxSize = 100;
    public:
    /* Queue constructor initializes the head and tail pointers to nullptr
    Queue destructor uses a temporary pointer to iterate through the queue
    and unlinks each node and deletes it before moving to the next node 
    until the tail that points to nullptr is reached. Functions and helper
    Function declarations are also provided below. */
        Queue() {
            head = nullptr;
            tail = nullptr;
            nodeCount = 0;
        }; 
        ~Queue() {
            QueueNode *garbage = head;
            while (garbage != nullptr) {
                head = head->next;
                garbage->next = nullptr;
                delete garbage;
                garbage = head;
            }
        };

        bool isFull();
        bool isEmpty();
        int dequeue(int);
        int enqueue(int);
        void clearQueue(); 
        void printQueue(int, int); 
};

# endif