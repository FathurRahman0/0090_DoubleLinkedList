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
    
    void hapus()
    {
        if(START == NULL)
        {
            cout <<"\nlist is empty" << endl;
            return;
        }
        
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // step 1: Traverse the list to find the node
            while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            if (current == NULL)
            {
                cout << "Record not found" << endl;
                return;
            }

                // step 2: if node is at the beginning
                if (current == START)
                {
                    START = current->next; // Step 2a: START = START.next
                    if(START != NULL)
                       START->prev = NULL; // Step 2b: START.prev = NULL
                }
                else
                {
                // Step 3: Link previous node to next of current
                current->prev->next = current->next;

                 // step 4: if current is not the last node
                if (current->next != NULL)
                current->next->prev = current->prev;
                }
                // step 5: delete the node
                delete current;
                cout << "record with roll number " << rollNo << "deleted" << endl;
        }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nlist is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        Node *currentNode = START;
        
        // Step 2: Repeat untill currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {

                cout << i + 1 << "." << currentNode->noMhs << " " << endl;

                //Step 3: Move to next node
                currentNode = currentNode->next;
                i++;
        }
    }
        


         }




       

}
