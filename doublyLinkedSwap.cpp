

/*Description: This program implements a doubly linked list with a "dummy" node at each end (head and tail)
 and provides a swapWithNext function that swaps a node pointed to by p with its next node by adjusting the pointers 
linking the nodes, without changing their data values. It also includes utility functions to create the linked list from 
an array, retrieve nodes by index, and print the list forwards and backwards. Thank you for reading my code! :):):)  */

#include "doublyLinkedSwap.h"

// Implement the following function:
// p and afterp are pointers to the nodes to be swapped.
void swapWithNext(Node* p) {
    // Check if the given node or its neighbors are NULL or if the second neighbor is NULL
    if (p == NULL || p->prev == NULL || p->next == NULL || p->next->next == NULL) 
    {
        // If any of the conditions are met, return without performing any swaps
        return;
    }

    // Store pointers to the previous and next nodes in temporary variables
    Node* oldPrev = p->prev;
    Node* oldNext = p->next;

    // Update pointers to skip over the next node
    p->next = p->next->next;
    p->next->prev = p;

    // Update pointers of the previous node to point to the new next node
    oldPrev->next = oldNext;
    oldNext->prev = oldPrev;

    // Update the previous pointer of the current node to point to the new next node
    p->prev = oldNext;

    // Update the next pointer of the new next node to point to the current node
    oldNext->next = p;
}



/*//Be sure to comment out the main() function when submitting to codePost
int main()
{
    int array[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    Node * head = arrayToList(array, 10);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [0],[1]" << endl;
    Node * p = getNode(head, 0);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [4],[5]" << endl;
    p = getNode(head, 4);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [8],[9]" << endl;
    p = getNode(head, 8);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
}*/

//Do not modify any functions below this line
Node * arrayToList(int array[], int size)
{
    Node * head;
    Node * p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node * getTail(Node * head)
{
    Node * p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node * getNode(Node * head, int index)
{
    int pos = 0;
    Node * p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node * head)
{
    Node * p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node * tail)
{
    Node * p = tail->prev;
    while (p->prev != nullptr)
    {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}