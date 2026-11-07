#include <iostream>
#include <windows.h>
 
const int BITS = sizeof(unsigned int) * 8; // unsigned int (uint) - öå òèï äàííèõ ó ÿêîìó íåìà á³òà ÿêèé â³äïîâ³äàº çà çíàê (+/-)
// ÿ ³ñïîëüçîâàâ ³ìåííî óèíò òîìó ùî â unsigned íåìà çíàêîâîãî á³òà, òîìó âñå 32 áèòà ìîæíî ðàññìàòðèâàòü ÿê îáè÷íûå ðàçðÿäû, à â îáè÷íîìó èíò â ñëó÷àè â³ä'ºìíîãî ÷èñëà äîïèñèâàþòñÿ åäèíèö³, è âèâîä á³òîâ àáî ïîäñ÷åò ïîëó÷àþòüñÿ íåâ³ðíèì

void task_1(unsigned int n) {
    for (int i = BITS - 1; i >= 0; i--) {
        std::cout << ((n >> i) & 1u);
        if ((i & 7) == 0 && i != 0) std::cout << ' '; 
    }
    std::cout << '\n';
}

//Ïàðí³ñòü: îñòàí³é á³ò - 0 -> ïàðíå, 1 -> íåïàðíå
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

//-1, ÿêùî n == 0
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
    std::cout << (task_2(n) ? "ïàðíå" : "íåïàðíå") << '\n';
    task_1(task_3(n, 3));
    task_1(task_4(n, 0));
    task_1(task_5(n, 5));

    int ones, zeros;
    task_6(n, ones, zeros);
    std::cout << "Îäèíèöü: " << ones << ", íóë³â: " << zeros << '\n';

    std::cout << task_7(64) << ' ' << task_7(40) << '\n';
    std::cout << task_8(n) << '\n';
    task_1(task_9(n));
}

