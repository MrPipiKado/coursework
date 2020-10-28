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
                    //TODO exeption Incorrect surname in line
                    //return;
                }
            }
            if(!str[0].isUpper())
            {
                //TODO exeption Incorrect surname in line
                //return;
            }

            //Read name
            input>>str;
            for(auto c:str)
            {
                if(!c.isLetter())
                {
                    //TODO exeption Incorrect name in line
                    //return;
                }
            }
            if(!str[0].isUpper())
            {
                //TODO exeption Incorrect surname in line
                //return;
            }

            //Read Group
            input>>str;
            //TODO case or if for group

            //Read physics mark
            input>>num;
            if(num>5||num<0)
            {
                //TODO exeption physics mark
                //return;
            }

            //Read math mark
            input>>num;
            if(num>5||num<0)
            {
                //TODO exeption math mark
                //return;
            }

            //Read foreign language mark
            input>>num;
            if(num>5||num<0)
            {
                //TODO exeption foreign language mark
                //return;
            }

            //Read ukr language mark
            input>>num;
            if(num>5||num<0)
            {
                //TODO exeption ukr language mark
                //return;
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
        //TODO can not open file
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
            //TODO exception file is not empty
        }
    }
    else
    {
        //TODO exception can not open
    }

    return file;
}
