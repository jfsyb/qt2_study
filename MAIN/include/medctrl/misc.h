class CLanguageSelect
{
public:
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QToolButton *toolButton_home;
	QPushButton *pushButton_cancel;
	QLabel *label;
	QSpacerItem *horizontalSpacer;
	QSpacerItem *horizontalSpacer_2;
	QPushButton *pushButton_accept;
	QLabel *label_2;
	QSpacerItem *horizontalSpacer_3;
	QComboBox *comboBox_current;
	QComboBox *comboBox_selected;
	QSpacerItem *verticalSpacer;
	QSpacerItem *verticalSpacer_2;
	QSpacerItem *horizontalSpacer_4;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QString::fromUtf8("Dialog"));
		Dialog->resize(416, 256);
		gridLayoutWidget = new QWidget(Dialog);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(20, 10, 361, 241));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		toolButton_home = new QToolButton(gridLayoutWidget);
		toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
		toolButton_home->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_home, 5, 5, 1, 1);

		pushButton_cancel = new QPushButton(gridLayoutWidget);
		pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

		gridLayout->addWidget(pushButton_cancel, 3, 3, 1, 1);

		label = new QLabel(gridLayoutWidget);
		label->setObjectName(QString::fromUtf8("label"));

		gridLayout->addWidget(label, 1, 1, 1, 1);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer, 3, 5, 1, 1);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

		pushButton_accept = new QPushButton(gridLayoutWidget);
		pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));

		gridLayout->addWidget(pushButton_accept, 3, 1, 1, 1);

		label_2 = new QLabel(gridLayoutWidget);
		label_2->setObjectName(QString::fromUtf8("label_2"));

		gridLayout->addWidget(label_2, 2, 1, 1, 1);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_3, 3, 2, 1, 1);

		comboBox_current = new QComboBox(gridLayoutWidget);
		comboBox_current->setObjectName(QString::fromUtf8("comboBox_current"));

		gridLayout->addWidget(comboBox_current, 1, 2, 1, 2);

		comboBox_selected = new QComboBox(gridLayoutWidget);
		comboBox_selected->setObjectName(QString::fromUtf8("comboBox_selected"));

		gridLayout->addWidget(comboBox_selected, 2, 2, 1, 2);

		verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

		gridLayout->addItem(verticalSpacer, 4, 5, 1, 1);

		verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

		gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

		horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_4, 5, 4, 1, 1);


		retranslateUi(Dialog);

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
		toolButton_home->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
		pushButton_cancel->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
		label->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		pushButton_accept->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
		label_2->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};


class CAbout
{
public:
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QLabel *label_hard;
	QToolButton *toolButton_home;
	QLabel *label_soft;
	QSpacerItem *verticalSpacer;
	QLabel *label_softd;
	QLabel *label_hardd;
	QToolButton *toolButton_stop;
	QToolButton *toolButton_begin;
	QSpacerItem *horizontalSpacer_2;
	QSpacerItem *horizontalSpacer_4;
	QSpacerItem *horizontalSpacer_3;
	QLabel *label_dis;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QString::fromUtf8("Dialog"));
		Dialog->resize(569, 525);
		gridLayoutWidget = new QWidget(Dialog);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(0, 0, 561, 471));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		label_hard = new QLabel(gridLayoutWidget);
		label_hard->setObjectName(QString::fromUtf8("label_hard"));

		gridLayout->addWidget(label_hard, 1, 0, 1, 1);

		toolButton_home = new QToolButton(gridLayoutWidget);
		toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
		toolButton_home->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_home, 5, 6, 1, 1);

		label_soft = new QLabel(gridLayoutWidget);
		label_soft->setObjectName(QString::fromUtf8("label_soft"));

		gridLayout->addWidget(label_soft, 0, 0, 1, 1);

		verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

		gridLayout->addItem(verticalSpacer, 4, 6, 1, 1);

		label_softd = new QLabel(gridLayoutWidget);
		label_softd->setObjectName(QString::fromUtf8("label_softd"));

		gridLayout->addWidget(label_softd, 0, 1, 1, 3);

		label_hardd = new QLabel(gridLayoutWidget);
		label_hardd->setObjectName(QString::fromUtf8("label_hardd"));

		gridLayout->addWidget(label_hardd, 1, 1, 1, 3);

		toolButton_stop = new QToolButton(gridLayoutWidget);
		toolButton_stop->setObjectName(QString::fromUtf8("toolButton_stop"));
		toolButton_stop->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_stop, 4, 4, 1, 1);

		toolButton_begin = new QToolButton(gridLayoutWidget);
		toolButton_begin->setObjectName(QString::fromUtf8("toolButton_begin"));
		toolButton_begin->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_begin, 4, 2, 1, 1);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_2, 4, 1, 1, 1);

		horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_4, 4, 3, 1, 1);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_3, 4, 5, 1, 1);

		label_dis = new QLabel(gridLayoutWidget);
		label_dis->setObjectName(QString::fromUtf8("label_dis"));

		gridLayout->addWidget(label_dis, 2, 0, 2, 7);

		gridLayout->setRowStretch(0, 1);
		gridLayout->setRowStretch(1, 1);
		gridLayout->setRowStretch(2, 4);
		gridLayout->setRowStretch(3, 2);
		gridLayout->setRowStretch(4, 1);
		gridLayout->setRowStretch(5, 2);

		retranslateUi(Dialog);

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
		label_hard->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		toolButton_home->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
		label_soft->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		label_softd->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		label_hardd->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		toolButton_stop->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
		toolButton_begin->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
		label_dis->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};


