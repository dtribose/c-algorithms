// float_string.cpp
#include <iostream>
#include <string>

using namespace std;


void test_string_literals(){

    cout << R"x(She said "The quick fox lazily jumps over the brown dog (I think that's how it goes).")x" << endl;

    cout << endl;
}


void bad_print(char* msg) {
    cout << "In bad_print      : " << msg << endl;
    // msg[4] = 'y'; // Trying to change the value on a const pointer (cast as a non-const) caused segmentation fault.
}

void print_as_list(const string str_) {
    string::const_iterator si = str_.begin();
    cout << '{';
    while(si != str_.end()) {
        if(si != str_.begin()) {
            cout << ',';
        }
        cout << *si;
        si++;
    } 
    cout << '}' << endl;
}

void type_conversion() {
    
    const char* msg = "hello gorgeous world";

    cout << "In type conversion: " << msg << endl;
    // bad_print(msg);  // Not allowed, since msg is a pointer to a const char *

    //auto foo = const_cast<char *> (msg); // Need to use a const_cast to force this to be a non-constant pointer.
    //bad_print(foo);
    bad_print(const_cast<char *> (msg));
    
    string str_msg{msg};

    cout << "string version    : " << str_msg << endl;

    print_as_list(str_msg);

    cout << endl;
}

void float_string() {
    int forty_two_d = 42;
    cout << "Decimal 42 = " << forty_two_d << endl;

    int forty_two_hex = 0x2a;
    cout << "Hexadecimal 42 (0x2a) = " << forty_two_hex << endl;

    int forty_two_oct = 052;
    cout << "Octal 42 (052) = " << forty_two_oct << endl;

    int one_million = 1'000'000;
    cout << "One million with single quotes (1'000'000) = " << one_million << endl;

    cout << endl;
}

void test_auto() {

    const auto& xy = 6;
    cout << "xy = " << xy << endl;

    int z = xy + 3;
    cout << "xy + 3 = " << z << endl;

    auto s = "Greetings Aliens"s;
    cout << "s = " << s << endl;

    cout << endl;
}

void test_iteration() {
    string beetle_str = "sdrawkcab em yalP"s;

    cout << "Funny string             : ";
    for(auto abs: beetle_str) {

        if(abs == 'e'){
            abs = 'i';  // Does not change value in string.
        }

        cout << abs;
    }   
    cout << endl;

    cout << "In reverse...            : ";
    string::const_reverse_iterator crt = beetle_str.crbegin();
    while(crt != beetle_str.crend()){
        cout << *crt;
        crt++;
    }
    cout << endl;
    
    cout << "Funny... using references: ";
    for(auto& abs: beetle_str) {

        if(abs == 'e'){
            abs = 'i';  // Does change value!
        }

        cout << abs;
    }   
    cout << endl;

    cout << "In reverse...            : ";
    crt = beetle_str.crbegin();
    while(crt != beetle_str.crend()){
        cout << *crt;
        crt++;
    }
    cout << endl;

    cout << endl << endl;
}

void next_previous(){

    string foo = "fubar";
    cout << "string = " << foo << endl;

    int len_foo = distance(foo.begin(), foo.end());
    cout << "length of string is " << len_foo << endl;

    if (foo.begin() == begin(foo)) {
        cout << "Ah, foo.begin == begin(foo)" << endl;
    }

    int mid_point = len_foo / 2;

    string::iterator mid = begin(foo);
    advance(mid, mid_point);

    if(mid != foo.end()) {
        cout << "middle element is '" << *mid << "'";
        cout << ", with index into string equal to " << distance(foo.begin(), mid) << endl;

    }

    advance (mid, 10);
    if(mid == foo.end()) {
        cout << "Yes, went past the end when added 10" << endl;
    }

    cout << endl;
}

void switch_if() {

    string fbo = "ba r\tf\no o";

    if(auto si=fbo.begin(); si != fbo.end()){
        cout << *si << endl;
    }

    int white_space = 0;
    for(auto c: fbo) {
        switch(c) {
            case ' ':
                [[fallthrough]];
            case '\t':
                [[fallthrough]];
            case '\n':
                ++white_space;
                break;
            default:
                break;
        }
    }

    cout << "Number of whitespace characters in '" << fbo << "' is " << white_space << endl;

    cout << endl;
}

//Testing out floating point number values 
int main() {

    // float_string();
    // type_conversion();
    // test_string_literals();
    //  test_auto();
    //  test_iteration();
    next_previous();

    switch_if();
}
