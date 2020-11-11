#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H
#include "student.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <exception>
#include <string>
#include <QTableWidget>

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

class empty_list: public std::exception
{
public:
    empty_list(){};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "List is empty"; }
};

typedef struct rank
{
    double mark;
    GROUPS group;
} RANK;

class StudentsList
{
public:
    StudentsList();
    StudentsList(const StudentsList &new_list);
    StudentsList(std::vector<Student> &list);

    friend QFile & operator>>(QFile &file, StudentsList &list);
    friend QFile & operator<<(QFile &file, StudentsList &list);
    friend void operator<<(QTableWidget * table, StudentsList &list);
    std::vector<Student>& getList();
    void setList(std::vector<Student> &list);
    StudentsList getLoosers();
    void getGroupRanks(RANK(*) [4][6]);
    StudentsList getSameNames();
    StudentsList getSameNamesInGroup();
    StudentsList getTwoSpecific(short flag1, short flag2,
                                unsigned short mark1, unsigned short mark2);
    StudentsList getThreeSpecific(short flag1, short flag2, short flag3,
                                  unsigned short mark1, unsigned short mark2);
    StudentsList getFourSpecific(unsigned short mark1, unsigned short mark2);
    StudentsList ForeignPhisics5Math3();
    StudentsList Phisics4UkrForeign3();
    StudentsList Foreign4Math5Phisics3();

    void sort();
    void add(Student student);
    void clear();

private:
    void calculateGroupRanks();

    std::vector<Student> list;

    RANK group_ranks[4][6];
};

#endif // STUDENTSLIST_H
