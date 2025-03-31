#include ".includes.hpp"

int main()
{
    // Get the current time
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);

    // Format the time as [YYYYMMDD_HHMMSS]
    std::cout << '['
              << std::put_time(local_time, "%Y%m%d_%H%M%S")
              << ']' << std::endl;

    return 0;
}