#include "studentslist.h"

StudentsList::StudentsList()
{

}

StudentsList::StudentsList(const StudentsList &new_list)
{
    this->list = new_list.list;
}

StudentsList::StudentsList(std::vector<Student> &list)
{
    this->list = list;
}

QFile & operator>>(QFile &file, StudentsList &list)
{
    int line = 1;
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream input(&file);
        while(!input.atEnd())
        {
            QString str;
            int num;

            //Read surname
            input>>str;
            if(str.isEmpty())break;
            for(auto c:str)
            {
                if(!c.isLetter())
                {
                    //Exeption Incorrect surname in line
                    file.close();
                    throw bad_input("Surname", str, line);
                }
            }
            if(!str[0].isUpper())
            {
                //Exeption Incorrect surname in line
                file.close();
                throw bad_input("Surname", str, line);
            }

            //Read name
            input>>str;
            for(auto c:str)
            {
                if(!c.isLetter())
                {
                    //Exeption Incorrect name in line
                    file.close();
                    throw bad_input("Name", str, line);
                }
            }
            if(!str[0].isUpper())
            {
                //Exeption Incorrect name in line
                file.close();
                throw bad_input("Name", str, line);
            }

            //Read Group
            input>>str;
            if(!(str=="PZ21" || str=="PZ22" || str=="PZ23"
                    || str=="PZ24" || str=="PZ25" || str=="PZ26"))
            {
                //Exeption Incorrect group in line
                file.close();
                throw bad_input("Group", str, line);
            }

            //Read physics mark
            input>>num;
            if(num>5||num<0)
            {
                //Exeption physics mark
                file.close();
                throw bad_input("Physics", QString::number(num), line);
            }

            //Read math mark
            input>>num;
            if(num>5||num<0)
            {
                //Exeption math mark
                file.close();
                throw bad_input("Math", QString::number(num), line);
            }

            //Read foreign language mark
            input>>num;
            if(num>5||num<0)
            {
                //Exeption language mark
                file.close();
                throw bad_input("Language", QString::number(num), line);
            }

            //Read ukr language mark
            input>>num;
            if(num>5||num<0)
            {
                //Exeption ukr language mark
                file.close();
                throw bad_input("Ukr Language", QString::number(num), line);
            }

            ++line;
        }

        file.close();

        file.open(QFile::ReadOnly | QFile::Text);
        while(!input.atEnd())
        {
            Student tmp;
            if(input>>tmp)
              list.list.push_back(tmp);
        }

        file.close();

    }
    else
    {
        throw bad_file("Can not open");
    }
    return file;
}

QFile & operator<<(QFile &file, StudentsList &list)
{
    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        if (file.pos() == 0)
        {
            QTextStream output(&file);
            QString tmp = "";
            for(auto index = list.list.begin(); index<list.list.end(); ++index)
            {
                tmp = tmp + index->getSurname() + " ";
                tmp = tmp + index->getName() + " ";
                if(index->getGroup() == GROUPS::PZ21)
                    tmp = tmp + "PZ21" " ";
                if(index->getGroup() == GROUPS::PZ22)
                    tmp = tmp + "PZ22" " ";
                if(index->getGroup() == GROUPS::PZ23)
                    tmp = tmp + "PZ23" " ";
                if(index->getGroup() == GROUPS::PZ24)
                    tmp = tmp + "PZ24" " ";
                if(index->getGroup() == GROUPS::PZ25)
                    tmp = tmp + "PZ25" " ";
                if(index->getGroup() == GROUPS::PZ26)
                    tmp = tmp + "PZ26" " ";
                tmp = tmp + QString::number(index->getPhysics()) + ".";
                tmp = tmp + QString::number(index->getMath()) + ".";
                tmp = tmp + QString::number(index->getForeignLanguage()) + " ";
                tmp = tmp + QString::number(index->getUkrLanguage()) + " ";
                if(index!=list.list.end()-1)
                {
                    tmp = tmp + "\n";
                }
            }
            output<<tmp;
            file.flush();
            file.close();
        }
        else
        {
            file.close();
            throw bad_file("File is not empty");
        }
    }
    else
    {
        throw bad_file("Can not open");
    }

    return file;
}

