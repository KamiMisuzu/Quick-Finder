#include <iostream>
#include <thread>
//#include <mutex>

using namespace std;

void ThreadMain() {
	cout << "begin thread ID:" << this_thread::get_id() << endl;
	for (int i = 0; i <10 ; i++)
	{
		cout << "in thread:" << i << endl;

		this_thread::sleep_for(1s);
	}
	cout << "end sub thread main" << this_thread::get_id() << endl;
}


int main()
{	
	cout << "main thread ID:" << this_thread::get_id() << endl;
	thread th(ThreadMain);
	th.join();
	
}
