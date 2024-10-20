#include <atomic>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

class FizzBuzz {
private:
  int n;
  volatile int i;
  mutex mtx;

public:
  FizzBuzz(int n) {
    this->n = n;
    i = 1;
  }

  ~FizzBuzz() {}
  
  // For each of these threads, the while condition is a "last check" 
  // to make sure we exit the thread. We may be inside the while loop 
  // when another thread increments our counter "i", which could cause
  // the if condition to be met and another output to printed (race 
  // condition), therefore we need to check the value of "i" in each
  // if block as well. This is the trick.

  void fizz(function<void()> printFizz) {
    while (i <= n) {
      lock_guard<mutex> lock(mtx);
      if ((i % 3 == 0) && (i % 5 != 0) && (i <= n)) {
        printFizz();
        i++;
      }
    }
  }
 
  void buzz(function<void()> printBuzz) {
    while (i <= n) {
      lock_guard<mutex> lock(mtx);
      if ((i % 5 == 0) && (i % 3 != 0) && (i <= n)) {
        printBuzz();
        i++;
      }
    }
  }
 
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (i <= n) { 
      lock_guard<mutex> lock(mtx); 
      if ((i % 5 == 0) && (i % 3 == 0) && (i <= n)) {
        printFizzBuzz();
        i++;
      }
    }
  }
 
  void number(function<void(int)> printNumber) {

    while (i <= n) {
      lock_guard<mutex> lock(mtx);

      if ((i % 3 != 0) && (i % 5 != 0) && (i <= n)) {
        printNumber(i);
        i++;
      }
    }
  }
};

// Thread A: calls fizz() that should output the word "fizz".
// Thread B: calls buzz() that should output the word "buzz".
// Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
// Thread D: calls number() that should only output the integers.

void a(FizzBuzz *fb) {
  fb->fizz([]() { cout << flush << "FIZZ"; });
}

void b(FizzBuzz *fb) {
  fb->buzz([]() { cout << flush << "buzz"; });
}

void c(FizzBuzz *fb) {
  fb->fizzbuzz([]() { cout << flush << "fizzbuzz"; });
}

void d(FizzBuzz *fb) {
  fb->number([](int i) { cout << flush << i; });
}

int main() {

  // Output may hang due to the way this is run in the console, but the solution works

  FizzBuzz *fb = new FizzBuzz(15);

  thread t1(a, fb);
  thread t2(b, fb);
  thread t3(c, fb);
  thread t4(d, fb);

  t1.detach();
  t2.detach();
  t4.detach();
  t3.detach();

  while (true)
    cin.get(); // ctrl+c to quit

  return 0;
}