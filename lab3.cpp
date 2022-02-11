#include <iostream>
#include <chrono>
#include <random>
#include <Header.hpp>
const int N = 10000;

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Задание 1" << std::endl;
    std::cout << "Введите число (от 0 до 100)" << std::endl;
   int mas[N];
    for (int i = 0; i < N; i++) {
        mas[i] = rand()%101 ;
    }
    quicksort(0, N - 1, mas);
     int j;
    std::cin >> j;
    Timer t;
    int f = search(0, N-1, j, mas);
    std::cout << "Binary search: " << t.elapsed() << '\n';
    Timer v;
    f = prostoysearch(mas, N, j);
    std::cout << "Search by selection: " << v.elapsed() << '\n';
   std::cout<<""<< std::endl;
    std::cout << "Задание 2" << std::endl;
    std::cout << "x^2 - 10 = 0, x =?" << std::endl;
    double e = 0.0001;
    double ds = bisektion(0, 10, e);
    std::cout <<"x = " << ds;

}

