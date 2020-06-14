#include <iostream>
#include <cassert>
#include <complex>
#include "Queue.h"
#include "BinarHeap.h"
#include "BinarTree.h"
#include <utility>


void TestBinarHeapAdd() {
	{
		BinaryHeap<int> h(7);
		int tmp[1] = { 7 };
		int* temp = new int[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
	}
	{
		BinaryHeap<int> h((3, 0));
		for (auto i = 2; i < 5; i++) h.Add((i, 0));
		std::complex<int> tmp[4] = { (4,0),(3,0),(3,0),(2,0) };
		std::complex<int>* temp = new std::complex<int>[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
	}
	{
		double temp[6] = { 2.11, 0.53, 1.52, 2.5, 3.71, 4 };
		BinaryHeap<double> h(temp, 6);
		double tmp[6] = { 4, 2.5 ,3.71, 0.53, 2.11, 1.52 };
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
	}
}
	void TestBinarHeapDelElem() {
		{
			BinaryHeap<int> h(2);
			for (auto i = 0; i < 5; i++) h.Add(i);
			h.deleteIn(0);
			int tmp[5] = { 3,2,2,0,1 };
			int* temp = new int[5];
			temp[0] = 0;
			for (int j = 0; j < h.getSize(); j++) {
				temp[j] = h.searchValue(j);
			}
			for (int j = 0; j < h.getSize(); j++)
				assert(tmp[j] == temp[j]);
		}
		{
			BinaryHeap<int> h(2);
			for (auto i = 0; i < 5; i++) h.Add(i);
			h.deleteIn(3);
			int tmp[5] = { 4,2,3,1,2 };
			int* temp = new int[5];
			temp[0] = 0;
			for (int j = 0; j < h.getSize(); j++) {
				temp[j] = h.searchValue(j);
			}
			for (int j = 0; j < h.getSize(); j++)
				assert(tmp[j] == temp[j]);
		}
	}

	void TestBinarHeapFindElem(){
		{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.searchValue(3);
		int tmp = 0;
		assert(tmp == temp);
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.searchIndex(0);
		int tmp = 3;
		assert(tmp == temp);
	}
	{
		double temp[6] = { 2.1,0.3,1.22,2.5,3.01,4 };
		BinaryHeap<double> h(temp, 6);
		double temp_ = h.getMin();
		double tmp = 0.3;
		assert(tmp == temp_);
	}

	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.getMax();
		int tmp = 4;
		assert(tmp == temp);
	}

}

	void TestBinarTreeAdd() {
		{
			BinaryTree<int> h(0);
			bool quest = h.exist(0);
			assert(quest == true);
		}
		{
			BinaryTree<int> h(2);
			bool quest = false;
			for (auto i = 0; i < 100; i++) h.add(i);
			for (int j = 0; j < h.getSize() - 1; j++) {
				quest = h.exist(j);
				assert(quest == true);
			}
		}
		{
			BinaryTree<int> h(2);
			bool quest = false;
			for (auto i = 0; i < 15; i++) h.add(i);
			for (int j = 0; j < h.getSize() - 1; j++) {
				quest = h.exist(j);
				assert(quest == true);
			}

		}
		{
			BinaryTree<double> h(2.3);
			bool quest = false;
			double i = 0.1;
			while (i < 5) {
				h.add(i);
				i = i + 1;
			}
			i = 0.1;
			while (i < 5) {
				quest = h.exist(i);
				assert(quest == true);
				i = i + 1;
			}
		}
	}
	void TestBinarTreeDel() {
		{
			BinaryTree<int> h(2);
			for (auto i = 0; i < 10; i++) h.add(i);
			h.erase(0);
			bool quest = h.exist(0);
			assert(quest != true);
		}
		{
			BinaryTree<int> h(2);
			for (auto i = 0; i < 5; i++) h.add(i);
			h.erase(3);
			bool quest = h.exist(3);
			assert(quest != true);
		}
	}
	void TestBinarTreeFind(){
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 5; i++) h.add(i);
		int temp = h.min();
		int tmp = 0;
		assert(tmp == temp);
	}
	{
		BinaryTree<double> h(2.3);
		double i = 1.1;
		while (i < 6) {
			h.add(i);
			i++;
		}
		double temp = h.min();
		double tmp = 1.1;
		assert(tmp == temp);
	}
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 5; i++) h.add(i);
		int temp = h.max();
		int tmp = 4;
		assert(tmp == temp);
	}
	{
		BinaryTree<double> h(6.3);
		double i = 1.1;
		while (i < 6) {
			h.add(i);
			i++;
		}
		double temp = h.max();
		double tmp = 6.3;
		assert(tmp == temp);
	}

}

	void TestQueue(){
		{
			Queue<int> h(2, 1);
			for (auto i = 0; i < 5; i++) h.add(i, i);
			h.delet(0);
			bool tmp = h.exist({ 4,4 });
			assert(tmp == false);
		}
		{
			Queue<int> h(2, 1);
			for (auto i = 0; i < 5; i++) h.add(i, i);
			h.delet(2);
			bool tmp = h.exist({ 3,3 });
			assert(tmp == false);
		}
		{
			Queue<int> h(2, 1);
			for (auto i = 0; i < 5; i++) h.add(i, i);
			std::pair<int,int> temp = h.search(2);
			std::pair<int,int> tmp = { 3,3 };
			assert(tmp == temp);
		}
		{
			std::pair<int,double> temp[6] = { {2,2.1},{0,0.3},{1,1.22},{2,2.5},{3,3.01},{4,4} };
			Queue<double> h(temp, 6);
			std::pair<int,double> temp_ = h.search(1);
			std::pair<int,double> tmp = { 2,2.1 };
			assert(tmp != temp_);
		}
	}


int main() {
	TestBinarHeapAdd();
	std::cout << "1 test ok\n";
	TestBinarHeapDelElem();
	std::cout << "2 test ok\n";
	TestBinarHeapFindElem();
	std::cout << "3 test ok\n";
	TestBinarTreeAdd();
	std::cout << "4 test ok\n";
	TestBinarTreeDel();
	std::cout << "5 test ok\n";
	TestBinarTreeFind();
	std::cout << "6 test ok\n";
	TestQueue();
	std::cout << "7 test ok\n";
	std::cout << "all tests ok\n";
} 
