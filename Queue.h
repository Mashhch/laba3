#pragma once

#include "BinarHeap.h"
#include <utility>
#define IndexOutOfRange = "Invalid range of index!";
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define NotFound = "Element doesnt found";

template <class T>
class Queue
{
private:
	int size = 0;
	BinaryHeap<std::pair<int, T>>* queue;
public:
	Queue(const int priority, const T data) {
		this->queue = new BinaryHeap<std::pair<int,T>>(std::pair<int,T>(priority, data));
		this->size = 1;
	}
	Queue(std::pair<int, T>* pair_, int size) {
		if (size <= 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);
		this->queue = new BinaryHeap<std::pair<int, T>>(pair_, size);
		this->size = size;
	}
	bool operator == (Queue& q) {
		if (q.queue == this->queue)
			return true;
		else return false;
	}
	void add(const int priority, const T value)
	{
		this->queue->Add(std::pair<int,T>(priority, value));
		this->size++;
	}
	void delet(int priority)
	{
		this->queue->deleteIn(priority);
		this->size--;
	}
	std::pair<int, T> search(int priority) {
		return this->queue->searchValue(priority);
	}
	bool exist(std::pair<int, T> value) {
		bool answ = this->queue->exist(value);
		return answ;
	}
	int getSize() {
		return this->size;
	}
	void Show() {
		this->queue->Show();
	}
	~Queue() = default;
};


