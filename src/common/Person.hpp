#ifndef SOURCECPP_PERSON_HPP
#define SOURCECPP_PERSON_HPP

#include <optional>
#include <ostream>

namespace varu {

    class Person {

    public:
        Person(std::string name, uint32_t age, std::optional<std::string> cellNumber,
               std::optional<std::string> homeNumber);

        [[nodiscard]] const std::string &getName() const;

        [[nodiscard]] uint32_t getAge() const;

        [[nodiscard]] const std::optional<std::string> &getCellNumber() const;

        [[nodiscard]] const std::optional<std::string> &getHomeNumber() const;

        friend std::ostream &operator<<(std::ostream &os, const varu::Person &person) {
            os << "name: " << person.name_ << " age: " << person.age_ << " cell number: " << person.cell_number_.value_or("")
               << " home number: " << person.home_number_.value_or("");
            return os;
        }

    private:
        std::string name_;
        uint32_t age_;
        std::optional<std::string> cell_number_;
        std::optional<std::string> home_number_;
    };
}

#endif //SOURCECPP_PERSON_HPP
