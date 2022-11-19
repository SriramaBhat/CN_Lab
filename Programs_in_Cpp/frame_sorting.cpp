// C++ Program to sort frames by their sequence number
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Frame {
    int sqNum;
    string data;
} Frame;

vector<int> id;

bool compare(Frame a, Frame b) {
    return (a.sqNum < b.sqNum) ? true : false;
}

int main() {
    int n;
    vector<Frame> frames;
    cout << "Enter the number of frames: " << endl;
    cin >> n;
    cout << "Enter the frame sequence number and frame contents: " << endl;
    for(int i=0; i<n; i++) {
        Frame f;
        cin >> f.sqNum >> f.data;
        frames.push_back(f);
        id.push_back(f.sqNum);
    }
    sort(frames.begin(), frames.end(), compare);
    cout << "The frames in original sequence: " << endl;
    for (Frame f : frames) {
        cout << f.data << " ";
    }
    cout << endl;
}