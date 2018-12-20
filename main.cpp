#include <iostream>
#include <math.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int CountBitNum1(int in)
{
    int cnt = 0;

    for (int i = 0; i < 32; i++) {
        if (((in >> i) & 0x1) == 1)
            cnt++;
    }

    return cnt;
}

int CountBitNum2(int in)
{
    int cnt = 0;

    for (int i = 0; i < 32; i++) {
        if (in < (int)pow(2.0, i)) {
            for (int j = 0; j < i; j++) {
                if (((in >> j) & 0x1) == 1)
                    cnt++;
            }
            break;
        }
    }

    return cnt;
}

high_resolution_clock::time_point t1;
high_resolution_clock::time_point t2;
void BitCounter(int in)
{
    t1 = high_resolution_clock::now();
    for (int i = 0; i <= in; i++) {
        //cout << CountBitNum1(i) << " ";
        CountBitNum1(i);
    }
    cout << endl;
    t2 = high_resolution_clock::now();
    cout << (duration_cast<duration<double>>(t2 - t1)).count() << endl;

    t1 = high_resolution_clock::now();
    for (int i = 0; i <= in; i++) {
        //cout << CountBitNum1(i) << " ";
        CountBitNum2(i);
    }
    cout << endl;
    t2 = high_resolution_clock::now();
    cout << (duration_cast<duration<double>>(t2 - t1)).count() << endl;
}

int main() 
{
    int test = 0;

    // test = 5;
    // BitCounter(test);
    
    test = 65535;
    BitCounter(test);    

    return 0;
}