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
{//this exception is thrown
 //in case input file does no follow
 //this application's data representation convetions
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
{//this exception is thrown
 //in case input file can not be opened for some reasons
 //(does not exist, is locked, has specific permissins)
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
{//this exception is thrown
 //in case sudents list is empty
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
    StudentsList();//default constructor
    StudentsList(const StudentsList &new_list);//copy constructor
    StudentsList(std::vector<Student> &list);//constructor with parameter

    //read from file
    friend QFile & operator>>(QFile &file, StudentsList &list);
    //write to file
    friend QFile & operator<<(QFile &file, StudentsList &list);
    //print list on table
    friend void operator<<(QTableWidget * table, StudentsList &list);
    std::vector<Student>& getList();
    void setList(std::vector<Student> &list);
    //returns students with lowest average marks from each group
    StudentsList getLoosers();
    //returns Group Ranks table
    void getGroupRanks(RANK(*) [4][6]);
    //returns students with same surnames in entire list
    StudentsList getSameNames();
    //returns students with same surnames in the same group
    StudentsList getSameNamesInGroup();
    //returns students with two specific marks from two specific subjects
    StudentsList getTwoSpecific(short flag1, short flag2,
                                unsigned short mark1, unsigned short mark2);
    //returns students with two specific marks from three specific subjects
    StudentsList getThreeSpecific(short flag1, short flag2, short flag3,
                                  unsigned short mark1, unsigned short mark2);
    //returns students with two specific marks from all subjects
    StudentsList getFourSpecific(unsigned short mark1, unsigned short mark2);
    //returns students with 5 for Foreign language and phisics and 3 for math
    StudentsList ForeignPhisics5Math3();
    //returns students with 3 for Foreign and ukr language and 4 for phisics
    StudentsList Phisics4UkrForeign3();
    //returns students with 3 for phisics and 5 for math and 4 for Foreign language
    StudentsList Foreign4Math5Phisics3();

    //sorts each row of Group Ranks table using quick sort algorithm
    void sort();
    void add(Student student);
    void clear();

private:
    //calculates groups' average mark
    void calculateGroupRanks();

    std::vector<Student> list;

    RANK group_ranks[4][6];
};

#endif // STUDENTSLIST_H
