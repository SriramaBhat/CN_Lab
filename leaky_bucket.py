# Program to implement the leaky bucket algorithm

import time
import random


class Packet:
    def __init__(self, size: int, id_no: int):
        self._size = size
        self.id_no = id_no

    def get_id(self):
        return self.id_no

    def get_size(self):
        return self._size

    def set_size(self, size):
        self._size = size
        return


class LeakyBucket:
    def __init__(self, leak_rate: int, bucket_size: int):
        self.leak_rate = leak_rate
        self.max_capacity = bucket_size
        self.buffer = []
        self.current_buffer_size = 0

    def add_packet(self, new_packet: Packet):
        if self.current_buffer_size + new_packet.get_size() > self.max_capacity:
            print("Packet rejected, as the bucket is full")
            return

        self.buffer.append(new_packet)
        self.current_buffer_size += new_packet.get_size()
        print("Packet with size = {} and id_no = {} is added to the bucket"
              .format(new_packet.get_size(), new_packet.get_id()))

    def leakage(self):
        if len(self.buffer) == 0:
            print("No packets are there in the bucket")
            return -1
        else:
            n = self.leak_rate
            transmit_size = 0
            packet_id = []
            while len(self.buffer) > 0 and n != 0:
                front_packet = self.buffer[0]
                if front_packet.get_size() > n:
                    front_packet.set_size(front_packet.get_size()-n)
                    packet_id.append(front_packet.get_id())
                    transmit_size += n
                    n = 0
                else:
                    n -= front_packet.get_size()
                    transmit_size += front_packet.get_size()
                    self.current_buffer_size -= front_packet.get_size()
                    packet_id.append(front_packet.get_id())
                    self.buffer.pop(0)

            for id_no in packet_id:
                print("Output has packet with id_no = {}".format(id_no))
            print("Successful output, {} units is transmitted.".format(transmit_size))
            return 0


if __name__ == "__main__":
    bucket = LeakyBucket(100, 1000)
    for i in range(1, 10):
        bucket.add_packet(Packet(random.randint(30, 150), i))

    while True:
        temp = bucket.leakage()
        if temp == -1:
            break
        print("Interval")
        time.sleep(1)
