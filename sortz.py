#
# Sortz
#


# Bubble Sort, n^2
def bubbleSort(data):
    n = len(data)
    for i in range(0, n):
        for j in range(i+1, n):
            if data[i] > data[j]:
                temp = data[i]
                data[i] = data[j]
                data[j] = temp

# Selection Sort, n^2
# Beginning from the first position, move through the data until you find the
# smallest element, place it at the front, then move to the next postion, and
# move through the data until you find the next smallest element, placing it in
# position. Repeat until the data is sorted. We are selected the next smallest.
def selectionSort(data):
    n = len(data)
    for i in range(0, n):
        min = i
        for j in range(i+1, n):
            if data[j] < data[min]:
                min = j

        temp = data[i]
        data[i] = data[min]
        data[min] = temp

def buildHeap(data):
    n = len(data)
    heap = []
    for i in range(0, n):
        heap.append(data[i])
        reheapUp(heap, len(heap)-1)
    return heap

def reheapUp(data, i):
    parent = int((i-1)/2)
    if(data[i] > data[parent]):
        data[i], data[parent] = data[parent], data[i]
        reheapUp(data, parent)

def heapSort(data):
    heap = buildHeap(data)
    print(heap)
    for i in range(0, len(heap)):
        heap[i], heap[len(heap)-1] = heap[len(heap)-1], heap[i]
        reheapUp(data, i)

    print(heap)


def reheapDown(heap, i):
    left = i*2 + 1
    right = (i+1)*2

def printData(data):
    for datum in data:
        print(datum)

data = [2, 4, 68, 56, 99, 56, 59, 24, 35, 199, 44, 19]
heapSort(data)
# printData(data)
