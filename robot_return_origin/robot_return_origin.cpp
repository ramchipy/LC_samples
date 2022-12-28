#include <map>
#include <string_view>
#include <vector>
#include <iostream>

bool does_robot_return_origin(std::string_view str)
{
    const std::map<char, std::pair<int, int>> DIR{
        {'U', {0, 1}},
        {'D', {0, -1}},
        {'R', {1, 0}},
        {'L', {-1, 0}}
    };
    int x = 0;
    int y = 0;
    for(char ch: str)
    {
        auto [dirx, diry] = DIR.at(ch);
        x += dirx;
        y += diry;
    }

    return x == 0 && y == 0;
}

int main(void)
{
#if 0
for dirs in ['UD', 'UR', 'UURRDDLL']:
    print("After '{}' does robot return: {}".format(dirs, does_robot_return_origin(dirs)))
#endif
    for(auto& str: std::vector<std::string_view>{"UD", "UR", "UURRDDLL"})
    {
        std::cout<<"After '"<<str<<"' does robot return: "<<does_robot_return_origin(str)<<"\n";
    }
}