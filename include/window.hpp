#pragma once

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QLabel>
#include <QStatusBar>

#include "database.hpp"
#include "lessondialog.hpp"
#include "groupdialog.hpp"
#include "studentdialog.hpp"
#include "markdialog.hpp"
#include "groupselectiondialog.hpp"

class window : public QMainWindow
{
    Q_OBJECT
public:
    explicit window(QWidget *parent = nullptr);

private:
   DataBase *db;


   LessonDialog *lessonDialog;
   GroupDialog *groupDialog;
   StudentDialog *studentDialog;
   MarkDialog *markDialog;
   GroupSelectionDialog *selectDialog;

   QLabel *selectedGroup;

   QTableView *view;
   QSqlRelationalTableModel *model;

   void updateModel();


private slots:
   void onStudentDialogAccepted();
   void onLessonDialogAccepted();
   void onGroupDialogAccepted();
   void onMarkDialogAccepted();
   void onSelectGroupDialogAccepted();

};
