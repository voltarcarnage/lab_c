#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct list {
    char c;
    struct list *next;
} list;

list * init(char x);
list * add(list *a, char n);
list * del(list *a, list *orig);
list * del_root(list *orig);
void print_list(list *a);
void free_list(list *orig);
list* fill(char *str);
list* wordRev(list *list);
list* gapDel(list *lst);
//void listShow(list *list);
//void reverseList(list *list,list **filtered_list);


int main()
{

    list *head = NULL;
    char *str;
    while(scanf("%m[^\n]",&str) != EOF)
    {
      if(str == NULL)
      {
        printf("Empty string");
      }
      else
      {
        head = fill(str);
        head = gapDel(head);
        head = wordRev(head);
        print_list(head);
      }
      scanf("%*c");
      free_list(head);
      free(str);
      printf("\n");
    }
    return 0;
}

list * init(char x){
  list *a;
  a = malloc(sizeof(list));
  a->c = x;
  a->next = NULL;
  return a;
}


list * add(list *a, char c){
  list *tmp, *p;
  tmp = malloc(sizeof(list));
  p = a->next;
  a->next = tmp;
  tmp->c = c;
  tmp->next = p;
  return tmp;
}


list * del(list *a, list *orig){
  list *tmp;
  tmp = orig;

  while(tmp->next != a){
    tmp = tmp->next;
  }

  tmp->next = a->next;
  free(a);
  return tmp;
}


list * del_root(list *orig){
   list *tmp;
   tmp = orig->next;
   free(orig);
   return tmp;
}


void print_list(list *a){
  list *p;
  p = a;
  while(p != NULL){
    printf("%c", p->c);
    p = p->next;
  }
}


void free_list(list *orig){
  list *p;
  while(orig != NULL){
    p = orig->next;
    free(orig);
    orig = p;
  }
}

list* fill(char *str)
{
  list* tmp = NULL;
  list* o = NULL;
  tmp = init(*str);
  str++;
  o = tmp;
  for(; *str != '\0'; ++str)
  {
    tmp = add(tmp, *str);
  }
  tmp = add(tmp, ' ');
  tmp = o;
  return tmp;
}

list* wordRev(list *lst)
{
  list *temp = NULL;
  list *temp3 = NULL;
  list *temp2 = NULL;
  list *temp1 = NULL;
  int k = 0,m = 0;
  list *o = NULL;
  o = lst;
  if(!lst)
  {
    return NULL;
  }
  while(lst)
  {
    if(lst->c == ' ')
    {
      if(temp3)
      {
        //printf("%c - temp1, %c - temp3, %c - temp2 ", temp1->c, temp3->c, temp2->c);
        temp2 = lst;
        lst = temp3;
        lst->next = temp1;
        lst = temp2;
      }
      k = 0;
      temp3 = lst;
      lst = temp;
      lst->next = temp3;
      if(lst->next)
        lst = lst->next;
      if(lst->next)
          lst = lst->next;
      while(lst->c == ' ' && m)//Нет проверки на нуль и хуeta какая to
      {
        lst = del(lst,o);
      }
      //printf("\nVivod, %c - Bykva ", lst->c);
      //print_list(lst);
    }
    else
    {
      if(!k)
      {
        m = 1;
        //printf("\nPervoe vxozdenie simvola posle probela - ");
        //print_list(lst);
        k = 1;
        temp1 = lst;
        temp = lst;
        lst = lst->next;
      }
      else
      {
        //printf("\nOstalnoe slovo - ");
        //print_list(lst);
        temp2 = lst->next;
        lst->next = temp1;
        temp1 = lst;
        if(temp2->c == ' ' && o == temp)
        {
          o = lst;
        }
        lst = temp2;
      }
    }
  }
  lst = o;
  //printf("\nfinal ");
  //print_list(lst);
  return lst;
}

list * gapDel(list * lst){
  list * tmp;
  int k = 1;
  while(lst && k){
    if(lst->c == ' ' || lst->c == '\t'){
      lst = del_root(lst);

    }
    else{
      k=0;
    }
  }

  tmp = lst;

  while(lst->next){
    if(lst->c == ' ' || lst->c == '\t'){
      if(!k){
        k = 1;
        lst->c = ' ';
        lst = lst->next;
      }
      else{
      k = 0;
      lst = del(lst, tmp);
      }
    }

    else{
      k = 0;
      lst = lst->next;
    }
  }
  //lst = add(lst, ' ');
  lst = tmp;
  return lst;
}
/*void listShow(Node *list)
{
  Node *tmp = NULL;
  Node *filtered_tmp = NULL;
  int flag = 0;
  int n = 0;
  while(list)
  {
    if(list->symbol == ' ')
    {
      if(flag == 0)
        continue;
      reverseList(tmp, &filtered_tmp);
      insert(filtered_tmp, n, ' ');
      outputList(filtered_tmp);
      deleteList(&tmp);
      flag = 0;
    }
    else
    {
      flag = 1;
      tmp->next = (Node *)malloc(sizeof(Node));
      tmp = tmp->next;
      tmp->symbol = list->symbol;
      filtered_tmp->next = (Node *)malloc(sizeof(Node));
      filtered_tmp = filtered_tmp->next;
      n++;
    }
  }
}

void reverseList(Node *list,Node **filtered_list)
{
  char buff[1024] = {0};
  int i = 0;
  while(list)
  {
    buff[i] = list->symbol;
    list = list->next;
    i++;
  }
  for(int j = strlen(buff) - 1; j > 0; j--)
  {
    (*filtered_list)->symbol = buff[j];
    (*filtered_list) = (*filtered_list)->next;
  }
}
*/
