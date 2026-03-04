// int is_valid_input(char *c)
// {
//     if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//         return (1);
//     else
//         return (0); 
// }
char is_valid_input(char *c)
{
    int i = 0;
    while (c[i])
    {
        if ((c[i] == '-' && i == 0) || (c[i] == '+' && i == 0))
        {
            i++;
            continue;
        }
        if (!(c[i] >= '0' && c[i] <= '9'))
            return (0);
        i++;
    }
    return (1); 
}

int push_swap(int argc, char **argv)
{
    if (argc < 2)
        return(0);
    if (argc == 2)
    {
        if (is_valid_input(argv[1]) == 0)
            return(write(1, "Error", 5));
        // Process the single argument case
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (is_valid_input(argv[i]) == 0)
                return(write(1, "Error", 5));
            // Process each argument
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    return push_swap(argc, argv);
}
