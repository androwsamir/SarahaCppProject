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
	public:
		int ID = 202016999;
		Form^ mainform;
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
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ Password;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ password2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ RegisterButtun;
	private: System::Windows::Forms::Button^ Back;
	private: System::Windows::Forms::Label^ checklabel;
	private: System::Windows::Forms::CheckBox^ checkBox1;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->password2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RegisterButtun = (gcnew System::Windows::Forms::Button());
			this->Back = (gcnew System::Windows::Forms::Button());
			this->checklabel = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(126, 250);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(344, 2);
			this->panel1->TabIndex = 8;
			// 
			// Username
			// 
			this->Username->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->Username->Location = System::Drawing::Point(126, 221);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(344, 23);
			this->Username->TabIndex = 7;
			this->Username->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::Username_KeyDown);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(122, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"User name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(114, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 69);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Sign in ";
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(126, 355);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(344, 2);
			this->panel2->TabIndex = 11;
			// 
			// Password
			// 
			this->Password->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->Password->Location = System::Drawing::Point(126, 326);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(344, 23);
			this->Password->TabIndex = 10;
			this->Password->UseSystemPasswordChar = true;
			this->Password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::Password_KeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(122, 282);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Password";
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(126, 469);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(344, 2);
			this->panel3->TabIndex = 14;
			// 
			// password2
			// 
			this->password2->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->password2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->password2->Location = System::Drawing::Point(126, 440);
			this->password2->Name = L"password2";
			this->password2->Size = System::Drawing::Size(344, 23);
			this->password2->TabIndex = 13;
			this->password2->UseSystemPasswordChar = true;
			//this->password2->TextChanged += gcnew System::EventHandler(this, &RegisterForm::password2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(122, 396);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(187, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Re enter your password";
			// 
			// RegisterButtun
			// 
			this->RegisterButtun->BackColor = System::Drawing::Color::RoyalBlue;
			this->RegisterButtun->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->RegisterButtun->FlatAppearance->BorderSize = 0;
			this->RegisterButtun->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSlateGray;
			this->RegisterButtun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RegisterButtun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterButtun->Location = System::Drawing::Point(126, 571);
			this->RegisterButtun->Name = L"RegisterButtun";
			this->RegisterButtun->Size = System::Drawing::Size(140, 44);
			this->RegisterButtun->TabIndex = 15;
			this->RegisterButtun->Text = L"Register";
			this->RegisterButtun->UseVisualStyleBackColor = false;
			this->RegisterButtun->Click += gcnew System::EventHandler(this, &RegisterForm::RegisterButtun_Click);
			// 
			// Back
			// 
			this->Back->BackColor = System::Drawing::Color::Black;
			this->Back->FlatAppearance->BorderColor = System::Drawing::Color::CornflowerBlue;
			this->Back->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSteelBlue;
			this->Back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back->ForeColor = System::Drawing::Color::RoyalBlue;
			this->Back->Location = System::Drawing::Point(305, 571);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(140, 44);
			this->Back->TabIndex = 16;
			this->Back->Text = L"Back";
			this->Back->UseVisualStyleBackColor = false;
			this->Back->Click += gcnew System::EventHandler(this, &RegisterForm::Back_Click);
			// 
			// checklabel
			// 
			this->checklabel->AutoSize = true;
			this->checklabel->BackColor = System::Drawing::Color::Transparent;
			this->checklabel->ForeColor = System::Drawing::Color::Blue;
			this->checklabel->Location = System::Drawing::Point(229, 498);
			this->checklabel->Name = L"checklabel";
			this->checklabel->Size = System::Drawing::Size(130, 16);
			this->checklabel->TabIndex = 18;
			this->checklabel->Text = L"terms and conditions";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(126, 498);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(110, 20);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"I Agree to the ";
			this->checkBox1->UseVisualStyleBackColor = false;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1186, 673);
			this->Controls->Add(this->checklabel);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Back);
			this->Controls->Add(this->RegisterButtun);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->password2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
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
			password2->Focus();
		}
	}
	private: System::Void Back_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainform->Show();
	}
	private: System::Void RegisterButtun_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filename = "check.txt";
		String^ user;
		String^ id;
		String^ temp;
		bool found = 0;
		int c = 0;
		if (Username->Text->Length == 0) {
			MessageBox::Show("username is empty");
			return;
		}
		if (Password->Text->Length == 0) {
			MessageBox::Show("password is empty");
			return;
		}
		if (password2->Text != Password->Text) {
			MessageBox::Show("Check confirm password");
			return;
		}
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
			for (int i = id->Length - 1; i >= 0; i--) {
				temp += id[i];
			}
			id = temp;
			int Id = 0;
			for (int i = 0; i < id->Length; i++) {
				Id = Id * 10 + (id[i] - '0');
			}
			Id++;
			if (Id == 1) {
				ID++;
			}
			else {
				ID = Id;
			}
			din2->Close();
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
			StreamWriter^ sw = gcnew StreamWriter(filename,true);
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
};
}
