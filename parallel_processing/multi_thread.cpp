#include <iostream>
#include <thread>
#include <chrono>
#include <ratio>
#include <thread>
#include <time.h>

using namespace std::chrono;

milliseconds TIME_SPAN(5000); // 5 seconds (or whatever)


// Have the threads actually do something that really takes time,
// to see how many CPUs are put to work.

void beauty(milliseconds time_to_sleep) {
    std::cout << "\nwaiting..." << std::endl;
    std::this_thread::sleep_for(time_to_sleep);
    std::cout << "\nBeauty is only skin deep\n.\n.\n." << std::endl;
}

int test_multithreading() {
    clock_t start, end;
    double elapsed;
    std::thread t2;
    
    high_resolution_clock::time_point start_t = high_resolution_clock::now();
    
    std::thread t1(beauty, TIME_SPAN);
    t2 = std::thread(beauty, TIME_SPAN);  // alternative form.
    std::thread t3(beauty, TIME_SPAN);
    std::thread t4(beauty, TIME_SPAN);
    std::thread t5(beauty, TIME_SPAN);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    high_resolution_clock::time_point end_t = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_t - start_t);

    std::cout << "\nElapsed time in seconds: " << time_span.count() << "\n" << std::endl;

    return 0;
}

int main() {
    int parallel = 1;
    return test_multithreading();

}