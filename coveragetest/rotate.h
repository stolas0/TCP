#pragma once

template<class T>
struct Vector {
    T x;
    T y;

    Vector(T X, T Y): x(X), y(Y) {};

    bool operator==(const Vector& v) const {
        return x == v.x && y == v.y;
    }
};


template<class T>
Vector<T> rotate(const Vector<T>& v, int degree) {

    while(degree < 0) degree += 360;
    while(degree >= 360) degree -= 360;

    if (degree == 90)
        return Vector<T>(-v.y, v.x);

    if (degree == 180)
        return Vector<T>(-v.x, -v.y);

    if (degree == 270)
        return Vector<T>(v.y, -v.x);

    return Vector<T>(v.x, v.y);
}
