#include "../include/studentdialog.hpp"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

studentDialog::studentDialog(QWidget *parent)
    : QDialog(parent)
{
    db = new DataBase;

    groups = db->getAllGroups();

    QGridLayout *layout = new QGridLayout(this);

    setWindowTitle("Новый студент");

    setMinimumWidth(600);

    QLabel *studentName = new QLabel("Инициалы:");

    initialsEdit = new QLineEdit;
    initialsEdit->setValidator(new nameValidatior);
    initialsEdit->setPlaceholderText("Ф.И.О.");

    QLabel *groupLabel = new QLabel("Группа:");

    QPushButton *ok = new QPushButton("&Ok");
    QPushButton *cancel = new QPushButton("&Cancel");

    groupsBox = new QComboBox;
    groupsBox->addItems(groups.first);

    layout->addWidget(studentName, 0, 0);
    layout->addWidget(initialsEdit, 0, 1);
    layout->addWidget(groupLabel,1, 0);
    layout->addWidget(groupsBox, 1, 1);
    layout->addWidget(ok, 2, 0);
    layout->addWidget(cancel, 2, 1);

    connect(ok, &QPushButton::clicked, this,&QDialog::accept);
    connect(cancel, &QPushButton::clicked,this, &QDialog::reject);
}

QString studentDialog::getInitials() const
{
    return initialsEdit->text();
}

int studentDialog::getId() const
{
    int index = groupsBox->currentIndex();
    return groups.second.at(index);
}

void studentDialog::clear()
{
    initialsEdit->clear();
}

void studentDialog::updateAll()
{
    groups = db->getAllGroups();
}


