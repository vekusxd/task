#pragma once

#include <QDialog>
#include <QObject>
#include <QLineEdit>

class GroupDialog : public QDialog
{
    Q_OBJECT
public:
    explicit GroupDialog(QWidget *parent = nullptr);

private:
    QLineEdit *groupEdit;

public:
    QString getGroup() const;
    void clear();
};
