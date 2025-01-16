/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:15:15 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/16 09:10:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_rotate(t_stack **src, t_stack **dest, t_rotate r, char dname)
{
	char	sname;

	if (dname == 'a')
		sname = 'b';
	else
		sname = 'a';
	while (r.rs && r.rd)
	{
		rotate(src, dest, 'r');
		r.rs--;
		r.rd--;
	}
	while (r.rs--)
		rotate(src, NULL, sname);
	while (r.rd--)
		rotate(dest, NULL, dname);
}

void	ex_revrotate(t_stack **src, t_stack **dest, t_rotate r, char dname)
{
	char	sname;

	if (dname == 'a')
		sname = 'b';
	else
		sname = 'a';
	while (r.rrs && r.rrd)
	{
		reverse_rotate(src, dest, 'r');
		r.rrs--;
		r.rrd--;
	}
	while (r.rrs--)
		reverse_rotate(src, NULL, sname);
	while (r.rrd--)
		reverse_rotate(dest, NULL, dname);
}

void	cal_rotate(t_stack **src, t_stack **dest, t_stack *item, char dname)
{
	t_rotate	r;
	int			len_dest;

	r.rs = item->index;
	r.rd = 0;
	r.rrs = 0;
	r.rrd = 0;
	len_dest = stack_size(*dest);
	if ((item->target->index < (len_dest + 1) / 2))
	{
		r.rd = item->target->index;
		ex_rotate(src, dest, r, dname);
	}
	else if (item->target->index >= (len_dest + 1) / 2)
	{
		r.rrd = len_dest - item->target->index;
		ex_revrotate(src, dest, r, dname);
	}
}

void	cal_revrotate(t_stack **src, t_stack **dest, t_stack *item, char dname)
{
	t_rotate	r;
	int			len_dest;
	int			len_src;

	len_dest = stack_size(*dest);
	len_src = stack_size(*src);
	r.rrs = len_src - item->index;
	r.rrd = 0;
	r.rs = 0;
	r.rd = 0;
	if ((item->target->index >= (len_dest + 1) / 2))
	{
		r.rrd = len_dest - item->target->index;
		ex_revrotate(src, dest, r, dname);
	}
	else if (item->target->index < (len_dest + 1) / 2)
	{
		r.rd = item->index;
		ex_rotate(src, dest, r, dname);
	}
}

void	push_to_stack(t_stack **src, t_stack **dest, int index, char dname)
{
	int		len_src;
	t_stack	*item;

	len_src = stack_size(*src);
	item = *src;
	while (item->index != index)
		item = item->next;
	if (item->index < (len_src + 1) / 2)
		cal_rotate(src, dest, item, dname);
	else
		cal_revrotate(src, dest, item, dname);
	push(src, dest, dname);
}
