/*
    Date : Tue Mar 07 2023 18:09:16 GMT+0530 (India Standard Time)
    Author : Suman Gurung
    Description : Implementation of Circular Linked List in C++
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

class CircularLinkedList
{
public:
    Node *head, *tail;

    CircularLinkedList(int value)
    {
        head = new Node(value);
        tail = head;
    }

    int getLength()
    {
        int length = 0;
        Node *current = head;

        current = current->next;
        length++;

        while (current != head)
        {
            length++;
            current = current->next;
        }

        return length;
    }

    void printCircularLinkedList()
    {
        Node *temp = head;

        cout << temp->value << " -> ";
        temp = temp->next;

        while (temp != head)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "head";
    }

    void insertAtStart(int value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        tail->next = head;
    }

    void insertAtEnd(int value)
    {
        Node *new_node = new Node(value);
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }

    void insertAtPosition(int value, int position)
    {
        Node *current = head;
        Node *new_node = new Node(value);

        if (position == 0)
        {
            insertAtStart(value);
            return;
        }

        if (position == getLength())
        {
            insertAtEnd(value);
            return;
        }

        if (position > 0 && position < getLength())
        {
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }

            new_node->next = current->next;

            current->next = new_node;
            return;
        }

        cout << "Position Error\n";
        return;
    }

    void deleteAtStart()
    {
        Node *current = head;
        tail->next = current->next;
        head = current->next;
        delete current;
    }

    void deleteAtEnd()
    {
        Node *current = head;

        while (current->next->next != head)
        {
            current = current->next;
        }

        // current points to second last node
        Node *tail_node = current->next;

        // second last node points to NULL
        current->next = tail_node->next;

        tail = current;

        // delete last node
        delete tail_node;
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
            Node *current = head;
            Node *temp;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;
            delete temp;

            return;
        }

        cout << "Position Error\n";
        return;
    }

    void printCircularLinkedListInfo()
    {
        Node *current = head;
        cout << current << "\t" << current->next << endl;
        current = current->next;
        while (current != head)
        {
            cout << current << "\t" << current->next << endl;
            current = current->next;
        }
    }
};

int main()
{
    CircularLinkedList *cll = new CircularLinkedList(1);
    cll->insertAtStart(0);
    cll->insertAtEnd(2);
    cll->insertAtPosition(10, 3);
    cll->deleteAtPosition(2);
    cll->printCircularLinkedListInfo();
    cll->printCircularLinkedList();
}
