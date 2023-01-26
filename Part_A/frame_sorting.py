import random


class Frame:
    def __init__(self, seqNo, data=None):
        self.seqNo = seqNo
        self.data = data
        

def bubble_sort(arr):
    flag = 0
    for i in range(len(arr)):
        for j in range(len(arr)-i-1):
            if arr[j].seqNo > arr[j+1].seqNo:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
                flag = 1
        if flag == 0:
            break
        else:
            flag = 0
    
    
n = int(input("Enter the number of frames: "))

seqList = []
for _ in range(n):
    r = random.randint(1, n*100)
    while r in seqList:
        r = random.randint(1, n*100)
    seqList.append(r)
    
frames = []
for _ in range(n):
    ch = random.choice(seqList)
    frames.append(Frame(ch))
    seqList.remove(ch)
    
for i in range(n):
    frames[i].data = input(f"Enter frame data for the sequence number {frames[i].seqNo} : ")
    
bubble_sort(frames)
print("\n----------Sorted Frames---------")
for frame in frames:
    print(f"{frame.seqNo} - {frame.data}")
print()