void operator<<(QTableWidget * table, StudentsList &list)
{

    table->clear();
    table->setEditTriggers(QAbstractItemView::EditTriggers(0));
    table->setContextMenuPolicy(Qt::CustomContextMenu);
    table->setRowCount(0);
    table->setRowCount(list.list.size());
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Group"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Math"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Phisic"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Lang"));
    table->setHorizontalHeaderItem(6, new QTableWidgetItem("Ukr"));
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    QString tmp;
    for(int i = 0; i < table->rowCount(); i++)
    {
        tmp = "";
        table->setItem(i, 0,new QTableWidgetItem(list.list[i].getSurname()));
        table->setItem(i, 1,new QTableWidgetItem(list.list[i].getName()));
        if(list.list[i].getGroup() == GROUPS::PZ21)
            tmp = "PZ21";
        if(list.list[i].getGroup() == GROUPS::PZ22)
            tmp = "PZ22";
        if(list.list[i].getGroup() == GROUPS::PZ23)
            tmp = "PZ23";
        if(list.list[i].getGroup() == GROUPS::PZ24)
            tmp = "PZ24";
        if(list.list[i].getGroup() == GROUPS::PZ25)
            tmp = "PZ25";
        if(list.list[i].getGroup() == GROUPS::PZ26)
            tmp = "PZ26";
        table->setItem(i, 2,new QTableWidgetItem(tmp));
        table->setItem(i, 3,new QTableWidgetItem(QString::number(list.list[i].getMath())));
        table->setItem(i, 4,new QTableWidgetItem(QString::number(list.list[i].getPhysics())));
        table->setItem(i, 5,new QTableWidgetItem(QString::number(list.list[i].getForeignLanguage())));
        table->setItem(i, 6,new QTableWidgetItem(QString::number(list.list[i].getUkrLanguage())));
    }
}

std::vector<Student>& StudentsList::getList()
{
    return this->list;
}

void StudentsList::setList(std::vector<Student> &list)
{
    this->list = list;
}

StudentsList StudentsList::getLoosers()
{
    std::vector<Student> output;
    double min[6] = {6,6,6,6,6,6};
    for(int i = 0;i<6; ++i)
    {
        for(auto st : list)
        {
            if(st.getGroup()==i)
            {
                if(st.getAvgMark()<min[i])
                    min[i] = st.getAvgMark();
            }
        }
    }

    for(int i = 0;i<6; ++i)
    {
        for(auto st : list)
        {
            if(st.getGroup()==i && st.getAvgMark()==min[i])
            {
                output.push_back(st);
            }
        }
    }
    StudentsList out(output);
    return out;
}

void StudentsList::getGroupRanks(RANK(* out)[4][6] )
{
    this->sort();
    for(int i=0; i<4;++i)
        for(int j = 0; j<6; ++j)
            (*out)[i][j] = group_ranks[i][j];
}

void swap(RANK& a, RANK& b)
{
    RANK t = a;
    a = b;
    b = t;
}

void quickSort(RANK arr[], int first, int last)
{
    if (first == last)
    {
            return;
        }
        double m = arr[(first + last) / 2].mark;
        int begin = first, end = last;
        while (begin <= end)
        {
            while (arr[begin].mark < m)
            {
                begin++;
            }
            while (arr[end].mark > m)
            {
                end--;
            }
            if (begin <= end)
            {
                swap(arr[begin], arr[end]);
                begin++;
                end--;
            }
        }
        if (end > first)
        {
            quickSort(arr, first, end);
        }
        if (last > begin)
        {
            quickSort(arr, begin, last);
        }
}

void StudentsList::sort()
{
    calculateGroupRanks();

    for(int i = 0; i<4; ++i)
        quickSort(group_ranks[i], 0, 5);

    return;
}

void StudentsList::calculateGroupRanks()
{
    int count;
    for(int i = 0;i<6; ++i)
    {
        count = 0;
        for(auto st : list)
        {
            if(st.getGroup()==i)
            {
                ++count;
                this->group_ranks[0][i].mark+=st.getMath();
            }
        }
        group_ranks[0][i].mark/=count*1.0;
    }

    for(int i = 0;i<6; ++i)
    {
        count = 0;
        for(auto st : list)
        {
            if(st.getGroup()==i)
            {
                ++count;
                this->group_ranks[1][i].mark+=st.getPhysics();
            }
        }
        group_ranks[1][i].mark/=count*1.0;
    }

    for(int i = 0;i<6; ++i)
    {
        count = 0;
        for(auto st : list)
        {
            if(st.getGroup()==i)
            {
                ++count;
                this->group_ranks[2][i].mark+=st.getForeignLanguage();
            }
        }
        group_ranks[2][i].mark/=count*1.0;
    }

    for(int i = 0;i<6; ++i)
    {
        count = 0;
        for(auto st : list)
        {
            if(st.getGroup()==i)
            {
                ++count;
                this->group_ranks[3][i].mark+=st.getUkrLanguage();
            }
        }
        group_ranks[3][i].mark/=count*1.0;
    }
    for(int i = 0; i<4; ++i)
        for(int j = 0; j<6; ++j)
            this->group_ranks[i][j].group=(GROUPS)j;
}

void StudentsList::add(Student student)
{
    list.push_back(student);
}

void StudentsList::clear()
{
    list.clear();
}
