#include "groupdialog.hpp"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


GroupDialog::GroupDialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    setWindowTitle("Новая группа");

    QLabel *groupTitle = new QLabel("Название группы:");

    setMinimumWidth(400);

    groupEdit = new QLineEdit;
    groupEdit->setPlaceholderText("Группа");

    QPushButton *ok = new QPushButton("&Ok");
    QPushButton *cancel = new QPushButton("&Cancel");

    layout->addWidget(groupTitle, 0, 0);
    layout->addWidget(groupEdit, 0, 1);
    layout->addWidget(ok, 1, 0);
    layout->addWidget(cancel, 1, 1);

    connect(ok, &QPushButton::clicked, this,&QDialog::accept);
    connect(cancel, &QPushButton::clicked,this, &QDialog::reject);
}

QString GroupDialog::getGroup() const
{
    return groupEdit->text();
}

void GroupDialog::clear()
{
    groupEdit->clear();
}
