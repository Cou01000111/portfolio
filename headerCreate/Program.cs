using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace headerCreate
{
  class Program
  {
    static void Main(string[] args)
    {
      bool inHeader = false;
      foreach (var file in Directory.GetFiles(@"../","*.html",SearchOption.AllDirectories))
      {
        StreamReader sr = new StreamReader(file, Encoding.GetEncoding("Shift_JIS"));
        string s = sr.ReadToEnd();
        sr.Close();

        if(s == @"<header>"){
          Console.WriteLine("In header.");
          if(inHeader)continue;
          else if(s == @"</header>"){
            Console.WriteLine("Out header");
          }
        }

        StreamWriter sw = new StreamWriter(
          file,
          false,
          System.Text.Encoding.GetEncoding("Shift_JIS")
          );

        sw.Write(s);
        sw.Close();
      }
    }
  }
}
