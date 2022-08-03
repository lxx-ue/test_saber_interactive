#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <time.h>

struct ListNode {
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	ListNode* rand = nullptr; 
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
		std::unordered_map<ListNode*, int> m; // map for ListNode
		ListNode* temp = head;
		int pos = 0;
		while (temp)
		{
			m.insert(std::make_pair(temp, pos)); // add to map
			++pos;
			temp = temp->next;
		}
		temp = head;
		while (temp)
		{
			*out << temp->data << ' '; // write to file
			if (temp->rand) *out << m[temp->rand]; // random position
			else *out << -1;
			//*out << node->rand ? m[node->rand] : -1;
			*out << '\n';
			temp = temp->next;
		}
	}

	void Deserialize(std::ifstream* fin)
	{
		if (!fin->is_open()) 
		{
			std::cerr << "Can't open file";
			exit(EXIT_FAILURE);
		}
		std::unordered_map< int, ListNode* > m; // map for ListNode
		int pos = 0;
		std::vector<int> rand_num; // vector for rand positions
		while (!fin->eof())
		{
			std::string s1;
			getline(*fin, s1);
			if (!s1.empty())
			{
				std::stringstream ssstream; // trim by stream
				ssstream << s1;
				std::string word; // first part of stream = data
				int n; // first part of stream = rand number
				ssstream >> word >> n; 
				rand_num.push_back(n); // add num to vector 
				m.insert(std::make_pair(pos, addItem(word))); // add node to map
				++pos;
			}
		}
		ListNode* temp = head;
		int i = 0;
		while (temp) // set rand positions from map according vector
		{
			temp->rand = m[rand_num.at(i)];
			temp = temp->next;
			i++;
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
		std::vector<ListNode*> m; // vector of nodes
		ListNode* temp = head;
		while (temp)
		{
			m.push_back(temp);
			temp = temp->next;
		}
		temp = head;
		int pos = 0;
		while (temp)
		{
			int r = rand() % count;
			temp->rand = m.at(r); // set rand by vector
			temp = temp->next;
			++pos;
		}
	}

	void print()
	{
		ListNode* temp = head;
		std::cout << "data\taddress\t\t\tprev\t\t\tnext\t\t\trand\n\n";
		while (temp)
		{
			std::cout << temp->data << '\t' << temp << '\t' << temp->prev <<'\t'<< temp->next << '\t' << temp->rand << std::endl;
			temp = temp->next;
		}
	}
};

int main()
{
	srand(time(0));
	ListRand list;
	
	bool serialize_mode = true; // set true to Serialize, or false to Deserialize

	if (serialize_mode)
	{
		list.addItem("red");
		list.addItem("green");
		list.addItem("blue");
		list.addItem("black");
		list.addItem("white");
		std::ofstream fout("tt.txt");
		list.setRands();
		list.Serialize(&fout);
		list.print();
	}
	else 
	{
		std::ifstream fin2("tt.txt");
		list.Deserialize(&fin2);
		list.print();
	}

}