#include <iostream>

using namespace std;

int	main(int counter, char **input)
{
	if (counter != 2)
		return ;
	for (int i = 0; (*input)[i]; i++)
		cout << toupper((*input)[i]);
	cout << endl;
}