#pragma once
#using <system.dll>
#include<cliext/hash_map>
#include<cliext/map>

namespace BlueSara7a {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace cliext;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Add_Contact
	/// </summary>
	public ref class Add_Contact : public System::Windows::Forms::Form
	{
	private:
		String^ username;
		String^ Contact_Name;
		long long ID;
		map<String^, long long>Contacts;
	private: System::Windows::Forms::Button^ button1;
		   hash_map<String^, String^> users_id;

		bool Check(long long id) {
			bool found = 0;
			for (pair<String^, String^>pr : users_id) {
				if (pr.second == System::Convert::ToString(id)) {
					Contact_Name = pr.first;
					found = 1;
					break;
				}
			}
			return found;
		}
		void Add_User(long long id) {
			if (!Check(id)) {
				MessageBox::Show("Invalid ID!");
			}
			else {
				String^ filename = "Data/";
				filename += username + "_" + System::Convert::ToString(ID) + "/contacts.txt";
				long long Id = Contacts[Contact_Name];
				if (System::Convert::ToString(Id)->Length > 1) {
					MessageBox::Show("This contact already exists");
				}
				else {
					StreamWriter^ sw = gcnew StreamWriter(filename, true);
					sw->WriteLine(Contact_Name + " " + System::Convert::ToString(id));
					sw->Close();
					this->Hide();
				}
			}
		}
	public:
		Add_Contact(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Add_Contact(String^ username, long long ID, hash_map<String^, String^> users_id, map<String^, long long>Contacts)
		{
			this->Contacts = Contacts;
			this->users_id = users_id;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add_Contact::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Contact_ID = (gcnew System::Windows::Forms::TextBox());
			this->Cancel_Button = (gcnew System::Windows::Forms::Button());
			this->Add2_Button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label3->Location = System::Drawing::Point(30, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"ID";
			// 
			// Contact_ID
			// 
			this->Contact_ID->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contact_ID->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->Contact_ID->Location = System::Drawing::Point(75, 82);
			this->Contact_ID->Name = L"Contact_ID";
			this->Contact_ID->Size = System::Drawing::Size(167, 27);
			this->Contact_ID->TabIndex = 9;
			// 
			// Cancel_Button
			// 
			this->Cancel_Button->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Cancel_Button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Cancel_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MediumTurquoise;
			this->Cancel_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MediumTurquoise;
			this->Cancel_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Cancel_Button->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_Button->ForeColor = System::Drawing::SystemColors::ControlLight;
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
			this->Add2_Button->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Add2_Button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Add2_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MediumTurquoise;
			this->Add2_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MediumTurquoise;
			this->Add2_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add2_Button->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add2_Button->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Add2_Button->Location = System::Drawing::Point(34, 143);
			this->Add2_Button->Name = L"Add2_Button";
			this->Add2_Button->Size = System::Drawing::Size(79, 31);
			this->Add2_Button->TabIndex = 6;
			this->Add2_Button->Text = L"Add";
			this->Add2_Button->UseVisualStyleBackColor = false;
			this->Add2_Button->Click += gcnew System::EventHandler(this, &Add_Contact::Add2_Button_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(3, -4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(76, 90);
			this->button1->TabIndex = 12;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// Add_Contact
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(290, 221);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Contact_ID);
			this->Controls->Add(this->Cancel_Button);
			this->Controls->Add(this->Add2_Button);
			this->HelpButton = true;
			this->Location = System::Drawing::Point(10000, 1000);
			this->Name = L"Add_Contact";
			this->ShowIcon = false;
			this->Text = L"Add_Contact";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancel_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void Add2_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Contact_ID->Text->Length == 9) {
			Add_User(System::Convert::ToInt32(Contact_ID->Text));
		}
		else {
			MessageBox::Show("Invalid ID!");
		}
	}
};
}
