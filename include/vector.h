#pragma once

typedef struct vector {
  double x;
  double y;
  double z;
} vector;

vector vec_add(vector u, vector v);
double vec_dot(vector u, vector v);
vector vec_cross(vector u, vector v);
vector vec_smult(double a, vector u);
double vec_norm(vector u);
vector vec_normalize(vector u);
vector vec_project_plane(vector u, vector normal);

vector vec_rand_on_sphere();
vector vec_rand_sphere_tangent();
