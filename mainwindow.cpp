#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>

#include "globals.h"
Student tmpStudent;
RANK group_ranks[4][6];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table->setEditTriggers(QAbstractItemView::EditTriggers(0));
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->table->clear();
    ui->table->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->table->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->table->setHorizontalHeaderItem(2, new QTableWidgetItem("Group"));
    ui->table->setHorizontalHeaderItem(3, new QTableWidgetItem("Math"));
    ui->table->setHorizontalHeaderItem(4, new QTableWidgetItem("Phisic"));
    ui->table->setHorizontalHeaderItem(5, new QTableWidgetItem("Lang"));
    ui->table->setHorizontalHeaderItem(6, new QTableWidgetItem("Ukr"));
    ui->table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    isSaved = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//calls addStudent form
void MainWindow::on_actionAdd_Student_triggered()
{
    addstudent form(this);
    if(form.exec())
    {
        list.add(tmpStudent);
        isSaved = false;
        ui->table<<list;
    }
}

//reads list from file
void MainWindow::on_action_Open_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                tr("Open File"),"/home/user", "Text file(*.txt)");
        if (!file.isEmpty())
        {
            QFile FILE(file);
            try
            {
                FILE>>list;
            }
            catch (bad_input & error)
            {
                QMessageBox::critical(this,"Incorrect input" ,"Incorrect" + error.getType()
                                      + " in " + error.getWhere()
                                      + " in line " + QString::number(error.getLine()));
            }
            catch (bad_file & error)
            {
                QMessageBox::critical(this,"File error" ,"Can not open file\n" + error.getType());
            }
        }
        ui->table<<list;
}

//seves list to file
void MainWindow::on_action_Save_triggered()
{
    QString filename;
    QString file = QFileDialog::getSaveFileName(this,
            tr("Open File"),filename, "Text file(*.txt)");
    if (!file.isEmpty())
    {
        QFile FILE(file);
        FILE<<list;
    }
}

//clears list
void MainWindow::on_action_New_triggered()
{
    ui->table->clear();
    list.clear();
}

//calls form to show students with low average mark
void MainWindow::on_actionAverage_marks_triggered()
{
    OutputTable form(this->list.getLoosers().getList(),this);
    form.exec();
}

//calls form to print group Ranks
void MainWindow::on_actionGroups_top_list_triggered()
{
    list.getGroupRanks(&group_ranks);
    GroupRanks form(this);
    form.exec();
}

//calls form to print students with same names in same group
void MainWindow::on_actionGroup_triggered()
{
    OutputTable form(this->list.getSameNamesInGroup().getList(),this);
    form.exec();
}

//calls form to print students with same names
void MainWindow::on_actionEntire_list_triggered()
{
    OutputTable form(this->list.getSameNames().getList(),this);
    form.exec();
}

//calls form to choose what marks to show
void MainWindow::on_actionTwo_specific_marks_triggered()
{
    SpecificMarks form(this->list, this);
    form.exec();
}

//calls form to print students with some specific marks
void MainWindow::on_action5_foreign_triggered()
{
    try
    {
        this->list.ForeignPhisics5Math3();
    }
    catch (std::exception & error)
    {
        QMessageBox::critical( this, "ERROR",
                     "There are no such students",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    OutputTable form(this->list.ForeignPhisics5Math3().getList(),this);
    form.exec();
}

//calls form to print students with some specific marks
void MainWindow::on_action4_physics_3_both_languages_triggered()
{
    try
    {
        this->list.Phisics4UkrForeign3();
    }
    catch (std::exception & error)
    {
        QMessageBox::critical( this, "ERROR",
                     "There are no such students",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    OutputTable form(this->list.Phisics4UkrForeign3().getList(),this);
    form.exec();
}

//calls form to print students with some specific marks
void MainWindow::on_action3_5_4_triggered()
{
    try
    {
        this->list.Foreign4Math5Phisics3();
    }
    catch (std::exception & error)
    {
        QMessageBox::critical( this, "ERROR",
                     "There are no such students",
                     QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    OutputTable form(this->list.Foreign4Math5Phisics3().getList(),this);
    form.exec();
}
