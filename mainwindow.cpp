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

void MainWindow::on_action_New_triggered()
{
    ui->table->clear();
    list.clear();
}

void MainWindow::on_actionAverage_marks_triggered()
{
    OutputTable form(this->list.getLoosers().getList(),this);
    form.exec();
}

void MainWindow::on_actionGroups_top_list_triggered()
{
    list.getGroupRanks(&group_ranks);
    GroupRanks form(this);
    form.exec();
}
