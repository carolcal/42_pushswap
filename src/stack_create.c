#include "push_swap.h"

t_stack	*stack_new(int	number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = number;
	new -> index = 0;
	new -> prev = NULL;
	new -> next = NULL;
    return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	last = stack_last(*stack);
	if(!last)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
		new->index = last->index + 1;
	}
}

void    stack_addfront(t_stack  **stack, t_stack *new)
{
    if(!stack || !new)
        return ;
    if (*stack)
    {
        new->next = *stack;
        (*stack)->prev = new;
    }
    else
    {
        new->next = NULL;
        new->prev = NULL;
    }
    *stack = new;
    update_index(stack);
}

t_stack *create_stack(int	length, char *argv[])
{
    int i;
	int	number;
	t_stack *stack = NULL;

	i = 0;
	while (i++ < length)
	{
		number = ft_atoi(argv[i]);
		stack_addback(&stack, stack_new(number));
	}
	return (stack);
}