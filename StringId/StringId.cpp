//
//  StringId.cpp
//  Курсвая
//
//  Created by Данил Лямкин on 02.07.2020.
//  Copyright © 2020 Данил Лямкин. All rights reserved.
//

#include "StringId.hpp"
#include "../settings.h"
#include "../String/String.hpp"
#include <iostream>

StringId::StringId(char ch)
{
    if (DEBUG)
        std::cout << "Log: Вызов конструктора StringId с параметром: символ (char)" << std::endl;
    
    
    if (this->isValidFirstChar(ch))
    {
        this->length = 1;
        this->value = new char[2];

        this->value[0] = ch;
        this->value[1] = '\0';
    }
    else
    {
        this->length = 0;
        this->value = nullptr;
    }
}

StringId::StringId(char* str)
{
    if (DEBUG)
        std::cout << "Log: Вызов конструктора StringId с параметром: си строка (char *)" << std::endl;
    
    this->length = 0;
    this->value = nullptr;
    
    if (this->isValidFirstChar(*str))
        this->setStringId(str);
}

StringId::StringId(StringId &str)
{
    if (DEBUG)
    {
        this->countCopyConstructor++;
        std::cout << "Log: Вызов конструктора копирования StringId с параметром: StringId& (" << this->countCopyConstructor << " раз)" << std::endl;
    }
    
    int length = str.length;
    this->length = length;
    this->value = new char[length + 1];
    
    for (int i = 0; i < length; i++)
        this->value[i] = str.value[i];
}

StringId StringId::toUpper()
{
    StringId upperStr;
    
    upperStr.setStringId(this->value);
    
    for (int i = 0; i < this->length; i++)
    {
        // Инвертируем у всех строчных букв шестой бит
        if (upperStr.value[i] >= 'a' && upperStr.value[i] <= 'z')
            upperStr.value[i] = upperStr.value[i] ^ 0x20;
    }
    
    return upperStr;
}

StringId& StringId::operator=(const StringId &other)
{
    if (DEBUG)
        std::cout << "Log: Вызов метода перегрузки оператора =" << std::endl;
    
    // Проверка на самопросваивание
    if (this->value == other.value)
        return *this;
    
    // Если задано старое значение, очищаем
    if (this->value != nullptr)
        delete[] this->value;
    
    // Устанавливаем новое значение
    this->setStringId(other.value);

    return *this;
}

StringId StringId::operator+(const StringId &other)
{
    if (DEBUG)
        std::cout << "Log: Вызов метода перегрузки оператора +" << std::endl;
    
    
    StringId newStr;
    
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
    
    return newStr;
}

std::ostream& operator<<(std::ostream& out, const StringId &str)
{
    if (DEBUG)
        std::cout << "Log: Вызов метода вывода на экран" << std::endl;
    
    if (str.value == NULL)
        return out << '\0';
    
    return out << str.value;
}

void StringId::setStringId(char* str)
{
    if (DEBUG)
        std::cout << "Log: Вызов метода setStringId" << std::endl;
    
    int length = (int) strlen(str);
    
    for (int i = 1; i < length; i++)
    {
        if (!this->isValidChar(str[i]))
        {
            std::cout << "Error: Строка не соответсвует правилам записи идентификаторов" << std::endl;
            return;
        }
    }
    
    this->value = new char[length + 1];
    this->length = length;
    
    for (int i = 0; i < length; i++)
        this->value[i] = str[i];
    
    this->value[length] = '\0';
}

bool StringId::isValidFirstChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_'))
    {
        return true;
    }
    
    return false;
}

bool StringId::isValidChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    
    return false;
}
