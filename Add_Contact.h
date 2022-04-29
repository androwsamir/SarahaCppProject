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
	/// Summary for Add_Contact
	/// </summary>
	public ref class Add_Contact : public System::Windows::Forms::Form
	{
	private:
		Form^ userform;
		String^ username;
		String^ Contact_Name;
		long long ID;

		bool Check(long long id) {
			String^ filename = "check.txt";
			bool found = 0;
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				String^ contactname = "";
				String^ Id = "";
				String^ temp = "";
				while ((str = din->ReadLine()) != nullptr)
				{
					contactname = "";
					Id = "";
					temp = "";
					for (int i = 0; i < str->Length; i++) {
						if (str[i] != ' ') {
							contactname += str[i];
						}
						else {
							break;
						}
					}
					for (int i = str->Length - 1; i >= 0; i--) {
						if (str[i] != ' ') {
							Id += str[i];
						}
						else {
							break;
						}
					}
					for (int i = Id->Length - 1; i >= 0; i--) {
						temp += Id[i];
					}
					Id = temp;
					if (Id == System::Convert::ToString(id)) {
						Contact_Name = contactname;
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
			if (!found) {
				MessageBox::Show("Check username or ID");
			}
			return found;
		}
		void Add_User(long long id) {
			if (!Check(id)) {
				return;
			}
			String^ filename = "Data/";
			filename += this->username + "_" + System::Convert::ToString(ID) + "/contacts.txt";
			bool found = 0;
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				String^ contactname = "";
				while ((str = din->ReadLine()) != nullptr)
				{
					contactname = "";
					for (int i = 0; i < str->Length; i++) {
						if (str[i] != ' ') {
							contactname += str[i];
						}
						else {
							break;
						}
					}
					if (contactname == Contact_Name) {
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
				MessageBox::Show("This contact is already exist");
				return;
			}
			StreamWriter^ sw = gcnew StreamWriter(filename, true);
			sw->WriteLine(Contact_Name + " " + System::Convert::ToString(id));
			sw->Close();
			//load_contacts();
		}
	public:
		Add_Contact(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_Contact(Form^ userform, String^ username, long long ID)
		{
			this->userform = userform;
			this->username = username;
			this->ID = ID;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_Contact()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	protected:

	private: System::Windows::Forms::TextBox^ Contact_ID;

	private: System::Windows::Forms::Button^ Cancel_Button;
	private: System::Windows::Forms::Button^ Add2_Button;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Contact_ID = (gcnew System::Windows::Forms::TextBox());
			this->Cancel_Button = (gcnew System::Windows::Forms::Button());
			this->Add2_Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(30, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"ID";
			// 
			// Contact_ID
			// 
			this->Contact_ID->Location = System::Drawing::Point(75, 68);
			this->Contact_ID->Name = L"Contact_ID";
			this->Contact_ID->Size = System::Drawing::Size(167, 22);
			this->Contact_ID->TabIndex = 9;
			// 
			// Cancel_Button
			// 
			this->Cancel_Button->BackColor = System::Drawing::Color::Gray;
			this->Cancel_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Cancel_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_Button->Location = System::Drawing::Point(154, 143);
			this->Cancel_Button->Name = L"Cancel_Button";
			this->Cancel_Button->Size = System::Drawing::Size(88, 31);
			this->Cancel_Button->TabIndex = 7;
			this->Cancel_Button->Text = L"Cancel";
			this->Cancel_Button->UseVisualStyleBackColor = false;
			this->Cancel_Button->Click += gcnew System::EventHandler(this, &Add_Contact::Cancel_Button_Click);
			// 
			// Add2_Button
			// 
			this->Add2_Button->BackColor = System::Drawing::Color::Gray;
			this->Add2_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Add2_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add2_Button->Location = System::Drawing::Point(34, 143);
			this->Add2_Button->Name = L"Add2_Button";
			this->Add2_Button->Size = System::Drawing::Size(79, 31);
			this->Add2_Button->TabIndex = 6;
			this->Add2_Button->Text = L"Add";
			this->Add2_Button->UseVisualStyleBackColor = false;
			this->Add2_Button->Click += gcnew System::EventHandler(this, &Add_Contact::Add2_Button_Click);
			// 
			// Add_Contact
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(285, 221);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Contact_ID);
			this->Controls->Add(this->Cancel_Button);
			this->Controls->Add(this->Add2_Button);
			this->Location = System::Drawing::Point(10000, 1000);
			this->Name = L"Add_Contact";
			this->Text = L"Add_Contact";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancel_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void Add2_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Contact_ID->Text->Length != 0) {
			Add_User(System::Convert::ToInt32(Contact_ID->Text));
			this->Hide();
		}
	}
};
}
