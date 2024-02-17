#include "../include/lessondialog.hpp"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "../include/lessonvalidator.hpp"

lessonDialog::lessonDialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    setWindowTitle("Новый предмет");

    setMinimumWidth(400);

    QLabel *lessonName = new QLabel("Название предмета:");
    lessonEdit = new QLineEdit;
    lessonEdit->setValidator(new lessonValidator);
    lessonEdit->setPlaceholderText("Предмет");

    QPushButton *ok = new QPushButton("&Ok");
    QPushButton *cancel = new QPushButton("&Cancel");

    layout->addWidget(lessonName, 0, 0);
    layout->addWidget(lessonEdit, 0, 1);
    layout->addWidget(ok, 1, 0);
    layout->addWidget(cancel, 1, 1);

    connect(ok, &QPushButton::clicked, this,&QDialog::accept);
    connect(cancel, &QPushButton::clicked,this, &QDialog::reject);
}

QString lessonDialog::getLesson() const
{
    return lessonEdit->text();
}

void lessonDialog::clear()
{
    lessonEdit->clear();
}
