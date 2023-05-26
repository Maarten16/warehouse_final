
#include "include/Employee.hpp"

Employee::Employee(std::string name, bool forkLiftCertificate)
: name(name),
forkLiftCertificate(forkLiftCertificate){
    //new employees are automatically assigned not busy
    this->busy = false;
}

std::string Employee::getName() {//gets employee name
    return this->name;
}

bool Employee::getBusy() {//gets whether employee is busy
    return this->busy;
}

void Employee::setBusy(bool busy) {//sets whether employee is busy
    this->busy = busy;
}

bool Employee::getForkLiftCertificate() {//gets whether employee has a forklift certificate
    return this->forkLiftCertificate;
}

void Employee::setForkLiftCertificate(bool forkLiftCertificate) {//sets employee forklift certificate
    this->forkLiftCertificate = forkLiftCertificate;
}
