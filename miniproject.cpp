#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
class Employee
{
  private:
          int eid,sal;
          char name[20],cname[20];
  public:
          void get();
          void getupdate();
          void put();
          int checklogin(char user[20],char pass[20],char fname[20]);
          void add();
          void display();
          void search(int id);
          void Delete(int id);
          void update(int id);
};
int Employee::checklogin(char user[20],char pass[20],char fname[20])
{
  char u[20],p[20];
  fstream obj;
  obj.open(fname,ios::in);
  obj>>u;
  obj>>p;
  obj.close();
  if(strcmp(u,user)==0 && strcmp(p,pass)==0)
  {
    return 1;
  }
  return 0;
}
void Employee::get()
{
  cout<<"\n\t Enter the employee id: ";
  cin>>eid;
  cout<<"\n\t Enter the employee name: ";
  cin>>name;
  cout<<"\n\t Enter the employee company name: ";
  cin>>cname;
  cout<<"\n\t Enter the employee salary: ";
  cin>>sal;
}
void Employee::getupdate()
{
  cout<<"\n\t Enter the employee name: ";
  cin>>name;
  cout<<"\n\t Enter the employee company name: ";
  cin>>cname;
  cout<<"\n\t Enter the employee salary: ";
  cin>>sal;
}
void Employee::put()
{
  cout<<"\n\t"<<setiosflags(ios::left)<<setw(5)<<eid<<setw(10)<<name<<setw(10)<<cname<<setw(10)<<sal; 
}
void Employee::add()
{
  Employee objE;
  fstream objF;
  objF.open("emp.txt",ios::app|ios::binary);
  if(objF.good())
  {
   objE.get();
   objF.write((char*)&objE,sizeof(objE));
   if(objF.good())
   {
      cout<<"\n\t Record added successfully.";
   }
   objF.close();
  }
  else
  {
     cout<<"\n\t emp.txt file open error in add module.";
  }
}
void Employee::display()
{
  Employee objE;
  fstream objF;
  objF.open("emp.txt",ios::in|ios::binary);
  if(objF.good())
  {
   while(objF.read((char*)&objE,sizeof(objE)))
   {
    objE.put();
   }
   objF.close();
  }
  else
  {
     cout<<"\n\t emp.txt file open error in display module.";
  }
}
void Employee::search(int id)
{
  int x=0;
  Employee objE;
  fstream objF;
  objF.open("emp.txt",ios::in|ios::binary);
  if(objF.good())
  {
   while(objF.read((char*)&objE,sizeof(objE)))
   {
    if(objE.eid==id)
    {
      objE.put();
      x++;
    }
    objE.put();
   }
   objF.close();
   if(x==0)
   {
      cout<<"\n\t Record not found";  
   }
   else
   {
     cout<<"\n\t Record found"<<x<<" Times";  
   }
  }
  else
  {
    cout<<"\n\t emp.txt file open error in display module.";
  }
}
void Employee::update(int id)
{
  int x=0;
  Employee objE;
  fstream objF,objt;
  objF.open("emp.txt",ios::in|ios::binary);
  if(objF.good())
  {
   objt.open("temp.txt",ios::out|ios::binary);
   while(objF.read((char*)&objE,sizeof(objE)))
   {
    if(objE.eid==id)
    {
      objE.getupdate();
      objt.write((char*)&objE,sizeof(objE));
      x++;
    }
    else
    {
      objt.write((char*)&objE,sizeof(objE));
    }
    objE.put();
   }
   objF.close();
   objt.close();
   remove("emp.txt");
   rename("temp.txt","emp.txt");
   if(x==0)
   {
      cout<<"\n\t Record not found";  
   }
   else
   {
     cout<<"\n\t Total Records updated "<<x;  
   }
  }
  else
  {
     cout<<"\n\t emp.txt file open error in update module.";
  }
}
void Employee::Delete(int id)
{
  int x=0;
  Employee objE;
  fstream objF,objt;
  objF.open("emp.txt",ios::in|ios::binary);
  if(objF.good())
  {
   objt.open("temp.txt",ios::out|ios::binary);
   while(objF.read((char*)&objE,sizeof(objE)))
   {
    if(objE.eid==id)
    {
      x++;
    }
    else
    {
      objt.write((char*)&objE,sizeof(objE));
    }
    objE.put();
   }
   objF.close();
   objt.close();
   remove("emp.txt");
   rename("temp.txt","emp.txt");
   if(x==0)
   {
      cout<<"\n\t Record not found";  
   }
   else
   {
     cout<<"\n\t Total Records deleted "<<x;  
   }
  }
  else
  {
     cout<<"\n\t emp.txt file open error in display module.";
  }
}
int main()
{
  int choice,id,x;
  char ch,user[20],pass[20];
  Employee obj;
  do
  {
    system("cls");
    cout<<"\n\t -------------------------------------------------";
    cout<<"\n\t\t Welcome to Employee Management System ";
    cout<<"\n\t -------------------------------------------------";
    cout<<"\n\t\t Log in Section";
    cout<<"\n\t -------------------------------------------------";
    cout<<"\n\t 1.Admin log in";
    cout<<"\n\t 2.Employee log in";
    cout<<"\n\t 3.Exit";
    cout<<"\n\t -------------------------------------------------";
    cout<<"\n\t Enter your choice(1-3)";
    cin>>choice;
    cout<<"\n\t -------------------------------------------------";
    switch(choice)
    {
      case 1:
              cout<<"\n\t Enter the user name: ";
              cin>>user;
              cout<<"\n\t Enter the Password: ";
              cin>>pass;
              x=obj.checklogin(user,pass,"admin.txt");
              if(x==1)
              {
                do
                  {
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t\t Welcome to Admin Dashboard/section ";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t\t Admin Section";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t 1.Add Record";
                    cout<<"\n\t 2.Display Record";
                    cout<<"\n\t 3.search Record";
                    cout<<"\n\t 4.update Record";
                    cout<<"\n\t 5.delete Record";
                    cout<<"\n\t 6.log out";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t Enter your choice(1-6)";
                    cin>>choice;
                    cout<<"\n\t -------------------------------------------------";
                    switch(choice)
                    {
                      case 1:
                              obj.add();
                              break;
                      case 2:
                               cout<<"\n\t -------------------------------------------------";                    
                               cout<<"\n\t"<<setiosflags(ios::left)<<setw(5)<<"eid"<<setw(10)<<"name"<<setw(10)<<"cname"<<setw(10)<<"sal";
                                cout<<"\n\t -------------------------------------------------";
                                obj.display();
                                cout<<"\n\t -------------------------------------------------";
                              break;
                      case 3:
                              cout<<"\n\t Enter the employee id to search Record: ";
                              cin>>id;
                              obj.search(id);
                              break;
                      case 4:
                              cout<<"\n\t Enter the employee id to Update Record: ";
                              cin>>id;
                              obj.update(id);
                              break;
                      case 5:
                              cout<<"\n\t Enter the employee id to Delete the Record: ";
                              cin>>id;
                              obj.Delete(id);
                              break;
                      case 6:
                              cout<<"\n\t Logged out successfully.";
                              exit(0);
                              break;
                      default:
                              cout<<"\n\t Invalid Choice!";
                    }
                    cout<<"\n\t Do you want to Continue in admin section(y/n): ";
                    cin>>ch;
                  
                  }while(ch=='Y'||ch=='y');
              }
              else
              {
                cout<<"\n\t please enter correct user name and password";
              }
              break;
      case 2:
              cout<<"\n\t Enter the user name: ";
              cin>>user;
              cout<<"\n\t Enter the Password: ";
              cin>>pass;
              x=obj.checklogin(user,pass,"user.txt");
              if(x==1)
              {
                do
                  {
                    system("cls");
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t\t Welcome employee login Dashboard/section ";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t\t Employee Section";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t 1.Display Record";
                    cout<<"\n\t 2.search Record";
                    cout<<"\n\t 3.log out";
                    cout<<"\n\t -------------------------------------------------";
                    cout<<"\n\t Enter your choice(1-3)";
                    cin>>choice;
                    cout<<"\n\t -------------------------------------------------";
                    switch(choice)
                    {
                      case 1:
                              cout<<"\n\t -------------------------------------------------";                    
                              cout<<"\n\t"<<setiosflags(ios::left)<<setw(5)<<"eid"<<setw(10)<<"name"<<setw(10)<<"cname"<<setw(10)<<"sal";
                              cout<<"\n\t -------------------------------------------------";
                              obj.display();
                              cout<<"\n\t -------------------------------------------------";
                              break;
                      case 2:
                              cout<<"\n\t Enter the employee id to search Record: ";
                              cin>>id;
                              obj.search(id);
                              break;
                      case 3:
                              exit(0);
                              break;
                      default:
                              cout<<"\n\t Invalid Choice!";
                    }
                    cout<<"\n\t Do you want to Continue in Employee login section(y/n): ";
                    cin>>ch;
                  
                  }while(ch=='Y'||ch=='y');
              }
              else
              {
                cout<<"\n\t please enter correct user name and password";
              }
              break;
      case 3:
              exit(0);
              break;
      default:
              cout<<"\n\t Invalid Choice!";
    }
    cout<<"\n\t Do you want to Continue in Employee Management system(y/n) : ";
    cin>>ch;
  
  }while(ch=='Y'||ch=='y');
  return 0;
}
