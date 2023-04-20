/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:56:46 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/20 16:07:03 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int check_bit_position(t_list *list, int pos)
{
    while (list)
    {
        if (list->content & (1 << pos))
            return (1);
        list = list->next;
    }
    return (0);
}

void    push_bit_b(int pos)
{
    int i;
    int size;

    if (pos > get()->last_bit)
        return ;
    i = 0;
    size = ft_lstsize(get()->second.list);
    while (i < size && get()->second.list)
    {
        if (get()->second.list->content & (1 << pos))
            pa();
        else
            rb();
        i++;
    }
    push_bit_a((pos + 1));
}

void    push_bit_a(int pos)
{
    int i;
    int size;

    if (pos > get()->last_bit)
        return ;
    i = 0;
    size = ft_lstsize(get()->first.list);
    while (i < size && get()->first.list)
    {
        if (get()->first.list->content & (1 << pos))
            pb();
        else
            ra();
        i++;
    }
    push_bit_b((pos + 1));
}

void    push_bit_position(int list_id, int pos)
{
    t_list *list;
    int     counter;

    list = get()->second.list;
    list_id = 1;
    if (list_id == 1)
    {
        list = get()->first.list;
        list_id = 2;
    }
    if (pos > get()->last_bit)
        return ;
    counter = 0;
    while (check_bit_position(list, pos))
    {
        if (get()->first.list->content & (1 << pos))
        {
            pb();
            counter++;
        }
        else
            ra();
        list = get()->second.list;
        if (list_id == 1)
            list = get()->first.list;
    }
    push_bit_position(list_id, (pos + 1));
}

void	radix(void)
{
    int i;
    int pos;

    pos = 0;
    while (pos <= get()->last_bit)
    {
        i = 0;
        while (i < get()->first.size && get()->first.list)
        {
            if (get()->first.list->content & (1 << pos))
                pb();
            else
                ra();
            i++;
        }
        while (get()->second.list)
            pa();
        pos++;
    }
}
// void	radix(void)
// {
//     int pos;

//     pos = 0;
//     while (pos < get()->last_bit + 1)
//     {
//         while (check_bit_position(get()->first.list, pos))
//         {
//             if (get()->first.list->content & (1 << pos))
//                 pb();
//             else
//                 ra();
//         }
//         while (get()->second.list)
//             pa();
//        pos++;
//     }
// }
