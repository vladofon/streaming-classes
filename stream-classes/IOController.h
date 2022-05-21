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
      // ios::app - save without rewriting
      fstream fout(filename, ios::app);

      if (fout.is_open())
      {
         fout << data;
      }

      fout.close();
   }

   static void rewrite(const string& data, const string& filename)
   {
      // ios::out - save with rewriting
      fstream fout(filename, ios::out);

      if (fout.is_open())
      {
         fout << data;
      }

      fout.close();
   }

   static List<string>* retrieve(const string& filename)
   {
      const auto lines = new LinkedList<string>();

      fstream fin(filename);

      if (fin.is_open())
      {
         string line;
         while (fin >> line)
         {
            lines->add(line);
         }
      }

      fin.close();

      return lines;
   }

   static void remove(const int index, const string& filename)
   {
      const auto lines = retrieve(filename);

      lines->remove(index);

      rewrite(append(lines), filename);
   }

   static void update(const int index, const employee* object, const string& filename)
   {
      const auto lines = retrieve(filename);

      lines->edit(index, object->to_string());

      rewrite(append(lines), filename);
   }

private:

   // Append all lines into one string
   static string append(List<string>* lines)
   {
      string new_file;
      for (int i = 0; i < lines->getSize(); i++)
      {
         new_file += lines->get(i) + "\n";
      }

      return new_file;
   }
};