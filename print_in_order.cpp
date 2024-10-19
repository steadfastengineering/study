#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


/*
The same instance of Foo will be passed to three different threads. Thread A will call first(), 
thread B will call second(), and thread C will call third(). Design a mechanism and modify the 
program to ensure that second() is executed after first(), and third() is executed after second().

Note:
We do not know how the threads will be scheduled in the operating system, even though the numbers 
in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' 
comprehensiveness.
*/ 

/*
    The key thing to understand is that successive calls to lock() on a mutex will block execution until
    unlock() is called on that mutex.  
*/
class Foo {
public:

    //mutex first_mutex; // don't need this because first can begin at anytime. we only need to stop 2 and 3 from executing.
    mutex second_mutex;
    mutex third_mutex;

    Foo() 
    {
        // during initialization, we must lock the sections of code that are not able to run yet
        second_mutex.lock();
        third_mutex.lock();    
    }

    void first(function<void()> printFirst) {
        
        printFirst();
        second_mutex.unlock();
    }

    void second(function<void()> printSecond) {
        second_mutex.lock(); 
        printSecond();
        third_mutex.unlock();
    }

    void third(function<void()> printThird) {
        third_mutex.lock(); 
        printThird();

        // lock everything again so scheduling can continue as before.
        second_mutex.lock();
        third_mutex.lock();
    }
};