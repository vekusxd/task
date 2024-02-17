#pragma once

#include <QDialog>
#include <QObject>
#include <QLineEdit>

class LessonDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LessonDialog(QWidget *parent = nullptr);

private:
    QLineEdit *lessonEdit;

public:
    QString getLesson() const;
    void clear();
};
