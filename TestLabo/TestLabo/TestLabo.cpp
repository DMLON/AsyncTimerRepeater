// TestLabo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AsyncTimerFactory.h"
#include "AsyncRepeaterFactory.h"
#include "Timer.h"

using namespace std;

class A {
    const int a;
public:
    A(int aa) :a(aa) {
        //En 5 segundos llama a imprimir
        AsyncTimerFactory<A>::NewTimer(5000, this, &A::Imprimir);
    };

    void Imprimir() {
        cout << "Hola " << a << endl;
    }

    ~A() {

    }
};

class B {
    const int a;
public:
    B(int aa) :a(aa) {
        //En 0.5 segundos llama a imprimir
        AsyncRepeaterFactory<B>::NewTimer(250, this, &B::Imprimir);
        AsyncTimerFactory<B>::NewTimer(5000, this, &B::CancelarTimer);
    };

    void Imprimir() {
        cout << "Hola soy B: " << a << endl;
    }

    void CancelarTimer() {
        AsyncRepeaterFactory<B>::StopRepeater();
    }

    ~B() {

    }
};

void hola() {
    cout << "hola";
}



int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Hello World con corona!\n";
    cout << "Hola" << endl;
    A holinga(50);
    B holanga(10);

    Timer t2{ 3500,[]() {std::cout << "---------------- I waited to print! ----------------\n"; } };
    Timer t1{ 3000,[]() {std::cout << "---------------- I waited to print! ----------------\n"; }};

    cin.get();

}
