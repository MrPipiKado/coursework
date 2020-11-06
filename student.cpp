#include "student.h"

Student::Student()
{
    this->surname = "";
    this->name = "";
    this->group = GROUPS::PZ21;
    this->math = 0;
    this->physics = 0;
    this->foreign_language = 0;
    this->ukr_language = 0;
}

Student::Student(QString surname,
        QString name,
        GROUPS group,
        unsigned short math,
        unsigned short physics,
        unsigned short foreign_language,
        unsigned short ukr_language)
{
    this->surname = surname;
    this->name = name;
    this->group = group;
    this->math = math;
    this->physics = physics;
    this->foreign_language = foreign_language;
    this->ukr_language = ukr_language;

}

Student::Student(const Student& copy)
{
    this->surname = copy.surname;
    this->name = copy.name;
    this->group = copy.group;
    this->math = copy.math;
    this->physics = copy.physics;
    this->foreign_language = copy.foreign_language;
    this->ukr_language = copy.ukr_language;
}

void Student::setSurname(QString surname)
{
    this->surname = surname;
}

QString Student::getSurname()
{
    return this->surname;
}

void Student::setName(QString name)
{
    this->name = name;
}

QString Student::getName()
{
    return this->name;
}

void Student::setGroup(GROUPS group)
{
    this->group = group;
}

GROUPS Student::getGroup()
{
    return this->group;
}

void Student::setMath(unsigned short math)
{
    this->math = math;
}

unsigned short Student::getMath()
{
    return this->math;
}

void Student::setPhysics(unsigned short physics)
{
    this->physics = physics;
}

unsigned short Student::getPhysics()
{
    return this->physics;
}

void Student::setForeignLanguage(unsigned short foreign_language)
{
    this->foreign_language = foreign_language;
}

unsigned short Student::getForeignLanguage()
{
    return this->foreign_language;
}

void Student::setUkrLanguage(unsigned short ukr_language)
{
    this->ukr_language = ukr_language;
}

unsigned short Student::getUkrLanguage()
{
    return this->ukr_language;
}


double Student::getAvgMark()
{
    return (this->math
            + this->physics
            + this->foreign_language
            + this->ukr_language)
            / 4.0;
}

bool operator>>(QTextStream & input, Student &student)
{
    QString tmp;
    input>>tmp;
    if(tmp.isEmpty())return false;
    student.surname = tmp;
    input>>student.name;
    input>>tmp;
    if(tmp == "PZ21")
        student.group = GROUPS::PZ21;
    if(tmp == "PZ22")
        student.group = GROUPS::PZ22;
    if(tmp == "PZ23")
        student.group = GROUPS::PZ23;
    if(tmp == "PZ24")
        student.group = GROUPS::PZ24;
    if(tmp == "PZ25")
        student.group = GROUPS::PZ25;
    if(tmp == "PZ26")
        student.group = GROUPS::PZ26;
    input>>student.physics;
    input>>student.math;
    input>>student.foreign_language;
    input>>student.ukr_language;

    return true;
}
