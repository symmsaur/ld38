#pragma once

typedef struct vector {
  double x;
  double y;
  double z;
} vector;

vector vec_add(vector u, vector v);
double vec_dot(vector u, vector v);
vector vec_cross(vector u, vector v);
vector vec_smult(double a, struct vector u);
