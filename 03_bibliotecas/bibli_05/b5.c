#include "b5.h"
#include <stdio.h>

int string_length(char *str)
{
    int x=0, count=0;
    for(x=0 ; x>-1 ; x++)
    {
        if(str[x]=='\0')
        {
            break;
        }
        count++;
    }
    return count;
}

void string_copy(char *src, char *dest)
{
    int x=0;
    for(x=0 ; x<string_length(src) ; x++)
    {
        dest[x]=src[x];
    }
    x = string_length(src);
    dest[x]='\0';
}

void string_upper(char *str)
{
    int x=0;
    for(x=0 ; x<string_length(str) ; x++)
    {
        if(str[x]>='a' && str[x]<='z')
        {
            str[x]-=32;
        }
    }
}

void string_lower(char *str)
{
    int x=0;
    for(x=0 ; x<string_length(str) ; x++)
    {
        if(str[x]>='A' && str[x]<='Z')
        {
            str[x]+=32;
        }
    }
}

void string_reverse(char *str)
{
    int x=0, y=0;
    char reverso[string_length(str)];
    for(x=string_length(str)-1, y=0; x>=0 ; x-- , y++)
    {
        reverso[y] = str[x];
    }
    x = string_length(str);
    reverso[x] =  '\0';
    printf("String invertida: %s", reverso);
}