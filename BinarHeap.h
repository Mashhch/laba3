#pragma once

#include <stdexcept>
#include <iostream>


#define NOT_FOUND "Element doesnt found"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"


template<class T>
class BinaryHeap {
private:
    T* heap;
    int size = 0;
public:
    BinaryHeap(T data) {
        this->heap = new T[1];
        this->heap[0] = data;
        this->size = 1;
    }
    BinaryHeap(T* data, int size) {
        if (size < 0)
            throw std::out_of_range(NEGATIVE_SIZE_MESSAGE);
        this->heap = new T[size];
        for (auto i = 0; i < size; i++) this->Add(data[i]);
        this->size = size;
    }
    void Add(T value) {
        int i, parent;
        i = this->size;
        T* tmp = new T[this->size + 1];
        for (int j = 0; j < this->size; j++) {
            tmp[j] = this->heap[j];
        }
        tmp[i] = value;
        parent = (i - 1) / 2;
        while (parent >= 0 && i > 0) {
            if (tmp[i] > tmp[parent]) {
                T temp = tmp[i];
                tmp[i] = tmp[parent];
                tmp[parent] = temp;
            }
            i = parent;
            parent = (i - 1) / 2;
        }
        delete[] this->heap;
        this->heap = tmp;
        this->size++;
    }
    void heapSort(int i) {
        if (i > this->size || i < 0)
            throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        int left, right;
        T temp;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < this->size) {
            if (this->heap[i] < this->heap[left]) {
                temp = this->heap[i];
                this->heap[i] = this->heap[left];
                this->heap[left] = temp;
                this->heapSort(left);
            }
        }
        if (right < this->size) {
            if (this->heap[i] < this->heap[right]) {
                temp = this->heap[i];
                this->heap[i] = this->heap[right];
                this->heap[right] = temp;
                this->heapSort(right);
            }
        }
    }
    void deleteIn(int index) {
        if (index > this->size || index < 0)
            throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (index < this->size) {
            this->heap[index] = this->heap[this->size - 1];
            this->size--;
            this->heapSort(0);
        }
    }
    T searchValue(int index) {
        if (index > this->size || index < 0) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        return this->heap[index];
    }
    int searchIndex(T value) {
        for (int i = 0; i < this->size; i++)
            if (this->heap[i] == value) return i;
        return -1;
    }

    bool exist(T value) {
        for (int i = 0; i < this->size; ++i)
            if (this->heap[i] == value)
                return true;
        return false;
    }

    T getMin() {
        T item = this->heap[0];
        for (int i = 1; i < this->size; i++)
            if (this->heap[i] < item) item = this->heap[i];
        return item;
    }

    T getMax() {
        T item = this->heap[0];
        for (int i = 1; i < this->size; i++)
            if (this->heap[i] > item) item = this->heap[i];
        return item;
    }

    int getSize() {
        return this->size;
    }

    bool operator == (const BinaryHeap& h) {
        if (this->size != h.size) return false;
        for (int i = 0; i < this->size; i++)
            if (this->heap[i] != h.heap[i])
                return false;
        return true;

    }

    void SHOW() {
        int i = 0;
        int k = 1;
        while (i < this->size) {
            while ((i < k) && (i < this->size)) {
                std::cout << this->heap[i] << " ";
                i++;
            }
            std::cout << std::endl;
            k = k * 2 + 1;
        }
    }

    ~BinaryHeap() {
        delete[] this->heap;
        this->size = 0;
    }
};

