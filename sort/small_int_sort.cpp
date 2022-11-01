#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <climits>


std::vector <unsigned short int> sort_vec1(const std::vector <unsigned short int> &vec_in) {

    // map should be ordered. If want unordered use unordered_map
    std::map<unsigned short int, int> mp;
    for(auto var: vec_in)
        ++mp[var];

    std::cout << std::endl << "size of map is: " << mp.size() << "\n" << std::endl;
    for (auto const& [key, val] : mp) {
        std::cout << key << ':' << val << std::endl;
    }
    std::cout << std::endl;

    std::vector<unsigned short int> sorted_vec = vec_in;

    std::vector <unsigned short int>::iterator iv = sorted_vec.begin();
    for(auto const& [key, val] : mp) {
        std::fill(iv, iv + val, key);
        iv += val;
    }

    return sorted_vec;
}

std::vector <unsigned short int> sort_vec2(const std::vector <unsigned short int> &vec_in) {

    // use unordered_map for faster inserts
    std::unordered_map<unsigned short int, int> mp;
    for(auto var: vec_in)
        ++mp[var];

    std::cout << std::endl << "size of map is: " << mp.size() << "\n" << std::endl;
    for (auto const& [key, val] : mp) {
        std::cout << key << ':' << val << std::endl;
    }
    std::cout << std::endl;

    std::vector<unsigned short int> sorted_vec = vec_in;

    int val;
    std::vector <unsigned short int>::iterator iv = sorted_vec.begin();

    // Convert to a do/while?
    unsigned short int key=0;
    for (int i=0; i<((int) USHRT_MAX)+1; i++) {
        if (mp.find(key) != mp.end()) {
            val = mp[key];
            std::fill(iv, iv + val, key);
            iv += val;
            std::cout << key << ", " << val << std::endl;
        }
        key++;
    }

    return sorted_vec;
}

void test_sort(int nsort) {
    // Create a vector of small ints in random order
    std::vector <unsigned short int> siv = {5,5,6,7,7,0,0,2,1,0,7,5,1,8,3,6,5,2,3,2,0,7,9,6,7,65535,5};
    //std::vector <unsigned short int> siv = {7,65535,5};

    // ** How to make a list of random numbers in C++ : Use to test out algorithms
    // v1, v2 and planned v3 with no using 'find'

   std::vector <unsigned short int> siv_copy(siv);
    for(int i=0; i<siv_copy.size(); i++) {
        std::cout << siv_copy[i] << " ";
    }
    std::cout << std::endl;

    std::vector <unsigned short int> sorted;   
    if (nsort == 1){
        sorted = sort_vec1(siv);
    } else {
        sorted = sort_vec2(siv);
    }

    std::cout << "\nFinal result..." << std::endl;
    for(int i=0; i<sorted.size(); i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl << std::endl;
}


int main() {

    // Calling sort testing routine
    test_sort(2);
}