// url.h declare class for url

#ifndef URL_H_
#define URL_H_

#include <string>

using namespace std;

class Url {

    private:

        string protocol;
        string resource;

    public:

        Url(const string &protocol, const string &resource);
        void print_url();
};

#endif // URL_H_