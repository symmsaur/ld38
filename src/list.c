#include <stdlib.h>
#include "../include/list.h"

list* list_create() {
  list* new_list = malloc(sizeof(list));
  new_list->first = NULL;
  new_list->last = NULL;
  return new_list;
}

item *list_add(list *l, void *elem) {
  item *new_item = malloc(sizeof(item));
  new_item->elem = elem;
  new_item->next = NULL;
  if(l->last != NULL) {
    new_item->prev = l->last;
    l->last->next = new_item;
    l->last = new_item;
  }
  else {
    //No items in list
    new_item->prev = NULL;
    new_item->next = NULL;
    l->first = new_item;
    l->last = new_item;
  }
  return new_item;
}

void list_remove(list *l, item *i) {
  if(i->prev != NULL)
    i->prev->next = i->next;
  if(i->next != NULL)
    i->next->prev = i->prev;
  if(l->first == i)
    l->first = i->next;
  if(l->last == i)
    if(l->last->prev != NULL)
      l->last = l->last->prev;
  free(i);
}

void list_destroy(list *l) {
  item *current = l->first;
  while(current->next != NULL) {
    current = current->next;
    free(current->prev);
  }
  free(l);
}
