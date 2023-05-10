

// void	ft_lstadd_back(t_list **lst, t_list *new);
// t_list	*ft_lstnew(void *content);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstadd_front(t_list **lst, t_list *new);

// void	ft_free_linklist(t_list *list)
// {
// 	t_list	*temp;

// 	while (list)
// 	{
// 		temp = list->next;
// 		free (list);
// 		list = temp;
// 	}
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	if (*lst)
// 	{
// 		while ((*lst)->next)
// 			(*lst) = (*lst)->next;
// 		(*lst)->next = new;
// 	}
// 	else
// 		*lst = new;
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*newnode;

// 	newnode = ft_calloc(sizeof(t_list), 1);
// 	if (!newnode)
// 		return (NULL);
// 	newnode->content = content;
// 	return (newnode);
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delete;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		delete = (*lst);
		(*lst) = (*lst)->next;
		(*del)(delete->content);
		free(delete);
		delete = NULL;
	}
}

// int	ft_lstsize(t_list *lst)
// {
// 	int		counter;
// 	t_list	*interate;

// 	if (!lst)
// 		return (0);
// 	counter = 1;
// 	interate = lst;
// 	while (interate->next != NULL)
// 	{
// 		counter++;
// 		interate = interate->next;
// 	}
// 	return (counter);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*newlist;
// 	t_list	*newmember;

// 	if (!lst || !(*f) || !(*del))
// 		return (NULL);
// 	newlist = NULL;
// 	while (lst != NULL)
// 	{
// 		newmember = ft_lstnew((*f)(lst->content));
// 		if (!newmember)
// 		{
// 			ft_lstclear(&newlist, (*del));
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&newlist, newmember);
// 		lst = lst->next;
// 	}
// 	return (newlist);
// }

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	t_list	*iterate;

// 	if (!lst || !f)
// 		return ;
// 	iterate = lst;
// 	while (iterate != NULL)
// 	{
// 		(*f)(iterate->content);
// 		iterate = iterate->next;
// 	}
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	(*del)(lst->content);
// 	free(lst);
// }

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*delete;

// 	if (!lst || !del)
// 		return ;
// 	while ((*lst))
// 	{
// 		delete = (*lst);
// 		(*lst) = (*lst)->next;
// 		(*del)(delete->content);
// 		free(delete);
// 		delete = NULL;
// 	}
// }