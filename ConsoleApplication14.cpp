#include <iostream>
#include <windows.h>

const int BITS = sizeof(unsigned int) * 8; // unsigned int (uint) - це тип данних у якому нема біта який відповідає за знак (+/-)
// я іспользовав іменно уинт тому що в unsigned нема знакового біта, тому все 32 бита можно рассматривать як обичные разряды, а в обичному инт в случаи від'ємного числа дописиваются единиці, и вивод бітов або подсчет получаються невірним

void task_1(unsigned int n) {
    for (int i = BITS - 1; i >= 0; i--) {
        std::cout << ((n >> i) & 1u);
        if ((i & 7) == 0 && i != 0) std::cout << ' '; 
    }
    std::cout << '\n';
}

//Парність: останій біт - 0 -> парне, 1 -> непарне
bool task_2(unsigned int n) {
    return !(n & 1u);
}

unsigned int task_3(unsigned int n, int index) {
    return n & ~(1u << index);
}

unsigned int task_4(unsigned int n, int index) {
    return n | (1u << index);
}

unsigned int task_5(unsigned int n, int index) {
    return n ^ (1u << index);
}

void task_6(unsigned int n, int& ones, int& zeros) {
    ones = 0;
    for (int i = 0; i < BITS; i++) {
        ones += (n >> i) & 1u;
    }
    zeros = BITS - ones;
}

bool task_7(unsigned int n) {
    return n && !(n & (n - 1));
}

//-1, якщо n == 0
int task_8(unsigned int n) {
    if (!n) return -1;
    int i = 0;
    while (!((n >> i) & 1u)) {
        i++;
    }
    return i;
}

unsigned int task_9(unsigned int n) {
    return n & (n - 1);
}

int main()
{
    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251);
    int n = -40;

    task_1(n);
    std::cout << (task_2(n) ? "парне" : "непарне") << '\n';
    task_1(task_3(n, 3));
    task_1(task_4(n, 0));
    task_1(task_5(n, 5));

    int ones, zeros;
    task_6(n, ones, zeros);
    std::cout << "Одиниць: " << ones << ", нулів: " << zeros << '\n';

    std::cout << task_7(64) << ' ' << task_7(40) << '\n';
    std::cout << task_8(n) << '\n';
    task_1(task_9(n));
}