class CUserInfo
{
public:
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QTableView *tableView;
	QToolButton *toolButton_home;
	QPushButton *pushButton_seach;
	QPushButton *pushButton_del;
	QLabel *label_user;
	QPushButton *pushButton_add;
	QLineEdit *lineEdit_uname;
	QSpacerItem *horizontalSpacer_2;
	QSpacerItem *horizontalSpacer;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QString::fromUtf8("Dialog"));
		Dialog->resize(590, 533);
		gridLayoutWidget = new QWidget(Dialog);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(0, 20, 581, 481));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		tableView = new QTableView(gridLayoutWidget);
		tableView->setObjectName(QString::fromUtf8("tableView"));

		gridLayout->addWidget(tableView, 1, 0, 1, 7);

		toolButton_home = new QToolButton(gridLayoutWidget);
		toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
		toolButton_home->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_home, 2, 6, 1, 1);

		pushButton_seach = new QPushButton(gridLayoutWidget);
		pushButton_seach->setObjectName(QString::fromUtf8("pushButton_seach"));

		gridLayout->addWidget(pushButton_seach, 0, 2, 1, 1);

		pushButton_del = new QPushButton(gridLayoutWidget);
		pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

		gridLayout->addWidget(pushButton_del, 0, 4, 1, 1);

		label_user = new QLabel(gridLayoutWidget);
		label_user->setObjectName(QString::fromUtf8("label_user"));

		gridLayout->addWidget(label_user, 0, 0, 1, 1);

		pushButton_add = new QPushButton(gridLayoutWidget);
		pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

		gridLayout->addWidget(pushButton_add, 0, 3, 1, 1);

		lineEdit_uname = new QLineEdit(gridLayoutWidget);
		lineEdit_uname->setObjectName(QString::fromUtf8("lineEdit_uname"));

		gridLayout->addWidget(lineEdit_uname, 0, 1, 1, 1);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_2, 2, 5, 1, 1);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer, 0, 5, 1, 2);

		gridLayout->setRowStretch(0, 1);
		gridLayout->setRowStretch(1, 4);
		gridLayout->setRowStretch(2, 2);

		retranslateUi(Dialog);

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
		toolButton_home->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
		pushButton_seach->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
		pushButton_del->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
		label_user->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
		pushButton_add->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

class CTimeZoneSelect
{
	public:
		QWidget *gridLayoutWidget;
		QGridLayout *gridLayout;
		QLineEdit *lineEdit_time;
		QSpacerItem *verticalSpacer;
		QComboBox *comboBox_tz;
		QLabel *label_manual;
		QToolButton *toolButton_home;
		QSpacerItem *horizontalSpacer;
		QRadioButton *ntpeable;
		QPushButton *time_apply;
		QLabel *ntp_svr;
		QLineEdit *ntp_svre;
		QSpacerItem *horizontalSpacer_3;
		QLineEdit *lineEdit_date;
		QLabel *t1;
		QLabel *label_ntpport;
		QPushButton *ntp_apply;
		QLabel *label_time;
		QLabel *label_date;
		QLineEdit *lineEdit_ntpport;
		QPushButton *tz_apply;
		QSpacerItem *horizontalSpacer_2;

