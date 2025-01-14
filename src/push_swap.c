
#include "push_swap.h"

void	test_change_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("stack_a:\n");
	print_stack(*stack_a);
	ft_printf("stack_b:\n");
	print_stack(*stack_b);
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	ft_printf("stack_a:\n");
	print_stack(*stack_a);
	ft_printf("stack_b:\n");
	print_stack(*stack_b);
}

int	main(int argc, char *argv[])
{
    t_stack	*stack_a;
    t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = create_stack(argc - 1, argv);
    	stack_b = NULL;
		test_change_stacks(&stack_a, &stack_b);

		free_stack(stack_a);
	}
	return (0);
}
