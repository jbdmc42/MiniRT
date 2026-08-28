#include "minirt.h"

static int  verify_extension(char *arg, int len)
{
    if (arg[len - 3] == '.' && arg[len - 2] == 'r' && arg[len - 1] == 't')
        return (1);
    return (0);
}

int    input_validation(char *arg)
{
    int len;
    
    len = ft_strlen(arg);
    if (len < 4)
        return (0);
    if (!verify_extension(arg, len))
        return (0);
    return (1);
}
