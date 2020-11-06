#ifndef GROUPRANKS_H
#define GROUPRANKS_H

#include <QDialog>

namespace Ui {
class GroupRanks;
}

class GroupRanks : public QDialog
{
    Q_OBJECT

public:
    explicit GroupRanks(QWidget *parent = nullptr);
    ~GroupRanks();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GroupRanks *ui;
};

#endif // GROUPRANKS_H
