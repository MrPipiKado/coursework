#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QTextStream>

enum GROUPS {PZ21, PZ22, PZ23, PZ24, PZ25, PZ26};

class Student
{
public:
    Student();
    Student(QString surname,
            QString name,
            GROUPS group,
            unsigned short math,
            unsigned short physics,
            unsigned short foreign_language,
            unsigned short ukr_language);
    Student(const Student& copy);

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

    double getAvgMark();

    friend bool operator>>(QTextStream & input, Student & student);

private:
    QString surname;
    QString name;
    GROUPS group;
    unsigned short math;
    unsigned short physics;
    unsigned short foreign_language;
    unsigned short ukr_language;
};

#endif // STUDENT_H
