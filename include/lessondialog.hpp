#pragma once

#include <QDialog>
#include <QObject>
#include <QLineEdit>

class lessonDialog : public QDialog
{
    Q_OBJECT
public:
    explicit lessonDialog(QWidget *parent = nullptr);

private:
    QLineEdit *lessonEdit;

public:
    QString getLesson() const;
    void clear();
};
