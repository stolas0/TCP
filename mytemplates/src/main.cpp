#include <iostream>
#include <string>
#include <array>
#include "message.h"
#include "cat.h"
#include "tie.h"

using namespace std;

int main() {
    message(cout, "%%\n", 'a', 'b');

    array<float,3> vec1{1.0f,2.0f,3.0f};
    array<float,2> vec2{4.0f,5.0f};
    array<float,4> vec3{6.0f,7.0f, 8.0f, 9.0f};
    array<float,2> vec4{10.0f,11.0f};   
    auto r = cat(vec1, vec2, vec3, vec4);
    
    for (size_t i = 0; i < r.size(); ++i) cout << r[i] << ' ';
    cout << endl;

    array<float, 2> v1, v2;
    mytie(v1, v2) = vec3;
    for (size_t i = 0; i < v1.size(); ++i) cout << v1[i] << ' ';
    cout << endl;
    for (size_t i = 0; i < v2.size(); ++i) cout << v2[i] << ' ';    
    cout << endl;

    return 0;
}
