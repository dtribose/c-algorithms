#include <string>
#include <iostream>
#include <vector>

using namespace std;


void test_find_variants() {
    const string typing{"The extra quick brown fox jumps over the lazy dog"};

    int first_x = typing.find('x', 0);
    cout << "First x is at location " << first_x << endl;

    int second_x = typing.find('x', first_x + 1);
    cout << "Second x is located at " << second_x << endl;

    int z_loc = typing.find('z', 40);
    if(z_loc != string::npos) {
        cout << "Location of z is " << z_loc << endl;
    }
    else {
        cout << "Could not find z at or after position 44" << endl;
    }

    z_loc = typing.rfind('a', 40);
    if(z_loc != string::npos) {
        cout << "Location of a is " << z_loc << endl;
    }
    else {
        cout << "Could not find a" << endl;
    }

    // find_first_of(), find_last_of()

    string hgl = "happy go lucky";

    string im = "I'm ";

    im.append(hgl);

    im += ' ';
    im += 't';
    im += 'o';
    im += 'o';
    cout << im << endl;

    string ttt = "t very";
    hgl.insert(8, ttt, 0, 1);

    cout << hgl << endl;

    // erase(), replace()

    // Can usually use integers or iterators, or a combination.

    // assign()
}


void test_conversions() {

    string hello("Hello");

    _Float32 fpi = 3.14159;
    string pi{to_string(fpi)};  // Some extendion to float precision occurs here.

    hello.append(" ").append(pi);

    cout << hello << endl;

    // stoi

    size_t n_processed;
    auto i = stoi("31415&*9"s, &n_processed);
    cout << "i = " << i << ", n_processed= " << n_processed << endl;

    int x = stoi("2aba0", nullptr, 16);
    cout << "x = " << x << endl;

    // stol, stoll, stoull
    // and stof, as well as stod().

    cout << "pi = " << stod("3.14259"s) << endl;

}


void test_misc() {

    // data() function to access internal pointer to array or string data store.
    // One cout pass this 'pointer' to a c-style function the needs pointers.

    // str/vector swap() member funtion and global swap function.

    vector<int> v1{5,4,3,2,1};
    vector<int> v2{1,3,6,9,12};

    cout << "pre swap   v1[0], v2[0]: " << v1[0] << ", " << v2[0] << endl;
    v1.swap(v2);
    cout << "post swap, v1[0], v2[0]: " << v1[0] << ", " << v2[0] << endl;

    // NOTE: String swap - and likely something similar for vector swap as well -
    // only swaps the internal headers with information of buffer size and a pointer.
}




int main(){

    test_find_variants();

    test_conversions();

    test_misc();

    cout << endl;
    return 0;
}