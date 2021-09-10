#ifndef EXPENSESCONTROLLER_H
#define EXPENSESCONTROLLER_H

#include <QDir>
#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>

//#include <boost/tokenizer.hpp>
class ExpensesController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY addingExpenses)
    Q_PROPERTY(QString days READ days WRITE setDays NOTIFY addingDays)
public:
    ExpensesController(const QString message = "OK", const QString days = "0");

    const QString &message() const;
    void setMessage(const QString &newMessage);
    void writeToFile(const QString &newMessage);
    Q_INVOKABLE QString calculate();
    void setDays(const QString &newDays);
    void setToFile();
    const QString &days() const;
signals:
    void addingExpenses();
    void addingDays();

private:
    QString m_message;
    QString m_days;
    QString curr_path = QDir::currentPath();
};

#endif // EXPENSESCONTROLLER_H
