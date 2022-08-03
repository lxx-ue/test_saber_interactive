#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include <time.h>

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
	std::vector<int> rands;
	int count = 0;

	void Serialize(std::ofstream* out)
	{
		std::unordered_map<ListNode*, int> m;
		ListNode* current = head;
		int pos = 0;
		while (current)
		{
			m.insert(std::make_pair(current, pos));
			++pos;
			current = current->next;
		}
		current = head;
		while (current)
		{
			*out << current->data << ' ';
			if (current->rand) *out << m[current->rand];
			else *out << -1;
			//*out << node->rand ? m[node->rand] : -1;
			*out << '\n';
			current = current->next;
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

	void setRands()
	{
		std::vector<ListNode*> m;
		ListNode* node = head;
		while (node)
		{
			m.push_back(node);
			node = node->next;
		}
		node = head;
		int pos = 0;
		while (node)
		{
			int r = rand() % count;
			node->rand = m.at(r);
			node = node->next;
			++pos;
		}
	}

	void print()
	{
		ListNode* node = head;
		while (node)
		{
			std::cout << node->data << '\t' << node << '\t' << node->prev <<'\t'<<node->next << '\t' << node->rand << std::endl;
			node = node->next;
		}
		//int i = 0;
		//while (node)
		//{
		//	int r = rand() % count;
		//	std::cout << i << '\t' << node->data << '\t' << node << '\t' << r;// << std::endl;
		//	
		//	ListNode* hnode = head;
		//	int j = 0;
		//	while (hnode)
		//	{

		//		if (j == r) std::cout << ' ' << hnode << std::endl;
		//		hnode = hnode->next;
		//		j++;
		//	}
		//	
		//	node = node->next;
		//	++i;

		//}
	}
};

int main()
{
	srand(time(0));
	ListRand list;
	
	list.addItem("green");
	list.addItem("orange");
	list.addItem("red");
	list.addItem("black");
	list.addItem("white");
	std::ofstream fout("tt.txt");

	list.setRands();
	list.Serialize(&fout);
	list.print();

	//std::ifstream fin2("tt.txt");
	//list.Deserialize(&fin2);
	//list.print();
}