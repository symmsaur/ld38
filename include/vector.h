typedef struct vector {
  double x;
  double y;
  double z;
} vector;

vector add(vector u, vector v);
double dot(vector u, vector v);
vector cross(vector u, vector v);
vector smult(double a, struct vector u);

