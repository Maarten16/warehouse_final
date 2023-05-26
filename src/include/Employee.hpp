#pragma once
#include <iostream>

class Employee {
    const std::string name;
    bool busy;
    bool forkLiftCertificate;

public:
    Employee(std::string name, bool forkLiftCertificate);
    std::string getName();
    bool getBusy();
    void setBusy(bool busy);
    bool getForkLiftCertificate();
    void setForkLiftCertificate(bool forkLiftCertificate);

};


