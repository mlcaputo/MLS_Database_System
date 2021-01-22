#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main(int argc, char *argv[])
{
  int T1[500][4]  = { 0 };
  int T2[500][5]  = { 0 };
  int T3[500][6]  = { 0 };


  ifstream file1( argv[1] );
  for(int i = 0; i < 500; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      file1 >> T1[i][j];
    }
  }
  file1.close();


  ifstream file2( argv[2] );
  for(int i = 0; i < 500; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      file2 >> T2[i][j];
    }
  }
  file2.close();


  ifstream file3( argv[3] );
  for(int i = 0; i < 500; i++)
  {
    for(int j = 0; j < 6; j++)
    {
      file3 >> T3[i][j];
    }
  }
  file3.close();

  std::string line;
  while (std::getline(std::cin, line))
  {
    vector <string> query;
    stringstream check1(line);
    string intermediate;

    while(getline(check1, intermediate, ' '))
    {
        query.push_back(intermediate);
    }

    bool error = false;
                                                                                  //SECURITY LEVEL INFO
    int security = stoi(query[0]);

                                                                                  //SELCET INFO


    int location[3];
    location[0] = 1;
    for(int i = 0; i < query.size(); i++)
    {
      if(query[i] == "WHERE")
      {
        location[2] = i;
      }

      if(query[i] == "FROM")
      {
        location[1] = i;
      }
    }

    int column1 = 0;
    int column2 = -1;
    if(location[1] - 2 == 1)
    {
      if(query[2] == "A1") column1 = 0;
      else if(query[2] == "KC") column1 = 1;
      else if(query[2] == "A2") column1 = 2;
      else if(query[2] == "B1") column1 = 0;
      else if(query[2] == "B2") column1 = 2;
      else if(query[2] == "B3") column1 = 3;
      else if(query[2] == "C1") column1 = 0;
      else if(query[2] == "C2") column1 = 2;
      else if(query[2] == "C3") column1 = 3;
      else if(query[2] == "C4") column1 = 4;
      else if(query[2] == "*") column1 = -1;
      else
      {
        cout << "Error in query" << endl;
        error = true;
      }
    }

    if(location[1] - 2 == 2)
    {
      if(query[2] == "A1,") column1 = 0;
      else if(query[2] == "KC,") column1 = 1;
      else if(query[2] == "A2,") column1 = 2;
      else if(query[2] == "B1,") column1 = 0;
      else if(query[2] == "B2,") column1 = 2;
      else if(query[2] == "B3,") column1 = 3;
      else if(query[2] == "C1,") column1 = 0;
      else if(query[2] == "C2,") column1 = 2;
      else if(query[2] == "C3,") column1 = 3;
      else if(query[2] == "C4,") column1 = 4;

      if(query[3] == "A1") column2 = 0;
      else if(query[3] == "KC") column2 = 1;
      else if(query[3] == "A2") column2 = 2;
      else if(query[3] == "B1") column2 = 0;
      else if(query[3] == "B2") column2 = 2;
      else if(query[3] == "B3") column2 = 3;
      else if(query[3] == "C1") column2 = 0;
      else if(query[3] == "C2") column2 = 2;
      else if(query[3] == "C3") column2 = 3;
      else if(query[3] == "C4") column2 = 4;

      else
      {
        cout << "Error in query" << endl;
        error = true;
      }
    }
                                                                                    //FROM INFO


    int from;
    if(location[2] - location[1] - 1 == 1)
    {
      if(query[location[1] + 1] == "T1")
      {
        from = 1;
      }
      else if(query[location[1] + 1] == "T2")
      {
        from = 2;
      }
      else
      {
        from = 3;
      }
    }

    if(location[2] - location[1] - 1 == 2)
    {
      if(query[location[1] + 1] == "T1," && query[location[1] + 2]== "T2")
      {
        from = 12;
      }
      else if(query[location[1] + 1] == "T1," && query[location[1] + 2]== "T3")
      {
        from = 13;
      }
      else
      {
        from = 23;
      }
    }
    if(location[2] - location[1] - 1 == 3)
    {
      from = 123;
    }
                                                                                          //WHERE INFO

    int value;
    int value2 = -1;
    int position;
    int position2 = -1;
    if(query.size() - location[2] - 1 == 1)
    {
      string temp = query[query.size()-1];
      string p;
      string v;
      for(int i=0; i < temp.size(); i++)
      {
        if(i == 0 || i == 1)
        {
          p += temp[i];
          if(p == "A1") position = 0;
          else if(p == "KC") position = 1;
          else if(p == "A2") position = 2;
          else if(p == "B1") position = 0;
          else if(p == "B2") position = 2;
          else if(p == "B3") position = 3;
          else if(p == "C1") position = 0;
          else if(p == "C2") position = 2;
          else if(p == "C3") position = 3;
          else if(p == "C4") position = 4;
          else if(p == "TC" && from == 1) position = 3;
          else if(p == "TC" && from == 2) position = 4;
          else if(p == "TC" && from == 3) position = 5;

        }
        else if(i>= 3)
        {
          v += temp[i];
          value = stoi(v);
        }
      }
    }

    if(query.size() - location[2] - 1 == 3)
    {
      string temp = query[query.size()-1];
      string p;
      string v;
      for(int i=0; i < temp.size(); i++)
      {
        if(i == 0 || i == 1)
        {
          p += temp[i];
          if(p == "A1") position = 0;
          else if(p == "KC") position = 1;
          else if(p == "A2") position = 2;
          else if(p == "B1") position = 0;
          else if(p == "B2") position = 2;
          else if(p == "B3") position = 3;
          else if(p == "C1") position = 0;
          else if(p == "C2") position = 2;
          else if(p == "C3") position = 3;
          else if(p == "C4") position = 4;
          else if(p == "TC" && from == 1) position = 3;
          else if(p == "TC" && from == 2) position = 4;
          else if(p == "TC" && from == 3) position = 5;

        }
        else if(i>= 3)
        {
          v += temp[i];
          value = stoi(v);
        }
      }
      string temp2 = query[query.size()-3];
      string p2;
      string v2;
      for(int i=0; i < temp2.size(); i++)
      {
        if(i == 0 || i == 1)
        {
          p2 += temp2[i];
          if(p2 == "A1") position2 = 0;
          else if(p2 == "KC") position2 = 1;
          else if(p2 == "A2") position2 = 2;
          else if(p2 == "B1") position2 = 0;
          else if(p2 == "B2") position2 = 2;
          else if(p2 == "B3") position2 = 3;
          else if(p2 == "C1") position2 = 0;
          else if(p2 == "C2") position2 = 2;
          else if(p2 == "C3") position2 = 3;
          else if(p2 == "C4") position2 = 4;
          else if(p2 == "TC" && from == 1) position2 = 3;
          else if(p2 == "TC" && from == 2) position2 = 4;
          else if(p2 == "TC" && from == 3) position2 = 5;

        }
        else if(i>= 3)
        {
          v2 += temp2[i];
          value2 = stoi(v2);
        }
      }

    }


    if(error == false)
    {
      if(column2 == -1 && column1>=0 && position2 ==-1 )
      {
        cout << query[2] << "    " << "TC" << endl;
        cout << "_____________" << endl;
        if(from == 1)
        {
          for(int i = 0; i<500; i++)
          {
            if(T1[i][position] == value && security >= T3[i][5])
            {
              cout << T1[i][column1] << "   " << T1[i][3] << endl;
            }
          }
        }
        else if (from == 2)
        {
          for(int i = 0; i<500; i++)
          {
            if(T2[i][position] == value &&  security >= T3[i][5])
            {
              cout << T2[i][column1] << "   " << T2[i][4] << endl;
            }
          }
        }
        else if(from == 3)
        {
          for(int i = 0; i<500; i++)
          {
            if(T3[i][position] == value &&  security >= T3[i][5])
            {
              cout << T3[i][column1] << "   " << T3[i][5] << endl;
            }
          }
        }
      }

      if(column2 == -1 && column1>=0 && position2 != -1 )
      {
        cout << query[2] << "    " << "TC" << endl;
        cout << "_____________" << endl;
        if(from == 1)
        {
          for(int i = 0; i<500; i++)
          {
            if(T1[i][position] == value && security >= T3[i][5] && T1[i][position2] == value2)
            {
              cout << T1[i][column1] << "   " << T1[i][3] << endl;
            }
          }
        }
        else if (from == 2)
        {
          for(int i = 0; i<500; i++)
          {
            if(T2[i][position] == value &&  security >= T3[i][5] && T2[i][position2] == value2)
            {
              cout << T2[i][column1] << "   " << T2[i][4] << endl;
            }
          }
        }
        else if(from == 3)
        {
          for(int i = 0; i<500; i++)
          {
            if(T3[i][position] == value &&  security >= T3[i][5] && T3[i][position2] == value2)
            {
              cout << T3[i][column1] << "   " << T3[i][5] << endl;
            }
          }
        }
      }

      if(column1 == -1 && column2 ==-1)
      {
        if(from == 1)
        {
          cout << "A1" << "   " << "KC" << "    " << "A2" << "    " << "TC" << endl;
          cout << "________________________" <<endl;
          for(int i = 0; i<500; i++)
          {
            if(T1[i][position] == value && security >= T3[i][5])
            {
              cout << T1[i][0] << "   " << T1[i][1] << "    " << T1[i][2] << "    " << T1[i][3]<< endl;
            }
          }
        }
        else if (from == 2)
        {
          cout << "B1" << "   " << "KC" << "    " << "B2" << "    " << "B3" << "    " << "TC" << endl;
          cout << "_____________________________" <<endl;
          for(int i = 0; i<500; i++)
          {
            if(T2[i][position] == value &&  security >= T3[i][5])
            {
              cout << T2[i][0] << "   " << T2[i][1] << "    " << T2[i][2] << "    " << T2[i][3]<< "    " << T2[i][4] << endl;
            }
          }
        }
        else if(from == 3)
        {
          cout << "C1" << "   " << "KC" << "    " << "C2" << "    " << "C3" << "    " << "C4"<< "    " << "TC" << endl;
          cout << "________________________________" <<endl;
          for(int i = 0; i<500; i++)
          {
            if(T3[i][position] == value &&  security >= T3[i][5])
            {
                cout << T3[i][0] << "   " << T3[i][1] << "    " << T3[i][2] << "    " << T3[i][3]<< "    " << T3[i][4] << "   " << T3[i][5] << endl;
            }
          }
        }
      }



      if(column2 != -1)
      {
        cout << query[2] << "    " << query[3] << "   " << "TC" << endl;
        cout << "_________________" << endl;
        if(from == 1)
        {
          for(int i = 0; i<500; i++)
          {
            if(T1[i][position] == value && security >= T3[i][5])
            {
              cout << T1[i][column1] << "   " << T1[i][column2] << "    " << T1[i][3] << endl;
            }
          }
        }
        else if (from == 2)
        {
          for(int i = 0; i<500; i++)
          {
            if(T2[i][position] == value &&  security >= T3[i][5])
            {
              cout << T2[i][column1] << "   " << T2[i][column2] << "    " << T2[i][4] << endl;
            }
          }
        }
        else if(from == 3)
        {
          for(int i = 0; i<500; i++)
          {
            if(T3[i][position] == value &&  security >= T3[i][5])
            {
              cout << T3[i][column1] << "   " << T3[i][column2] << "    " << T3[i][5] << endl;
            }
          }
        }
      }
    }
    else
    {
      cout<< "An Error occured"<< endl;
    }




  }



  return 0;
}
