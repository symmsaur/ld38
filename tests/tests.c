#include <stdlib.h>
#include <stdio.h>
#include "../include/list.h"
#include "../include/vector.h"

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

int test_vector_cross() {
  vector v1 = {1,0,0};
  vector v2 = {0,1,0};
  vector v3 = {0,0,1};
  vector v1_cross_v2 = cross(v1, v2);
  vector v2_cross_v3 = cross(v2, v3);
  vector v3_cross_v1 = cross(v3, v1);
  if (v1_cross_v2.x != v3.x ||
      v1_cross_v2.y != v3.y ||
      v1_cross_v2.z != v3.z)
    return 1;
  if (v2_cross_v3.x != v1.x ||
      v2_cross_v3.y != v1.y ||
      v2_cross_v3.z != v1.z)
    return 1;
  if (v3_cross_v1.x != v2.x ||
      v3_cross_v1.y != v2.y ||
      v3_cross_v1.z != v2.z)
    return 1;
  return 0;
}

int main() {
  if (test_list_add()) printf("test_list_add failed");
  if (test_list_remove()) printf("test_list_remove failed");
  if (test_list_remove_first()) printf("test_list_remove_first failed");
  if (test_list_remove_last()) printf("test_list_remove_last failed");
  if (test_vector_cross()) printf("test_vector_cross failed");

  return 0;
}
