#ifndef _BST_H
#define _BST_H

#include <iostream>

using namespace std;

template<class T>
struct Node
{
	T data = NULL;
	Node *right = nullptr;
	Node *left = nullptr;
};

template<class T>
class BST
{
private:
	//Node<T> *root = new Node<T>;
	Node<T> root;

	void add(Node<T>& root, T data)
	{
		if (root.data == NULL)
		{
			root.data = data;
		}
		else if (root.data < data)
		{
			add(root.right == nullptr ? *(root.right = new Node<T>) : *root.right, data);
		}
		else if (root.data > data)
		{
			add(root.left == nullptr ? *(root.left = new Node<T>) : *root.left, data);
		}
	};

	void remove(Node<T> *root, T data)
	{
		if (root == nullptr)
		{
			return;
		}
		else if (root->data == data)
		{
			if (root->right != nullptr)
			{
				root->data = root->right->data;
				remove(root->right, root->right->data);
			}
			else if (root->left != nullptr)
			{
				root->data = root->left->data;
				remove(root->left, root->left->data);
			}
			else
			{
				cout << "deleted " << root->data << endl;
				root = nullptr;
			}
		}
		else
		{
			remove(root->data < data ? root->right : root->left, data);
		}
	};

	bool exist(Node<T> *root, T data)
	{
		if (root == nullptr)
		{
			return false;
		}
		else if (root->data == data)
		{
			return true;
		}
		else
		{
			return exist(root->data < data ? root->right : root->left, data);
		}
	};

public:
	BST() {};
	~BST() {};
	void add(T data) { add(root, data); };
	void remove(T data) { remove(&root, data); };
	bool exist(T data) { return exist(&root, data); };

};

#endif // _BST_H