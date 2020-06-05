// TestLabo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AsyncTimerFactory.h"

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
        AsyncTimerFactory<B>::NewTimer(500, this, &B::Imprimir);
    };

    void Imprimir() {
        cout << "Hola " << a << endl;
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
    cin.get();
}
