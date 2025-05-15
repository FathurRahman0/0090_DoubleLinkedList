#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1 : ALLcote memory for new node
        Node *newNode = new Node();
        // step 2: Assign value to the data field
        newNode->noMhs = nim;

        // step 3 : insert ar the beginning if list is empty or nim is smaller than the first node
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4 : newnode.next = start
            newNode->next = START;

            // step 5 : start.prev = newnode (if start exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6 : newnode.prev = null
            newNode->prev = NULL;

            // step 7 : start = newnode
            START = newNode;
            return;
        }

        // insert in between node
        // step 8 : Locate position to insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }
        // Step 9 : insert between current and current->next
        newNode->next =  current->next; // Step 9a : newNode.Next
        newNode->prev = current;        // Step 9b : newNode.prev

        // insert lost node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c: current->next.prev = newnode

        current->next = newNode; // step 9d: current.next = newnode
    }

       

}
