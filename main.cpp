//
//  main.cpp
//  Курсвая
//
//  Created by Данил Лямкин on 27.06.2020.
//  Copyright © 2020 Данил Лямкин. All rights reserved.
//

#include <iostream>
#include "String/String.hpp"
#include "StringId/StringId.hpp"

int main(int argc, const char * argv[])
{
    StringId id1("Name");
    StringId id2("last_name");
    String str('4');
    
    id2 = "LastName";
    
    StringId id3;
    id3 = id1 + id2;
    id3.toUpper();
    
    std::cout << str << std::endl;
    std::cout << id1 << std::endl;
    std::cout << id2 << std::endl;
    std::cout << id3 << std::endl;
    
    return 0;
}
