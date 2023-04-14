/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:21:52 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:22:13 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	rr(t_push *get)
{
	ra(get->first.head);
	rb(get->second.head);
	ft_printf("rr\n");
}

void	rrr(t_push *get)
{
	rra(&get->first);
	rra(&get->second);
	ft_printf("rrr\n");
}

void	ss(t_push *get)
{
	sa(get->first.head);
	sa(get->second.head);
	ft_printf("ss\n");
}
