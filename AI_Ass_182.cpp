
#include<iostream>
#include<string.h>
#include <cctype>
#include <cstring>
using namespace std;

int num_pred;
int num_arg[10];
int i,j;
string predicate[10];
string argument[10][10];
 

void substitue_and_equify();
void display_base();
void verify();


   int main()
   {
   int a=0;
   do{
   

 
            cout<<"Enter number of predicates : "<<endl;
            cin>>num_pred;
			

            for(i=0;i<num_pred;i++)
            {
               
            cout<<"Enter Predicate "<<i+1<<":"<<endl;
            cin>>predicate[i];
            cout<<"Enter number of arguments for the predicate "<<predicate[i]<<":"<<endl;
            cin>>num_arg[i];
                        for(j=0;j<num_arg[i];j++)
                        {
                         
                         cout<<"Enter argument "<<j+1<<":"<<endl;
                         cin>>argument[i][j];
                        }
            }

            display_base();
            verify();
            
            
            cout<<"Do you want to continue(0(Yes)/1(No)):"<<endl;
            cin>>a;
       }while(a == 0);
       return 0;
   }



   void display_base()
   {
            for(i=0;i<num_pred;i++)
            {
             cout<<"\n"<<predicate[i]<<"(";
                        for(j=0;j<num_arg[i];j++)
                        {
                        cout<<argument[i][j];
                        if(j!=num_arg[i]-1)
                                    cout<<",";
                        }
             cout<<")";
            }
            cout<<endl;
   }

   void verify()
   {
   int c=0;


 
            for(i=0;i<num_pred-1;i++)
            {
                        if(predicate[i]!=predicate[i+1])
                        {
                        cout<<"Cannot be unified. "<<endl;
                        c=1;
                        break;
                        }
            }

     if(c!=1)
     {
            for(i=0;i<num_arg[i]-1;i++)
            {
                        if(num_arg[i]!=num_arg[i+1])
                        {
                        cout<<"Argrguments are not unifiable."<<endl;
                        c=1;
                        break;
                        }
            }
     }
            if(c==0){
                        substitue_and_equify();}

   }

   void substitue_and_equify()
   {
            int flag=0;
            for(i=0;i<num_pred-1;i++)
            {
                 for(j=0;j<num_arg[i];j++)
                 {
                        if(argument[i][j]!=argument[i+1][j])
                        {
                          if(flag==0)
                          { 
                                 cout<<"Terms that can be substituted: "<<endl;
                          }
                        cout<<argument[i+1][j]<<" / "<<argument[i][j]<<endl;
                         flag=1;
                        }
                }
            }

              cout<<"Terms that are unified without substitution"<<endl;

            for(i=0;i<num_pred-1;i++)
            {
                 for(j=0;j<num_arg[i];j++)
                 {

                         string str1 = argument[i][j];
                         string str2 = argument[i+1][j];
                         if (isupper(str1[0]) || isupper(str2[0])){
                                cout<<argument[i][j]<<" = "<<argument[i+1][j]<<endl;
                         }

            }
       }
   }

