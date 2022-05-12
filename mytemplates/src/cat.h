#pragma once

#include <array>

using namespace std;

template<typename T, size_t N, size_t M>
auto cat(const array<T,N>& a1, const array<T,M>& a2) {
    array<T, N+M> res;

    for (size_t i = 0; i < N; ++i){
        res[i] = a1[i];
    }

    for (size_t i = 0; i < M; ++i){
        res[i+N] = a2[i];
    }
    cout << endl;
    return res;
}

template<typename T, size_t N, size_t M, typename ... Args>
auto cat(const array<T,N>& a1,const array<T,M>& a2, const Args& ... rest) {
    array<T, N+M> res;

    for (size_t i = 0; i < N; ++i){
        res[i] = a1[i];
    }

    for (size_t i = 0; i < M; ++i){
        res[i+N] = a2[i];
    }

    return cat(res, rest ...);
}
