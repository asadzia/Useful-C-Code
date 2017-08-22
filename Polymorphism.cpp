#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person 
{
    protected:
        string name;
        int age;
        
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person 
{
    protected: 
        int publications;
        int cur_id;
        static int cur_id_helper;
        
    public: 
    
        Professor()
        {
            ++cur_id_helper;
            cur_id = cur_id_helper;
        }
        
        void getdata ()
        {
            cin >> name;
            cin >> age;
            cin >> publications;
        }
        
        void putdata ()
        {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};

class Student : public Person 
{
    protected:
        int arr[6];
        static int cur_id_helper;
        int cur_id;
        int sum;
        
    public: 
        
        Student()
        {
            sum = 0;
            ++cur_id_helper;
            cur_id = cur_id_helper;
        }
        
        void getdata()
        {
            cin >> name;
            cin >> age;
            
            for (int i = 0; i < 6; ++i)
            {   
                cin >> arr[i];
                sum = sum + arr[i];
            }
        }
        
        void putdata()
        {   
            cout << name << " " << age << " " << sum << " " << cur_id << endl; 
        }
};

int Student::cur_id_helper = 0;
int Professor::cur_id_helper = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

/*

Input Format

The first line of input contains the number of objects that are being created. If the first line of input for each object is , it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.

If the first line of input for each object is , it means that the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.

Constraints

, where  is the length of the name. 
 
 
, where marks is the marks of the student in each subject.

Output Format

There are two types of output depending on the object.

If the object is of type Professor, print the space separated name, age, publications and id on a new line.

If the object is of the Student class, print the space separated name, age, the sum of the marks in  subjects and id on a new line.

Sample Input

4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
Sample Output

Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2

*/
