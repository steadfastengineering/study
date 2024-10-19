#include <iostream>
#include <thread>
using namespace std; 

//volatile int shared_count = 0;

void task1(int n)
{
    cout << n << endl;
   // shared_count += n;
   // cout << shared_count << endl;
}


int main()
{
    thread worker(task1,2);
    worker.join();

    return 0;
}