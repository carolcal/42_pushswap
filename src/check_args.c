#include "push_swap.h"

int is_repeat(char *argv[], char*str, int i)
{
    size_t len;

    len = ft_strlen(str);
    while (argv[i])
    {
        if(len == ft_strlen(argv[i]))
        {
            if (ft_strncmp(argv[i], str, len) == 0)
                return (EXIT_FAILURE);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int is_int(char *arg)
{
    int j;
    long    num;

    j = 0;
    if(arg[j] == '-')
    {
        if (ft_strlen(arg) > 11)
            return (EXIT_FAILURE);
        j++;
    }
    else if (ft_strlen(arg) > 10)
        return (EXIT_FAILURE);
    while (ft_isdigit(arg[j]) != 0 && arg[j])
        j++;
    if (arg[j] != '\0' && ft_isdigit(arg[j]) == 0)
        return (EXIT_FAILURE);
    num = ft_atoi(arg);
    if(num < INT_MIN || num > INT_MAX)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int check_arguments(char *argv[])
{
    int i;

    i = 1;    
    while (argv[i])
    {
        if(is_int(argv[i]) != 0)
            return (EXIT_FAILURE);
        if(is_repeat(argv, argv[i], i) != 0)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}