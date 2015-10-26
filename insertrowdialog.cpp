#include "insertrowdialog.h"
#include "ui_insertrowdialog.h"
#include "QPushButton"

InsertRowDialog::InsertRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertRowDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(onAccepted()));
	connect(ui->editName, SIGNAL(textChanged(QString)), this, SLOT(onInputValueChanged()));
	connect(ui->editValue, SIGNAL(valueChanged(int)), this, SLOT(onInputValueChanged()));

	validateForm();
}

InsertRowDialog::~InsertRowDialog()
{
    delete ui;
}

void InsertRowDialog::onAccepted()
{
	emit rowReady(ui->editName->text(), ui->editValue->value());
}

void InsertRowDialog::onInputValueChanged()
{
	validateForm();
}

void InsertRowDialog::validateForm()
{
	QString currentName = ui->editName->text();
	int currentValue = ui->editValue->value();
	QPushButton* okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
	bool isValid = true;
	isValid &= validateName(currentName);
	isValid &= validateValue(currentValue);
	okButton->setEnabled(isValid);
}

bool InsertRowDialog::validateName(QString const& name)
{
	bool result = true;
	result &= (name.length() > 0);

	return result;
}

bool InsertRowDialog::validateValue(const int newValue)
{
	bool result = true;
	result &= (newValue > 0);
	
	return result;
}
