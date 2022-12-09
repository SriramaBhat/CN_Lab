// Program to demonstrate token bucket algorithm
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class TokenBucket{
    public:
        int tokens;
        int time_unit;
        int bucket;
        time_t last_check;

        TokenBucket(int tokens, int time_unit) {
            this->tokens = tokens;
            this->time_unit = time_unit;
            this->bucket = tokens;
            this->last_check = time(NULL);
        }

        void handle(string packet) {
            time_t current = time(NULL);
            time_t time_passed = current - last_check;
            last_check = current;

            bucket = bucket + time_passed * (tokens/time_unit);

            if (bucket > tokens) {
                bucket = tokens;
            }

            if (bucket < 1) {
                drop_callback(packet);
            } else {
                bucket = bucket - 1;
                forward_callback(packet);
            }
        }

        void forward_callback(string packet) {
            cout << "Packet Forwarded: " << packet << endl;
        }

        void drop_callback(string packet) {
            cout << "Packet Dropped: " << packet << endl;
        }
};

int main() {
    TokenBucket throttle = TokenBucket(1, 1);
    int packet = 0;
    int max_limit = 10;

    while (packet <= max_limit) {
        Sleep(500);
        throttle.handle(to_string(packet));
        packet += 1;
    }
    
    return 0;
}
