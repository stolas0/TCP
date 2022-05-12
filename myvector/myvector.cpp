#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

template <class T>
class Vector{
private:
    size_t _size = 0;
    size_t _capacity = 0;
    T* _data = nullptr;

public:
    Vector() {}

    explicit Vector(size_t size)
        : _size(size), _capacity(size), _data(new T[size]) {}

    ~Vector() {
        delete [] _data;
    }

    Vector (Vector const& v)
        : _size(v._size), _data(new T[v._size]), _capacity(v._capacity) {
        for (size_t i = 0; i != _size; ++i){
            _data[i] = v._data[i];
        }
    }
    Vector (Vector&& v)
        : _size(v._size), _data(v._data), _capacity(v._capacity) {
        v._data = nullptr;
        v._size = 0;
        v._capacity = 0;
    }
    
    //----------------
    Vector& operator=(Vector const& v) {
	Vector tmp(v);
        this->swap(tmp);
        return *this;
    }
    //----------------
    Vector& operator=(Vector&& v) {
        if (this != &v) this->swap(v);
        return *this;
    }


    T* begin() {
        return _data;
    }

    T* end() {
        return _data + _size;
    }

    size_t size() {
        return _size;
    }
    
    size_t capacity() {
        return _capacity;
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            size_t tmp_size = _size == 0 ? 1 : _size*2;
            T* tmp = _data;
            _data = new T[tmp_size];
            
            for (size_t i = 0; i != _size; ++i){
                _data[i] = tmp[i];
            } 
            _capacity = tmp_size;
            delete[] tmp;
        }
        
        _data[_size] = value;
        _size++;
    }
    void push_back(T && value) {
        if (_size == _capacity) {
            size_t tmp_size = _size == 0 ? 1 : _size*2;
            T* tmp = _data;
            _data = new T[tmp_size];
            
            for (size_t i = 0; i != _size; ++i){
                _data[i] = move(tmp[i]);
            } 
            _capacity = tmp_size;
            delete[] tmp;
        }
        
        _data[_size] = move(value);
        _size++;
    }
//-----------
    void pop_back() {
        if (_size != 0)
            _size--;
    }
//-----------
    void erase(T* ptr) {
        copy(ptr + 1, end(), ptr);
        _size--;
    }

    void swap(Vector &v) {
        std::swap(_size, v._size);
        std::swap(_capacity, v._capacity);
        std::swap(_data, v._data);
    }
};

template <typename T>
void swap (Vector<T>& v1, Vector<T>& v2) {
    v1.swap(v2);
}


int main(){
    Vector<ofstream> files;
    size_t num_files = 4;

    for(size_t i = 0; i < num_files; i++) {
        string filename = to_string(i) + ".txt";
        ofstream file(filename);
        files.push_back(move(file));
    }

    mt19937 g {random_device{}()};
    g.seed(time(NULL));
    shuffle(files.begin(), files.end(), g);

    size_t i = 0;
    for(auto iter = files.begin(); iter != files.end(); iter++) {
        *iter << i++ << endl;
        (*iter).close();
    }

    return 0;
}
