#pragma once
#include<fstream>
#include<iostream>
#include <string>

#include "LinkedList.h"
#include "List.h"

using namespace std;

class io_controller
{
public:
   static void save(const string& data, const string& filename)
   {
      fstream fout(filename, ios::app);

      if (fout.is_open())
      {
         fout << data;
      }

      fout.close();
   }

   List<string>* get_all(const string& filename) const
   {
      const auto lines = new LinkedList<string>();

      fstream fin(filename, ios::app);

      if (fin.is_open())
      {
         string line;
         while (getline(fin, line))
         {
            lines->add(line);
         }
      }

      fin.close();

      return lines;
   }
};