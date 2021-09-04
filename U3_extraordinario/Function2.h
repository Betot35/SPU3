#include <stdlib.h>
#include <string.h>
int searchIndex(char *str, char Character)
{
    int n = 0, count = -1;
    n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == Character)
        {
            count = i;
            break;
        }
    }
    return count;
}