		void setupUi(QWidget *Form)
		{
			if (Form->objectName().isEmpty())
				Form->setObjectName(QString::fromUtf8("Form"));
			Form->resize(659, 462);
			gridLayoutWidget = new QWidget(Form);
			gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
			gridLayoutWidget->setGeometry(QRect(10, 10, 511, 401));
			gridLayout = new QGridLayout(gridLayoutWidget);
			gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
			gridLayout->setContentsMargins(0, 0, 0, 0);
			lineEdit_time = new QLineEdit(gridLayoutWidget);
			lineEdit_time->setObjectName(QString::fromUtf8("lineEdit_time"));

			gridLayout->addWidget(lineEdit_time, 7, 2, 1, 1);

			verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

			gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

			comboBox_tz = new QComboBox(gridLayoutWidget);
			comboBox_tz->setObjectName(QString::fromUtf8("comboBox_tz"));

			gridLayout->addWidget(comboBox_tz, 1, 2, 1, 1);

			label_manual = new QLabel(gridLayoutWidget);
			label_manual->setObjectName(QString::fromUtf8("label_manual"));

			gridLayout->addWidget(label_manual, 5, 1, 1, 2);

			toolButton_home = new QToolButton(gridLayoutWidget);
			toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
			toolButton_home->setMinimumSize(QSize(100, 96));

			gridLayout->addWidget(toolButton_home, 8, 5, 1, 1);

			horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

			gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

			ntpeable = new QRadioButton(gridLayoutWidget);
			ntpeable->setObjectName(QString::fromUtf8("ntpeable"));

			gridLayout->addWidget(ntpeable, 2, 1, 1, 2);

			time_apply = new QPushButton(gridLayoutWidget);
			time_apply->setObjectName(QString::fromUtf8("time_apply"));

			gridLayout->addWidget(time_apply, 7, 3, 1, 1);

			ntp_svr = new QLabel(gridLayoutWidget);
			ntp_svr->setObjectName(QString::fromUtf8("ntp_svr"));

			gridLayout->addWidget(ntp_svr, 3, 1, 1, 1);

			ntp_svre = new QLineEdit(gridLayoutWidget);
			ntp_svre->setObjectName(QString::fromUtf8("ntp_svre"));

			gridLayout->addWidget(ntp_svre, 3, 2, 1, 1);

			horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

			gridLayout->addItem(horizontalSpacer_3, 5, 5, 1, 1);

			lineEdit_date = new QLineEdit(gridLayoutWidget);
			lineEdit_date->setObjectName(QString::fromUtf8("lineEdit_date"));

			gridLayout->addWidget(lineEdit_date, 6, 2, 1, 1);

			t1 = new QLabel(gridLayoutWidget);
			t1->setObjectName(QString::fromUtf8("t1"));

			gridLayout->addWidget(t1, 1, 1, 1, 1);

			label_ntpport = new QLabel(gridLayoutWidget);
			label_ntpport->setObjectName(QString::fromUtf8("label_ntpport"));

			gridLayout->addWidget(label_ntpport, 4, 1, 1, 1);

			ntp_apply = new QPushButton(gridLayoutWidget);
			ntp_apply->setObjectName(QString::fromUtf8("ntp_apply"));

			gridLayout->addWidget(ntp_apply, 4, 3, 1, 1);

			label_time = new QLabel(gridLayoutWidget);
			label_time->setObjectName(QString::fromUtf8("label_time"));

			gridLayout->addWidget(label_time, 7, 1, 1, 1);

			label_date = new QLabel(gridLayoutWidget);
			label_date->setObjectName(QString::fromUtf8("label_date"));

			gridLayout->addWidget(label_date, 6, 1, 1, 1);

			lineEdit_ntpport = new QLineEdit(gridLayoutWidget);
			lineEdit_ntpport->setObjectName(QString::fromUtf8("lineEdit_ntpport"));

			gridLayout->addWidget(lineEdit_ntpport, 4, 2, 1, 1);

			tz_apply = new QPushButton(gridLayoutWidget);
			tz_apply->setObjectName(QString::fromUtf8("tz_apply"));

			gridLayout->addWidget(tz_apply, 1, 3, 1, 1);

			horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

			gridLayout->addItem(horizontalSpacer_2, 8, 4, 1, 1);


			retranslateUi(Form);

			QMetaObject::connectSlotsByName(Form);
		} // setupUi

		void retranslateUi(QWidget *Form)
		{
			Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
			label_manual->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			toolButton_home->setText(QApplication::translate("Form", "...", 0, QApplication::UnicodeUTF8));
			ntpeable->setText(QApplication::translate("Form", "RadioButton", 0, QApplication::UnicodeUTF8));
			time_apply->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
			ntp_svr->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			t1->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			label_ntpport->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			ntp_apply->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
			label_time->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			label_date->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
			tz_apply->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
		} // retranslateUi

	};


