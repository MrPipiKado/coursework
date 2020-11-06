#include "groupranks.h"
#include "ui_groupranks.h"
#include "globals.h"
GroupRanks::GroupRanks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupRanks)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTriggers(0));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Math"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Phisic"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Lang"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Ukr"));
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    QString tmp;
    for(int i = 0; i<4; ++i)
        for(int j = 0; j<6; ++j)
        {
            tmp = "";
            if(group_ranks[i][j].group == GROUPS::PZ21)
                tmp = "PZ21";
            if(group_ranks[i][j].group == GROUPS::PZ22)
                tmp = "PZ22";
            if(group_ranks[i][j].group == GROUPS::PZ23)
                tmp = "PZ23";
            if(group_ranks[i][j].group == GROUPS::PZ24)
                tmp = "PZ24";
            if(group_ranks[i][j].group == GROUPS::PZ25)
                tmp = "PZ25";
            if(group_ranks[i][j].group == GROUPS::PZ26)
                tmp = "PZ26";
            ui->tableWidget->setItem(j, i,new QTableWidgetItem(tmp + " " + QString::number(group_ranks[i][j].mark, 'f', 2)));
        }
}

GroupRanks::~GroupRanks()
{
    delete ui;
}

void GroupRanks::on_pushButton_clicked()
{
    this->done(0);
}
