//=======================================================================================
#ifndef BR_H
#define BR_H
//=======================================================================================
#include <iomanip>
//=======================================================================================
namespace br
{
//=======================================================================================
    void printBr(std::vector<std::vector<int>> br)
    {

        std::cout << std::setw(3) << ' ';
        for (int i = 1; i <= br[0].size(); ++i)
            std::cout << std::setw(2) << i << ' ';

        std::cout << std::endl;

        std::cout << std::setw(2) << ' ';
        for (int i = 0; i < br[0].size(); ++i)
            std::cout << std::setw(3) << '-';

        std::cout << std::endl;

        size_t j = 1;
        for (auto &row : br)
        {
            std::cout << std::setw(2) << j++ << "|";

            for(auto &r : row)
                std::cout << std::setw(2) << r << ' ';

            std::cout << std::endl;
        }
    }
//=======================================================================================
    std::vector<std::vector<int>> makeDeveloperBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.developer < monitors_h[i].developer)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makeDiagonalBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.diagonal < monitors_h[i].diagonal)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makeResolutionBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.resolution < monitors_h[i].resolution)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makeMatrixBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.matrix < monitors_h[i].matrix)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makeFrequencyBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.frequency < monitors_h[i].frequency)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makeResponseTimeBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.response_time >= monitors_h[i].response_time)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makePowerConsumeBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.power_consume >= monitors_h[i].power_consume)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makePpiBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.ppi < monitors_h[i].ppi)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
    std::vector<std::vector<int>> makePriceBr(const std::vector<Monitor> &monitors_h)
    {
        std::vector<std::vector<int>> br;
        auto monitors_v = monitors_h;
        for (auto &m_v : monitors_v)
        {
            std::vector<int> br_row;
            for (int i = 0; i < monitors_h.size(); ++i)
            {
                if (m_v.price < monitors_h[i].price)
                    br_row.push_back(0);
                else
                    br_row.push_back(1);
            }
            br.push_back(br_row);
        }

        return br;
    }
//=======================================================================================
}
//=======================================================================================
#endif //BR_H
//=======================================================================================