#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream out;
	ifstream in;
	string text;
	out.open("test.txt");
	cin >> text;
	out << text << endl;
	in.open("test.txt");
	in >> text;
	cout << text;
	in.close();
	out.close();
}