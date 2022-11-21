#include <iostream>
#include <string>


using namespace std;

class DtString {

        string ss;

    public:
        // Constructors
        DtString(): ss("Nada-zippo-rien") {};
        DtString(const string& ss_in): ss(ss_in) {};

        // Copy Constructors
        DtString(const DtString& dts) : ss(dts.ss) {
            cout << "called copy constructor" << endl;
        };

        // Assignment Operator
        DtString& operator=(const DtString& other) {
            ss = other.ss;
            cout << "called assignment" << endl;
            return *this;
        }

        void print() {cout << ss << endl;}
};


void test_dt_string() {
    DtString str1;
    cout << "str1 = "; str1.print();

    DtString str2("hello world"s);
    cout << "str2 = "; str2.print();
    
    DtString str2b("cookoo for cocoa puffs"s);
    cout << endl;
    DtString str3(str2b);
    cout << "str3 = "; str3.print();

    cout << endl;
    DtString str4;
    str4 = str2;
    cout << "str4 = "; str4.print();

    cout << endl;
    DtString str5 = str2b;
    cout << "str5 = "; str5.print();

    cout << endl;
}

class Test {
        int x;
        string ss;
    
    public:

        void print() { 
            cout << "x = " << x << "  ss = " << ss << endl;
        }
};


void test_test() {

    Test t;
    t.print();

    cout << endl;
}


int main() {

    test_dt_string();

    test_test();

}
