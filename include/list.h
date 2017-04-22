typedef struct item {
  void *elem;
  struct item *prev;
  struct item *next;
} item;

typedef struct list {
  item *first;
  item *last;
} list;

list* create();
void destroy(list *l);
void add(list *l, void *elem);
void remove(list *l, item *i);

