//
//  StringId.hpp
//  Курсвая
//
//  Created by Данил Лямкин on 02.07.2020.
//  Copyright © 2020 Данил Лямкин. All rights reserved.
//

#ifndef StringId_hpp
#define StringId_hpp

#include <iostream>
#include "../String/String.hpp"

class StringId : public String
{
public:
    // Конструктор без параметров
    StringId() : String() {};
    
    // Конструктор с параметром символ
    StringId(char);
    
    // Конструктор с параметром си строка
    StringId(char*);
    
    // Конструктор копирования
    StringId(StringId &);
    
    // Перегрузка оператора присваивания
    StringId& operator=(const StringId &);
    
    // Перегрузка оператора сложения
    StringId operator+(const StringId &);
    
    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream&, const StringId &);
    
    // Перевод всех символов в верхний регистр
    void toUpper();
    
    
private:
    // Проверка правил записи идентификатора
    bool isValidChar(char);
    
    // Проверка правил записи идентификатора для первого символа
    bool isValidFirstChar(char);
    
    // Установливает значение строки идентификатора
    void setStringId(char* str);
};

#endif /* StringId_hpp */
