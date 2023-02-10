#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

typedef struct Packet {
    int id;
    int size;
} packet;

int main() {
    srand(time(NULL));
    int bucketSize, curSize, outputRate;
    cout << "Enter the bucket size: " << endl;
    cin >> bucketSize;
    cout << "Enter the output rate: " << endl;
    cin >> outputRate;
    vector<packet> stored;
    int id = 0;
    int i =0;
    cout << "--------------------------------------------" << endl;

    while(true) {
        Sleep(1000);
        cout << "At second " << i << ": \n" << endl;
        i++;
        for(int j=0; j<rand()%5+1; j++) {
            packet p;
            p.id = id;
            id++;
            p.size = rand()%outputRate;
            if(curSize + p.size > bucketSize) {
                cout << "Packet with id " << p.id << " and size " << p.size << " dropped" << endl;
            } else {
                stored.push_back(p);
                curSize += p.size;
                cout << "Packet with id " << p.id << " and size " << p.size << " stored" << endl;
            }
        }

        cout << "Packets before transmission is " << stored.size() << endl;        
        int n = outputRate;
        int rate = 0;
        while(stored.size() != 0 && n != 0) {
            if(n < stored[0].size) {
                cout << "Waiting for next interval" << endl;
                break;
            } else {
                curSize -= stored[0].size;
                cout << "Packet with id " << stored[0].id << " and size " << stored[0].size << " transmitted" << endl;
                n -= stored[0].size;
                rate += stored[0].size;
                stored.erase(stored.begin());
            }
        }

        cout << "Packets after transmission is " << stored.size() << endl;
        cout << "Output rate is " << rate << endl;

        if(stored.size() == 0) {
            break;
        }

        cout << "----------------------------------------------------" << endl;
    }
}
