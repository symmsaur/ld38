#include "vector.h"

struct vector vec_add(vector u, vector v) {
  vector r;
  r.x = u.x + v.x;
  r.y = u.y + v.y;
  r.z = u.z + v.z;
  return r;
}

double vec_dot(vector u, vector v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

struct vector vec_cross(vector u, vector v) {
  vector r;
  r.x = u.y * v.z - u.z * v.y;
  r.y = u.z * v.x - u.x * v.z;
  r.z = u.x * v.y - u.y * v.x;
  return r;
}

struct vector vec_smult(double a, struct vector u) {
  vector r;
  r.x = a * u.x;
  r.y = a * u.y;
  r.z = a * u.z;
}

