#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table->setEditTriggers(QAbstractItemView::EditTriggers(0));
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->table->clear();
    ui->table->setHorizontalHeaderItem(0, new QTableWidgetItem("#"));
    ui->table->setHorizontalHeaderItem(1, new QTableWidgetItem("Surname"));
    ui->table->setHorizontalHeaderItem(2, new QTableWidgetItem("Name"));
    ui->table->setHorizontalHeaderItem(3, new QTableWidgetItem("Group"));
    ui->table->setHorizontalHeaderItem(4, new QTableWidgetItem("Math"));
    ui->table->setHorizontalHeaderItem(5, new QTableWidgetItem("Phisic"));
    ui->table->setHorizontalHeaderItem(6, new QTableWidgetItem("Lang"));
    ui->table->setHorizontalHeaderItem(7, new QTableWidgetItem("Ukr"));
    ui->table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    isSaved = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

