import random


class Frame:
    def __init__(self, seqNo, data=None):
        self.seqNo = seqNo
        self.data = data
        

def merge_sort(arr):
    if(len(arr) > 1):
        left_arr = arr[:len(arr)//2]
        right_arr = arr[len(arr)//2:]
        
        merge_sort(left_arr)
        merge_sort(right_arr)
        
        i = 0
        j = 0
        k = 0
        
        while i<len(left_arr) and j<len(right_arr):
            if left_arr[i].seqNo < right_arr[j].seqNo:
                arr[k] = left_arr[i]
                i += 1
            else:
                arr[k] = right_arr[j]
                j += 1    
            k += 1
            
        while i < len(left_arr):
            arr[k] = left_arr[i]
            i += 1
            k += 1
            
        while j < len(right_arr):
            arr[k] = right_arr[j]
            j += 1
            k += 1
            


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
    
merge_sort(frames)
print("\n----------Sorted Frames---------")
for frame in frames:
    print(f"{frame.seqNo} - {frame.data}")
print()