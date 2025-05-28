#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

class Stopwatch {
private:
std::chrono::steady_clock::time_point start_time;
std::chrono::steady_clock::time_point end_time;
bool running;

public:
Stopwatch() : running(false) {}

void start() {
    start_time = std::chrono::steady_clock::now();
    running = true;
}

void stop() {
    if (running) {
        end_time = std::chrono::steady_clock::now();
        running = false;
    }
}

void reset() {
    start_time = std::chrono::steady_clock::time_point();
    end_time = std::chrono::steady_clock::time_point();
    running = false;
}

double get_elapsed_time_seconds() const {
    std::chrono::duration<double> elapsed;
    if (running) {
        elapsed = std::chrono::steady_clock::now() - start_time;
    } else {
        elapsed = end_time - start_time;
    }
    return elapsed.count();
}

double get_elapsed_time_milliseconds() const {
    std::chrono::duration<double, std::milli> elapsed;
    if (running) {
        elapsed = std::chrono::steady_clock::now() - start_time;
    } else {
        elapsed = end_time - start_time;
    }
    return elapsed.count();
}
};

#endif 
