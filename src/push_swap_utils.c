
#include "push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    
    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    if(second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
	first->index = 1;
	second->index = 0;
    *stack = second;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*item;

	if(!src || !*src)
		return ;
	item = *src;
	stack_remove(src, 0);
	stack_addfront(dest, item);
	update_index(src);
	update_index(dest);
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);

	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	update_index(stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	update_index(stack);
}