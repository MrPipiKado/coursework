#include "studentslist.h"

StudentsList::StudentsList()
{

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
            if(str!="PZ21" || str!="PZ22" || str!="PZ23"
                    || str!="PZ24" || str!="PZ25" || str!="PZ26")
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
            input>>tmp;
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

void StudentsList::sort()
{

    return;
}
