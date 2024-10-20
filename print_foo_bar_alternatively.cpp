#include <iostream>
#include <string> 
#include <mutex>
#include <thread> 
#include <functional>

using namespace std;
 
class FooBar {
private:
    int n;
    volatile bool toggle;
    mutex foo_lock;
    mutex bar_lock;

public:
    FooBar(int n) {
        this->n = n;  
        bar_lock.lock();
    }
 
 
    void foo(function<void()> printFoo)
    { 
        for (int i = 0; i < n; i++) 
        {    
            foo_lock.lock();
         	printFoo();  
            bar_lock.unlock();
        }
    }

    void bar(function<void()> printBar) 
    {
        for (int i = 0; i < n; i++) 
        {  
            bar_lock.lock(); 
         	printBar(); 
            foo_lock.unlock(); 
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
    function<void()> f = [](){cout << flush << "foo" << flush;};
    fb->foo(f);
}
 
void task2(FooBar* fb)
{
    function<void()> f = [](){cout << flush << "bar" << flush;};
    fb->foo(f);
}

int main()
{
    FooBar* fb = new FooBar(3);
    
    thread thread_a(task1, fb);
    thread thread_b(task2, fb);

    thread_a.detach();
    thread_b.detach();

    cout << endl;

    return 0;
}