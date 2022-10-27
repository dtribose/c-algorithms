#include <iostream>
#include <thread>
#include <chrono>
#include <thread>
#include <time.h>

std::chrono::milliseconds timespan(1500); // or whatever

void beauty() {
    std::cout << "\nwaiting..." << std::endl;
    std::this_thread::sleep_for(timespan);
    std::cout << "\nBeauty is only skin deep\n.\n.\n.\n" << std::endl;
}

int test_multithreading() {
    clock_t start, end;
    double elapsed;
    start = clock();
    std::thread t1(beauty);
    std::thread t2(beauty);
    t1.join();
    //std::thread t2(beauty);
    t2.join();
    end = clock();
    elapsed = ((double) (end - start))/((double) 1000);
    std::cout << "Elapsed ticks for serial execution (in thousands): " << elapsed << "\n" << std::endl;

    return 0;
}



int main() {
    return test_multithreading();

}