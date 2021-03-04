#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ubiraetProbeli(char *str1, char *str2);
void ubiraetProbeli2(char *str1);
void viborSimvolov(char *stroka, char *symv1, char *symv2);
void selecting(char *str, char *group_str, char symv1, char symv2);
void addBlank(char *str);
void output(char *stroka);
void del(char *str);


int main()
{
    char symv1, symv2;
    char str[1024] = {0};
    char filtered_string[1024] = {0};
    char group_str[1024] = {0};
    while(scanf("%[^\n]%*s", str) != EOF)
    {
        ubiraetProbeli(str, filtered_string);
        viborSimvolov(filtered_string, &symv1, &symv2);
        selecting(filtered_string, group_str, symv1, symv2);
        output(group_str);
        del(group_str);
    }
    return 0;
}

void ubiraetProbeli(char *str1, char *str2)
{
    int secondary_index = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == ' ')
        {
            continue;
        }
        else
        {
            str2[secondary_index] = str1[i];
            ++secondary_index;
        }
    }
    str2[secondary_index] = '\0';
}

void ubiraetProbeli2(char *str1)
{
    int secondary_index = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == ' ')
        {
            continue;
        }
        else
        {
            str1[secondary_index] = str1[i];
            ++secondary_index;
        }
    }
    str1[secondary_index] = '\0';
}

void viborSimvolov(char *stroka, char *symv1, char *symv2)
{
    *symv1 = stroka[0];
    *symv2 = stroka[strlen(stroka) - 1];
}

void addBlank(char *str)
{
    strcat(str, " ");
}

void selecting(char *str, char *group_str, char symv1, char symv2)
{
    char buff[1024] = {' '};
    int temp_index = 0;
    int flag = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == symv1)
        {
            flag = 1;
            for(int j = 0; j < strlen(buff); j++)
                buff[j] = ' ';
            temp_index = 0;
        }
        else if(str[i + 1] == symv2)
        {
            if(!flag)
                continue;
            ubiraetProbeli2(buff);
            strcat(group_str, buff);
            addBlank(group_str);
            flag = 0;
        }
        if(flag)
        {
            buff[temp_index] = str[i + 1];
            temp_index++;
        }
    }
    //group_str[strlen(group_str) - 1] = '\0';
}

void output(char *stroka)
{
    printf("%s\n ", stroka);
}

void del(char *str)
{
    for(int i = 0; i < strlen(str); i++)
        str[i] = 0;
}
