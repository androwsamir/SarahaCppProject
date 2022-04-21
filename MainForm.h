#pragma once
#include "UserForm.h"
#include "RegisterForm.h"

namespace BlueSara7a {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ Password;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ checklabel;
	private: System::Windows::Forms::Button^ SignButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Register;
	private: System::Windows::Forms::Panel^ panel3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checklabel = (gcnew System::Windows::Forms::Label());
			this->SignButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(150, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(158, 224);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"User name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(158, 344);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			//this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// Username
			// 
			this->Username->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->Username->Location = System::Drawing::Point(162, 268);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(344, 23);
			this->Username->TabIndex = 3;
			this->Username->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Username_KeyDown);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(162, 297);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(344, 2);
			this->panel1->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(162, 411);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(344, 2);
			this->panel2->TabIndex = 6;
			//this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel2_Paint);
			// 
			// Password
			// 
			this->Password->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->Password->Location = System::Drawing::Point(162, 382);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(344, 23);
			this->Password->TabIndex = 5;
			this->Password->UseSystemPasswordChar = true;
			//this->Password->TextChanged += gcnew System::EventHandler(this, &MainForm::Password_TextChanged);
			this->Password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Password_KeyDown);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(164, 456);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(110, 20);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"I Agree to the ";
			this->checkBox1->UseVisualStyleBackColor = false;
			//this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// checklabel
			// 
			this->checklabel->AutoSize = true;
			this->checklabel->BackColor = System::Drawing::Color::Transparent;
			this->checklabel->ForeColor = System::Drawing::Color::Blue;
			this->checklabel->Location = System::Drawing::Point(265, 457);
			this->checklabel->Name = L"checklabel";
			this->checklabel->Size = System::Drawing::Size(130, 16);
			this->checklabel->TabIndex = 9;
			this->checklabel->Text = L"terms and conditions";
			//this->checklabel->Click += gcnew System::EventHandler(this, &MainForm::checklabel_Click);
			// 
			// SignButton
			// 
			this->SignButton->BackColor = System::Drawing::Color::RoyalBlue;
			this->SignButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->SignButton->FlatAppearance->BorderSize = 0;
			this->SignButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSlateGray;
			this->SignButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SignButton->Location = System::Drawing::Point(162, 518);
			this->SignButton->Name = L"SignButton";
			this->SignButton->Size = System::Drawing::Size(140, 44);
			this->SignButton->TabIndex = 10;
			this->SignButton->Text = L"Sign in ";
			this->SignButton->UseVisualStyleBackColor = false;
			this->SignButton->Click += gcnew System::EventHandler(this, &MainForm::SignButton_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::CornflowerBlue;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSteelBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->button1->Location = System::Drawing::Point(325, 518);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 44);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// Register
			// 
			this->Register->BackColor = System::Drawing::Color::Black;
			this->Register->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Register->ForeColor = System::Drawing::Color::White;
			this->Register->Location = System::Drawing::Point(390, 453);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(178, 23);
			this->Register->TabIndex = 12;
			this->Register->Text = L"Don\'t have an account yet\?";
			this->Register->UseVisualStyleBackColor = false;
			this->Register->Click += gcnew System::EventHandler(this, &MainForm::Register_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel3->ForeColor = System::Drawing::Color::MidnightBlue;
			this->panel3->Location = System::Drawing::Point(393, 475);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(175, 1);
			this->panel3->TabIndex = 13;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1186, 673);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->Register);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->SignButton);
			this->Controls->Add(this->checklabel);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Sara7a";
			//this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Password_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Username_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			Password->Focus();
		}
	}
	private: System::Void Password_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			SignButton->PerformClick();
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void SignButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filename = "check.txt";
		String^ user;
		String^ pass;
		String^ id;
		bool found = 0;
		int c = 0;
		try {
			Console::WriteLine("tying to open file", filename);
			StreamReader^ din = File::OpenText(filename);
			String^ str;
			while ((str = din->ReadLine()) != nullptr)
			{
				user = "";
				pass = "";
				id = "";
				c = 0;
				for (int i = 0; i < str->Length; i++) {
					if (str[i] != ' ') {
						user += str[i];
					}
					else {
						c = i + 1;
						break;
					}
				}
				for (int i = c; i < str->Length; i++) {
					if (str[i] != ' ') {
						pass += str[i];
					}
					else {
						c = i + 1;
						break;
					}
				}
				for (int i = c; i < str->Length; i++) {
					if (str[i] != ' ') {
						id += str[i];
					}
					else {
						break;
					}
				}
				if (user == Username->Text && pass == Password->Text) {
					found = 1;
					break;
				}
			}
			din->Close();
		}
		catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("file '{0}' not found", filename);
			else
				Console::WriteLine("problem reading file '{0}'", filename);
		}
		if (found) {
			UserForm^ userform = gcnew UserForm(this,Username->Text,Password->Text, id);
			this->Hide();
			userform->Show();
		}
		else
		{
			MessageBox::Show("username or password is wrong");
		}
	}
	private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForm^ registerform = gcnew RegisterForm(this);
		this->Hide();
		registerform->Show();
	}
};
}
