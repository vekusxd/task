#pragma once

#include <QObject>
#include <QValidator>

class LessonValidator : public QValidator
{
    Q_OBJECT
public:
    explicit LessonValidator(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString &, int &) const override;
};
