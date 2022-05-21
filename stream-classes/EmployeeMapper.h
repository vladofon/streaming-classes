#pragma once
#include "Employee.h"
#include <iostream>

#include "IOController.h"
#include "List.h"

using namespace std;

class employee_mapper
{
public:

   employee_mapper()
   {
      this->connection_ = io_controller();
   }

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

   List<employee*>* map_all(const string& path = "db.txt") const
   {
      const auto data = io_controller::retrieve(path);
      const auto result = new LinkedList<employee*>();

      while (data->getSize() != 0)
      {
         result->add(map(split(data->get(0), ":")));
         data->remove(0);
      }

      return result;
   }



private:

   io_controller connection_;

   static string find_one(const string& str, const string& delimiter)
   {
      return str.substr(0, str.find(delimiter));
   }

   static List<string>* split(string str, const string& delimiter)
   {
      const auto elements = new LinkedList<string>();

      while (str.find(delimiter) != -1)
      {
         string element = find_one(str, delimiter);
         elements->add(element);

         str = str.substr(element.length() + 1);
      }

      return elements;
   }

   employee* map(List<string>* data) const
   {
      const auto object = new employee();

      object->set_name(data->get(0));
      object->set_age(stoi(data->get(1)));
      object->set_experience(stoi(data->get(2)));

      return object;
   }

};
