#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "studentslist.h"
#include "addstudent.h"
#include "outputtable.h"
#include "groupranks.h"
#include "specificmarks.h"

#include <QFileDialog>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_Student_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_action_New_triggered();

    void on_actionAverage_marks_triggered();

    void on_actionGroups_top_list_triggered();

    void on_actionGroup_triggered();

    void on_actionEntire_list_triggered();

    void on_actionTwo_specific_marks_triggered();

    void on_action5_foreign_triggered();

    void on_action4_physics_3_both_languages_triggered();

    void on_action3_5_4_triggered();

private:
    Ui::MainWindow *ui;
    StudentsList list;
    bool isSaved;
};
#endif // MAINWINDOW_H
