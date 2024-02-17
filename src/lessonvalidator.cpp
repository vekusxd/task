#include "../include/lessonvalidator.hpp"
#include <QRegularExpression>

LessonValidator::LessonValidator(QObject *parent)
    : QValidator{parent}
{}

QValidator::State LessonValidator::validate(QString &str, int &) const
{
    QRegularExpression rxp = QRegularExpression("[A-Za-z]");
    if(str.contains(rxp)){
        return Invalid;
    }
    return Acceptable;
}
