#include <stdio.h>
#include <unistd.h>

# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)
#include <minishell.h>

int	split_case(char *line)
{
	if (!*line)
		return (0);
	else if (*line == '<' && *(line + 1) == '<')
		return (2);
	else if (*line == '>' && *(line + 1) == '>')
		return (2);
	else if (*line == '>' || *line == '<')
		return (1);
	return (0);
}

int	ignore_quotes(char *string)
{
	int		i;
	char	stop;

	i = 0;
	if (string[i] == '\"' || string[i] == '\'')
	{
		stop = string[i++];
		while (string[i] && string[i] != stop)
			i++;
	}
	return (i);
}

static int	getwords(char *s, char c)
{
	int		i;
	int		count;
	int		size;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		size = split_case(&s[i]);
		count += (s[i] && (s[i] != c));
		i += size + ignore_quotes(&s[i]); 
		while (s[i] && s[i] != c && !split_case(&s[i]) && !size)
			i++;
	}
	return (count);
}

void	force_space(char *line)
{
	int		i;
	char	stop;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			stop = line[i++];
			while (line[i] && line[i] != stop)
				i++;
		}
		if (line[i] == ' ')
			line[i] = -1;
		i++;
	}
}

int main(int c, char **v)
{
	HERE;
	force_space(v[1]);
	THERE;
	getwords(v[1], -1);
}


void	output_direct();
void	input_direct();
void	pipe_output();
void	here_doc();
void	echo_builtin();
void	cd_builtin();
void	pwd_builtin();
void	export_builtin();
void	unset_builtin();
void	env_builtin();
void	exit_builtin();
void	try_command();


char	*build_executable_path(t_control *get, char *command)
{
	int		i;
	char	*exec_path;

	if (!access(command, F_OK))
		return (ft_strdup(command));
	i = 0;
	while (get->paths[i])
	{
		exec_path = ft_strjoin(get->paths[i++], command);
		if (!access(exec_path, F_OK))
			return (exec_path);
		free(exec_path);
	}
	invalid_input(command);
	return (NULL);
}

t_command	*new_command(t_control *get)
{
	t_command	*new;

	new = ft_calloc(sizeof(t_command), 1);
	new->main = get;
	new->valid = 1;
	return (new);
}

	// write (2, "command not found: ", 19);
	// i = 0;
	// while (command[i])
	// 	write (2, &command[i++], 1);
	// write (2, "\n", 1);


// If flags are found, I need to take care so that it doenst got trhough the parser again.
void	try_command(t_command *get, int index)
{
	get->exec_path = build_executable_path(get->main, get->terminal[index]);
	if (!get->exec_path)
	{
		get->valid = 0;
		return ;
	}
	get->execute = execute_command;
	if (get->terminal[index + 1] && get->terminal[index + 1][0] == '-')
	{
		get->flags = ft_split(get->terminal[index + 1], ' ');
		get->terminal[index + 1][0] = 0;
	}
	else
		get->flags = ft_split(get->terminal[index], ' ');
}

void	do_nothing(void)
{
	return ;
}

t_exe	solve(char *find)
{
	int			index;
	int			length;
	static char	*cases[14] = {
		"", ">>", "<<", ">",
		"<", "|", "echo", "cd",
		"pwd", "export", "unset", "env",
		"exit", NULL
	};
	static t_exe	functions[14] = {
		do_nothing, output_direct, input_direct, output_direct,
		here_doc, pipe_output, echo_builtin, cd_builtin,
		pwd_builtin, export_builtin, unset_builtin, env_builtin,
		exit_builtin, try_command
	};

	length = ft_strlen(find);
	index = 0;
	while (cases[index] && ft_strncmp(find, cases[index], length))
		index++;
	return (functions[index]);
}

void	structure_commands(t_control *get, char **input)
{
	t_command	*command;
	int			i;

	command = new_command(get);
	i = 0;
	while (input[i] && (input[i - 1] && input[i - 1] != '|') && command->valid)
	{
		solve(input[i])(command, i);
		i++;
	}
	if (command->valid)
		ft_lstadd_back(&get->commands, ft_lstnew((void *)command));
	else
		free(command);
}

