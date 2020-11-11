#ifndef SPECIFICMARKS_H
#define SPECIFICMARKS_H

#include <QDialog>
#include "studentslist.h"

namespace Ui {
class SpecificMarks;
}

class SpecificMarks : public QDialog
{
    Q_OBJECT

public:
    explicit SpecificMarks(StudentsList list, QWidget *parent = nullptr);
    ~SpecificMarks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SpecificMarks *ui;
    StudentsList list;
};

#endif // SPECIFICMARKS_H
