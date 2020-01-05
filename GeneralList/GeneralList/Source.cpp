#include "GeneralList.h"
#include <iostream>

using namespace std;

int main()
{
	GeneralList list;
	list.add("red");
	list.add("re");
	list.add("reza");
	list.add("rezi");
	list.add("rezian");
	list.add("rex");
	list.add("bazar");
	list.add("baz");
	list.add("dos");
	list.add("rez");
	list.add("baran");
	list.add("bazi");
	list.add("dost");
	list.add("sadra");
	list.remove("re");
	list.print_all();
	cout << list.exist("rezi") << endl;
	return 0;
}