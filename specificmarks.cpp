#include "specificmarks.h"
#include "ui_specificmarks.h"
#include "outputtable.h"
#include <QMessageBox>

SpecificMarks::SpecificMarks(StudentsList list, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecificMarks)
{
    ui->setupUi(this);
    this->list = list;
}

SpecificMarks::~SpecificMarks()
{
    delete ui;
}

//Two specific subjects' marks 5 and 4
void SpecificMarks::on_pushButton_clicked()
{
    if(ui->Math->isChecked()&&ui->Phisics->isChecked()
            &&!ui->Ukr->isChecked()&&!ui->Foreign->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(0, 1, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(0, 1, 5, 4).getList(),this);
        form.exec();
    }
    else
    if(ui->Math->isChecked()&&ui->Ukr->isChecked()
            &&!ui->Phisics->isChecked()&&!ui->Foreign->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(0, 2, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(0, 2, 5, 4).getList(),this);
        form.exec();
    }
    else
    if(ui->Math->isChecked()&&ui->Foreign->isChecked()
            &&!ui->Phisics->isChecked()&&!ui->Ukr->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(0, 3, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(0, 3, 5, 4).getList(),this);
        form.exec();
    }
    else
    if(ui->Phisics->isChecked()&&ui->Ukr->isChecked()
            &&!ui->Math->isChecked()&&!ui->Foreign->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(1, 2, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(1, 2, 5, 4).getList(),this);
        form.exec();
    }
    else
    if(ui->Phisics->isChecked()&&ui->Foreign->isChecked()
            &&!ui->Math->isChecked()&&!ui->Ukr->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(1, 3, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(1, 3, 5, 4).getList(),this);
        form.exec();
    }
    else
    if(ui->Ukr->isChecked()&&ui->Foreign->isChecked()
            &&!ui->Math->isChecked()&&!ui->Phisics->isChecked())
    {
        try
        {
            this->list.getTwoSpecific(2, 3, 5, 4);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getTwoSpecific(2, 3, 5, 4).getList(),this);
        form.exec();
    }
    else
    {
        QMessageBox::information( this, "Wrong choice",
                     "Check exect two boxes",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
}

//Three specific subjects' marks 4 and 3
void SpecificMarks::on_pushButton_3_clicked()
{
    if(ui->Math->isChecked()&&ui->Phisics->isChecked()
            &&ui->Ukr->isChecked()&&!ui->Foreign->isChecked())
    {
        try
        {
            this->list.getThreeSpecific(0, 1, 2, 4, 3);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getThreeSpecific(0, 1, 2, 4, 3).getList(),this);
        form.exec();
    }
    else
    if(ui->Math->isChecked()&&!ui->Ukr->isChecked()
            &&ui->Phisics->isChecked()&&ui->Foreign->isChecked())
    {
        try
        {
            this->list.getThreeSpecific(0, 1, 3, 4, 3);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getThreeSpecific(0, 1, 3, 4, 3).getList(),this);
        form.exec();
    }
    else
    if(ui->Math->isChecked()&&ui->Foreign->isChecked()
            &&!ui->Phisics->isChecked()&&ui->Ukr->isChecked())
    {
        try
        {
            this->list.getThreeSpecific(0, 2, 3, 4, 3);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getThreeSpecific(0, 2, 3, 4, 3).getList(),this);
        form.exec();
    }
    else
    if(ui->Phisics->isChecked()&&ui->Ukr->isChecked()
            &&!ui->Math->isChecked()&&ui->Foreign->isChecked())
    {
        try
        {
            this->list.getThreeSpecific(1, 2, 3, 4, 3);
        }
        catch (std::exception & error)
        {
            QMessageBox::critical( this, "ERROR",
                         "There are no such students",
                         QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        OutputTable form(this->list.getThreeSpecific(1, 2, 3, 4, 3).getList(),this);
        form.exec();
    }
    else
    {
        QMessageBox::information( this, "Wrong choice",
                     "Check exect three boxes",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
}

//All marks 5 and 3
void SpecificMarks::on_pushButton_2_clicked()
{
    try
    {
        this->list.getFourSpecific(5, 3);
    }
    catch (std::exception & error)
    {
        QMessageBox::critical( this, "ERROR",
                     "There are no such students",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    OutputTable form(this->list.getFourSpecific(5, 3).getList(),this);
    form.exec();
}

void SpecificMarks::on_pushButton_4_clicked()
{
    done(0);
}
