#include <iostream>
#include <string>
#include <vector>

using namespace std;
using pfunc = int (*)(int&, int&);

int x{23};

namespace abc {
    int x{47};

    void func() {
        cout << "abc::x = " << x << endl;
        cout << "::x = " << ::x << endl;
    }
}

template<typename T>  // why no ';' after this line?
T Biggest(const T& b1, const T& b2) {
    if(b1 > b2)
        return b1;
    else 
        return b2;
}

template <class T>
class Test {

    T data;

    public:
        Test(const T& data) : data{data} {}

        void pprint() {
            cout << "Objects data is:" << data << endl;
        }
};

template <typename T>
class DBubble {

    T ddata;

    public:
        DBubble(const T& data) {
            ddata = data + data;
        }

        void pprint() {
            cout << "Objects data is:" << ddata << endl;
        }
};

void test_biggest() {

    long long foo = 123456789e10;
    long long bar = 133456789e10;

    cout << "Biggest number of foo and bar = " << Biggest(foo, bar) << endl;

    cout << endl;
}


void test_class_templates() {
    Test<string> test{"Hello"};
    test.pprint();

    DBubble<string> dbl{"Bubble "};
    dbl.pprint();  // outputs Bubble Bubble [as in 'toil and trouble']

    DBubble<int> dblint{7};  
    dblint.pprint(); // outputs 14
    cout << endl;

    cout << endl;
}

void test_namespaces() {
    abc::func();
    cout << endl;
}


class AddOrMult {

    private:
        pfunc pf1 = nullptr;
        pfunc pf2 = nullptr;

    public:
    AddOrMult(pfunc f1, pfunc f2) {
        pf1 = f1;
        pf2 = f2;
    }

    int do_math(string& method, int& v1, int& v2) {

        if(method == "add") {
            return (*pf1)(v1, v2);
        }
        else if (method == "mult"){
            return (*pf2)(v1, v2);
        } else {
            cout << "Sorry, no math today." << endl;
            return 0;
        }
    }
};

int mult_two(int& a, int& b) {
    return a * b;
}

int add_two(int& a, int& b) {
    return (a + b);
}

void test_function_pointers(string math){

    AddOrMult a_or_m = AddOrMult(&add_two, &mult_two);

    int x = 33;
    int y = 44;
    int val = a_or_m.do_math(math, x, y);

    cout << "Output value is " << val << endl;
    cout << endl;
}


void basic_string_ops(void){
    string s1{"This is a test "};
    string s2{"of the emergency broadcasting system."};

    cout << "s1 + s2 = " << s1 + s2 << endl;

    cout << "s2.substr(7, 9) = " << s2.substr(7, 9) << endl;

    cout << endl;
}


int main() {

    // test_biggest();
    // test_class_templates();
    // test_namespaces();
    test_function_pointers("mult");
    basic_string_ops();

    return 0;
}