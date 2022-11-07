#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main() {

    test_biggest();
    test_class_templates();
}