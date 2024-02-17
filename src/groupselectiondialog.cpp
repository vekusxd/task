#include "../include/groupselectiondialog.hpp"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>


GroupSelectionDialog::GroupSelectionDialog(QWidget *parent)
    : QDialog(parent)
{
    db = new DataBase;
    groups = db->getAllGroups();

    groupBox = new QComboBox;
    groupBox->addItems(groups.first);

    setMinimumWidth(400);

    QGridLayout *layout = new QGridLayout(this);

    setWindowTitle("Выбрать группу");

    QLabel *label = new QLabel("Группа:");

    QPushButton *ok = new QPushButton("&Ok");
    QPushButton *cancel = new QPushButton("&Cancel");

    layout->addWidget(label, 0, 0, 1, 1);
    layout->addWidget(groupBox, 0, 1, 1, 3);

    layout->addWidget(ok, 1, 0, 1, 2);
    layout->addWidget(cancel, 1, 2, 1, 2);

    connect(ok, &QPushButton::clicked, this,&QDialog::accept);
    connect(cancel, &QPushButton::clicked,this, &QDialog::reject);
}

int GroupSelectionDialog::getGroupId() const
{
    int index = groupBox->currentIndex();
    return groups.second.at(index);
}

QString GroupSelectionDialog::getGroupName() const
{
    return groupBox->currentText();
}
