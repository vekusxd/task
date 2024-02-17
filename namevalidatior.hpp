#pragma once

#include <QObject>
#include <QValidator>

class nameValidatior : public QValidator

{
    Q_OBJECT
public:
    explicit nameValidatior(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString & str, int & idk) const override;
};
