#pragma once

#include <QObject>
#include <QValidator>

class lessonValidator : public QValidator
{
    Q_OBJECT
public:
    explicit lessonValidator(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString &, int &) const override;
};
