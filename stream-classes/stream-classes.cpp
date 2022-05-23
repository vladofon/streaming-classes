#include <iostream>

#include "Employee.h"
#include "EmployeeMapper.h"
#include "IOController.h"

using namespace std;

int main()
{
   const employee_mapper mapper{};

   // Create data
   const auto to_save = new LinkedList<string>();
   to_save->add((new employee("first", 1, 1))->to_string());
   to_save->add((new employee("second", 2, 2))->to_string());
   to_save->add((new employee("third", 3, 3))->to_string());

   // Save data
   io_controller::save(to_save, "db.txt");

   // Do some operations...
   io_controller::update(0, new employee("edited", 8459, 487), "db.txt");
   io_controller::remove(2, "db.txt");

   // Map and print data from file
   const auto to_print = mapper.map_all();

   cout << endl;
   while (to_print->getSize() != 0)
   {
      cout << to_print->get(0)->to_formated_string() << endl;
      to_print->remove(0);
   }
}

