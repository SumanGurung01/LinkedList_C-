/*
    Date : Fri Feb 17 2023 22:23:56 GMT+0530 (India Standard Time)
    Author : Suman Gurung
    Description : Implementation of Doubly Linked List in C++
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *root;
    DoublyLinkedList(int value)
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

    void printDoublyLinkedList()
    {
        Node *current = root;
        cout << "NULL <-> ";
        while (current != NULL)
        {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL";
    }

    void insertAtStart(int value)
    {
        Node *new_node = new Node(value);

        new_node->next = root;
        root->prev = new_node;
        root = new_node;
    }

    void insertAtEnd(int value)
    {
        Node *new_node = new Node(value);
        Node *current = root;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
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

        if (position > 0 && position < getLength() - 1)
        {
            current = root;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }

            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            return;
        }
        cout << "Position Error\n";
        return;
    }

    void deleteAtStart()
    {
        Node *current = root;
        root = current->next;
        root->prev = NULL;
        delete current;
    }

    void deleteAtEnd()
    {
        Node *current = root;

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node *last_node = current->next;
        current->next = NULL;
        delete last_node;
    }

    void deleteAtPosition(int position)
    {
        if (position == 0)
        {
            deleteAtStart();
            return;
        }

        if (position == getLength() - 1)
        {
            deleteAtEnd();
            return;
        }

        if (position > 0 && position < getLength() - 1)
        {
            Node *current = root;
            Node *temp;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;

            return;
        }

        cout << "Position Error\n";
        return;
    }

    void printDoublyLinkedListInfo()
    {
        Node *current = root;
        while (current != NULL)
        {
            cout << current->prev << "\t" << current << "\t" << current->next << endl;
            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList *l1 = new DoublyLinkedList(1);
    l1->insertAtStart(0);
    l1->insertAtEnd(2);
    l1->insertAtEnd(3);
    l1->insertAtPosition(10, 2);
    l1->deleteAtPosition(3);
    l1->printDoublyLinkedListInfo();
    l1->printDoublyLinkedList();
}