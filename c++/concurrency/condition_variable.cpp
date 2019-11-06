#include <mutex>
#include <thread>

using namespace std;

class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz() {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 3 != 0 || count % 5 == 0))
                cv.wait(lock);
            if (count > n) return;
            printf("Fizz\n");
            ++count;
            cv.notify_all();
        }
    }

    void buzz() {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printf("Buzz\n");
            ++count;
            cv.notify_all();
        }
    }

	void fizzbuzz() {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 != 0))
                cv.wait(lock);
            if (count > n) return;
            printf("FizzBuzz\n");
            ++count;
            cv.notify_all();
        }
    }

    void number() {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 == 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printf("%d\n", count++);
            cv.notify_all();
        }
    }
};

void t1(FizzBuzz &fb)
{
  fb.buzz();
}
void t2(FizzBuzz &fb)
{
  fb.fizz();
}
void t3(FizzBuzz &fb)
{
  fb.fizzbuzz();
}
void t4(FizzBuzz &fb)
{
  fb.number();
}
int main() 
{
  FizzBuzz fb(100);
  // function<void()> printFizz = print_Fizz;
  // function<void()> printBuzz = print_Buzz;
  // function<void()> printFizzBuzz = print_Fizz_Buzz;
  // function<void(int)> printNum = print_n;

  // TODO comiple error to solve
  // TODO decay copy
  thread th1(t1, fb);
  thread th2(t2, fb);
  thread th3(t3, fb);
  thread th4(t4, fb);

  th1.join();
  th2.join();
  th3.join();
  th4.join();
}
