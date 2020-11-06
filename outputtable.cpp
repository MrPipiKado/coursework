#include "outputtable.h"
#include "ui_outputtable.h"

OutputTable::OutputTable(std::vector<Student>& list, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputTable)
{
    ui->setupUi(this);
    this->list = list;
    ui->tableWidget->clear();
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTriggers(0));
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(list.size());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Group"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Math"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Phisic"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Lang"));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Ukr"));
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    QString tmp;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        tmp = "";
        ui->tableWidget->setItem(i, 0,new QTableWidgetItem(this->list[i].getSurname()));
        ui->tableWidget->setItem(i, 1,new QTableWidgetItem(this->list[i].getName()));
        if(this->list[i].getGroup() == GROUPS::PZ21)
            tmp = "PZ21";
        if(this->list[i].getGroup() == GROUPS::PZ22)
            tmp = "PZ22";
        if(this->list[i].getGroup() == GROUPS::PZ23)
            tmp = "PZ23";
        if(this->list[i].getGroup() == GROUPS::PZ24)
            tmp = "PZ24";
        if(this->list[i].getGroup() == GROUPS::PZ25)
            tmp = "PZ25";
        if(this->list[i].getGroup() == GROUPS::PZ26)
            tmp = "PZ26";
        ui->tableWidget->setItem(i, 2,new QTableWidgetItem(tmp));
        ui->tableWidget->setItem(i, 3,new QTableWidgetItem(QString::number(this->list[i].getMath())));
        ui->tableWidget->setItem(i, 4,new QTableWidgetItem(QString::number(this->list[i].getPhysics())));
        ui->tableWidget->setItem(i, 5,new QTableWidgetItem(QString::number(this->list[i].getForeignLanguage())));
        ui->tableWidget->setItem(i, 6,new QTableWidgetItem(QString::number(this->list[i].getUkrLanguage())));
    }
}

OutputTable::~OutputTable()
{
    delete ui;
}

void OutputTable::on_pushButton_clicked()
{
    this->done(0);
}
