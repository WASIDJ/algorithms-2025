/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30300
 *
 * [707] 设计链表
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyLinkedList
{
public:
    struct Node
    {
        Node *nxt;
        Node *prev;
        int val;
        Node(int value) : nxt(nullptr), prev(nullptr), val(value) {}
    };
    Node *dummyhead;
    Node *dummytail;
    int size;

public:
    MyLinkedList()
    {
        dummyhead = new Node(int());
        dummytail = new Node(int());
        dummyhead->nxt = dummytail;
        dummytail->prev = dummyhead;
        size = 0;
    }
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        Node *curr = dummyhead->nxt;
        for (size_t i = 0; i < index; i++)
        {
            curr = curr->nxt;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        Node *curr = dummyhead->nxt;
        dummyhead->nxt = newNode;
        newNode->prev = dummyhead;

        newNode->nxt = curr;
        curr->prev = newNode;

        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *curr = dummytail->prev;

        dummytail->prev = newNode;
        newNode->nxt = dummytail;

        curr->nxt = newNode;
        newNode->prev = curr;

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *curr = dummyhead->nxt;
        Node *newNode = new Node(val);
        for (size_t i = 0; i < index; i++)
        {
            curr = curr->nxt;
        }
        Node *prev = curr->prev;
        Node *nxt = curr->nxt;
        newNode->nxt = curr;
        newNode->prev = prev;
        curr->prev = newNode;
        prev->nxt = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        Node *curr = dummyhead->nxt;
        if (index < 0 || index >= size)
        {
            return;
        }
        for (size_t i = 0; i < index; i++)
        {
            curr = curr->nxt;
        }
        Node *prev = curr->prev;
        Node *nxt = curr->nxt;
        prev->nxt = nxt;
        nxt->prev = prev;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main()
{
    // your test code here
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2); // 链表变为 1->2->3
    myLinkedList->get(1);           // 返回 2
    myLinkedList->deleteAtIndex(1); // 现在，链表变为 1->3
    myLinkedList->get(1);
}
