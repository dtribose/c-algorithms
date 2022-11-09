// define functions for Url
#include <string>
#include <iostream>
#include "url.h"

using namespace std;

Url::Url(const string &protocol, const string &resource) : protocol(protocol), resource(resource) {}

void Url::print_url() {
    cout << "url: " << protocol + R"(://)" + resource + "\n" << endl;
}


