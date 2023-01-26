// Program to demonstrate leaky bucket algorithm
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

typedef struct Packet {
    int id, size;
} Packet;

class LeakyBucket {
    public:
        int bucketSize;
        int leakRate;
        int curBufferSize;
        vector<Packet> buffer;

        LeakyBucket(int size, int rate) {
            bucketSize = size;
            leakRate = rate;
            curBufferSize = 0;          
        }

        void addPacket(Packet p) {
            if(curBufferSize + p.size > bucketSize) {
                cout << "Bucket full, package rejected" << endl;
                return;
            }

            buffer.push_back(p);
            curBufferSize += p.size;
            cout << "Packet with id " << p.id << " and size " << p.size << " is added to the bucket" << endl;          
        }

        int leakage() {
            if(buffer.size() == 0) {
                cout << "No packets are in the bucket!" << endl;
                return -1;
            } else {
                int n = leakRate;
                int size = 0;
                vector<int> pid;
                while(buffer.size() != 0 && n!=0) {
                    if(buffer.at(0).size > n) {
                        buffer.at(0).size -= n;
                        pid.push_back(buffer.at(0).id);
                        size += n;
                        n = 0;
                    } else {
                        n -= buffer.at(0).size;
                        size += buffer.at(0).size;
                        curBufferSize -= buffer.at(0).size;
                        pid.push_back(buffer.at(0).id);
                        buffer.erase(buffer.begin());
                    }
                }

                for(int i=0; i<pid.size(); i++)
                    cout << "Packet with id = " << pid.at(i) << " is in the output" << endl;
                cout << "Successful output with " << size << " units transmitted" << endl;
                return 0;
            }
        } 
};

int main() {
    cout << "Enter the bucket size and output rate:" << endl;
    int cap, rate;
    cin >> cap >> rate;
    LeakyBucket b = LeakyBucket(cap, rate);
    srand(time(0));
    for(int i=0; i<10; i++) {
        Packet p;
        p.id = i+1;
        p.size = rand()%200;
        b.addPacket(p);
    }

    while (true) {
        int temp = b.leakage();
        if(temp == -1)
            break;
        cout << "Interval" << endl;
        Sleep(1);
    }

    return 0;
}