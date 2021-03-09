#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getStr();
char *removeSpaces(char *le_string);
void removeSpacesForBuf(char *str1);
void charSelection(char *stroka, char *symv1, char *symv2);
char *selecting(char *str, char symv1, char symv2);
void addBlank(char *str);
void output(char *stroka);
void freeMem(char *str1, char* str2, char *str3);

int main()
{
    char symv1, symv2, *str = NULL, *filtered_str = NULL, *group_str = NULL;
    while(printf("Enter a string: \n"), str = getStr())
    {
        filtered_str = removeSpaces(str);
        output(filtered_str);
        charSelection(filtered_str, &symv1, &symv2);
        //printf("%c %c\n ", symv1, symv2);
        group_str = selecting(filtered_str, symv1, symv2);
        output(group_str);
        freeMem(str, filtered_str, group_str);
    }
    return 0;
}

char *getStr()
{
  char *ptr = (char *)malloc(1);
  char buf[81];
  int n, len = 0;
  *ptr ='\0';
  do
  {
    n = scanf("%80[^\n]", buf);
    if(n < 0)
    {
      free(ptr);
      ptr = NULL;
      continue;
    }
    if(n == 0)
    {
      scanf("%*c");
    }
    else
    {
      len += strlen(buf);
      ptr = (char *)realloc(ptr, len + 1);
      strcat(ptr,buf);
    }
  }while(n > 0);
  return ptr;
}

char *removeSpaces(char *le_string)
{
  int secondary_index = 0;
  char buf[1024];
  for(int i = 0; i < strlen(le_string); i++)
  {
      if(le_string[i] == ' ')
      {
          continue;
      }
      else
      {
          buf[secondary_index] = le_string[i];
          ++secondary_index;
      }
  }
  buf[secondary_index] = '\0';
  char *tmp = (char *)malloc(strlen(buf) + 1);
  strcpy(tmp,buf);
  //for(int i = 0; i < strlen(buf); i++)
    //buf[i] = 0;
  return tmp;
}

void removeSpacesForBuf(char *str1)
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

void charSelection(char *stroka, char *symv1, char *symv2)
{
    *symv1 = stroka[0];
    *symv2 = stroka[strlen(stroka) - 1];
}

char *selecting(char *str, char symv1, char symv2)
{
    char buff[1024] = {0};
    int temp_index = 0;
    int flag = 0, len = 0;
    char *temp = (char *)malloc(1);
    *temp = '\0';
    for(int i = 0; i < strlen(str); i++)
    {
       if(str[i] == symv1)
       {
        flag = 1;
        for(int j = 0; j < strlen(buff); j++)
        {
            buff[j] = ' ';
        }
        len = 0;
        temp_index = 0;
       }
       else if(str[i + 1] == symv2)
       {
         if(!flag)
             continue;
         printf("Buff: %s\n ", buff);
         removeSpacesForBuf(buff);
         strcat(buff, " ");
         printf("Buff2: %s\n ", buff);
         temp = (char *)realloc(temp,strlen(temp)+strlen(buff) + 1);
         strcat(temp, buff);
         printf("Temp: %s\n ", temp);
         flag = 0;
       }
       if(flag)
       {
         buff[temp_index] = str[i + 1];
         //len += strlen(buff);
         temp_index++;
       }

    }
    return temp;
}

void output(char *stroka)
{
    printf("%s\n ", stroka);
}

void freeMem(char *str1, char *str2, char *str3)
{
  free(str1);
  free(str2);
  free(str3);
}
