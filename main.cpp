#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Fibbonachi_Numbers(int n, string thread_name) {
	cout << "Вызван поток " << thread_name << endl;
	this_thread::sleep_for(chrono::milliseconds(10));
	int cur = 1, prev = 0, next;
	for (int i = 2; i < n; ++i) {
		next = prev + cur;
		cout << next << " ";
		prev = cur;
		cur = next;
	}
	cout << endl;
}
void Natural_Numbers(int n, string thread_name) {
	cout << "Вызван поток " << thread_name << endl;
	this_thread::sleep_for(chrono::milliseconds(10));
	for (int i = 1; i < n; ++i) {
		cout << i << " ";
	}
	cout << endl;
}
void Random_Numbers(int n, string thread_name) {
	cout << "Вызван поток " << thread_name << endl;
	this_thread::sleep_for(chrono::milliseconds(10));
	int i = 0;
	while (i < n) {
		cout << 1 + rand() % 100 << " ";
		++i;
	}
	cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
	int n1 = 26, n2 = 28, n3 = 22;

	thread t1(Fibbonachi_Numbers, n1, "t1");
	t1.join();

	thread t2(Natural_Numbers, n2, "t2");
	t2.join();

	thread t3(Random_Numbers, n3, "t3");
	t3.join();

	return 0;
}
