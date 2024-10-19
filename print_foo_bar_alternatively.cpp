#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <unistd.h> // sleep
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    volatile bool toggle;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n; 
        toggle = true;
    }
 
    void foo(function<void()> printFoo)
    { 
        for (int i = 0; i < n; i++) 
        {   
            unique_lock<mutex> ul(mtx); 
         	printFoo();  
            // it gets unlocked automatically at the end of this section when ul is de-structed!
        }
    }

    void bar(function<void()> printBar) 
    {
        for (int i = 0; i < n; i++) 
        { 
            unique_lock<mutex> ul(mtx);
         	printBar(); 
            // it gets unlocked automatically at the end of this section when ul is de-structed!
        }
    }
};


/*
The same instance of FooBar will be passed to two different threads:
    thread A will call foo(), while
    thread B will call bar().
Modify the given program to output "foobar" n times.
*/

void task1(FooBar* fb)
{
    function<void()> f = [](void){cout << "foo";};
    fb->foo(f);
}
 
void task2(FooBar* fb)
{
    function<void()> f = [](void){cout << "bar";};
    fb->foo(f);
}

int main()
{
    FooBar* fb = new FooBar(3);
    
    thread thread_a(task1, fb);
    thread thread_b(task2, fb);

    thread_b.detach();
    thread_a.join();

    cout << endl;

    return 0;
}