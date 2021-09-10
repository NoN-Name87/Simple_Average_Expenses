#include "expenses_controller.h"
#include <QDebug>
#include <iostream>
ExpensesController::ExpensesController(const QString message, const QString days)
    : m_message(message),
      m_days(days)
{

}

const QString &ExpensesController::message() const
{
    return m_message;
}

void ExpensesController::setMessage(const QString &newMessage)
{
    bool check_num;
    newMessage.toInt(&check_num);
    if(check_num) {
        m_message = newMessage;
        emit addingExpenses();
    }
    else
        qWarning() << "Incorrect value";
}

QString ExpensesController::calculate()
{
   QFileInfo check_file(curr_path + "/result.txt");
   if(check_file.exists()) {
       QFile file(curr_path + "/result.txt");
       if(file.open(QIODevice::ReadOnly)) {
           QTextStream in(&file);
           QString temp;
           in >> temp;
           m_days = QString::number(m_days.toInt() + temp.toInt());
           in >> temp;
           m_message = QString::number(m_message.toInt() + temp.toInt());
           file.close();
       }
   }
   setToFile();
   return QString::number(m_message.toInt() / m_days.toInt());
}

void ExpensesController::setDays(const QString &newDays)
{
    bool check_num;
    newDays.toInt(&check_num);
    if(check_num) {
        m_days = newDays;
        emit addingDays();
    }
    else
        qWarning() << "Incorrect value";
}

void ExpensesController::setToFile()
{
    QFile file(curr_path + "/result.txt");
    if(file.open(QIODevice::WriteOnly)) {
         QTextStream out(&file);
         out << m_days << "\n";
         out << m_message;
    }
    file.close();
}

const QString &ExpensesController::days() const
{
    return m_days;
}
