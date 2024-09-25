#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void showHelp() {
    std::cout << "Использование: ./calculator -o <операция> <операнды>\n";
    std::cout << "Доступные операции:\n";
    std::cout << "- summa: среднее арифметическое\n";
    std::cout << "- median: медиана\n";
}

double calculateMean(const std::vector<double>& operands) {
    return std::accumulate(operands.begin(), operands.end(), 0.0) / operands.size();
}

double calculateMedian(std::vector<double> operands) {
    std::sort(operands.begin(), operands.end());
    size_t size = operands.size();
    if (size % 2 == 0) {
        return (operands[size / 2 - 1] + operands[size / 2]) / 2;
    } else {
        return operands[size / 2];
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        showHelp();
        return 1;
    }

    std::string operation = argv[2];
    std::vector<double> operands;

    for (int i = 3; i < argc; ++i) {
        operands.push_back(std::stod(argv[i]));
    }

    // Проверка количества операндов
    if (operands.size() < 6 || operands.size() > 8) {
        std::cout << "Ошибка: количество операндов должно быть от 6 до 8." << std::endl;
        return 1;
    }

    // Выполнение операции
    if (operation == "summa") {
        double result = calculateMean(operands);
        std::cout << "Среднее арифметическое: " << result << std::endl;
    } else if (operation == "median") {
        double result = calculateMedian(operands);
        std::cout << "Медиана: " << result << std::endl;
    } else {
        showHelp();
    }

    return 0;
}
