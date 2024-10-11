#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();
    void (Harl::*complaints[4])();
    std::string levels[4];

public:
    Harl();
    void complain(std::string level);
};

#endif
