#pragma once

#include <array>

using namespace std;

template<typename T, typename ... Ts>
struct Tie {
private:
    T* data[sizeof...(Ts) + 1];

public:
    Tie(T& t, Ts&... ts): data{&t, &ts...} { }

    template<typename U, size_t N>
    void operator=(const array<U, N>& arr) {
        size_t array_size = data[0]->size();
        size_t count_arrays = sizeof...(Ts) + 1;

        for (size_t i = 0; i < count_arrays; i++)
            copy(arr.begin() + i*array_size, arr.begin() + (i + 1)*array_size, data[i]->begin());
    }
};

/**
\brief Создает кортеж ссылок на переданные аргументы.
\date 2020-07-13
\param[in] ts нуль или более аргументов.
\return объект, содержащий ссылки.
*/
template<typename T, typename ... Ts>
auto mytie(T& t, Ts&... ts) {
    return Tie<T, Ts...>(t, ts...);
}
