#include "Timer.h"



void main_test()
{
    //Sigue la misma logica, si se cambia a como está en los asyncTimers funciona tambien, agregar templates y el context con los punteros a metodos de objetos
    auto f = []() {std::cout << "---------------- I waited to print! ----------------\n"; };
    Timer t1{ 3000,f };
    Timer t2{ 10'000,f };
    Timer t3{ 20'000,f };
    Timer t4{ 1000,f };
}