void	execute_command(t_command *get)
{
	dup2(get->instream, STDIN_FILENO);
	dup2(get->pipe[2], STDIN_FILENO);
	get->id = fork();
	if (!get->id)
	{
		close(get->pipe[0]);
		execve(get->exec_path, get->flags, get->main->envp);
	}
	else
	{
		close(get->pipe[1]);
	}
}

// void	run_input(t_list *node)
// {
// 	while (node)
// 	{
// 		((t_command *)node->content)->execute((t_command *)node->content);
// 		node = node->next;
// 	}
// }

void	run_input(t_list *node)
{
	t_command	*command;

	while (node)
	{
		command = (t_command *)node->content;
		command->execute(command);
		node = node->next;
	}
}

// int	hash(char *find)
// {
// 	int			index;
// 	int			length;
// 	static char	*cases[12] = {
// 		">>", "<<", ">", "<",
// 		"|", "echo", "cd", "pwd",
// 		"export", "unset", "env",
// 		"exit"
// 	} ;

// 	length = ft_strlen(find);
// 	index = 0;
// 	while (cases[index])
// 	{
// 		if (!ft_strncmp(find, cases[index++], length))
// 				return (index);
// 	}
// 	return (index);
// }
// exe	solve(char *find)
// {
// 	static exe	functions[13] = {
// 		output_direct, input_direct, output_direct, here_doc,
// 		pipe_output, echo_builtin, cd_builtin, pwd_builtin,
// 		export_builtin, unset_builtin, env_builtin,
// 		exit_builtin, try_command
// 	};

// 	return (functions[hash(find)]);
// }

//Try and find the separators and the builtin cases. if they fail they fall
// in to the command case, try and find a command, if they are not a command, then they are no case.
	// if (ft_strncmp(find, ">>", ft_strlen(find)))
	// 	return (0);
	// else if (ft_strncmp(find, "<<", ft_strlen(find)))
	// 	return (1);
	// else if (ft_strncmp(find, ">", ft_strlen(find)))
	// 	return (2);
	// else if (ft_strncmp(find, "<", ft_strlen(find)))
	// 	return (3);
	// else if (ft_strncmp(find, "|", ft_strlen(find)))
	// 	return (4);
	// else if (ft_strncmp(find, "echo", ft_strlen(find)))
	// 	return (5);
	// else if (ft_strncmp(find, "cd", ft_strlen(find)))
	// 	return (6);
	// else if (ft_strncmp(find, "pwd", ft_strlen(find)))
	// 	return (7);
	// else if (ft_strncmp(find, "export", ft_strlen(find)))
	// 	return (8);
	// else if (ft_strncmp(find, "unset", ft_strlen(find)))
	// 	return (9);
	// else if (ft_strncmp(find, "env", ft_strlen(find)))
	// 	return (10);
	// else if (ft_strncmp(find, "exit", ft_strlen(find)))
	// 	return (11);
	// return (12);

/*
OLD FUNCTION LIST - CHANGED FOR A FUNCTION ARRAY.
t_list	**list_functions(void)
{
	static t_list	*f;

	return (&f);
}

exe	functions(char *find)
{
	t_list	*node;
	t_func	*function;

	node = *list_functions();
	while (node)
	{
		function = node->content;
		if (!ft_strncmp(function->type, find, ft_strlen(find)))
			return (function->pointer);
		node = node->next;
	}
	return (NULL);
}



void	set_builtins(void)
{
	t_func	*new;

	new = ft_calloc(sizeof(t_func), 1);
	new->type = "echo";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "cd";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "pwd";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "export";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "unset";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "env";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "exit";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
}
// echo with option -n
// ◦ cd with only a relative or absolute path
// ◦ pwd with no options
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit wi

void	set_function_list(void)
{
	t_func	*new;

	new = ft_calloc(sizeof(t_func), 1);
	new->type = ">>";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "<<";
	new->pointer = direct_input;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = ">";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "<";
	new->pointer = direct_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	new = ft_calloc(sizeof(t_func), 1);
	new->type = "|";
	new->pointer = pipe_output;
	ft_lstadd_back(list_functions(), ft_lstnew((void *)new));
	set_builtins();
}
*/