#include <iostream>

class ListNode {
public:
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr; // указатель на произвольный элемент списка
    std::string data;
};

class ListRand {
public:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* current = nullptr;
    
    int count = 0;

    void Serialize();
    void Deserialize();

    ListNode* addItem(const std::string data)
    {
        ListNode* node = new ListNode;
        node->data = data;
        if (head == 0)
        {
            head = current = tail = node;
        }
        else
        {
            current->next = node;
            node->prev = current;
            tail = current = node;
        }
        ++count;
        return node;
    }
};

int main()
{
    ListRand list;
    list.addItem("green");
    list.addItem("orange");
    list.addItem("red");

}