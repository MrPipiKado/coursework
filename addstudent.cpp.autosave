#include "addstudent.h"
#include "ui_addstudent.h"
#include "globals.h"

addstudent::addstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstudent)
{
    ui->setupUi(this);
}

addstudent::~addstudent()
{
    delete ui;
}

void addstudent::on_pushButton_clicked()
{//Initialise global variable
 //Main form uses this variable to add new student
    tmpStudent.setSurname(ui->surname->text());
    tmpStudent.setName(ui->name->text());
    if(ui->group->currentIndex() == 0)
        tmpStudent.setGroup(GROUPS::PZ21);
    if(ui->group->currentIndex() == 1)
        tmpStudent.setGroup(GROUPS::PZ22);
    if(ui->group->currentIndex() == 2)
        tmpStudent.setGroup(GROUPS::PZ23);
    if(ui->group->currentIndex() == 3)
        tmpStudent.setGroup(GROUPS::PZ24);
    if(ui->group->currentIndex() == 4)
        tmpStudent.setGroup(GROUPS::PZ25);
    if(ui->group->currentIndex() == 5)
        tmpStudent.setGroup(GROUPS::PZ26);
    tmpStudent.setMath(ui->math->text().toInt());
    tmpStudent.setPhysics(ui->phisics->text().toInt());
    tmpStudent.setUkrLanguage(ui->ukr->text().toInt());
    tmpStudent.setForeignLanguage(ui->foregn->text().toInt());

    tmpStudent.getAvgMark();
    this->done(1);
}

void addstudent::on_pushButton_2_clicked()
{
    this->done(0);
}
