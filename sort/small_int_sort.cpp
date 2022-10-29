#include <vector>
#include <iostream>
#include <map>
#include <ranges>
#include <algorithm>
#include <numeric>




int main() {
    // Create a vector it small ints in random order

    std::vector <unsigned short int> siv = {5,5,6,7,7,0,0,2,2,1,0,7,5,8,3,6,5,2,2,0,7,9,6};

    std::vector <unsigned short int> sorted_siv(siv);
    // Confirming that siv was actually copied to foo!
    for(int i=0; i<sorted_siv.size(); i++) {
        std::cout << sorted_siv[i] << " ";
    }
    std::cout << std::endl;

    // map should be ordered. If want unordered use unordered_map
    std::map<unsigned short int, int> mp;

    for(auto var: siv)
        ++mp[var];

    std::cout << std::endl << "size of map is: " << mp.size() << "\n" << std::endl;
    
    for (auto const& [key, val] : mp)
    {
        std::cout << key        
                  << ':'  
                  << val        
                  << std::endl;
    }
    std::cout << std::endl;
    // loop over a range in C++
    // std::iota may be available (staring in C++ 20)

    std::vector <unsigned short int>::iterator iv = sorted_siv.begin();

    for(auto const& [key, val] : mp) {
        std::fill(iv, iv + val, key);
        iv += val;
    }

    for(int i=0; i<sorted_siv.size(); i++) {
        std::cout << sorted_siv[i] << " ";
    }
    std::cout << std::endl << std::endl;
}