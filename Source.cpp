#include <iostream>
#include <string>


class String {
private:

    char* str_;
    int length_;
public:


    explicit String() {
        length_ = 80;
        this->str_ = new char[length_ + 1] {};
        str_[length_ - 1] = '\0';
    }

    String(int length) : length_(length) {
        str_ = new char[length_ + 1] {};
    }
    String(const char* strat)
    {
        length_ = strlen(strat);
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_; i++) {
            str_[i] = strat[i];
        }
        str_[length_] = '\0';
    }
    
    ~String()
    {
        delete[] this->str_;
    }
    String (const String& obj)
        : length_{ obj.length_ } {
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_; i++) {
            str_[i] = obj.str_[i];
        }
        str_[length_] = '\0';
    }


    const String& operator = (const String& obj) {
        if (&obj != this) {
            delete[] str_;
            length_ = obj.length_;
            str_ = new char[length_ + 1];
            for (int i = 0; i < length_; i++) {
                str_[i] = obj.str_[i];
            }
            str_[length_] = '\0';
        }
        return *this;
    }


    friend std::ostream& operator << (std::ostream& output, const String& obj)
    {
        output << obj.str_;
        return output;
    }
    friend std::istream& operator >> (std::istream& input, String& obj)
    {
        input >> obj.str_;
        return input;
    }
};


int main()
{
    system("chcp 1251>null");


    String string1, string2, string5;

    std::cout << "Enter string 1: ";
    std::cin >> string1;
    std::cout << string1 << std::endl;

    std::cout << "Enter string 2: ";
    std::cin >> string2;
    std::cout << string2 << std::endl;

    String string3 = "Hello";
    std::cout << string3 << std::endl;

    string5 = string1;
    std::cout << string5 << std::endl;
    
    String string6{ string2 };
    std::cout << string6 << std::endl;

    return 0;
}