#include <iostream>

#include "Employee.h"
#include "EmployeeMapper.h"
#include "IOController.h"

using namespace std;

int main()
{
   const employee_mapper mapper{};

   // Create data
   const auto to_save = new LinkedList<employee*>();
   to_save->add(new employee("first", 1, 1));
   to_save->add(new employee("second", 2, 2));
   to_save->add(new employee("third", 3, 3));

   // Save data
   while (to_save->getSize() != 0)
   {
      io_controller::save(to_save->get(0)->to_string(), "db.txt");
      to_save->remove(0);
   }

   // Do some operations...
   io_controller::update(0, new employee("edited", 8459, 487), "db.txt");
   io_controller::remove(2, "db.txt");

   // Map and print data from file
   const auto to_print = mapper.map_all();

   while (to_print->getSize() != 0)
   {
      cout << to_print->get(0)->to_formated_string() << endl;
      to_print->remove(0);
   }
}

