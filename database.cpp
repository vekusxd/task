#include "database.hpp"


DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../marks.db");
    bool ok = db.open();
}

void DataBase::insertLesson(const QString &title)
{
    QSqlQuery query;

    query.prepare("INSERT INTO lessons(title) VALUES (:title)");
    query.bindValue(":title", title);
    if(!query.exec()){
        qDebug() << "error insert into lessons\t" << query.lastError();
    }
}

void DataBase::insertStudent(const QString &initials, const int groupId)
{
    QSqlQuery query;

    query.prepare("INSERT INTO students(initials, group_id) VALUES (:name, :group)");

    query.bindValue(":name", initials);
    query.bindValue(":group", groupId);
    if(!query.exec()){
        qDebug() << "error insert into students\t" << query.lastError();
    }
}

void DataBase::insertGroup(const QString &title)
{
    QSqlQuery query;

    query.prepare("INSERT INTO groups(title) VALUES (:title)");
    query.bindValue(":title", title);
    if(!query.exec()){
        qDebug() << "error insert into groups\t" << query.lastError();
    }
}

void DataBase::insertMark(const int lesson_id, const int student_id, const QString& date, const int mark, const QString &theme)
{
    QSqlQuery query;

    query.prepare("INSERT INTO marks(lesson_id, student_id, date, mark, theme) "
                  "VALUES  "
                   "(:lesson, :student ,:date, :mark, :theme)");

    query.bindValue(":lesson", lesson_id);
    query.bindValue(":student", student_id);
    query.bindValue(":date", date);
    query.bindValue(":mark", mark);
    query.bindValue(":theme", theme);

    if(!query.exec()){
        qDebug() << "error insert into marks\t" << query.lastError();
    }
}

QPair<QStringList, QList<int>> DataBase::getAllLessons() const
{
    QSqlQuery query;

    query.exec("SELECT title, id from lessons");
    QStringList res;
    QList<int> ids;


    while(query.next()){
        res.push_back(query.value(0).toString());
        ids.push_back(query.value(1).toInt());
    }
    return QPair<QStringList, QList<int>>(res, ids);
}


QPair<QStringList, QList<int>> DataBase::getAllStudentsName() const
{
    QSqlQuery query;

    query.exec("SELECT initials, group_id from students");
    QStringList names;
    QList<int> ids;

    while(query.next()){
        names.push_back(query.value(0).toString());
        ids.push_back(query.value(1).toInt());
    }
    return QPair<QStringList, QList<int>>(names, ids);
}

QPair<QStringList, QList<int>> DataBase::getAllGroups() const
{
    QSqlQuery query;

    QStringList titles;
    QList<int> ids;

    query.exec("SELECT title, id FROM groups");

    while(query.next()){
        titles.push_back(query.value(0).toString());
        ids.push_back(query.value(1).toInt());
    }
    return QPair<QStringList, QList<int>>(titles, ids);
}

QString DataBase::getAllStudentsInGroup(int id) const
{
    QSqlQuery query;
    QString result;

    query.exec("select id from students where group_id = " + QString::number(id));
    result += "(";
    while(query.next()){
        result += query.value(0).toString() + ",";
    }
    if(result.size() < 2){
        return  "";
    }
    result.removeLast();
    result += ")";
    return result;
}


