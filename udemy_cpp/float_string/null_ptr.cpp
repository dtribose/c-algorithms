#include <iostream>

using namespace std;

void func(int i) {
    cout << "func(int) called\n" << endl;
}

void func(int *i) {
    cout << "func(int *) called\n" << endl;
}

int main() {
    // Null evaluates to zero 
    //func(NULL);  // In GCC NULL can be an int or an int * !!
    func(nullptr);

    if (0 == NULL) {
        cout << "0 == NULL" << endl;
    }
}
