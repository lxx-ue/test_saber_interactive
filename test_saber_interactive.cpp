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
    
    int count = 0;

    void Serialize();
    void Deserialize();
};

int main()
{
    std::cout << "Hello World!\n";
}