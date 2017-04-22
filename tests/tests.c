#include <stdlib.h>
#include <stdio.h>
#include "../include/list.h"

int test_list_add() {
  list *l = list_create();
  int first = 1;
  int middle = 2;
  int last = 3;
  list_add(l, &first);
  list_add(l, &middle);
  list_add(l, &last);
  if (*((int *)l->first->elem) != 1) return 1;
  if (*((int *)l->first->next->elem) != 2) return 1;
  if (*((int *)l->first->next->next->elem) != 3) return 1;
  if (l->first->next->next->next != NULL) return 1;

  if (*((int *)l->last->elem) != 3) return 1;
  if (*((int *)l->last->prev->elem) != 2) return 1;
  if (*((int *)l->last->prev->prev->elem) != 1) return 1;
  if (l->last->prev->prev->prev != NULL) return 1;
  return 0;
}

int test_list_remove() {
  list *l = list_create();
  int first = 1;
  int middle = 2;
  int last = 3;
  list_add(l, &first);
  item *middle_item = list_add(l, &middle);
  list_add(l, &last);
  list_remove(l, middle_item);
  if (*((int *)l->first->elem) != 1) return 1;
  if (*((int *)l->first->next->elem) != 3) return 1;
  if (l->first->next->next != NULL) return 1;
}

int test_list_remove_first() {
  list *l = list_create();
  int first = 1;
  int middle = 2;
  int last = 3;
  item *first_item = list_add(l, &first);
  list_add(l, &middle);
  list_add(l, &last);
  list_remove(l, first_item);
  if (*((int *)l->first->elem) != 2) return 1;
  if (*((int *)l->first->next->elem) != 3) return 1;
  if (l->first->next->next != NULL) return 1;
}

int test_list_remove_last() {
  list *l = list_create();
  int first = 1;
  int middle = 2;
  int last = 3;
  list_add(l, &first);
  list_add(l, &middle);
  item *last_item = list_add(l, &last);
  list_remove(l, last_item);
  if (*((int *)l->first->elem) != 1) return 1;
  if (*((int *)l->first->next->elem) != 2) return 1;
  if (l->first->next->next != NULL) return 1;
}

int main() {
  if (test_list_add()) printf("test_list_add failed");
  if (test_list_remove()) printf("test_list_remove failed");
  if (test_list_remove_first()) printf("test_list_remove_first failed");
  if (test_list_remove_last()) printf("test_list_remove_last failed");

  return 0;
}
