using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace headCopy
{
  class Program
  {
    static void Main(string[] args)
    {
      List<string> headTmp = new List<string>();
      string[] tmpFiles = Directory.GetFiles(@"../","tmp.html",SearchOption.AllDirectories);
      string tmpFile = tmpFiles[0];
      StreamReader tmp = new StreamReader(tmpFile, Encoding.GetEncoding("UTF-8"));
      bool inHead = false;
      string line;
      while((line = tmp.ReadLine()) != null){
        if(line.Contains(@"<head>") || line.Contains(@"</head>") || inHead){
          headTmp.Add(line);
          if(line.Contains(@"</head>"))inHead = false;
          else inHead = true;
          continue;
        }
      }
      foreach(var tmpLine in headTmp){
        Console.WriteLine(tmpLine);
      }
      tmp.Close();
      inHead = false;
      foreach (var file in Directory.GetFiles(@"../","*.html",SearchOption.AllDirectories))
      {
        Console.WriteLine("loading " + file);
        StreamReader sr = new StreamReader(file, Encoding.GetEncoding("UTF-8"));

        line = null;
        List<string> texts = new List<string>();
        while((line = sr.ReadLine()) != null){
          if(line.Contains(@"<head>") || line.Contains(@"</head>") || inHead){
            if(line.Contains(@"</head>")){
              inHead = false;
              texts.AddRange(headTmp);
              }
            else inHead = true;
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
