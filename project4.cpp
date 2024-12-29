#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
class MyDigitalClock {
public:
    void run() {
        while (true) {
            showCurrentTime();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

private:
    void showCurrentTime() {
        auto currentTimePoint = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);
        std::tm* localTime = std::localtime(&currentTime);

        std::cout << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":"
                  << std::setw(2) << std::setfill('0') << localTime->tm_min << ":"
                  << std::setw(2) << std::setfill('0') << localTime->tm_sec << "\r";
        std::cout.flush();
    }
};

int main() {
    MyDigitalClock clock;
    clock.run();
    return 0;
}
