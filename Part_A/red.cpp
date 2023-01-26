#include <bits/stdc++.h>

using namespace std;

const int QUEUE_SIZE = 10;
const int MAX_PACKETS = 20;
const double MAX_PROBABILITY = 0.7;
const double MIN_PROBABILITY = 0.3;

// Generates a random number between min and max
double rand_double(double min, double max) {
  return min + (max - min) * (double) rand() / RAND_MAX;
}

int main() {
  // Seed the random number generator
  srand(time(0));

  int queue_size = 0;
  double drop_probability = MIN_PROBABILITY;
  for (int i = 0; i < MAX_PACKETS; i++) {
    if (queue_size == QUEUE_SIZE) {
      // Queue is full, drop the packet
      cout << "Packet dropped (queue full)\n";
      drop_probability = MIN_PROBABILITY;
    } else if (rand_double(0, 1) < drop_probability) {
      // Randomly drop the packet based on the current drop probability
      cout << "Packet dropped (random)\n";
      drop_probability += (MAX_PROBABILITY - MIN_PROBABILITY) / (MAX_PACKETS - 1);
    } else {
      // Accept the packet
      cout << "Packet accepted\n";
      queue_size++;
      drop_probability = MIN_PROBABILITY;
    }
  }

  return 0;
}