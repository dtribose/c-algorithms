// Test routine for Url
#include <iostream>
#include "url.cpp"

using namespace std;

int main() { 

    string res{R"(example.com/index.html)"};
    string proto{R"(http)"};
    cout << "Creating Url object using protocol, " << proto << ", and resource, " + res << endl << endl;
    Url url = Url(proto, res);
    url.print_url();

    return 0;
}