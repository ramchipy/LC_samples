#include <chrono>
#include <string_view>
#include <boost/format.hpp>

template<typename func, typename ...Args>
decltype(auto) perform_print_duration(std::string_view explanation, func&& callable, Args&& ...args)
{
    namespace chrn = std::chrono;
    auto start = std::chrono::steady_clock::now();

    auto result = std::invoke(std::forward<func>(callable), std::forward<Args>(args)...);

    auto end = chrn::steady_clock::now();
    std::cout << "Elapsed time in seconds: "<< (boost::format("%.6f") % chrn::duration<float>(end - start).count()).str() << " sec\n";    
    return result;
}

template<typename func, typename ...Args>
void perform_measure(std::string_view explanation, func&& callable, Args&& ...args)
{
    namespace chrn = std::chrono;
    auto start = std::chrono::steady_clock::now();

    std::invoke(std::forward<func>(callable), std::forward<Args>(args)...);

    auto end = chrn::steady_clock::now();
    std::cout<<"Elapsed time in seconds for '"<<explanation<<"': "<< (boost::format("%.6f") % chrn::duration<float>(end - start).count()).str() << " sec\n";    
}