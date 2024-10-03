#include <iostream>
using namespace std;
class student
{
   int rollno ;
   float SGPA;
   string name;
   public:
   void getdata(){
       cout << "Enter the name of student: ";
       cin >> name;
       cout << "enter roll number: ";
       cin >> rollno;
       cout << "Enter SGPA: ";
       cin >> SGPA;
   }
   void putdata(){
       cout << "name: " << name <<endl;
       cout << "roll number: "<< rollno << endl;
       cout << "SGPA: " << SGPA <<endl;


   }
   void insertion_sort(student s[], int n);
};


void student :: insertion_sort(student s[], int n ){
   for(int i = 1; i < n; i++){
       int j = i - 1;
       student key = s[i];
       while(j >=0 && s[j].SGPA < key.SGPA){
               s[j+1] = s[j];
               j--;
       }
   s[j+1] = key;


}
}


int main()
{
   int n;
   cout << "number of students: ";
   cin >> n;
   student s[100], x;
   for (int i = 0; i < n;i++){
       s[i].getdata();
   }    
   x.insertion_sort(s, n);
   for (int i = 0; i < n;i++){
       s[i].putdata();
       }
       return 0;




return 0;
}

