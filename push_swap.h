
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "lib/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int		value;
	int		index;
    struct  s_stack *prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int	number);
t_stack	*stack_last(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);
void    stack_addfront(t_stack  **stack, t_stack *new);
t_stack *create_stack(int	length, char *argv[]);
void    update_index(t_stack **stack);
void    stack_remove(t_stack **stack, int index);
void    print_stack(t_stack *stack);
int     free_stack(t_stack *stack);
void    swap(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif
