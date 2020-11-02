#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H
#include "student.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <exception>
#include <string>

class bad_input: public std::exception
{
public:
    bad_input(QString where, QString type, int line)
    {this->where = where; this->type=type; this->line = line;};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "Incorrect input"; }

    QString getType()
    {return this->type;}

    QString getWhere()
    {return this->where;}

    int getLine()
    {return this->line;}

private:
    QString type;
    QString where;
    int line;
};

class bad_file: public std::exception
{
public:
    bad_file(QString type)
    {this->type=type;};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "File issue"; }

    QString getType()
    {return this->type;}

private:
    QString type;
};


class StudentsList
{
public:
    StudentsList();

    friend QFile & operator>>(QFile &file, StudentsList &list);
    friend QFile & operator<<(QFile &file, StudentsList &list);

    void sort();

private:
    std::vector<Student> list;

    float math_avg;
    float physics_avg;
    float foreign_language_avg;
    float ukr_language_avg;
    float group_rank;

};

#endif // STUDENTSLIST_H
