using namespace std;
#include <iostream>
#include <fstream>
#include <streambuf>

void ReadFile()
{
  ifstream DNAFile1;
  ifstream DNAFile2;
  string firstLine;
  char listaATCG[4] = {'A', 'T', 'C', 'G'};

  float size1 = 0;
  float size2 = 0;
  float counterA = 0;
  float counterT = 0;
  float counterC = 0;
  float counterG = 0;
  int repCounter = 1;
  int biggestRep = 0;
  
  DNAFile1.open("titin.txt");
  DNAFile2.open("KRAS.txt");
  
  string DNAsequence1 ((istreambuf_iterator<char>(DNAFile1)), istreambuf_iterator<char>());
  string DNAsequence2 ((istreambuf_iterator<char>(DNAFile2)), istreambuf_iterator<char>());

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < DNAsequence1.size(); j++)
    {
      if(DNAsequence1[j] == listaATCG[i])
      {
        size1++;
        if(DNAsequence1[j] == 'A')
        {
          counterA++;
        }
        else if(DNAsequence1[j] == 'T')
        {
          counterT++;
        }
        else if(DNAsequence1[j] == 'C')
        {
          counterC++;
        }
        else
        {
          counterG++;
        }
      }
    }
  }

  float porcentajeA = (counterA * 100) / size1;
  float porcentajeT = (counterT * 100) / size1;
  float porcentajeC = (counterC * 100) / size1;
  float porcentajeG = (counterG * 100) / size1;

  cout << "Titin:" << endl;
  cout << "Numero total de nucleotidos: " << size1 << endl;
  cout << "Porcentaje de Adenina: " << porcentajeA << "%" << endl;
  cout << "Porcentaje de Timina: " << porcentajeT << "%" << endl;
  cout << "Porcentaje de Citosina: " << porcentajeC << "%" << endl;
  cout << "Porcentaje de Guanina: " << porcentajeG << "%" << endl;
  
  for(int j = 0; j < DNAsequence1.size(); j++)
  {
    if(DNAsequence1[j] == 'A')
    {
      if(DNAsequence1[j] == DNAsequence1[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Adenina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence1.size(); j++)
  {
    if(DNAsequence1[j] == 'T')
    {
      if(DNAsequence1[j] == DNAsequence1[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Timina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence1.size(); j++)
  {
    if(DNAsequence1[j] == 'C')
    {
      if(DNAsequence1[j] == DNAsequence1[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Citosina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence1.size(); j++)
  {
    if(DNAsequence1[j] == 'G')
    {
      if(DNAsequence1[j] == DNAsequence1[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Guanina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;
  cout << endl;

  counterA = 0;
  counterT = 0;
  counterC = 0;
  counterG = 0;

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < DNAsequence2.size(); j++)
    {
      if(DNAsequence2[j] == listaATCG[i])
      {
        size2++;
        if(DNAsequence2[j] == 'A')
        {
          counterA++;
        }
        else if(DNAsequence2[j] == 'T')
        {
          counterT++;
        }
        else if(DNAsequence2[j] == 'C')
        {
          counterC++;
        }
        else
        {
          counterG++;
        }
      }
    }
  }

  porcentajeA = (counterA * 100) / size2;
  porcentajeT = (counterT * 100) / size2;
  porcentajeC = (counterC * 100) / size2;
  porcentajeG = (counterG * 100) / size2;

  cout << "KRAS" << endl;
  cout << "Numero total de nucleotidos: " << size2 << endl;
  cout << "Porcentaje de Adenina: " << porcentajeA << "%" << endl;
  cout << "Porcentaje de Timina: " << porcentajeT << "%" << endl;
  cout << "Porcentaje de Citosina: " << porcentajeC << "%" << endl;
  cout << "Porcentaje de Guanina: " << porcentajeG << "%" << endl;

  for(int j = 0; j < DNAsequence2.size(); j++)
  {
    if(DNAsequence2[j] == 'A')
    {
      if(DNAsequence2[j] == DNAsequence2[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Adenina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence2.size(); j++)
  {
    if(DNAsequence2[j] == 'T')
    {
      if(DNAsequence2[j] == DNAsequence2[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Timina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence2.size(); j++)
  {
    if(DNAsequence2[j] == 'C')
    {
      if(DNAsequence2[j] == DNAsequence2[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Citosina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "2" << endl;
  biggestRep = 0;

  for(int j = 0; j < DNAsequence2.size(); j++)
  {
    if(DNAsequence2[j] == 'G')
    {
      if(DNAsequence2[j] == DNAsequence2[j+1])
      {
        repCounter++;
      }
      else
      {
        if(repCounter > biggestRep)
        {
          biggestRep = repCounter;
        }
        repCounter = 1;
      }
    }
  }

  cout << "Mayor repeticion de Guanina: " << biggestRep << endl;
  cout << "Numero de repeticiones: " << "1" << endl;

  DNAFile1.close();
  DNAFile2.close();
}

int main()
{
  ReadFile();
  return 0;
}