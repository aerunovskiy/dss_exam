//=======================================================================================
#ifndef MONITOR_H
#define MONITOR_H
//=======================================================================================
#include <utility>
#include <vector>
//=======================================================================================
class Monitor
{
public:
    enum class Developer
    {
        DEXP    = 0,
        AOC     = 1,
        PHILIPS = 2,
        DELL    = 3,
        HP      = 4,
        LG      = 5,
        SAMSUNG = 6
    };

    enum class Matrix
    {
        TN  = 0,
        VA  = 1,
        IPS = 2,
        PLS = 3
    };

    struct Resolution
    {
        Resolution(uint16_t width,
                   uint16_t height)
        : width (width),
          height(height)
        {}

        uint8_t width;
        uint8_t height;
    };

    Monitor(std::string name,
            Developer   developer,
            double      diagonal,
            Resolution  resolution,
            Matrix      matrix,
            uint8_t     frequency,
            uint8_t     response_time,
            uint8_t     power_consume,
            uint8_t     ppi,
            uint32_t    price)
        : name         (std::move(name)),
          developer    (developer),
          diagonal     (diagonal),
          resolution   (resolution),
          matrix       (matrix),
          frequency    (frequency),
          response_time(response_time),
          power_consume(power_consume),
          ppi          (ppi),
          price        (price)
    {}

    std::string name;
    Developer   developer;
    double      diagonal;
    Resolution  resolution;
    Matrix      matrix;
    uint8_t     frequency;
    uint8_t     response_time;
    uint8_t     power_consume;
    uint8_t     ppi;
    uint32_t    price;
};
//=======================================================================================
bool operator<(const Monitor::Resolution &r1, const Monitor::Resolution &r2)
{
    return (r1.height * r1.width) < (r2.height * r2.width);
}
//=======================================================================================
std::vector<Monitor> makeMonitorsVector()
{
    std::vector<Monitor> monitors;

    Monitor m1("HP 20kd",
               Monitor::Developer::HP,
               19.5,
               Monitor::Resolution(1440, 900),
               Monitor::Matrix::IPS,
               60,
               8,
               18,
               87,
               6499);

    Monitor m2("AOC M2470SWD23",
               Monitor::Developer::AOC,
               23.6,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::VA,
               60,
               85,
               26,
               93,
               7899);

    Monitor m3("Samsung S24D332H",
               Monitor::Developer::SAMSUNG,
               24.0,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::TN,
               75,
               1,
               30,
               92,
               8699);

    Monitor m4("Dell E2221HN",
               Monitor::Developer::DELL,
               21.5,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::TN,
               60,
               3,
               13,
               102,
               7199);

    Monitor m5("Samsung S27F354FHI",
               Monitor::Developer::SAMSUNG,
               27,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::PLS,
               60,
               4,
               25,
               81,
               10999);

    Monitor m6("DEXP QF321K",
               Monitor::Developer::DEXP,
               31.5,
               Monitor::Resolution(2560, 1440),
               Monitor::Matrix::IPS,
               75,
               6,
               52,
               93,
               16999);

    Monitor m7("AOC Q3279VWFD8",
               Monitor::Developer::AOC,
               31.5,
               Monitor::Resolution(2560, 1440),
               Monitor::Matrix::IPS,
               75,
               5,
               50,
               93,
               17499);

    Monitor m8("Philips 243V5LHAB",
               Monitor::Developer::PHILIPS,
               23.6,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::TN,
               60,
               1,
               19,
               93,
               8599);

    Monitor m9("LG 24GL650-B",
               Monitor::Developer::LG,
               23.6,
               Monitor::Resolution(1920, 1080),
               Monitor::Matrix::TN,
               144,
               1,
               38,
               93,
               13499);

    monitors.push_back(m1);
    monitors.push_back(m2);
    monitors.push_back(m3);
    monitors.push_back(m4);
    monitors.push_back(m5);
    monitors.push_back(m6);
    monitors.push_back(m7);
    monitors.push_back(m8);
    monitors.push_back(m9);

    return monitors;
}
#endif //MONITOR_H
//=======================================================================================