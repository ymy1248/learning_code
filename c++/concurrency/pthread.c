#include <pthread.h>
#include <iostream>

using namespace std;

void *thread_func(void *arg)
{
  auto id = pthread_self();
  cout << id << endl;
}
int main() {
  pthread_create();
}
