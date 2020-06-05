#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class Timer {
public:
    Timer(size_t time, const std::function<void(void)>& f) : time{ std::chrono::milliseconds{time} }, f{ f } {}
    ~Timer() { wait_thread.join(); }

private:
    void wait_then_call()
    {
        std::unique_lock<std::mutex> lck{ mtx };
        for (int i{ 10 }; i > 0; --i) {
            cv.wait_for(lck, time / 10);
        }
        f();
    }
    std::mutex mtx;
    std::condition_variable cv{};
    std::chrono::milliseconds time;
    std::function <void(void)> f;
    std::thread wait_thread{ [this]() {wait_then_call(); } };
};

int main()
{
    //Sigue la misma logica, si se cambia a como está en los asyncTimers funciona tambien, agregar templates y el context con los punteros a metodos de objetos
    auto f = []() {std::cout << "---------------- I waited to print! ----------------\n"; };
    Timer t1{ 3000,f };
    Timer t2{ 10'000,f };
    Timer t3{ 20'000,f };
    Timer t4{ 1000,f };
}