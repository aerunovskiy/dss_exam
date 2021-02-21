//=======================================================================================
#include <iostream>
//=======================================================================================
#include "monitor.h"
#include "br.h"
//=======================================================================================
int getDomIndex(const std::vector<std::vector<int>> &br)
{
    int index = 0;
    int dom_sum = 0;

    for (size_t i = 0; i < br[0].size(); ++i)
    {
        int sum = 0;
        for (auto &element : br[i])
            sum += element;

        if (dom_sum < sum)
        {
            index   = i;
            dom_sum = sum;
        }
    }

    return index;
}
//=======================================================================================
void dominance(const std::vector<Monitor> &monitors)
{
    std::vector<int> dom_counters(monitors.size());
    std::vector<int> dom_indexes;

    dom_indexes.push_back(getDomIndex(br::makeDeveloperBr   (monitors)));
    dom_indexes.push_back(getDomIndex(br::makeDiagonalBr    (monitors)));
    dom_indexes.push_back(getDomIndex(br::makeResolutionBr  (monitors)));
    dom_indexes.push_back(getDomIndex(br::makeMatrixBr      (monitors)));
    dom_indexes.push_back(getDomIndex(br::makeFrequencyBr   (monitors)));
    dom_indexes.push_back(getDomIndex(br::makeResponseTimeBr(monitors)));
    dom_indexes.push_back(getDomIndex(br::makePowerConsumeBr(monitors)));
    dom_indexes.push_back(getDomIndex(br::makePpiBr         (monitors)));
    dom_indexes.push_back(getDomIndex(br::makePriceBr       (monitors)));

    for (auto &index : dom_indexes)
        dom_counters[index] += 1;

    std::cout << "Механизм доминирования:" << std::endl;
    std::cout << "Производитель: "         << monitors[dom_indexes[0]].name << std::endl;
    std::cout << "Диагональ: "             << monitors[dom_indexes[1]].name << std::endl;
    std::cout << "Разрешение: "            << monitors[dom_indexes[2]].name << std::endl;
    std::cout << "Тип матрицы: "           << monitors[dom_indexes[3]].name << std::endl;
    std::cout << "Частота: "               << monitors[dom_indexes[4]].name << std::endl;
    std::cout << "Время отклика: "         << monitors[dom_indexes[5]].name << std::endl;
    std::cout << "Потребление мощности: "  << monitors[dom_indexes[6]].name << std::endl;
    std::cout << "Плотность пикселей: "    << monitors[dom_indexes[7]].name << std::endl;
    std::cout << "Цена: "                  << monitors[dom_indexes[8]].name << std::endl;

    std::cout << std::endl;

    std::cout << "Количество доминируемых позиций:" << std::endl;

    for (size_t i = 0; i < monitors.size(); ++i)
        std::cout << monitors[i].name << ' ' << dom_counters[i] << std::endl;
}
//=======================================================================================
int getBlockIndex(const std::vector<std::vector<int>> &br)
{
    int index = 0;
    int block_sum = 0;

    for (size_t i = 0; i < br[0].size(); ++i)
    {
        int sum = 0;
        for (auto &row : br)
            sum += row[i];

        if (sum < block_sum || block_sum == 0)
        {
            index = i;
            block_sum = sum;
        }
    }

    return index;
}
//=======================================================================================
void blocking (const std::vector<Monitor> &monitors)
{
    std::vector<int> block_counters(monitors.size());
    std::vector<int> block_indexes;

    block_indexes.push_back(getBlockIndex(br::makeDeveloperBr   (monitors)));
    block_indexes.push_back(getBlockIndex(br::makeDiagonalBr    (monitors)));
    block_indexes.push_back(getBlockIndex(br::makeResolutionBr  (monitors)));
    block_indexes.push_back(getBlockIndex(br::makeMatrixBr      (monitors)));
    block_indexes.push_back(getBlockIndex(br::makeFrequencyBr   (monitors)));
    block_indexes.push_back(getBlockIndex(br::makeResponseTimeBr(monitors)));
    block_indexes.push_back(getBlockIndex(br::makePowerConsumeBr(monitors)));
    block_indexes.push_back(getBlockIndex(br::makePpiBr         (monitors)));
    block_indexes.push_back(getBlockIndex(br::makePriceBr       (monitors)));

    for (auto &index : block_indexes)
        block_counters[index] += 1;

    std::cout << "Механизм блокировки:"   << std::endl;
    std::cout << "Производитель: "        << monitors[getBlockIndex(br::makeDeveloperBr   (monitors))].name << std::endl;
    std::cout << "Диагональ: "            << monitors[getBlockIndex(br::makeDiagonalBr    (monitors))].name << std::endl;
    std::cout << "Разрешение: "           << monitors[getBlockIndex(br::makeResolutionBr  (monitors))].name << std::endl;
    std::cout << "Тип матрицы: "          << monitors[getBlockIndex(br::makeMatrixBr      (monitors))].name << std::endl;
    std::cout << "Частота: "              << monitors[getBlockIndex(br::makeFrequencyBr   (monitors))].name << std::endl;
    std::cout << "Время отклика: "        << monitors[getBlockIndex(br::makeResponseTimeBr(monitors))].name << std::endl;
    std::cout << "Потребление мощности: " << monitors[getBlockIndex(br::makePowerConsumeBr(monitors))].name << std::endl;
    std::cout << "Плотность пикселей: "   << monitors[getBlockIndex(br::makePpiBr         (monitors))].name << std::endl;
    std::cout << "Цена: "                 << monitors[getBlockIndex(br::makePriceBr       (monitors))].name << std::endl;

    std::cout << std::endl;

    std::cout << "Количество блокирующих позиций:" << std::endl;

    for (size_t i = 0; i < monitors.size(); ++i)
        std::cout << monitors[i].name << ' ' << block_counters[i] << std::endl;
}
//=======================================================================================
void multipleOnCoefficeients (std::vector<std::vector<double>> &matrix)
{
    std::vector<double> coefficients = {0.08, 0.14, 0.2, 0.1, 0.11, 0.06, 0.08, 0.03, 0.2};

    for (auto &row:matrix)
    {
        for (size_t i = 0; i < row.size(); ++i)
            row[i] *= coefficients[i];
    }
}
//=======================================================================================
std::vector<double> createColumn(std::vector<std::vector<int>> &br)
{
    std::vector<double> column;

    for (size_t i = 0; i < br[0].size(); ++i)
    {
        double sum = 0.0;
        for (size_t j = 0; j < br[0].size(); ++j)
        {
            if (br[i][j] == 1 && br[j][i] == 0)
                sum += 1;
            else if (br[i][j] == 0 && br[j][i] == 1)
                sum += 0;
            else if (i != j)
                sum += 0.5;
        }

        column.push_back(sum);
    }

    return column;
}
//=======================================================================================
std::vector<std::vector<double>> makeTournirMatrix(std::vector<Monitor> monitors)
{
    std::vector<std::vector<double>> tournir_matrix;
    std::vector<std::vector<std::vector<int>>> br_vector;

    br_vector.push_back(br::makeDeveloperBr   (monitors));
    br_vector.push_back(br::makeDiagonalBr    (monitors));
    br_vector.push_back(br::makeResolutionBr  (monitors));
    br_vector.push_back(br::makeMatrixBr      (monitors));
    br_vector.push_back(br::makeFrequencyBr   (monitors));
    br_vector.push_back(br::makeResponseTimeBr(monitors));
    br_vector.push_back(br::makePowerConsumeBr(monitors));
    br_vector.push_back(br::makePpiBr         (monitors));
    br_vector.push_back(br::makePriceBr       (monitors));

    for (auto & br : br_vector)
        tournir_matrix.push_back(createColumn(br));

    double t = 0.0;
    for (size_t i = 0; i < tournir_matrix[0].size(); ++i)
    {
        for (size_t j = 0; j < tournir_matrix[0].size(); ++j)
        {
            t = tournir_matrix[i][j];
            tournir_matrix[i][j] = tournir_matrix[j][i];
            tournir_matrix[j][i] = t;
        }
    }

    return tournir_matrix;
}
//=======================================================================================
void printMatrix(const std::vector<std::vector<double>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &r : row)
            std::cout << std::setw(5) << r << ' ';
        std::cout << std::endl;
    }
}
//=======================================================================================
std::vector<double> sumOfSum(const std::vector<std::vector<double>> &matrix)
{
    std::vector<double> sum_vector;
    for (auto &row : matrix)
    {
        double sum = 0.0;

        for (auto & r: row)
            sum += r;

        sum_vector.push_back(sum);
    }
    return sum_vector;
}
//=======================================================================================
int main()
{
    auto monitors = makeMonitorsVector();

    dominance(monitors);

    std::cout << std::endl;

    blocking(monitors);

    std::cout << std::endl;

    auto matrix = makeTournirMatrix(monitors);

    std::cout << "Результаты в матрице:" << std::endl;
    printMatrix(matrix);

    std::cout << std::endl;

    std::cout << "Умножение соответствующего БО на весовые коэффициенты:" << std::endl;
    multipleOnCoefficeients(matrix);
    printMatrix(matrix);

    std::cout << "\nСумма сумм для каждого варианта решения:" << std::endl;
    auto sum_of_sum = sumOfSum(matrix);

    for (size_t i = 0; i < monitors.size(); ++i)
        std::cout << monitors[i].name << " = " << sum_of_sum[i] << std::endl;

    return 0;
}
//=======================================================================================