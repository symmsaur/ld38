typedef struct item {
  void *elem;
  item *prev;
  item *next;
} item;

typedef struct list {
  item *first;
  item *last;
} list;

list* create();
void destroy();
void add(*list, *elem);
void remove(*list, *elem);

