#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 10;
    int b = 20;
    swap(a, b);

    // Apparently, need to update a compiler setting to use multicharacter strings.
    std::string a_equals = "a = "; std::string b_equals = "  b = ";
    std::cout << a_equals << a << b_equals << b << '\n' << std::endl;

    std::string s = "foo";
    std::string t = "bar";
    swap(s, t);

    std::string s_equals = "s = "; std::string t_equals = "  t = ";
    std::cout << s_equals << s <<  t_equals << t << '\n' << std::endl;

    return 0;
}