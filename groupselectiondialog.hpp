#pragma once

#include <QComboBox>
#include <QDialog>
#include <QWidget>
#include <QPair>


#include "database.hpp"

class GroupSelectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit GroupSelectionDialog(QWidget *parent = nullptr);

private:
    QComboBox *groupBox;

    DataBase *db;

    QPair<QStringList, QList<int>> groups;
public:
    int getGroupId() const;
    QString getGroupName() const;
};
