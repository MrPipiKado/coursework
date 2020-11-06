#ifndef OUTPUTTABLE_H
#define OUTPUTTABLE_H

#include <QDialog>
#include "studentslist.h"

namespace Ui {
class OutputTable;
}

class OutputTable : public QDialog
{
    Q_OBJECT

public:
    explicit OutputTable(std::vector<Student>& list, QWidget *parent = nullptr);
    ~OutputTable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OutputTable *ui;

    std::vector<Student> list;
};

#endif // OUTPUTTABLE_H
