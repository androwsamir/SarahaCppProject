#pragma once
#include "UserForm.h"
#include "RegisterForm.h"
#include<cliext/hash_map>

namespace BlueSara7a {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Speech;
	using namespace System::Speech::Synthesis;
	using namespace System::Speech::Recognition;
	using namespace cliext;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		hash_map <String^, String^>users_pass;
		hash_map <String^, String^>users_id;
		SpeechSynthesizer^ speaker = gcnew SpeechSynthesizer();
		bool reg = 0;
		
		void load_data() {
			users_id.clear();
			users_pass.clear();
			String^ filename = "check.txt";	// name password id
			String^ user;
			String^ pass;
			String^ id;
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
					users_pass[user] = pass;
					users_id[user] = id;
				}
				din->Close();
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
		}
	public:
		MainForm(void)
		{
			speaker->Speak("Welcome to Saraha");
			InitializeComponent();
			load_data();
			this->Show_pass->Hide();
			this->Sign_username_error->Hide();
			this->Sign_password_error->Hide();
			this->Sign_error1->Hide();
			this->Sign_error2->Hide();
			this->SignIn_error->Hide();
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
	private: System::Windows::Forms::Panel^ panel4;
	protected:
	private: System::Windows::Forms::Button^ SignButton;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ Show_pass;

	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ Register;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Hide_pass;
	private: System::Windows::Forms::PictureBox^ Sign_error2;
	private: System::Windows::Forms::PictureBox^ Sign_error1;
	private: System::Windows::Forms::Label^ Sign_password_error;
	private: System::Windows::Forms::Label^ Sign_username_error;
	private: System::Windows::Forms::Label^ SignIn_error;
	private: System::Windows::Forms::Button^ button1;

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
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->SignIn_error = (gcnew System::Windows::Forms::Label());
			this->Sign_password_error = (gcnew System::Windows::Forms::Label());
			this->Sign_username_error = (gcnew System::Windows::Forms::Label());
			this->Sign_error2 = (gcnew System::Windows::Forms::PictureBox());
			this->Sign_error1 = (gcnew System::Windows::Forms::PictureBox());
			this->SignButton = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->Hide_pass = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Show_pass = (gcnew System::Windows::Forms::Button());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Sign_error2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Sign_error1))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel4
			// 
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->SignIn_error);
			this->panel4->Controls->Add(this->Sign_password_error);
			this->panel4->Controls->Add(this->Sign_username_error);
			this->panel4->Controls->Add(this->Sign_error2);
			this->panel4->Controls->Add(this->Sign_error1);
			this->panel4->Controls->Add(this->SignButton);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Location = System::Drawing::Point(404, 1);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(630, 673);
			this->panel4->TabIndex = 14;
			// 
			// SignIn_error
			// 
			this->SignIn_error->AutoSize = true;
			this->SignIn_error->ForeColor = System::Drawing::Color::DarkRed;
			this->SignIn_error->Location = System::Drawing::Point(212, 501);
			this->SignIn_error->Name = L"SignIn_error";
			this->SignIn_error->Size = System::Drawing::Size(200, 16);
			this->SignIn_error->TabIndex = 20;
			this->SignIn_error->Text = L"*Invalid Password or Username*";
			// 
			// Sign_password_error
			// 
			this->Sign_password_error->AutoSize = true;
			this->Sign_password_error->ForeColor = System::Drawing::Color::DarkRed;
			this->Sign_password_error->Location = System::Drawing::Point(84, 409);
			this->Sign_password_error->Name = L"Sign_password_error";
			this->Sign_password_error->Size = System::Drawing::Size(119, 16);
			this->Sign_password_error->TabIndex = 19;
			this->Sign_password_error->Text = L"*Invalid Password*";
			// 
			// Sign_username_error
			// 
			this->Sign_username_error->AutoSize = true;
			this->Sign_username_error->ForeColor = System::Drawing::Color::DarkRed;
			this->Sign_username_error->Location = System::Drawing::Point(84, 323);
			this->Sign_username_error->Name = L"Sign_username_error";
			this->Sign_username_error->Size = System::Drawing::Size(122, 16);
			this->Sign_username_error->TabIndex = 18;
			this->Sign_username_error->Text = L"*Invalid Username*";
			// 
			// Sign_error2
			// 
			this->Sign_error2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Sign_error2.BackgroundImage")));
			this->Sign_error2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Sign_error2.Image")));
			this->Sign_error2->Location = System::Drawing::Point(528, 357);
			this->Sign_error2->Name = L"Sign_error2";
			this->Sign_error2->Size = System::Drawing::Size(41, 40);
			this->Sign_error2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Sign_error2->TabIndex = 17;
			this->Sign_error2->TabStop = false;
			// 
			// Sign_error1
			// 
			this->Sign_error1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Sign_error1.BackgroundImage")));
			this->Sign_error1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Sign_error1.Image")));
			this->Sign_error1->Location = System::Drawing::Point(528, 270);
			this->Sign_error1->Name = L"Sign_error1";
			this->Sign_error1->Size = System::Drawing::Size(41, 40);
			this->Sign_error1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Sign_error1->TabIndex = 16;
			this->Sign_error1->TabStop = false;
			// 
			// SignButton
			// 
			this->SignButton->BackColor = System::Drawing::Color::LightSeaGreen;
			this->SignButton->FlatAppearance->BorderColor = System::Drawing::Color::LightSeaGreen;
			this->SignButton->FlatAppearance->BorderSize = 2;
			this->SignButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SignButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SignButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->SignButton->Location = System::Drawing::Point(87, 443);
			this->SignButton->Name = L"SignButton";
			this->SignButton->Size = System::Drawing::Size(402, 55);
			this->SignButton->TabIndex = 4;
			this->SignButton->Text = L"Sign in";
			this->SignButton->UseVisualStyleBackColor = false;
			this->SignButton->Click += gcnew System::EventHandler(this, &MainForm::SignButton_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel5->Controls->Add(this->Hide_pass);
			this->panel5->Controls->Add(this->button4);
			this->panel5->Controls->Add(this->Show_pass);
			this->panel5->Controls->Add(this->Password);
			this->panel5->Location = System::Drawing::Point(78, 349);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(424, 57);
			this->panel5->TabIndex = 6;
			// 
			// Hide_pass
			// 
			this->Hide_pass->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Hide_pass->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Hide_pass.BackgroundImage")));
			this->Hide_pass->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Hide_pass->FlatAppearance->BorderSize = 0;
			this->Hide_pass->FlatAppearance->MouseDownBackColor = System::Drawing::Color::WhiteSmoke;
			this->Hide_pass->FlatAppearance->MouseOverBackColor = System::Drawing::Color::WhiteSmoke;
			this->Hide_pass->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Hide_pass->Location = System::Drawing::Point(376, 13);
			this->Hide_pass->Name = L"Hide_pass";
			this->Hide_pass->Size = System::Drawing::Size(35, 35);
			this->Hide_pass->TabIndex = 3;
			this->Hide_pass->UseVisualStyleBackColor = false;
			this->Hide_pass->Click += gcnew System::EventHandler(this, &MainForm::Hide_pass_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Enabled = false;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(9, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(35, 35);
			this->button4->TabIndex = 2;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// Show_pass
			// 
			this->Show_pass->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Show_pass->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Show_pass.BackgroundImage")));
			this->Show_pass->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Show_pass->FlatAppearance->BorderSize = 0;
			this->Show_pass->FlatAppearance->MouseDownBackColor = System::Drawing::Color::WhiteSmoke;
			this->Show_pass->FlatAppearance->MouseOverBackColor = System::Drawing::Color::WhiteSmoke;
			this->Show_pass->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Show_pass->Location = System::Drawing::Point(376, 12);
			this->Show_pass->Name = L"Show_pass";
			this->Show_pass->Size = System::Drawing::Size(35, 35);
			this->Show_pass->TabIndex = 1;
			this->Show_pass->UseVisualStyleBackColor = false;
			this->Show_pass->Click += gcnew System::EventHandler(this, &MainForm::Show_pass_Click);
			// 
			// Password
			// 
			this->Password->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->Password->Location = System::Drawing::Point(52, 17);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(318, 23);
			this->Password->TabIndex = 0;
			this->Password->Tag = L"Password";
			this->Password->Text = L"Password";
			this->Password->Click += gcnew System::EventHandler(this, &MainForm::Password_Click);
			this->Password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Password_KeyDown);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel6->Controls->Add(this->button5);
			this->panel6->Controls->Add(this->Username);
			this->panel6->Location = System::Drawing::Point(78, 263);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(424, 57);
			this->panel6->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Enabled = false;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(9, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(35, 35);
			this->button5->TabIndex = 3;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// Username
			// 
			this->Username->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->Username->Location = System::Drawing::Point(52, 17);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(318, 23);
			this->Username->TabIndex = 0;
			this->Username->Text = L"Username";
			this->Username->Click += gcnew System::EventHandler(this, &MainForm::Username_Click);
			this->Username->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Username_KeyDown);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label4->Location = System::Drawing::Point(74, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(523, 56);
			this->label4->TabIndex = 4;
			this->label4->Text = L"This is an Application That allow you to send Messages to your friends using thie"
				L"r ID";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Snap ITC", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label5->Location = System::Drawing::Point(100, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(312, 77);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Sign in ";
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->Register);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(408, 673);
			this->panel1->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(115, 91);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 143);
			this->button1->TabIndex = 21;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// Register
			// 
			this->Register->BackColor = System::Drawing::Color::Transparent;
			this->Register->FlatAppearance->BorderSize = 2;
			this->Register->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MediumTurquoise;
			this->Register->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MediumTurquoise;
			this->Register->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Register->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register->Location = System::Drawing::Point(134, 526);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(155, 55);
			this->Register->TabIndex = 3;
			this->Register->Text = L"Register";
			this->Register->UseVisualStyleBackColor = false;
			this->Register->Click += gcnew System::EventHandler(this, &MainForm::Register_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(85, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(204, 55);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sara7a";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1032, 673);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel4);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Sara7a";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::Password_KeyDown);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Sign_error2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Sign_error1))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Username_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			if (Username->Text->Length != 0 && Username->Text != "Username")
			{
				Sign_username_error->Hide();
				Sign_error1->Hide();
			}
			else
			{
				Sign_username_error->Show();
				Sign_error1->Show();
				Username->Text = "Username";
			}
			Password->UseSystemPasswordChar = true;
			Password->Clear();
			Password->Focus();
			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void Password_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			if (Password->Text->Length == 0 || Password->Text == "Password")
			{
				Sign_password_error->Show();
				Sign_error2->Show();
			}
			SignButton->PerformClick();
			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}
	
	private: System::Void SignButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (reg == 1) {
			load_data();
			reg = 0;
		}
		bool found = 0;
		if (Username->Text->Length == 0 || Username->Text == "Username") {
			Sign_username_error->Show();
			Sign_error1->Show();
		}
		else if (Password->Text->Length == 0 || Password->Text == "Password") {
			Sign_username_error->Hide();
			Sign_error1->Hide();
			Sign_password_error->Show();
			Sign_error2->Show();
		}
		else {
			this->Sign_username_error->Hide();
			this->Sign_password_error->Hide();
			this->Sign_error1->Hide();
			this->Sign_error2->Hide();
			this->SignIn_error->Hide();
			String^ pass;
			String^ id;
			for (pair<String^, String^>pr : users_pass) {
				Console::WriteLine(pr.first);
				Console::WriteLine(pr.second);
				Console::WriteLine(users_id[pr.first]);
				if (pr.first == Username->Text && pr.second == Password->Text) {
					UserForm^ userform = gcnew UserForm(this, Username->Text, Password->Text, users_id[pr.first], users_id);
					this->Hide();
					userform->Show();
					Username->Text = "Username";
					Password->Text = "Password";
					Password->UseSystemPasswordChar = false;
					found = 1;
				}
			}
			if(!found)
			{
				SignIn_error->Show();
			}
		}
	}
	private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {
		if (reg) {
			load_data();
			reg = 0;
		}
		Username->Text = "Username";
		Password->Text = "Password";
		Password->UseSystemPasswordChar = false;
		RegisterForm^ registerform = gcnew RegisterForm(this);
		this->Hide();
		registerform->Show();
		reg = 1;
	}
	
	private: System::Void Username_Click(System::Object^ sender, System::EventArgs^ e) { 
		if (Username->Text == "Username") {
			Username->Clear();
		}
		if (Password->Text->Length == 0 || Password->Text == "Password")
		{
			Password->Text = "Password";
			Password->UseSystemPasswordChar = false;
		}
		else {
			Sign_password_error->Hide();
			Sign_error2->Hide();
		}
	}
	private: System::Void Password_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Password->Text == "Password") {
			Password->Clear();
		}
		if (Username->Text->Length == 0 || Username->Text == "Username")
		{
			Username->Text = "Username";
			Sign_username_error->Show();
			Sign_error1->Show();
		}
		else {
			Sign_username_error->Hide();
			Sign_error1->Hide();
		}
		Password->UseSystemPasswordChar = true;
		this->Hide_pass->Show();
		this->Show_pass->Hide();
	}
	
	private: System::Void Show_pass_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide_pass->Show();
		this->Show_pass->Hide();
		Password->UseSystemPasswordChar = true;
	}
	private: System::Void Hide_pass_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Show_pass->Show();
		this->Hide_pass->Hide();
		Password->UseSystemPasswordChar = false;
	}
};
}
