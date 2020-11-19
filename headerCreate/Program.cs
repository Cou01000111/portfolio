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
      List<string> headerTmp = new List<string>();
      string[] tmpFiles = Directory.GetFiles(@"../","tmp.html",SearchOption.AllDirectories);
      string tmpFile = tmpFiles[0];
      StreamReader tmp = new StreamReader(tmpFile, Encoding.GetEncoding("UTF-8"));
      bool inHeader = false;
      string line;
      while((line = tmp.ReadLine()) != null){
        if(line.Contains(@"<header>") || line.Contains(@"</header>") || inHeader){
          headerTmp.Add(line);
          if(line.Contains(@"</header>"))inHeader = false;
          else inHeader = true;
          continue;
        }
      }
      foreach(var tmpLine in headerTmp){
        Console.WriteLine(tmpLine);
      }
      tmp.Close();
      inHeader = false;
      foreach (var file in Directory.GetFiles(@"../","*.html",SearchOption.AllDirectories))
      {
        Console.WriteLine("loading " + file);
        StreamReader sr = new StreamReader(file, Encoding.GetEncoding("UTF-8"));

        line = null;
        List<string> texts = new List<string>();
        while((line = sr.ReadLine()) != null){
          if(line.Contains(@"<header>") || line.Contains(@"</header>") || inHeader){
            if(line.Contains(@"</header>")){
              inHeader = false;
              texts.AddRange(headerTmp);
              }
            else inHeader = true;
            continue;
          }
          texts.Add(line);
        }
        sr.Close();
        StreamWriter sw = new StreamWriter(
          file,
          false,
          System.Text.Encoding.GetEncoding("UTF-8")
          );
        foreach (var text in texts)
        {
          sw.Write(text);
          sw.Write("\n");
        }
        sw.Close();
      }
    }
  }
}
