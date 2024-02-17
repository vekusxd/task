#include "../include/markdialog.hpp"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


MarkDialog::MarkDialog(QWidget *parent)
    : QDialog(parent)
{
    db = new DataBase;

    lessons = db->getAllLessons();
    students = db->getAllStudentsName();

    QGridLayout *layout = new QGridLayout(this);

    setWindowTitle("Новая оценка");

    QLabel *studentLabel = new QLabel("Студент:");

    studentBox = new QComboBox;
    studentBox->addItems(students.first);

    QLabel *lessonLabel = new QLabel("Предмет:");

    lessonBox = new QComboBox;
    lessonBox->addItems(lessons.first);

    QLabel* dateLabel = new QLabel("Дата:");
    calendar = new QCalendarWidget;

    QLabel *markLabel = new QLabel("Оценка:");

    markBox = new QSpinBox;
    markBox->setRange(1, 10);

    QLabel *themeLabel = new QLabel("Тема:");

    themeEdit = new QLineEdit;
    themeEdit->setPlaceholderText("введите тему");

    QPushButton *ok = new QPushButton("&Ok");
    QPushButton *cancel = new QPushButton("&Cancel");

    layout->addWidget(studentLabel, 0, 0);
    layout->addWidget(studentBox, 0, 1);

    layout->addWidget(lessonLabel, 1, 0);
    layout->addWidget(lessonBox, 1, 1);

    layout->addWidget(dateLabel, 2, 0);
    layout->addWidget(calendar, 2, 1);

    layout->addWidget(markLabel, 3, 0);
    layout->addWidget(markBox, 3, 1);

    layout->addWidget(themeLabel, 4, 0);
    layout->addWidget(themeEdit, 4, 1);

    layout->addWidget(ok, 5, 0);
    layout->addWidget(cancel, 5, 1);


    connect(ok, &QPushButton::clicked, this,&QDialog::accept);
    connect(cancel, &QPushButton::clicked,this, &QDialog::reject);

}

int MarkDialog::getStudentid() const
{
    int index = studentBox->currentIndex();
    return students.second.at(index);
}

int MarkDialog::getLessonId() const
{
    int index = lessonBox->currentIndex();
    return lessons.second.at(index);
}

QString MarkDialog::getDate() const
{
    return calendar->selectedDate().toString("yyyy-MM-dd");
}

int MarkDialog::getMark() const
{
    return markBox->value();
}

QString MarkDialog::getTheme() const
{
    return themeEdit->text();
}

void MarkDialog::clear()
{
    themeEdit->clear();
    markBox->setValue(1);
}

void MarkDialog::updateAll()
{
    students = db->getAllStudentsName();
    lessons = db->getAllLessons();
}



