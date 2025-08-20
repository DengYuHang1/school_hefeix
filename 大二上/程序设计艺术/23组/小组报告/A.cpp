#include <iostream>
#include <cmath>

int years_until_pollution(double N, double M, double K) {
    int years = 0;
    double current_area = N;
    while (current_area > M) {
        current_area *= (1 - K / 100);
        ++years;
    }
    return years;
}

int main() {
    double N, M, K;

    std::cout << "Enter the initial area: ";
    std::cin >> N;
    std::cout << "Enter the target area: ";
    std::cin >> M;
    std::cout << "Enter the percentage decrease per year: ";
    std::cin >> K;

    std::cout << "Years until pollution reaches target area: " 
              << years_until_pollution(N, M, K) << std::endl;

    return 0;
}
