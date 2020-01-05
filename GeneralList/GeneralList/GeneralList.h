#ifndef _GENERAL_LIST_H
#define _GENERAL_LIST_H

#include <iostream>

using namespace std;

struct Node
{
	char letter = NULL;
	bool end_of_word = false;
	Node *right = nullptr;
	Node *down = nullptr;
};

class GeneralList
{
private:
	Node head;
	void _add(Node&, string, int);
	void _remove(Node&, string, int);
	bool _exist(Node&, string, int);
	void _print_all(Node*, string);

public:
	GeneralList();
	~GeneralList();
	void add(string);
	void remove(string);
	bool exist(string);
	void print_all();

};

#endif