#include "vec2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NAN_VEC ((vec2){NAN, NAN})
#define ZERO_COORD ((coordinates){0, 0})

/// Create a 2d vector.
/// @param x_ The first component.
/// @param y_ The second component.
/// @return The newly created vector.
vec2 vec2_create(double x_, double y_) {
    vec2 Vector = {x_,y_};
    return Vector;
}

/// Create a zero 2d vector.
/// @return The newly created zero vector.
vec2 vec2_create_zero() {
    return vec2_create(0.0, 0.0);
}

/// Add two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The sum in a new vector.
vec2 vec2_add(vec2 lhs, vec2 rhs) {
    vec2 Vector = vec2_create(lhs.x + rhs.x, lhs.y + rhs.y);
    return Vector;
}

/// Substract two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The difference in a new vector.
vec2 vec2_sub(vec2 lhs, vec2 rhs) {

    vec2 Vector = vec2_create(lhs.x - rhs.x, lhs.y - rhs.y);
    return Vector;
}

/// Multiply a vector by a scalar.
/// @param scalar The left operand, a scalar.
/// @param rhs The right operand, a vector.
/// @return The product in a new vector.
vec2 vec2_mul(double scalar, vec2 rhs) {
    vec2 Vector = vec2_create(scalar * rhs.x, scalar * rhs.y);
    return Vector;
}

/// Rotate the vector counter-clockwise.
/// @param theta The left operand, an angle in radians.
/// @param rhs The right operand, a vector.
/// @return A new rotated vector.
vec2 vec2_rotate(double theta, vec2 rhs) {
    vec2 Vector = vec2_create(rhs.x * cos(theta) - rhs.y * sin(theta), rhs.x*sin(theta) + rhs.y * cos(theta));
    return Vector;
}

/// Compute the dot product (scalar product) between two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The dot product.
double vec2_dot(vec2 lhs, vec2 rhs) {
    double scalar = lhs.x * rhs.x + lhs.y * rhs.y;
    return scalar;
}

/// Compute the square of the euclidean norm of a given vector.
/// @param v The vector.
/// @return The square of the norm.
double vec2_norm_sqr(vec2 v) {
    double SqrNorm = v.x * v.x + v.y * v.y;
    return SqrNorm;
}

/// Compute the euclidean norm of a given vector.
/// @param v The vector.
/// @return The norm.
double vec2_norm(vec2 v) {
    double Norm = sqrt(vec2_norm_sqr(v));
    return Norm;
}

/// Compute the normalization of a given vector.
/// @param v The vector.
/// @return The new normalized vector.
vec2 vec2_normalize(vec2 v) {
    vec2 Vector = vec2_create(v.x /vec2_norm(v) , v.y /vec2_norm(v));
    return Vector;
}

/// Check whether two vectors are approximately equals within a given tolerance.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @param eps The tolerance.
/// @return true if vector are approximately equal, false otherwise.
bool vec2_is_approx_equal(vec2 lhs, vec2 rhs, double eps) {
    if((fabs(lhs.x - rhs.x) < eps) && (fabs(lhs.y - rhs.y) < eps)){
        return true;
    }
    else{
        return false;
    }
}

/// Compute the coordinates of a 2d vector (with components between -1 and 1)
/// in a given screen matrix.
/// @param v The 2d vector.
/// @param width The screen width.
/// @param height The screen height.
/// @return The coordinates (row, column).
coordinates vec2_to_coordinates(vec2 v, uint32_t width, uint32_t height) {
    vec2 Vector = vec2_create((v.x + 1)/2 , (v.y + 1)/2);
    coordinates Coordinates = {round(Vector.y * (height - 1)), round(Vector.x * (width - 1))};
    return Coordinates;
}

/// Print a vector in the standard output.
/// @param v The vector.
void vec2_print(vec2 v) {
    printf("x = %g, y = %g\n", v.x, v.y);
}