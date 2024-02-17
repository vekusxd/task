#include "namevalidatior.hpp"
#include <QRegularExpression>

nameValidatior::nameValidatior(QObject *parent)
    : QValidator{parent}
{}

QValidator::State nameValidatior::validate(QString &str, int &idk) const
{
    QRegularExpression rxp = QRegularExpression("[A-Za-z0-9]");
    if(str.contains(rxp)){
        return Invalid;
    }
    return Acceptable;
}
