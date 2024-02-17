#pragma once

#include <QDialog>
#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QCalendarWidget>


#include "database.hpp"


class MarkDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MarkDialog(QWidget *parent = nullptr);

    QPair<QStringList, QList<int>> students;
    QPair<QStringList, QList<int>> lessons;


private:
    QComboBox *studentBox;
    QComboBox *lessonBox;
    QCalendarWidget *calendar;
    QSpinBox *markBox;
    QLineEdit *themeEdit;

    DataBase *db;

public:
    int getStudentid() const;
    int getLessonId() const;
    QString getDate() const;
    int getMark() const;
    QString getTheme() const;
    void clear();
    void updateAll();
};
