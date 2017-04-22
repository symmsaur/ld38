#pragma once

typedef struct item {
  void *elem;
  struct item *prev;
  struct item *next;
} item;

typedef struct list {
  item *first;
  item *last;
} list;

list* list_create();
void list_destroy(list *l);
item* list_add(list *l, void *elem);
void list_remove(list *l, item *i);

