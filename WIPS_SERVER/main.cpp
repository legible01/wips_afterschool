#include <iostream>
#include <thread>
#include "svrsocket.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    //return 0;
    svrsocket testClass = svrsocket();
    testClass.testFunc();
    //thread thread1(&svrsocket::testFunc,testClass);
  //  thread1.join();
    return 0;
}
