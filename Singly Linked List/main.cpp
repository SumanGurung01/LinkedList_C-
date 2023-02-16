/*
    Date : Thu Feb 16 2023 23:11:06 GMT+0530 (India Standard Time)
    Author : Suman Gurung
    Description : Implementation of Single Linked List in C++
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *root;

    LinkedList(int value)
    {
        root = new Node(value);
    }

    int getLength()
    {
        int length = 0;
        Node *current = root;
        while (current != NULL)
        {
            length++;
            current = current->next;
        }

        return length;
    }

    void printLinkedList()
    {
        Node *current = root;
        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "NULL";
    }

    void insertAtEnd(int value)
    {
        // create new node
        Node *new_node = new Node(value);
        Node *current = root;

        // get the last node
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }

    void insertAtStart(int value)
    {
        // create new node
        Node *new_node = new Node(value);

        // new node point toward root
        new_node->next = root;

        // new node becomes new root
        root = new_node;
    }

    void insertAtPosition(int value, int position)
    {
        Node *current = root;
        Node *new_node = new Node(value);

        if (position == 0)
        {
            insertAtStart(value);
            return;
        }

        if (position == getLength() - 1)
        {
            insertAtEnd(value);
            return;
        }

        if (position > 0 and position < getLength() - 1)
        {
            current = root;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }

            // new node points to current node next
            new_node->next = current->next;

            // current points towards new node
            current->next = new_node;
            return;
        }

        cout << "Position Error\n";
        return;
    }
};

int main()
{
    LinkedList *l1 = new LinkedList(1);

    l1->insertAtStart(0);

    l1->insertAtEnd(2);

    l1->insertAtPosition(10, 1);

    l1->printLinkedList();

    cout << "\nLength : " << l1->getLength();
}