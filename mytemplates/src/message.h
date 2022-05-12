#pragma once

#include <iostream>

using namespace std;

template<typename T>
ostream& message(ostream& os, string templ, const T& t) {
    auto id = templ.find_first_of('%');
    return os << templ.substr(0, id) << t << templ.substr(id+1);
}

template<typename T, typename ... Args>
ostream& message(ostream& os, string templ, const T& t, const Args& ... rest) {
    auto id = templ.find_first_of('%');
    
    os << templ.substr(0, id) << t;
    templ.erase(0, id+1);

    return message(os, templ, rest ...);
}
