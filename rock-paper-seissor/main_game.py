from PyQt5 import QtCore, QtGui, QtWidgets
import time
import random


class Ui_Form(object):

    def __init__(self):
        self.secenekler = ["rock","paper","scissors"]
        
        self.rounds = 0
        self.user_skor = 0
        self.computer_skor = 0

        self.setupUi

    def setupUi(self, Form):
        Form.setObjectName("form")
        Form.setFixedSize(781, 473)


        self.scissors_btn = QtWidgets.QPushButton(Form)
        self.scissors_btn.setGeometry(QtCore.QRect(500, 410, 191, 51))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(r"scissors.png"), QtGui.QIcon.Normal, QtGui.QIcon.On)
        self.scissors_btn.setIcon(icon)
        self.scissors_btn.setIconSize(QtCore.QSize(100, 40))
        self.scissors_btn.clicked.connect(self.scissorsBtn)

        self.rock_btn = QtWidgets.QPushButton(Form)
        self.rock_btn.setGeometry(QtCore.QRect(100, 410, 191, 51))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(r"rock.png"), QtGui.QIcon.Normal, QtGui.QIcon.On)
        self.rock_btn.setIcon(icon1)
        self.rock_btn.setIconSize(QtCore.QSize(120, 40))
        self.rock_btn.clicked.connect(self.rockBtn)

        self.paper_btn = QtWidgets.QPushButton(Form)
        self.paper_btn.setGeometry(QtCore.QRect(300, 410, 191, 51))
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(r"paper.png"), QtGui.QIcon.Normal, QtGui.QIcon.On)
        self.paper_btn.setIcon(icon2)
        self.paper_btn.setIconSize(QtCore.QSize(100, 40))
        self.paper_btn.clicked.connect(self.paperBtn)

        self.skorBoard = QtWidgets.QLabel(Form)
        self.skorBoard.setGeometry(QtCore.QRect(280, 10, 201, 111))
        self.skorBoard.setPixmap(QtGui.QPixmap(r"skorboard.png"))

        self.start_and_finish_btn = QtWidgets.QPushButton(Form)
        self.start_and_finish_btn.setGeometry(QtCore.QRect(300, 370, 191, 28))
        self.start_and_finish_btn.setStyleSheet("background-color: rgb(85, 170, 255);\n"
"font: 87 10pt \"Arial Black\";")
        self.start_and_finish_btn.clicked.connect(self.start_and_finish_btnButon)

        self.user_lbl = QtWidgets.QLineEdit(Form)
        self.user_lbl.setGeometry(QtCore.QRect(390, 35, 81, 20))
        self.user_lbl.setStyleSheet("font: 87 8pt \"Arial Black\";")
        self.user_lbl.setAlignment(QtCore.Qt.AlignCenter)

        self.user_options = QtWidgets.QLabel(Form)
        self.user_options.setGeometry(QtCore.QRect(460, 120, 311, 251))
        self.user_options.setPixmap(QtGui.QPixmap(r"rock.png"))

        self.computer_options = QtWidgets.QLabel(Form)
        self.computer_options.setGeometry(QtCore.QRect(20, 120, 311, 251))
        self.computer_options.setPixmap(QtGui.QPixmap(r"first_sign.png"))

        self.computer_lbl = QtWidgets.QLineEdit(Form)
        self.computer_lbl.setGeometry(QtCore.QRect(290, 35, 81, 20))
        self.computer_lbl.setStyleSheet("font: 87 8pt \"Arial Black\";")
        self.computer_lbl.setAlignment(QtCore.Qt.AlignCenter)

        self.vs_lbl = QtWidgets.QLabel(Form)
        self.vs_lbl.setGeometry(QtCore.QRect(340, 190, 101, 121))
        self.vs_lbl.setPixmap(QtGui.QPixmap(r"vs_sign.png"))

        self.computer_skor_lbl = QtWidgets.QLineEdit(Form)
        self.computer_skor_lbl.setGeometry(QtCore.QRect(290, 60, 80, 31))
        self.computer_skor_lbl.setStyleSheet("background-color: rgb(79, 159, 239);\n"
"color: rgb(230, 0, 0);\n"
"font: 87 12pt \"Arial Black\";")
        self.computer_skor_lbl.setAlignment(QtCore.Qt.AlignCenter)

        self.user_skor_lbl = QtWidgets.QLineEdit(Form)
        self.user_skor_lbl.setGeometry(QtCore.QRect(390, 60, 81, 31))
        self.user_skor_lbl.setStyleSheet("background-color: rgb(79, 159, 239);\n"
"color: rgb(230, 0, 0);\n"
"font: 87 12pt \"Arial Black\";background-color: rgb(79, 159, 239);")
        self.user_skor_lbl.setAlignment(QtCore.Qt.AlignCenter)

        self.rock_btn.hide()
        self.paper_btn.hide()
        self.scissors_btn.hide()

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)


    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.start_and_finish_btn.setText(_translate("Form", "START"))
        self.computer_lbl.setText(_translate("Form", "Computer"))
        self.computer_skor_lbl.setText(_translate("Form", "0"))
        self.user_skor_lbl.setText(_translate("Form", "0"))


    def rockBtn(self):
        self.user_options.setPixmap(QtGui.QPixmap(r"rock.png"))
        self.computer = self.secenekler[random.randint(0,2)]

        time.sleep(0.5)
        self.combPhoto()

        if self.rockpaperscissorsGame("rock") == "user_":
            self.user_skor += 1
            self.user_skor_lbl.clear()
            self.user_skor_lbl.setText(str(self.user_skor))

        elif self.rockpaperscissorsGame("rock") == "computer":
            self.computer_skor += 1
            self.computer_skor_lbl.clear()
            self.computer_skor_lbl.setText(str(self.computer_skor))


    def paperBtn(self):
        self.user_options.setPixmap(QtGui.QPixmap(r"paper.png"))
        self.computer = self.secenekler[random.randint(0,2)]

        time.sleep(0.5)
        self.combPhoto()

        if self.rockpaperscissorsGame("paper") == "user_":
            self.user_skor += 1
            self.user_skor_lbl.clear()
            self.user_skor_lbl.setText(str(self.user_skor))

        elif self.rockpaperscissorsGame("paper") == "computer":
            self.computer_skor += 1
            self.computer_skor_lbl.clear()
            self.computer_skor_lbl.setText(str(self.computer_skor))


    def scissorsBtn(self):
        self.user_options.setPixmap(QtGui.QPixmap(r"scissors.png"))
        self.computer = self.secenekler[random.randint(0,2)]

        time.sleep(0.5)
        self.combPhoto()

        if self.rockpaperscissorsGame("scissors") == "user_":
            self.user_skor += 1
            self.user_skor_lbl.clear()
            self.user_skor_lbl.setText(str(self.user_skor))

        elif self.rockpaperscissorsGame("scissors") == "computer":
            self.computer_skor += 1
            self.computer_skor_lbl.clear()
            self.computer_skor_lbl.setText(str(self.computer_skor))


    def start_and_finish_btnButon(self):
        if self.rounds == 0:
            self.rock_btn.show()
            self.paper_btn.show()
            self.scissors_btn.show()
            self.start_and_finish_btn.setText("FINISH")
            self.rounds = 1


        elif self.rounds == 1:
            self.rock_btn.hide()
            self.paper_btn.hide()
            self.scissors_btn.hide()
            self.start_and_finish_btn.setText("START")
            self.user_skor_lbl.setText("0")
            self.computer_skor_lbl.setText("0")
            self.user_skor = 0
            self.computer_skor = 0
            self.rounds = 0

    
    def rockpaperscissorsGame(self,user_):
        x = None
        computer = self.computer

        if (user_ == "rock") and (computer == "rock"):
            x = "continue"

        elif (user_ == "rock") and (computer == "paper"):
            x = "computer"

        elif (user_ == "rock") and (computer == "scissors"):
            x = "user_"

        elif (user_ == "paper") and (computer == "rock"):
            x = "user_"

        elif (user_ == "paper") and (computer == "paper"):
            x = "continue"

        elif (user_ == "paper") and (computer == "scissors"):
            x = "computer"

        elif (user_ == "scissors") and (computer == "rock"):
            x = "computer"

        elif (user_ == "scissors") and (computer == "paper"):
            x = "user_"

        elif (user_ == "scissors") and (computer == "scissors"):
            x = "continue"

        return x
    

    def combPhoto(self):
        if self.computer == "rock":
            self.computer_options.setPixmap(QtGui.QPixmap(r"rock_comp.png"))

        elif self.computer == "paper":
            self.computer_options.setPixmap(QtGui.QPixmap(r"paper_comp.png"))

        elif self.computer == "scissors":
            self.computer_options.setPixmap(QtGui.QPixmap(r"scissors_comp.png"))
        


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())

        




