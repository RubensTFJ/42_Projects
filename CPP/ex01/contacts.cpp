#include <iostream>

class Contact {
	const char	*name;
	const char	*last_name;
	const char	*nickname;
	const char	*secret;
	int			number;

	void	table_print(const char *string) {
		int i = 0;
		while (string[i] && i < 7)
			std::cout << string[i++];
		if (string[i] && i == 7)
			std::cout << '. ';
		else
		{
			while (i < 8)
				std::cout << " ";	
		}
	}

	public:
		void	Update(const char *name, const char *last_name, const char *nickname,
			const char *secret, int number) {
			this->name = name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->secret = secret;
			this->number = number;
		}

		void	MiniPrint(int index) {
			std::cout << index << "         ";
			std::cout << "| ";
			table_print(name);
			std::cout << "| ";
			table_print(last_name);
			std::cout << "| ";
			table_print(nickname);
			std::cout << std::endl;
		}

		void	FullPrint(void) {

		}
} ;

class PhoneBook {
	int		keeper = 0;
	Contact	*contacts[8];

	int	get_index(const char *input) {
		std::cout << "Enter Contact Index: " << std::endl;
		return (atoi(input));
	}

	public:
		void	Add(const char *name, const char *last_name, const char *nickname,
			const char *secret, int number) 
		{
			if (!contacts[keeper])
				contacts[keeper] = new Contact;
			contacts[keeper]->Update(name, last_name, nickname, secret, number);
			keeper++;
			if (keeper > 7)
				keeper = 0;
		}

		void	Search(void)
		{
			for (int i = 0; contacts[i]; i++)
				contacts[i]->MiniPrint(i);
			int	index = get_index("blabla");
			if (-1 < index && index < 8 && contacts[index])
				contacts[index]->FullPrint();
			else
				std::cout << "Invalid Index" << std::endl;
		}

		void	Exit(void) {
			for (int i = 0; contacts[i]; i++)
				delete contacts[i];
		}
} ;

int	main(int counter, char **input)
{
	PhoneBook book;

	while (true)
	{
		if (input)
	}
}
