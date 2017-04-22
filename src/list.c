#include <stdlib.h>
#include "../include/list.h"

list* list_create() {
  list* new_list = malloc(sizeof(list));
  new_list->first = NULL;
  new_list->last = NULL;
  return new_list;
}

void list_add(list *l, void *elem) {
  item *new_item = malloc(sizeof(item));
  if(l->last != NULL) {
    new_item->prev = l->last;
    l->last->next = new_item;
    l->last = new_item;
  }
}

void list_destroy(list *l) {
}

void list_remove(list *l, item *i) {
}
