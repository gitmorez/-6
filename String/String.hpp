//
//  String.hpp
//  Курсвая
//
//  Created by Данил Лямкин on 28.06.2020.
//  Copyright © 2020 Данил Лямкин. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>

class String
{
public:
    // Конструктор без параметров
    String();
    
    // Конструктор с параметром си строка
    String(char*);
    
    // Конструктор с параметром символ
    String(char);
    
    // Конструктор копирования
    String(String&);
    
    // Деструктор
    ~String();
    
    // Перегрузка оператора присваивания
    String& operator=(const String&);
    
    // Перегрузка оператора сложения
    String operator+(const String&);
    
    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream&, const String&);
    
    // Метод получения длинны строки
    int getLength();
    
protected:
    char* value;
    int length;
    static int countCopyConstructor;
    
private:
    // Установливает значение строки
    void setString(char*);
    
};

#endif /* String_hpp */
