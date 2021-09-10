import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.12
import Expenses 1.0
ColumnLayout {
    AverageExpenses {
        id: _expenses
    }
    ListView {
        Layout.fillHeight: true
        Layout.fillWidth: true
        clip: true
        model: ListModel {
            id: _lstModel
            ListElement {
                message: "Hello"
            }
        }
        delegate: ItemDelegate {
            text: message
        }
        ScrollBar.vertical: ScrollBar{}
    }
    RowLayout {
        TextField {
            id: _days
            placeholderText: "Кол-во дней"
            text: _expenses.days
        }
        TextField {
            id: _day_expences
            text: _expenses.message
            visible: true
            Layout.fillWidth: true
            placeholderText: "Введите ваши расходы"
            onAccepted: _accept.clicked()
        }
        Button {
            id: _accept
            text: qsTr("Ввод")
            onClicked: {
                _expenses.message = _day_expences.text
                _expenses.days = _days.text
                _lstModel.append({message: "Average expenses: " + _expenses.calculate() + ""})
                _day_expences.clear()
                _days.clear()
            }
        }
    }
}
