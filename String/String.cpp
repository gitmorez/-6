//
//  String.cpp
//  Курсвая
//
//  Created by Данил Лямкин on 28.06.2020.
//  Copyright © 2020 Данил Лямкин. All rights reserved.
//

#include "String.hpp"
#include <cstring>
#include "../settings.h"
#include <iostream>

int String::countCopyConstructor = 0;

String::String()
{
    this->value = nullptr;
    
    if (DEBUG)
        std::cout << "Log: Вызов конструктора String без параметров" << std::endl;
}

String::String(char* str)
{    
    this->setString(str);
    
    if (DEBUG)
        std::cout << "Log: Вызов конструктора String с параметром: си строка" << std::endl;
}

String::String(char ch)
{
    this->length = 1;
    this->value = new char[2];
    
    this->value[0] = ch;
    this->value[1] = '\0';
    
    if (DEBUG)
        std::cout << "Log: Вызов конструктора String с параметром: символ (char)" << std::endl;
}

String::String(String &str)
{
    int length = str.length;
    this->length = length;
    this->value = new char[length + 1];
    
    for (int i = 0; i < length; i++)
        this->value[i] = str.value[i];
    
    if (DEBUG)
    {
        this->countCopyConstructor++;
        std::cout << "Log: Вызов конструктора копирования String с параметром: String& (" << this->countCopyConstructor << " раз)" << std::endl;
    }
}

String::~String()
{
    delete[] this->value;
    
    if (DEBUG)
        std::cout << "Log: Вызов деструктора String" << std::endl;
}

void String::setString(char* str)
{
    int length = (int) strlen(str);
    this->value = new char[length + 1];
    this->length = length;
    
    for (int i = 0; i < length; i++)
        this->value[i] = str[i];
    
    this->value[length] = '\0';
    
    if (DEBUG)
        std::cout << "Log: Вызов метода setString" << std::endl;
}

int String::getLength()
{
    if (DEBUG)
        std::cout << "Log: Вызов метода getLength" << std::endl;
    
    return this->length;
}

std::ostream& operator<<(std::ostream& out, const String &str)
{
    out << str.value;
    return out;
}

String& String::operator=(const String &other)
{
    // Проверка на самопросваивание
    if (this->value == other.value)
        return *this;
    
    // Если задано старое значение, очищаем
    if (this->value != nullptr)
        delete[] this->value;
    
    // Устанавливаем новое значение
    this->setString(other.value);

    if (DEBUG)
        std::cout << "Log: Вызов метода перегрузки оператора =" << std::endl;

    return *this;
}

String String::operator+(const String &other)
{
    String newStr;
    
    // Длина новой строки
    int length = this->length + other.length;
    newStr.length = length;
    
    newStr.value = new char[length + 1];
    
    int i = 0;
    
    // Записываем в новую строку левый операнд
    for (; i < this->length; i++)
        newStr.value[i] = this->value[i];
    
    // Дополняем новую строку правым операндом
    for (int j = 0; j < other.length; j++, i++)
        newStr.value[i] = other.value[j];
    
    newStr.value[length] = '\0';
    
    if (DEBUG)
        std::cout << "Log: Вызов метода перегрузки оператора +" << std::endl;
    
    return newStr;
}
