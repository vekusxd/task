#include "window.hpp"

#include <QToolBar>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>

window::window(QWidget *parent)
    : QMainWindow{parent}
{
    db = new DataBase;
    lessonDialog = new class lessonDialog;
    groupDialog = new GroupDialog;
    this->studentDialog = new class studentDialog;
    markDialog = new MarkDialog;
    selectDialog = new GroupSelectionDialog;

    QWidget *mainWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);


    selectedGroup = new QLabel(selectDialog->getGroupName());

    statusBar()->addWidget(selectedGroup);

    setCentralWidget(mainWidget);


    model = new QSqlRelationalTableModel;

    model->setTable("marks");

    model->setHeaderData(1, Qt::Horizontal, "Предмет");
    model->setHeaderData(2, Qt::Horizontal, "Студент");
    model->setHeaderData(3, Qt::Horizontal, "Дата");
    model->setHeaderData(4, Qt::Horizontal, "Оценка");
    model->setHeaderData(5, Qt::Horizontal, "Тема");

    model->setRelation(1, QSqlRelation("lessons", "id", "title"));
    model->setRelation(2, QSqlRelation("students", "id", "initials"));
    model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    onSelectGroupDialogAccepted();
    model->select();

    view = new QTableView;
    view->setModel(model);
    view->resizeRowsToContents();
    view->resizeColumnsToContents();
    view->setColumnWidth(0, 0);
    view->setItemDelegate(new QSqlRelationalDelegate(view->model()));

    layout->addWidget(view);

    QToolBar *toolBar = new QToolBar("Test");
    toolBar->addAction(QPixmap(":/lessonAddIcon.png"), "Добавить предмет", lessonDialog, &lessonDialog::exec);
    toolBar->addAction(QPixmap(":/groupAddIcon.png"), "Добавить группу", groupDialog, &GroupDialog::exec);
    toolBar->addAction(QPixmap(":/studenAddIcon.png"),"Добавить студента", studentDialog, &studentDialog::exec);
    toolBar->addAction(QPixmap(":/addMarkIcon.png"), "Добавить оценку", markDialog, &MarkDialog::exec);
    toolBar->addAction(QPixmap(":/filterIcon.png"), "Выбрать группу", selectDialog, &GroupSelectionDialog::exec);

    addToolBar(Qt::TopToolBarArea, toolBar);

    connect(lessonDialog, &lessonDialog::accepted, this, &window::onLessonDialogAccepted);
    connect(groupDialog, &GroupDialog::accepted, this, &window::onGroupDialogAccepted);
    connect(studentDialog, &studentDialog::accepted, this, &window::onStudentDialogAccepted);
    connect(markDialog, &MarkDialog::accepted, this, &window::onMarkDialogAccepted);
    connect(selectDialog, &GroupSelectionDialog::accepted, this, &window::onSelectGroupDialogAccepted);
}

void window::updateModel()
{
    model->setTable("marks");
    model->setRelation(1, QSqlRelation("lessons", "id", "title"));
    //model->setRelation(2, QSqlRelation("students", "id", "group_id"));
    model->setRelation(2, QSqlRelation("students", "id", "initials"));
    model->select();
    view->reset();
    model->setHeaderData(1, Qt::Horizontal, "Предмет");
    model->setHeaderData(2, Qt::Horizontal, "Студент");
    model->setHeaderData(3, Qt::Horizontal, "Дата");
    model->setHeaderData(4, Qt::Horizontal, "Оценка");
    view->resizeRowsToContents();
    view->resizeColumnsToContents();
    view->setColumnWidth(0, 0);
    onSelectGroupDialogAccepted();
    studentDialog->updateAll();
    markDialog->updateAll();
    view->setItemDelegate(new QSqlRelationalDelegate(view->model()));
}

void window::onStudentDialogAccepted()
{
    if(studentDialog->getInitials().isEmpty()){
        return;
    }
    int id = studentDialog->getId();
    db->insertStudent(studentDialog->getInitials(), id);
    studentDialog->clear();
    studentDialog->updateAll();
    markDialog->updateAll();
    updateModel();
}

void window::onLessonDialogAccepted()
{
    if(lessonDialog->getLesson().isEmpty()){
        return;
    }
    db->insertLesson(lessonDialog->getLesson());
    lessonDialog->clear();
    studentDialog->updateAll();
    markDialog->updateAll();
    updateModel();

}

void window::onGroupDialogAccepted()
{
    if(groupDialog->getGroup().isEmpty()){
        return;
    }
    db->insertGroup(groupDialog->getGroup());
    groupDialog->clear();
    studentDialog->updateAll();
    markDialog->updateAll();
    updateModel();

}

void window::onMarkDialogAccepted()
{
    if(markDialog->getTheme().isEmpty()){
        return;
    }
    db->insertMark(markDialog->getLessonId(), markDialog->getStudentid(), markDialog->getDate(), markDialog->getMark(), markDialog->getTheme());
    markDialog->clear();
    studentDialog->updateAll();
    markDialog->updateAll();
    updateModel();

}

void window::onSelectGroupDialogAccepted()
{
    QString filter = QString("marks.student_id in %1").arg(db->getAllStudentsInGroup(selectDialog->getGroupId()));
    model->setFilter(filter);
    studentDialog->updateAll();
    markDialog->updateAll();
    selectedGroup->setText(selectDialog->getGroupName());
}

