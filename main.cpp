#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class test_class {
public:
	void operator()() {
		cout << "Hello from test class - " << this_thread::get_id() << endl;
	}
};


void foo() {
	cout << "Hello from foo - " << this_thread::get_id() << endl;
}

void test() {

	//thread - function parameter
	thread t1(foo);
	t1.join();

	//thread - lambda parameter
	thread t2([] {cout << "Hello from lambda - " << this_thread::get_id() << endl; });
	t2.join();

	//thread - class object parameter
	test_class obj;
	thread t3(obj);
	t3.join();
}


//function to check main thread
void is_main() {
	thread::id m = this_thread::get_id();

	if (m == this_thread::get_id()) {
		cout << "This is the main thread" << endl;
	}
	else {
		cout << "This is not the main thread" << endl;
	}

}


int main() {
	test();

	thread t4(is_main);
	t4.join();
}
