#pragma once
#using <system.dll>

namespace BlueSara7a {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	private:
		int ID = 202016999;
		Form^ mainform;

	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		RegisterForm(Form^ mainform)
		{
			this->mainform = mainform;
			InitializeComponent();
			this->error1->Hide();
			this->error2->Hide();
			this->error3->Hide();
			this->Username_error->Hide();
			this->Password_error->Hide();
			this->Confirm_error->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ password2;
	private: System::Windows::Forms::Button^ RegisterButton;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ error3;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::PictureBox^ error2;

	private: System::Windows::Forms::PictureBox^ error1;
	private: System::Windows::Forms::Label^ Confirm_error;
	private: System::Windows::Forms::Label^ Password_error;
	private: System::Windows::Forms::Label^ Username_error;
	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Back;
	private: System::Windows::Forms::Label^ label5;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->Back = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->error3 = (gcnew System::Windows::Forms::PictureBox());
			this->error2 = (gcnew System::Windows::Forms::PictureBox());
			this->error1 = (gcnew System::Windows::Forms::PictureBox());
			this->Confirm_error = (gcnew System::Windows::Forms::Label());
			this->Password_error = (gcnew System::Windows::Forms::Label());
			this->Username_error = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->password2 = (gcnew System::Windows::Forms::TextBox());
			this->RegisterButton = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error1))->BeginInit();
			this->panel8->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->Back);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(408, 673);
			this->panel4->TabIndex = 19;
			// 
			// Back
			// 
			this->Back->BackColor = System::Drawing::Color::Transparent;
			this->Back->FlatAppearance->BorderColor = System::Drawing::Color::Azure;
			this->Back->FlatAppearance->BorderSize = 2;
			this->Back->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MediumTurquoise;
			this->Back->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MediumTurquoise;
			this->Back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Back->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back->Location = System::Drawing::Point(134, 526);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(155, 55);
			this->Back->TabIndex = 3;
			this->Back->Text = L"Sign in";
			this->Back->UseVisualStyleBackColor = false;
			this->Back->Click += gcnew System::EventHandler(this, &RegisterForm::Back_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Snap ITC", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(85, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(204, 55);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Sara7a";
			// 
			// panel5
			// 
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->error3);
			this->panel5->Controls->Add(this->error2);
			this->panel5->Controls->Add(this->error1);
			this->panel5->Controls->Add(this->Confirm_error);
			this->panel5->Controls->Add(this->Password_error);
			this->panel5->Controls->Add(this->Username_error);
			this->panel5->Controls->Add(this->panel8);
			this->panel5->Controls->Add(this->RegisterButton);
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->panel7);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Location = System::Drawing::Point(402, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(631, 673);
			this->panel5->TabIndex = 20;
			// 
			// error3
			// 
			this->error3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error3.BackgroundImage")));
			this->error3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error3.Image")));
			this->error3->Location = System::Drawing::Point(533, 463);
			this->error3->Name = L"error3";
			this->error3->Size = System::Drawing::Size(41, 40);
			this->error3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->error3->TabIndex = 13;
			this->error3->TabStop = false;
			// 
			// error2
			// 
			this->error2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error2.BackgroundImage")));
			this->error2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error2.Image")));
			this->error2->Location = System::Drawing::Point(533, 369);
			this->error2->Name = L"error2";
			this->error2->Size = System::Drawing::Size(41, 40);
			this->error2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->error2->TabIndex = 12;
			this->error2->TabStop = false;
			// 
			// error1
			// 
			this->error1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error1.BackgroundImage")));
			this->error1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error1.Image")));
			this->error1->Location = System::Drawing::Point(533, 270);
			this->error1->Name = L"error1";
			this->error1->Size = System::Drawing::Size(41, 40);
			this->error1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->error1->TabIndex = 11;
			this->error1->TabStop = false;
			// 
			// Confirm_error
			// 
			this->Confirm_error->AutoSize = true;
			this->Confirm_error->ForeColor = System::Drawing::Color::DarkRed;
			this->Confirm_error->Location = System::Drawing::Point(84, 516);
			this->Confirm_error->Name = L"Confirm_error";
			this->Confirm_error->Size = System::Drawing::Size(195, 16);
			this->Confirm_error->TabIndex = 10;
			this->Confirm_error->Text = L"*The password is not the same*";
			// 
			// Password_error
			// 
			this->Password_error->AutoSize = true;
			this->Password_error->ForeColor = System::Drawing::Color::DarkRed;
			this->Password_error->Location = System::Drawing::Point(84, 422);
			this->Password_error->Name = L"Password_error";
			this->Password_error->Size = System::Drawing::Size(119, 16);
			this->Password_error->TabIndex = 9;
			this->Password_error->Text = L"*Invalid Password*";
			// 
			// Username_error
			// 
			this->Username_error->AutoSize = true;
			this->Username_error->ForeColor = System::Drawing::Color::DarkRed;
			this->Username_error->Location = System::Drawing::Point(84, 323);
			this->Username_error->Name = L"Username_error";
			this->Username_error->Size = System::Drawing::Size(122, 16);
			this->Username_error->TabIndex = 8;
			this->Username_error->Text = L"*Invalid Username*";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel8->Controls->Add(this->button1);
			this->panel8->Controls->Add(this->password2);
			this->panel8->Location = System::Drawing::Point(78, 456);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(424, 57);
			this->panel8->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(9, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(35, 35);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// password2
			// 
			this->password2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->password2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->password2->Location = System::Drawing::Point(52, 21);
			this->password2->Name = L"password2";
			this->password2->Size = System::Drawing::Size(318, 23);
			this->password2->TabIndex = 0;
			this->password2->Tag = L"Password";
			this->password2->Text = L"Confirm Password";
			this->password2->Click += gcnew System::EventHandler(this, &RegisterForm::password2_Click);
			this->password2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::password2_KeyDown);
			// 
			// RegisterButton
			// 
			this->RegisterButton->BackColor = System::Drawing::Color::LightSeaGreen;
			this->RegisterButton->FlatAppearance->BorderColor = System::Drawing::Color::LightSeaGreen;
			this->RegisterButton->FlatAppearance->BorderSize = 2;
			this->RegisterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RegisterButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->RegisterButton->Location = System::Drawing::Point(87, 549);
			this->RegisterButton->Name = L"RegisterButton";
			this->RegisterButton->Size = System::Drawing::Size(402, 55);
			this->RegisterButton->TabIndex = 4;
			this->RegisterButton->Text = L"Register";
			this->RegisterButton->UseVisualStyleBackColor = false;
			this->RegisterButton->Click += gcnew System::EventHandler(this, &RegisterForm::RegisterButton_Click);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel6->Controls->Add(this->button4);
			this->panel6->Controls->Add(this->Password);
			this->panel6->Location = System::Drawing::Point(78, 362);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(424, 57);
			this->panel6->TabIndex = 6;
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
			// Password
			// 
			this->Password->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->Password->Location = System::Drawing::Point(52, 21);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(318, 23);
			this->Password->TabIndex = 0;
			this->Password->Tag = L"Password";
			this->Password->Text = L"Password";
			this->Password->Click += gcnew System::EventHandler(this, &RegisterForm::Password_Click);
			this->Password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::Password_KeyDown);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel7->Controls->Add(this->button5);
			this->panel7->Controls->Add(this->Username);
			this->panel7->Location = System::Drawing::Point(78, 263);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(424, 57);
			this->panel7->TabIndex = 5;
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
			this->Username->Click += gcnew System::EventHandler(this, &RegisterForm::Username_Click);
			this->Username->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::Username_KeyDown);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label4->Location = System::Drawing::Point(74, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(523, 60);
			this->label4->TabIndex = 4;
			this->label4->Text = L"This is an Application That allow you to send Messages to your friends using thie"
				L"r ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Snap ITC", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label3->Location = System::Drawing::Point(100, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(341, 77);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Register";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Enabled = false;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(113, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 152);
			this->button2->TabIndex = 9;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1032, 673);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RegisterForm";
			this->ShowIcon = false;
			this->Text = L"RegisterForm";
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error1))->EndInit();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void Username_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			if (Username->Text->Length != 0 && Username->Text != "Username")
			{
				Username_error->Hide();
				error1->Hide();
			}
			else
			{
				Username_error->Show();
				error1->Show();
				Username->Text = "Username";
			}
			Password->Focus();
		}
		
	}
	private: System::Void Password_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			if (Password->Text->Length == 8 && Password->Text != "Password")
			{
				Password_error->Hide();
				error2->Hide();
			}	
			else
			{
				Password_error->Show();
				error2->Show();
				Password->Text = "Password";
			}
			password2->Focus();
		}
	}
	private: System::Void password2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			if (password2->Text != Password->Text || password2->Text == "Confirm Password")
			{
				Confirm_error->Show();
				error3->Show();
			}
			RegisterButton->PerformClick();
		}
	}
	
	private: System::Void Back_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainform->Show();
	}
	private: System::Void RegisterButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filename = "check.txt";
		String^ user;
		String^ id;
		String^ temp;
		bool found = 0;
		int Id = 0;
		int c = 0;
		if (Username->Text->Length == 0 || Username->Text == "Username") {
			Username_error->Show();
			error1->Show();
		}
		else if (Password->Text->Length == 0 || Password->Text->Length != 8 || Password->Text == "Password")
		{
			Username_error->Hide();
			error1->Hide();
			Password_error->Show();
			error2->Show();
		}
		else if (password2->Text != Password->Text) {
			Password_error->Hide();
			error2->Hide();
			Confirm_error->Show();
			error3->Show();
		}
		else {
			this->error1->Hide();
			this->error2->Hide();
			this->error3->Hide();
			this->Username_error->Hide();
			this->Password_error->Hide();
			this->Confirm_error->Hide();
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				StreamReader^ din2 = File::OpenText(filename);
				String^ str;
				while ((str = din->ReadLine()) != nullptr)
				{
					user = "";
					for (int i = 0; i < str->Length; i++) {
						if (str[i] != ' ') {
							user += str[i];
						}
						else {
							break;
						}
					}
					if (user == Username->Text) {
						found = 1;
						break;
					}
				}
				din->Close();
				while ((str = din2->ReadLine()) != nullptr)
				{
					id = "";
					for (int i = str->Length - 1; i >= 0; i--) {
						if (str[i] != ' ') {
							id += str[i];
						}
						else {
							break;
						}
					}

				}
				din2->Close();
				if (id != nullptr) {
					for (int i = id->Length - 1; i >= 0; i--) {
						temp += id[i];
					}
					id = temp;
					for (int i = 0; i < id->Length; i++) {
						Id = Id * 10 + (id[i] - '0');
					}
				}
				Id++;
				if (Id == 1) {
					ID++;
				}
				else {
					ID = Id;
				}
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
			if (found) {
				MessageBox::Show("This username is already in use");
			}
			else {
				StreamWriter^ sw = gcnew StreamWriter(filename, true);
				String^ data = Username->Text + " " + Password->Text + " " + System::Convert::ToString(ID);
				String^ directory = "Data/" + Username->Text + "_" + System::Convert::ToString(ID);
				sw->WriteLine(data);
				sw->Close();
				Directory^ dic;
				dic->CreateDirectory(directory);
				String^ Contacts = directory + "/contacts.txt";
				String^ Messages = directory + "/message.txt";
				String^ FavoriteMessages = directory + "/favoritemessage.txt";
				StreamWriter^ sw1 = gcnew StreamWriter(Contacts, true);
				sw1->Close();
				StreamWriter^ sw2 = gcnew StreamWriter(Messages, true);
				sw2->Close();
				StreamWriter^ sw3 = gcnew StreamWriter(FavoriteMessages, true);
				sw3->Close();
				this->Hide();
				mainform->Show();
			}
		}
	}
	private: System::Void Username_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Username->Text == "Username") {
			Username->Clear();
		}
		if (Password->Text->Length == 0)
		{
			Password->Text = "Password";
		}
		if (password2->Text->Length == 0)
		{
			password2->Text = "Confirm Password";
		}
	}
	private: System::Void Password_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Password->Text == "Password") {
			Password->Clear();
		}
		if (Username->Text->Length == 0)
		{
			Username->Text = "Username";
		}
		if (password2->Text->Length == 0)
		{
			password2->Text = "Confirm Password";
		}
		if (Username->Text->Length != 0 && Username->Text != "Username")
		{
			Username_error->Hide();
			error1->Hide();
		}
		else {
			Username_error->Show();
			error1->Show();
		}
	}
	private: System::Void password2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password2->Text == "Confirm Password") {
			password2->Clear();
		}
		if (Username->Text->Length == 0)
		{
			Username->Text = "Username";
		}
		if (Password->Text->Length == 0)
		{
			Password->Text = "Password";
		}
		if (Username->Text == "Username")
		{
			Username_error->Show();
			error1->Show();
		}
		if (Password->Text->Length == 8 && Password->Text != "Password")
		{
			Password_error->Hide();
			error2->Hide();
		}
		else 
		{
			Password_error->Show();
			error2->Show();
		}
	}
};
}
