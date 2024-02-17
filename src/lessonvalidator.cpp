#include "../include/lessonvalidator.hpp"
#include <QRegularExpression>

lessonValidator::lessonValidator(QObject *parent)
    : QValidator{parent}
{}

QValidator::State lessonValidator::validate(QString &str, int &) const
{
    QRegularExpression rxp = QRegularExpression("[A-Za-z]");
    if(str.contains(rxp)){
        return Invalid;
    }
    return Acceptable;
}
