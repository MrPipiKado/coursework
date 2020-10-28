#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H
#include "student.h"
#include <vector>
#include <QFile>
#include <QTextStream>

class StudentsList
{
public:
    StudentsList();

    friend QFile & operator>>(QFile &file, StudentsList &list);
    friend QFile & operator<<(QFile &file, StudentsList &list);

private:
    std::vector<Student> list;

    unsigned short math_avg;
    unsigned short physics_avg;
    unsigned short foreign_language_avg;
    unsigned short ukr_language_avg;

};

#endif // STUDENTSLIST_H
