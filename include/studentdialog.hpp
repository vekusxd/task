#pragma once

#include <QDialog>
#include <QWidget>
#include <QComboBox>
#include <QPair>
#include <QLineEdit>

#include "namevalidatior.hpp"
#include "database.hpp"

class StudentDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StudentDialog(QWidget *parent = nullptr);


    QPair<QStringList, QList<int>> groups;

private:
    QLineEdit *initialsEdit;
    QComboBox *groupsBox;
    DataBase *db;


public:
    QString getInitials() const;
    int getId() const;
    void clear();
    void updateAll();

};
