#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    struct studentTYPE
    {
        int age[5];
        int score[5];
        string idnumber[5];
        string name[5];
        char grade[5];
        char gender[5];
    };

    
    
int main()
{
	 studentTYPE st;   
	int i;
    int mcounter=0;
    int fcounter=0;
    int tscore=0;
    int sumage=0;
    int avgscore=0;
    int avgage=0;
	
    for(i=0;i<5;i++)
     {
         cout<<"Please enter your name"<<i+1<<endl;
         cin>>st.name[i];
         
		 cout<<"please enter your idnumber"<<i+1<<endl;
         cin>>st.idnumber[i];
         
		 cout<<"enter gender for female"<<i+1<<"f"<<endl;
		 cout<<"enter gender for male"<<i+1<<"m"<<endl;
         cin>>st.gender[i];
         
         if(st.gender[i]=='f')
           fcounter++;
        else if(st.gender[i]=='m')
           mcounter++;
         
		 cout<<"please enter age"<<i+1<<endl;
         cin>>st.age[i];
         sumage=sumage+st.age[i];
         
         
		 cout<<"enter score"<<i+1<<endl;
        cin>>st.score[i];
        tscore=tscore+st.score[i];

    if(st.score[i]>=80)
        st.grade[i]='A';
    else if (70<st.score[i]<79)
         st.grade[i]='B';
    else if (69<st.score[i]<70)
         st.grade[i]='C';
     else if (50<st.score[i]<59)
         st.grade[i]='D';
     else if(40<st.score[i]<49)
         st.grade[i]='E';
     else
         st.grade[i]='F';

     }

    avgscore= tscore/5;

    avgage= sumage/5;
    
    //output into file
    
    ofstream std;
    
    std.open("new.txt",ios::app);
    
    std<<" *************************************************************** "<<endl;
    
    std<<"tnames"<<"\tidnumbr"<<"\tgender"<<"\tage"<<"\tscore"<<"\tgrade"<<endl;
    
    for(int i; i<5; i++)
    {
    	std<<i++<<st.name[i]<<"t\t"<<st.idnumber[i]<<"t\t"<<st.gender[i]<<"t\t"<<st.age[i];
    	 
		 std<<"\t"<<st.score[i]<<"\t"<<st.grade[i]<<endl;
    	
	}

    std<<endl;
    
    std<<"average age:"<<avgage<<endl;
    std<<"average score:"<<avgscore<<endl;
    std<<"total number of male:"<<mcounter<<endl;
    std<<"total number of females:"<<fcounter<<endl;
    
    std.close();

    return 0;
}
