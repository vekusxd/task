#pragma once

#include <QObject>
#include <QtSql>
#include <QTime>
#include <QPair>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);

    void insertLesson(const QString& title);
    void insertStudent(const QString& initials, const int groupId);
    void insertGroup(const QString& title);
    void insertMark(const int lesson_id, const int student_id, const QString& date, const int mark, const QString& theme);
    QPair<QStringList, QList<int>> getAllLessons() const;
    //QStringList getAllStudentsName(int group_id) const;
    QPair<QStringList, QList<int>> getAllStudentsName() const;
    QPair<QStringList, QList<int>> getAllGroups() const;
    QString getAllStudentsInGroup(int id) const;

private:
    QSqlDatabase db;
};
