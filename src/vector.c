#include <math.h>
#include <stdlib.h>

#include "vector.h"

vector vec_add(vector u, vector v) {
  vector r;
  r.x = u.x + v.x;
  r.y = u.y + v.y;
  r.z = u.z + v.z;
  return r;
}

double vec_dot(vector u, vector v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

vector vec_cross(vector u, vector v) {
  vector r;
  r.x = u.y * v.z - u.z * v.y;
  r.y = u.z * v.x - u.x * v.z;
  r.z = u.x * v.y - u.y * v.x;
  return r;
}

vector vec_smult(double a, vector u) {
  vector r;
  r.x = a * u.x;
  r.y = a * u.y;
  r.z = a * u.z;
  return r;
}

double vec_norm(vector u) {
  return sqrt(vec_dot(u, u));
}

vector vec_normalize(vector u) {
  vector r = vec_smult(1.0 / vec_norm(u), u);
  return r;
}

vector vec_project_plane(vector u, vector normal) {
  vector unit_normal = vec_normalize(normal);
  vector u_perp = vec_smult(vec_dot(u, unit_normal), unit_normal); 
  return vec_add(u, vec_smult(-1, u_perp));
}

vector vec_rand_on_sphere() {
  vector u;
  u.x = 2 * ((double)rand() / RAND_MAX) - 1;
  u.y = 2 * ((double)rand() / RAND_MAX) - 1;
  u.z = 2 * ((double)rand() / RAND_MAX) - 1;
  return vec_normalize(u);
}

