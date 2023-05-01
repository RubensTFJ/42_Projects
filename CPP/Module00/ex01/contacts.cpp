#include <iostream>

using namespace std;

std::string	ask_input(char *string) {
	std::string	input;

	input.clear();
	while (input.empty())
	{
		cout << string << endl;
		getline(cin, input);
		if (input.empty())
			cout << "Invalid Input." << endl;
	}
	return (input);
}

void	str_tolower(std::string	string)
{
	for (char& c : string)
		c = tolower(c);
}

class Contact {
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	secret;
	std::string	number;

	void	table_print(std::string string) {
		int i = 0;
		while (string[i] && i < 8)
			cout << string[i++];
		if (string[i] && i == 8)
			cout << '.';
		else
		{
			while (i++ < 8)
				cout << " ";	
		}
	}

	public:
		void	Update(std::string name, std::string last_name, std::string nickname,
			std::string secret, std::string number) {
			this->name = name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->secret = secret;
			this->number = number;
		}

		void	MiniPrint(int index) {
			cout << " " << index << "        ";
			cout << "| ";
			table_print(name);
			cout << "| ";
			table_print(last_name);
			cout << "| ";
			table_print(nickname);
			cout << endl;
		}

		void	FullPrint(void) {
			cout << "Name: " << name << endl;
			cout << "Last Name: " << last_name << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Darkest Secret: " << secret << endl;
			cout << "Phone Number: " << number << endl;
		}
} ;

class PhoneBook {
	int		keeper = 0;
	Contact	*contacts[8];

	public:
		void	Add(void) 
		{
			if (!contacts[keeper])
				contacts[keeper] = new Contact;
			contacts[keeper]->Update(ask_input("Enter First Name: "), ask_input("Enter Last Name: "), ask_input("Enter Nickname: "),
				ask_input("Enter Phone Number: "), ask_input("Enter Dark Secret: "));
			keeper++;
			if (keeper > 7)
				keeper = 0;
		}

		void	Search(void)
		{
			for (int i = 0; contacts[i]; i++)
				contacts[i]->MiniPrint(i);
			int	index = atoi(ask_input("Enter Desired Contact: ").c_str());
			if (-1 < index && index < 8 && contacts[index])
				contacts[index]->FullPrint();
			else
				cout << "Invalid Index." << endl;
		}

		void	Exit(void) {
			for (int i = 0; contacts[i]; i++)
				delete contacts[i];
		}
} ;

int	main(int counter, char **input)
{
	PhoneBook	book;
	std::string	command;

	while (true)
	{
		cout << "Enter Command: " << endl;
		getline(cin, command);
		str_tolower(command);
		if (command == "add")
			book.Add();
		else if (command == "search")
			book.Search();
		else if (command == "exit")
		{
			book.Exit();
			return (0);
		}
		else
			cout << "Wrong Usage. Valid commands: 'ADD', 'SEARCH' and 'EXIT'" << endl;
	}
}
