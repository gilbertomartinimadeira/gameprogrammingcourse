#include <iostream>
#include <vector>
#include <fstream>

//#include "myfuncs.h"

class Student
{
    private:
        std::string m_first = ""; //novidade do c++ moderno, inicialização de campos!
        std::string m_last = "";
        int         m_sid = 0;
        int         m_grade = 0;

    public:
        
    Student(){}

    //not the preferred way, because it will "reinitialize" variables
    // Student(std::string first, std::string last, int id, int grade)
    // {
    //     m_first = first;
    //     m_last = last;
    //     m_sid = id;
    //     m_grade = grade;

    //     std::cout << "Constructor \n";

    // }

    //The optimization : use initialization list as follows.
    Student(const std::string& first,
            const std::string& last, 
            int id, 
            int grade)
     :m_first (first), 
      m_last  (last), 
      m_sid   (id), 
      m_grade (grade)
      {
          //std::cout << "Constructor\n";   
      }


    // ~Student()
    // {
    //     std::cout << "Destructor\n";
    // }

    std::string getFirst()
    {
        return m_first;
    }

    std::string getLast()
    {
        return m_last;
    }

    int getSID(){
        return m_sid;
    }
    int getGrade()
    {
        return m_grade;
    }

    void print()
    {
        std::cout << m_first << " " << " " << m_last << " " << m_sid << "  " << m_grade << "\n";
    }
};

class Course
{
    std::vector<Student> m_students;
    std::string          m_name;

public:

    Course(const std::string& name)
    : m_name(name){}
    
    void addStudent(const Student& s)
    {
        m_students.push_back(s);
    }

    const std::vector<Student> & getStudents()
    {
        return m_students;
    }

    void print()
    {
        for(auto s : m_students)
        {
            s.print();
        }
    }

    void addStudentsFromFile(const std::string & fileName)
    {
        std::ifstream inputFileStream(fileName);

        std::string first, last;
        int id, grade;

        while(inputFileStream >> first)
        {
            inputFileStream >> last >> id >> grade;

            addStudent(Student(first, last,id,grade));
        }
    }
};


int main(int argumentCount, char * argumentValues[])
{
    Course c("comp4300");

    c.addStudentsFromFile("students.txt");
    c.print();

    return 0;


    // Student s1("Gilberto", "Martini", 1983, 79);
    // Student s2("João", "Martini", 2020, 98);

    // c.addStudent(s1);
    // c.addStudent(s2);


    // students.push_back(s1);
    // students.push_back(s2);

    // for(size_t i = 0; i < students.size(); i++)
    // {
    //     students[i].print();
    // }

    // for(Student& s : c.getStudents())
    // {
    //     s.print();
    // }

    



}

