
#include "Person.hpp"

#include <utility>

const std::string &varu::Person::getName() const {
    return name_;
}

uint32_t varu::Person::getAge() const {
    return age_;
}

const std::optional<std::string> &varu::Person::getCellNumber() const {
    return cell_number_;
}

const std::optional<std::string> &varu::Person::getHomeNumber() const {
    return home_number_;
}

varu::Person::Person(std::string name, uint32_t age, std::optional<std::string> cellNumber,
                     std::optional<std::string> homeNumber) : name_(std::move(name)), age_(age), cell_number_(std::move(cellNumber)),
                                                                     home_number_(std::move(homeNumber)) {}


