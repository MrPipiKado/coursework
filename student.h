#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QTextStream>

enum GROUPS {PZ21, PZ22, PZ23, PZ24, PZ25, PZ26};

class Student
{
public:
    Student(); //default constructor
    Student(QString surname,
            QString name,
            GROUPS group,
            unsigned short math,
            unsigned short physics,
            unsigned short foreign_language,
            unsigned short ukr_language); //constructor with parameters
    Student(const Student& copy); //copy constructor

    void setSurname(QString surname);
    QString getSurname();
    void setName(QString name);
    QString getName();
    void setGroup(GROUPS group);
    GROUPS getGroup();
    void setMath(unsigned short math);
    unsigned short getMath();
    void setPhysics(unsigned short physics);
    unsigned short getPhysics();
    void setForeignLanguage(unsigned short foreign_language);
    unsigned short getForeignLanguage();
    void setUkrLanguage(unsigned short ukr_language);
    unsigned short getUkrLanguage();

    double getAvgMark();  //calculate average mark
    //read data from opened QTextStream
    friend bool operator>>(QTextStream & input, Student & student);

private:
    QString surname; //student's surname
    QString name; //student's name
    GROUPS group; //student's group
    unsigned short math; //student's math mark
    unsigned short physics; //student's physics mark
    unsigned short foreign_language; //student's foreign language mark
    unsigned short ukr_language; //student's ukr language mark
};

#endif // STUDENT_H
