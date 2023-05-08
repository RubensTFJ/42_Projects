#include <iostream>

using namespace std;

int	main(int counter, char **input)
{
	if (counter != 2)
		return (1);
	for (int i = 0; input[1][i]; i++)
		cout << (char)toupper(input[1][i]);
	cout << endl;
	return (0);
}