#include <iostream>
#include <_sample/_sample.h>

int main() {
    foo f(10);
    f.add(5);
    std::cout << "TEST " << f.bar << '\n';
}