class CWifiSelect
{
public:
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QLineEdit *lineEdit_pass;
	QLabel *label_pass;
	QPushButton *pushButton_del;
	QPushButton *pushButton_add;
	QComboBox *comboBox_ssnsel;
	QLabel *label_ssn;
	QPushButton *pushButton_default;
	QSpacerItem *horizontalSpacer;
	QPushButton *pushButton_update;
	QSpacerItem *horizontalSpacer_2;
	QTableView *tableView;
	QToolButton *toolButton_2;

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QString::fromUtf8("Form"));
		Form->resize(570, 444);
		gridLayoutWidget = new QWidget(Form);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(60, 20, 491, 341));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		lineEdit_pass = new QLineEdit(gridLayoutWidget);
		lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));

		gridLayout->addWidget(lineEdit_pass, 1, 2, 1, 1);

		label_pass = new QLabel(gridLayoutWidget);
		label_pass->setObjectName(QString::fromUtf8("label_pass"));

		gridLayout->addWidget(label_pass, 1, 1, 1, 1);

		pushButton_del = new QPushButton(gridLayoutWidget);
		pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

		gridLayout->addWidget(pushButton_del, 0, 3, 1, 1);

		pushButton_add = new QPushButton(gridLayoutWidget);
		pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

		gridLayout->addWidget(pushButton_add, 0, 4, 1, 1);

		comboBox_ssnsel = new QComboBox(gridLayoutWidget);
		comboBox_ssnsel->setObjectName(QString::fromUtf8("comboBox_ssnsel"));

		gridLayout->addWidget(comboBox_ssnsel, 0, 2, 1, 1);

		label_ssn = new QLabel(gridLayoutWidget);
		label_ssn->setObjectName(QString::fromUtf8("label_ssn"));

		gridLayout->addWidget(label_ssn, 0, 1, 1, 1);

		pushButton_default = new QPushButton(gridLayoutWidget);
		pushButton_default->setObjectName(QString::fromUtf8("pushButton_default"));

		gridLayout->addWidget(pushButton_default, 1, 4, 1, 1);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

		pushButton_update = new QPushButton(gridLayoutWidget);
		pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));

		gridLayout->addWidget(pushButton_update, 1, 3, 1, 1);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

		tableView = new QTableView(gridLayoutWidget);
		tableView->setObjectName(QString::fromUtf8("tableView"));

		gridLayout->addWidget(tableView, 2, 1, 1, 4);

		toolButton_2 = new QToolButton(gridLayoutWidget);
		toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
		toolButton_2->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_2, 3, 5, 1, 1);


		retranslateUi(Form);

		QMetaObject::connectSlotsByName(Form);
	} // setupUi

	void retranslateUi(QWidget *Form)
	{
		Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
		lineEdit_pass->setInputMask(QString());
		label_pass->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
		pushButton_del->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
		pushButton_add->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
		label_ssn->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
		pushButton_default->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
		pushButton_update->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
		toolButton_2->setText(QApplication::translate("Form", "...", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

class CPasswordChange
{
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QSpacerItem *horizontalSpacer;
	QLineEdit *lineEdit;
	QLabel *label_2;
	QLabel *label;
	QToolButton *toolButton_home;
	QLineEdit *lineEdit_2;
	QLineEdit *lineEdit_3;
	QSpacerItem *horizontalSpacer_2;
	QSpacerItem *verticalSpacer;
	QLabel *label_3;
	QSpacerItem *horizontalSpacer_3;
	QSpacerItem *horizontalSpacer_4;
	QSpacerItem *verticalSpacer_2;
	QSpacerItem *horizontalSpacer_5;

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QString::fromUtf8("Form"));
		Form->resize(534, 449);
		gridLayoutWidget = new QWidget(Form);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(0, 10, 511, 401));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

		lineEdit = new QLineEdit(gridLayoutWidget);
		lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

		gridLayout->addWidget(lineEdit, 1, 2, 1, 1);

		label_2 = new QLabel(gridLayoutWidget);
		label_2->setObjectName(QString::fromUtf8("label_2"));

		gridLayout->addWidget(label_2, 2, 1, 1, 1);

		label = new QLabel(gridLayoutWidget);
		label->setObjectName(QString::fromUtf8("label"));

		gridLayout->addWidget(label, 1, 1, 1, 1);

		toolButton_home = new QToolButton(gridLayoutWidget);
		toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
		toolButton_home->setMinimumSize(QSize(100, 96));

		gridLayout->addWidget(toolButton_home, 5, 5, 1, 1);

		lineEdit_2 = new QLineEdit(gridLayoutWidget);
		lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

		gridLayout->addWidget(lineEdit_2, 2, 2, 1, 1);

		lineEdit_3 = new QLineEdit(gridLayoutWidget);
		lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

		gridLayout->addWidget(lineEdit_3, 3, 2, 1, 1);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

		verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

		gridLayout->addItem(verticalSpacer, 4, 5, 1, 1);

		label_3 = new QLabel(gridLayoutWidget);
		label_3->setObjectName(QString::fromUtf8("label_3"));

		gridLayout->addWidget(label_3, 3, 1, 1, 1);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

		horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_4, 5, 3, 1, 1);

		verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

		gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

		horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		gridLayout->addItem(horizontalSpacer_5, 5, 4, 1, 1);


		retranslateUi(Form);

		QMetaObject::connectSlotsByName(Form);
	} // setupUi

	void retranslateUi(QWidget *Form)
	{
		Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
		label_2->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
		label->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
		toolButton_home->setText(QApplication::translate("Form", "...", 0, QApplication::UnicodeUTF8));
		label_3->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};