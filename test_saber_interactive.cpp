#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

	void Serialize(std::ofstream* out)
	{
		ListNode* node = head;
		while (node)
		{
			*out << node->data;
			*out << '\n';
			node = node->next;
		}
	}

	void Deserialize(std::ifstream* fin)
	{
		if (!fin->is_open())
		{
			std::cerr << "Can't open file";
			exit(EXIT_FAILURE);
		}
		while (!fin->eof())
		{
			std::string s1;
			getline(*fin, s1);
			if(!s1.empty())
			addItem(s1);
		}
	}

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

	void print()
	{
		ListNode* node = head;
		while (node)
		{
			std::cout << node->data << '\t' << node << '\t' << node->prev <<'\t'<<node->next << std::endl;
			node = node->next;
		}
		std::cout << std::endl << count;
	}
};


int main()
{
	ListRand list;
	//list.addItem("green");
	//list.addItem("orange");
	//list.addItem("red");
	//std::ofstream fout("tt.txt");
	//list.Serialize(&fout);

	std::ifstream fin2("tt.txt");
	list.Deserialize(&fin2);
	list.print();
}