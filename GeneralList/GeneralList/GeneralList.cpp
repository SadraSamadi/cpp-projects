#include "GeneralList.h"
#include <string>

GeneralList::GeneralList()
{

}

GeneralList::~GeneralList()
{

}

void GeneralList::add(string word)
{
	_add(head, word, 0);
}

void GeneralList::remove(string word)
{
	_remove(head, word, 0);
}

bool GeneralList::exist(string word)
{
	return _exist(head, word, 0);
}

void GeneralList::print_all()
{
	_print_all(&head, "");
}

void GeneralList::_add(Node& head, string word, int index)
{
	if (index == word.size())
	{
		head.end_of_word = index != 0;
		return;
	}
	if (!head.right)
	{
		(head.right = new Node)->letter = word[index];
		_add(*head.right, word, index + 1);
	}
	else if (head.right->letter == word[index])
	{
		_add(*head.right, word, index + 1);
	}
	else
	{
		_add(head.down ? *head.down : *(head.down = new Node), word, index);
	}
}

void GeneralList::_remove(Node& head, string word, int index)
{
	if (index == word.size())
	{
		head.end_of_word = false;
		return;
	}
	if (head.right && head.right->letter == word[index])
	{
		_remove(*head.right, word, index + 1);
	}
	else if (head.down)
	{
		_remove(*head.down, word, index);
	}
}

bool GeneralList::_exist(Node& head, string word, int index)
{
	if (index == word.size())
	{
		return head.end_of_word;
	}
	if (!head.right)
	{
		return false;
	}
	else if (head.right->letter == word[index])
	{
		return _exist(*head.right, word, index + 1);
	}
	else
	{
		return head.down && _exist(*head.down, word, index);
	}
}

void GeneralList::_print_all(Node *head, string pre)
{
	Node *row = head;
	while (row)
	{
		Node *col = row->right;
		string line;
		while (col)
		{
			line += col->letter;
			cout << (col->end_of_word ? pre + line + "\n" : "");
			if (col->down)
			{
				_print_all(col, pre + line);
				break;
			}
			col = col->right;
		}
		row = row->down;
	}
}