#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define F & (1 << 31)
#define S & (1 << 30)
#define C (char)
#define DEBUG1 write(1, "var\n", 4)
// int set(int *var, int value);
int reset(int *var, int value);



int reset(int *var, int value)
{
    static int  *compare;

    if (var == compare)
        return (0);
    else if (!var)
        compare = NULL;
    else
    {
        compare = var;
        *var = value;
        // set(0, 0);
        return (1);
    }
}

// int set(int *var, int value)
// {
//     static int  *compare;

//     if (var == compare)
//         return (0);
//     else
//     {
//         compare = var;
//         *var = value;
//         return (1);
//     }
// }

int setter(int type)
{
    static int setter = 31;

    if (type == 'C')
    {
        printf("%c, setter: %i \n", type, setter);
        if (setter == 31)
            return (setter);
        else
            return (setter + 1);
    }
    else if (type == 'G')
    {
        printf("%c, setter: %i \n", type, setter); 
        return (setter--);
    }
    return (0);
}




int set(int *var, int value)
{
    *var = value;
    *var |= (1 << 31);
}

int main(void)
{
    int  i;

    while ((i++ F || set(&i, 0)) && (char)i < 10)
        printf("%i\n", (char)i);
}
