#pragma once
#include "Employee.h"
#include <iostream>

#include "List.h"

using namespace std;

class employee_mapper
{
public:

   static employee* create()
   {
      string name;
      int age;
      int experience;

      cout << "Enter Employee`s name: "; cin >> name;
      cout << "Enter Employee`s age: "; cin >> age;
      cout << "Enter Employee`s experience: "; cin >> experience;

      const auto object = new employee();
      object->set_name(name);
      object->set_age(age);
      object->set_experience(experience);

      return object;
   }

   List<employee*>* map(string path = "db.txt")
   {
      // from file...
   }

};
