#pragma once

#include<cliext/map>
#include<cliext/vector>
#include<cliext/queue>
#include<cliext/stack>
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
	using namespace cliext;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for UserForm
	/// </summary>
	public ref class UserForm : public System::Windows::Forms::Form
	{
	private:
		int i = 1;
		int x = 60;
		String^ name;
		bool this_contact = 0;
		String^ prev_name = "";
		Form^ mainform;
		long long ID = 0;
		map<String^, long long>Contacts;
		String^ username;
		String^ password;
		stack<String^> Messages;
		queue<String^> LifeChat;
		queue<String^> favoritemessage;
		void set_Messages_in_file() {
			   set_message_size();
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/message.txt";
			   StreamWriter^ sw = gcnew StreamWriter(filename, false);
			   while (!Messages.empty()) {
				   sw->WriteLine(Messages.top());
				   Messages.pop();
			   }
			   sw->Close();
		   }
		void set_FavoriteMessages_in_file() {
			   set_favoritemessage_size();
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/favoritemessage.txt";
			   StreamWriter^ sw = gcnew StreamWriter(filename, false);
			   while (!favoritemessage.empty()) {
				   sw->WriteLine(favoritemessage.front());
				   favoritemessage.pop();
			   }
			   sw->Close();
		   }
		void set_favoritemessage_size() {
			   queue<String^>temp;
			   //Console::WriteLine(favoritemessage.size());
			   while (!favoritemessage.empty()) {
				   if (favoritemessage.front() != nullptr) {
					   temp.push(favoritemessage.front());
					   favoritemessage.pop();
				   }
			   }
			   while (!temp.empty()) {
				   favoritemessage.push(temp.front());
				   temp.pop();
			   }
		   }
		void set_message_size() {
			   stack<String^>temp;
			   //Console::WriteLine(Messages.size());
			   while (!Messages.empty()) {
				   if (Messages.top() != nullptr) {
					   temp.push(Messages.top());
					   Messages.pop();
				   }
			   }
			   while (!temp.empty()) {
				   Messages.push(temp.top());
				   temp.pop();
			   }
		   }
		void set_message_size2() {
			   queue<String^>temp;
			   //Console::WriteLine(Messages.size());
			   while (!LifeChat.empty()) {
				   if (LifeChat.front() != nullptr) {
					   temp.push(LifeChat.front());
					   LifeChat.pop();
				   }
			   }
			   while (!temp.empty()) {
				   LifeChat.push(temp.front());
				   temp.pop();
			   }
		   }
		void load_messages() {
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/message.txt";
			   try {
				   Console::WriteLine("tying to open file", filename);
				   StreamReader^ din = File::OpenText(filename);
				   String^ str;
				   while ((str = din->ReadLine()) != nullptr)
				   {
					   Messages.push(str);
				   }
				   din->Close();
			   }
			   catch (Exception^ e) {
				   if (dynamic_cast<FileNotFoundException^>(e))
					   Console::WriteLine("file '{0}' not found", filename);
				   else
					   Console::WriteLine("problem reading file '{0}'", filename);
			   }
			   set_message_size();
		   }
		void load_messages(long long id) {
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/" + System::Convert::ToString(id) + ".txt";
			   try {
				   Console::WriteLine("tying to open file", filename);
				   StreamReader^ din = File::OpenText(filename);
				   String^ str;
				   while ((str = din->ReadLine()) != nullptr)
				   {
					   LifeChat.push(str);
				   }
				   din->Close();
			   }
			   catch (Exception^ e) {
				   if (dynamic_cast<FileNotFoundException^>(e))
					   Console::WriteLine("file '{0}' not found", filename);
				   else
					   Console::WriteLine("problem reading file '{0}'", filename);
			   }
			   set_message_size2();
			   Display_Chat();
		}
		void load_favorite() {
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/favoritemessage.txt";
			   try {
				   Console::WriteLine("tying to open file", filename);
				   StreamReader^ din = File::OpenText(filename);
				   String^ str;
				   while ((str = din->ReadLine()) != nullptr)
				   {
					   favoritemessage.push(str);
				   }
				   din->Close();
			   }
			   catch (Exception^ e) {
				   if (dynamic_cast<FileNotFoundException^>(e))
					   Console::WriteLine("file '{0}' not found", filename);
				   else
					   Console::WriteLine("problem reading file '{0}'", filename);
			   }
			   set_favoritemessage_size();
		   }
		void load_contacts() {
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/contacts.txt";
			   try {
				   Console::WriteLine("tying to open file", filename);
				   StreamReader^ din = File::OpenText(filename);
				   String^ str;
				   String^ contactname = "";
				   String^ contactid = "";
				   int c = 0;
				   while ((str = din->ReadLine()) != nullptr)
				   {
					   contactname = "";
					   contactid = "";
					   c = 0;
					   for (int i = 0; i < str->Length; i++) {
						   if (str[i] != ' ') {
							   contactname += str[i];
						   }
						   else {
							   c = i + 1;
							   break;
						   }
					   }
					   for (int i = c; i < str->Length; i++) {
						   if (str[i] != ' ') {
							   contactid += str[i];
						   }
						   else {
							   break;
						   }
					   }
					   Contacts[contactname] = System::Convert::ToInt32(contactid);
				   }
				   din->Close();
			   }
			   catch (Exception^ e) {
				   if (dynamic_cast<FileNotFoundException^>(e))
					   Console::WriteLine("file '{0}' not found", filename);
				   else
					   Console::WriteLine("problem reading file '{0}'", filename);
			   }
			   Display_Contacts();
		   }
		void Undo_last_message() {
			   Messages.pop();
			   set_Messages_in_file();
		   }
		void Put_Message_Favorite(String^ message) {
			   favoritemessage.push(message);
			   set_FavoriteMessages_in_file();
		   }
		void Remove_theOldest_Message() {
			   favoritemessage.pop();
			   set_FavoriteMessages_in_file();
		   }
		void Search_About_Contact(String^ username) {
			   if (Contacts.find(username) != Contacts.end()) {
				   Console::WriteLine(username + " " + Contacts[username]);
			   }
			   else {
				   MessageBox::Show("This contact doesn't exist");
			   }
		   }
		String^ Search_About_Contact_id(long long search_id) {
			for (pair<String^, long long>pr : Contacts) {
				if (search_id == pr.second)
				{
					return pr.first;
					break;
				}
			}
		}
		bool Check(String^ username, long long id) {
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
					   Console::WriteLine(contactname);
					   Console::WriteLine(Id);
					   if (contactname == username && Id == System::Convert::ToString(id)) {
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
		void Add_User(String^ username, long long id) {
			   if (!Check(username, id)) {
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
					   if (contactname == username) {
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
			   sw->WriteLine(username + " " + System::Convert::ToString(id));
			   sw->Close();
			   Add_panel->Hide();
			   load_contacts();
		   }
		void Display_Contacts() {
			   for (pair<String^, long long>pr : Contacts) {
				   String^ last_message = get_last_message(pr.first, System::Convert::ToString(Contacts[pr.first]));
				   Create_Contact(pr.first, last_message);
			   }
		   }
		void Display_Messages() {
			while (!Messages.empty())
			{
				Chat1->Items->Add(Messages.top());
				Messages.pop();
			}
			load_messages();
		}
		String^ get_last_message(String^ name, String^ id) {
			   String^ last_message;
			   String^ filename = "Data/";
			   filename += username + "_" + System::Convert::ToString(ID) + "/" + id + ".txt";
			   try {
				   Console::WriteLine("tying to open file", filename);
				   StreamReader^ din = File::OpenText(filename);
				   String^ str;
				   while ((str = din->ReadLine()) != nullptr)
				   {
					   last_message = "";
					   for (int i = 1; i < str->Length; i++) {
						   last_message += str[i];
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
			   return last_message;
		   }
		String^ get_username(long long id) {
			   for (pair<String^, long long>pr : Contacts) {
				   if (pr.second == id) {
					   return pr.first;
				   }
			   }
		   }
		long long get_id(String^ name) {
			return Contacts[name];
		}
		void Send_Message(String^ message, long long id) {
			   String^ user = get_username(id);
			   String^ filename = "Data/" + user + "_" + System::Convert::ToString(id) + "/" + System::Convert::ToString(ID) + ".txt";
			   String^ filename1 = "Data/" + username + "_" + System::Convert::ToString(ID) + "/" + System::Convert::ToString(id) + ".txt";
			   StreamWriter^ sw = gcnew StreamWriter(filename, true);
			   sw->WriteLine("2" + message);
			   sw->Close();
			   StreamWriter^ sw1 = gcnew StreamWriter(filename1, true);
			   sw1->WriteLine("1" + message);
			   sw1->Close();
			   Messages.push(message);
			   set_Messages_in_file();
		}
		void Display_Chat()
		{
			String^ msg = "";
			String^ msg2 = "";

			while (!LifeChat.empty())
			{
				msg = LifeChat.front();
				LifeChat.pop();
				msg2 = "";
				if (msg[0] == '2')
				{
					for (int i = 1; i < msg->Length; i++)
					{
						msg2 += msg[i];
					}
					Chat1->Items->Add(msg2);
					Chat2->Items->Add("");
				}
				else if (msg[0]=='1')
				{
					for (int i = 1; i < msg->Length; i++)
					{
						msg2 += msg[i];
					}
					Chat2->Items->Add(msg2);
					Chat1->Items->Add("");
				}
			}
		}
	private: System::Windows::Forms::ListBox^ Chat1;

	private: System::Windows::Forms::Panel^ Add_panel;

	private: System::Windows::Forms::Panel^ Menu2;
	private: System::Windows::Forms::Button^ Favorit_Button;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ Special_contact;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Contact_ID;

	private: System::Windows::Forms::TextBox^ Contact_Name;
	private: System::Windows::Forms::Button^ Cancel_Button;


	private: System::Windows::Forms::Button^ Add2_Button;
	private: System::Windows::Forms::ListBox^ Chat2;


	private: System::Windows::Forms::Button^ Search_button;
	private: System::Windows::Forms::TextBox^ Search;
	private: System::Windows::Forms::Button^ UnSearch_button;


	public:
		void Create_Contact(String^ name, String^ last_message) {
			String^ button_name = "Contact" + System::Convert::ToString(i);
			Button^ Contact = gcnew Button;
			Contact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			Contact->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			Contact->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			Contact->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			Contact->ForeColor = System::Drawing::Color::White;
			int y;
			y = 160 + x;
			x += 70;
			Contact->Location = System::Drawing::Point(3, y);
			Contact->Name = L"Contact" + System::Convert::ToString(i);
			Contact->Size = System::Drawing::Size(390, 60);
			Contact->TabIndex = 8;
			String^ text = name + "\n" + last_message;
			Contact->Text = text;
			Contact->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			Contact->UseVisualStyleBackColor = true;
			Contact->Click += gcnew System::EventHandler(this, &UserForm::Contact_Click);
			Controls->Add(Contact);
			i++;
		}

	public:
		UserForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		UserForm(Form^ mainform, String^ username, String^ password, String^ id)
		{
			this->username = username;
			this->password = password;
			for (int i = 0; i < id->Length; i++) {
				ID = 10 * ID + (id[i] - '0');
			}
			this->mainform = mainform;
			load_messages();
			load_favorite();
			load_contacts();
			InitializeComponent();
			this->UnSearch_button->Hide();
			this->Add_Button->Hide();
			this->Logout_Button->Hide();
			this->Star_Button->Hide();
			this->Back_Button->Hide();
			this->Star2_button->Hide();
			this->Add_panel->Hide();
			this->Menu2->Hide();
			this->button3->Hide();
			this->Special_contact->Enabled = false;
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ Menu;

	private: System::Windows::Forms::Label^ Chat_Name;
	private: System::Windows::Forms::TextBox^ Message;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ Star_Button;
	private: System::Windows::Forms::Button^ Logout_Button;

	private: System::Windows::Forms::Button^ Add_Button;
	private: System::Windows::Forms::Button^ Back_Button;
	private: System::Windows::Forms::Button^ Star2_button;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Menu2 = (gcnew System::Windows::Forms::Panel());
			this->Favorit_Button = (gcnew System::Windows::Forms::Button());
			this->Chat2 = (gcnew System::Windows::Forms::ListBox());
			this->Add_panel = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Contact_ID = (gcnew System::Windows::Forms::TextBox());
			this->Contact_Name = (gcnew System::Windows::Forms::TextBox());
			this->Cancel_Button = (gcnew System::Windows::Forms::Button());
			this->Add2_Button = (gcnew System::Windows::Forms::Button());
			this->Chat1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Message = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Star2_button = (gcnew System::Windows::Forms::Button());
			this->Back_Button = (gcnew System::Windows::Forms::Button());
			this->Star_Button = (gcnew System::Windows::Forms::Button());
			this->Logout_Button = (gcnew System::Windows::Forms::Button());
			this->Add_Button = (gcnew System::Windows::Forms::Button());
			this->Menu = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Chat_Name = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->Special_contact = (gcnew System::Windows::Forms::Button());
			this->UnSearch_button = (gcnew System::Windows::Forms::Button());
			this->Search_button = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->Menu2->SuspendLayout();
			this->Add_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->Menu2);
			this->panel1->Controls->Add(this->Chat2);
			this->panel1->Controls->Add(this->Add_panel);
			this->panel1->Controls->Add(this->Chat1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->Message);
			this->panel1->Location = System::Drawing::Point(396, 72);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(795, 602);
			this->panel1->TabIndex = 1;
			// 
			// Menu2
			// 
			this->Menu2->Controls->Add(this->Favorit_Button);
			this->Menu2->Location = System::Drawing::Point(616, 6);
			this->Menu2->Name = L"Menu2";
			this->Menu2->Size = System::Drawing::Size(128, 138);
			this->Menu2->TabIndex = 7;
			// 
			// Favorit_Button
			// 
			this->Favorit_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Favorit_Button->Location = System::Drawing::Point(4, 6);
			this->Favorit_Button->Name = L"Favorit_Button";
			this->Favorit_Button->Size = System::Drawing::Size(121, 42);
			this->Favorit_Button->TabIndex = 0;
			this->Favorit_Button->Text = L"Add To favorit";
			this->Favorit_Button->UseVisualStyleBackColor = true;
			this->Favorit_Button->Click += gcnew System::EventHandler(this, &UserForm::Favorit_Button_Click);
			// 
			// Chat2
			// 
			this->Chat2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chat2->FormattingEnabled = true;
			this->Chat2->ItemHeight = 29;
			this->Chat2->Location = System::Drawing::Point(393, 12);
			this->Chat2->Name = L"Chat2";
			this->Chat2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->Chat2->Size = System::Drawing::Size(385, 497);
			this->Chat2->TabIndex = 10;
			// 
			// Add_panel
			// 
			this->Add_panel->BackColor = System::Drawing::Color::Silver;
			this->Add_panel->Controls->Add(this->label3);
			this->Add_panel->Controls->Add(this->label4);
			this->Add_panel->Controls->Add(this->Contact_ID);
			this->Add_panel->Controls->Add(this->Contact_Name);
			this->Add_panel->Controls->Add(this->Cancel_Button);
			this->Add_panel->Controls->Add(this->Add2_Button);
			this->Add_panel->Location = System::Drawing::Point(21, 154);
			this->Add_panel->Name = L"Add_panel";
			this->Add_panel->Size = System::Drawing::Size(311, 194);
			this->Add_panel->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(44, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"ID";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(21, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Name";
			// 
			// Contact_ID
			// 
			this->Contact_ID->Location = System::Drawing::Point(95, 87);
			this->Contact_ID->Name = L"Contact_ID";
			this->Contact_ID->Size = System::Drawing::Size(167, 22);
			this->Contact_ID->TabIndex = 3;
			// 
			// Contact_Name
			// 
			this->Contact_Name->Location = System::Drawing::Point(95, 40);
			this->Contact_Name->Name = L"Contact_Name";
			this->Contact_Name->Size = System::Drawing::Size(167, 22);
			this->Contact_Name->TabIndex = 2;
			// 
			// Cancel_Button
			// 
			this->Cancel_Button->BackColor = System::Drawing::Color::Gray;
			this->Cancel_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Cancel_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_Button->Location = System::Drawing::Point(172, 143);
			this->Cancel_Button->Name = L"Cancel_Button";
			this->Cancel_Button->Size = System::Drawing::Size(75, 31);
			this->Cancel_Button->TabIndex = 1;
			this->Cancel_Button->Text = L"Cancel";
			this->Cancel_Button->UseVisualStyleBackColor = false;
			this->Cancel_Button->Click += gcnew System::EventHandler(this, &UserForm::Cancel_Button_Click);
			// 
			// Add2_Button
			// 
			this->Add2_Button->BackColor = System::Drawing::Color::Gray;
			this->Add2_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Add2_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add2_Button->Location = System::Drawing::Point(64, 143);
			this->Add2_Button->Name = L"Add2_Button";
			this->Add2_Button->Size = System::Drawing::Size(75, 31);
			this->Add2_Button->TabIndex = 0;
			this->Add2_Button->Text = L"Add";
			this->Add2_Button->UseVisualStyleBackColor = false;
			this->Add2_Button->Click += gcnew System::EventHandler(this, &UserForm::Add2_Button_Click);
			// 
			// Chat1
			// 
			this->Chat1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chat1->FormattingEnabled = true;
			this->Chat1->ItemHeight = 29;
			this->Chat1->Location = System::Drawing::Point(7, 12);
			this->Chat1->Name = L"Chat1";
			this->Chat1->Size = System::Drawing::Size(385, 497);
			this->Chat1->TabIndex = 9;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(719, 534);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 41);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &UserForm::button2_Click);
			// 
			// Message
			// 
			this->Message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Message->Location = System::Drawing::Point(7, 534);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(700, 41);
			this->Message->TabIndex = 0;
			this->Message->Text = L"Type text";
			this->Message->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserForm::Message_KeyDown);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->Star2_button);
			this->panel2->Controls->Add(this->Back_Button);
			this->panel2->Controls->Add(this->Star_Button);
			this->panel2->Controls->Add(this->Logout_Button);
			this->panel2->Controls->Add(this->Add_Button);
			this->panel2->Controls->Add(this->Menu);
			this->panel2->Location = System::Drawing::Point(0, -2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(397, 79);
			this->panel2->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(304, 17);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 51);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserForm::button3_Click);
			// 
			// Star2_button
			// 
			this->Star2_button->BackColor = System::Drawing::Color::Transparent;
			this->Star2_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Star2_button.BackgroundImage")));
			this->Star2_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Star2_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Star2_button->FlatAppearance->BorderSize = 0;
			this->Star2_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Star2_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Star2_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Star2_button->Location = System::Drawing::Point(89, 13);
			this->Star2_button->Name = L"Star2_button";
			this->Star2_button->Size = System::Drawing::Size(45, 51);
			this->Star2_button->TabIndex = 5;
			this->Star2_button->UseVisualStyleBackColor = false;
			this->Star2_button->Click += gcnew System::EventHandler(this, &UserForm::Star2_button_Click);
			// 
			// Back_Button
			// 
			this->Back_Button->BackColor = System::Drawing::Color::Transparent;
			this->Back_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Back_Button.BackgroundImage")));
			this->Back_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Back_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Back_Button->FlatAppearance->BorderSize = 0;
			this->Back_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Back_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Back_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Back_Button->Location = System::Drawing::Point(12, 20);
			this->Back_Button->Name = L"Back_Button";
			this->Back_Button->Size = System::Drawing::Size(44, 43);
			this->Back_Button->TabIndex = 4;
			this->Back_Button->UseVisualStyleBackColor = false;
			this->Back_Button->Click += gcnew System::EventHandler(this, &UserForm::Back_Button_Click);
			// 
			// Star_Button
			// 
			this->Star_Button->BackColor = System::Drawing::Color::Transparent;
			this->Star_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Star_Button.BackgroundImage")));
			this->Star_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Star_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Star_Button->FlatAppearance->BorderSize = 0;
			this->Star_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Star_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Star_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Star_Button->Location = System::Drawing::Point(89, 13);
			this->Star_Button->Name = L"Star_Button";
			this->Star_Button->Size = System::Drawing::Size(45, 51);
			this->Star_Button->TabIndex = 3;
			this->Star_Button->UseVisualStyleBackColor = false;
			this->Star_Button->Click += gcnew System::EventHandler(this, &UserForm::Star_Button_Click);
			// 
			// Logout_Button
			// 
			this->Logout_Button->BackColor = System::Drawing::Color::Transparent;
			this->Logout_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logout_Button.BackgroundImage")));
			this->Logout_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Logout_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Logout_Button->FlatAppearance->BorderSize = 0;
			this->Logout_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Logout_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Logout_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Logout_Button->Location = System::Drawing::Point(164, 17);
			this->Logout_Button->Name = L"Logout_Button";
			this->Logout_Button->Size = System::Drawing::Size(45, 51);
			this->Logout_Button->TabIndex = 2;
			this->Logout_Button->UseVisualStyleBackColor = false;
			this->Logout_Button->Click += gcnew System::EventHandler(this, &UserForm::Logout_Button_Click);
			// 
			// Add_Button
			// 
			this->Add_Button->BackColor = System::Drawing::Color::Transparent;
			this->Add_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Add_Button.BackgroundImage")));
			this->Add_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Add_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Add_Button->FlatAppearance->BorderSize = 0;
			this->Add_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Add_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Add_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add_Button->ForeColor = System::Drawing::Color::Transparent;
			this->Add_Button->Location = System::Drawing::Point(232, 13);
			this->Add_Button->Name = L"Add_Button";
			this->Add_Button->Size = System::Drawing::Size(45, 51);
			this->Add_Button->TabIndex = 1;
			this->Add_Button->UseVisualStyleBackColor = false;
			this->Add_Button->Click += gcnew System::EventHandler(this, &UserForm::Add_Button_Click);
			// 
			// Menu
			// 
			this->Menu->BackColor = System::Drawing::Color::Transparent;
			this->Menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Menu.BackgroundImage")));
			this->Menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Menu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Menu->FlatAppearance->BorderSize = 0;
			this->Menu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->Menu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->Menu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Menu->Location = System::Drawing::Point(12, 20);
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(44, 43);
			this->Menu->TabIndex = 0;
			this->Menu->UseVisualStyleBackColor = false;
			this->Menu->Click += gcnew System::EventHandler(this, &UserForm::Menu_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->Chat_Name);
			this->panel3->Location = System::Drawing::Point(396, -2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(795, 79);
			this->panel3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MidnightBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(734, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(44, 43);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserForm::button1_Click);
			// 
			// Chat_Name
			// 
			this->Chat_Name->AutoSize = true;
			this->Chat_Name->BackColor = System::Drawing::Color::MidnightBlue;
			this->Chat_Name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chat_Name->ForeColor = System::Drawing::Color::White;
			this->Chat_Name->Location = System::Drawing::Point(44, 20);
			this->Chat_Name->Name = L"Chat_Name";
			this->Chat_Name->Size = System::Drawing::Size(196, 32);
			this->Chat_Name->TabIndex = 0;
			this->Chat_Name->Text = L"Saif Al Eslam";
			// 
			// panel4
			// 
			this->panel4->AutoScroll = true;
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->Special_contact);
			this->panel4->Controls->Add(this->UnSearch_button);
			this->panel4->Controls->Add(this->Search_button);
			this->panel4->Controls->Add(this->Search);
			this->panel4->Location = System::Drawing::Point(0, 75);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(397, 599);
			this->panel4->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Silver;
			this->panel5->Location = System::Drawing::Point(3, 121);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(394, 6);
			this->panel5->TabIndex = 8;
			// 
			// Special_contact
			// 
			this->Special_contact->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->Special_contact->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Special_contact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Special_contact->ForeColor = System::Drawing::Color::White;
			this->Special_contact->Location = System::Drawing::Point(3, 50);
			this->Special_contact->Name = L"Special_contact";
			this->Special_contact->Size = System::Drawing::Size(391, 57);
			this->Special_contact->TabIndex = 1;
			this->Special_contact->Text = L"Search contact";
			this->Special_contact->UseVisualStyleBackColor = false;
			this->Special_contact->Click += gcnew System::EventHandler(this, &UserForm::Special_contact_Click);
			
			// 
			// UnSearch_button
			// 
			this->UnSearch_button->BackColor = System::Drawing::Color::Transparent;
			this->UnSearch_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UnSearch_button.BackgroundImage")));
			this->UnSearch_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UnSearch_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnSearch_button->FlatAppearance->BorderSize = 0;
			this->UnSearch_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->UnSearch_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->UnSearch_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UnSearch_button->Location = System::Drawing::Point(3, 3);
			this->UnSearch_button->Name = L"UnSearch_button";
			this->UnSearch_button->Size = System::Drawing::Size(32, 31);
			this->UnSearch_button->TabIndex = 7;
			this->UnSearch_button->UseVisualStyleBackColor = false;
			this->UnSearch_button->Click += gcnew System::EventHandler(this, &UserForm::UnSearch_button_Click);
			// 
			// Search_button
			// 
			this->Search_button->BackColor = System::Drawing::Color::Transparent;
			this->Search_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Search_button.BackgroundImage")));
			this->Search_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Search_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Search_button->FlatAppearance->BorderSize = 0;
			this->Search_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Search_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Search_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Search_button->Location = System::Drawing::Point(3, 3);
			this->Search_button->Name = L"Search_button";
			this->Search_button->Size = System::Drawing::Size(32, 31);
			this->Search_button->TabIndex = 6;
			this->Search_button->UseVisualStyleBackColor = false;
			this->Search_button->Click += gcnew System::EventHandler(this, &UserForm::Search_button_Click);
			// 
			// Search
			// 
			this->Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Search->Location = System::Drawing::Point(41, 0);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(356, 34);
			this->Search->TabIndex = 0;
			this->Search->Text = L"Search for a contact";
			this->Search->TextChanged += gcnew System::EventHandler(this, &UserForm::Search_TextChanged);
			this->Search->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserForm::Search_KeyDown);
			// 
			// UserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1186, 673);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"UserForm";
			this->Text = L"UserForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->Menu2->ResumeLayout(false);
			this->Add_panel->ResumeLayout(false);
			this->Add_panel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	

	private: System::Void Logout_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainform->Show();
	}
	private: System::Void Star_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Star_Button->Hide();
		Star2_button->Show();
		Chat1->Items->Clear();
		Chat2->Items->Clear();
		while (!favoritemessage.empty())
		{
			Chat1->Items->Add(favoritemessage.front());
			favoritemessage.pop();
		}
		load_favorite();
		name = "";
	}
	private: System::Void Back_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Logout_Button->Hide();
		Back_Button->Hide();
		Add_Button->Hide();
		Star_Button->Hide();
		Star2_button->Hide();
		button3->Hide();
	}
	private: System::Void Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		Back_Button->Show();
		Logout_Button->Show();
		Add_Button->Show();
		Star_Button->Show();
		button3->Show();
	}
	private: System::Void Contact_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ this_Button = (Button^)sender;
		name = "";
		for (int i = 0; i < this_Button->Text->Length; i++) {
			if (this_Button->Text[i] != '\n') {
				name += this_Button->Text[i];
			}
			else { break; }
		}
		Chat_Name->Text = name;
		if (prev_name == name) {
			//continue;
		}
		else {
			prev_name = name;
			Chat1->Items->Clear();
			Chat2->Items->Clear();
			long long id = get_id(name);
			load_messages(id);
			Message->Focus();
		}
	}
	private: System::Void Star2_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Star2_button->Hide();
		Star_Button->Show();
		Chat1->Items->Clear();
		Chat2->Items->Clear();
	}
	private: System::Void Search_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Search_button->Hide();
		//UnSearch_button->Show();
		long long search_id = System::Convert::ToInt32(Search->Text);
		Search->Text = "";
		
		Special_contact->Text = Search_About_Contact_id(search_id);

	}
	private: System::Void Search_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//Search_button->Hide();
		UnSearch_button->Hide();

	}
	private: System::Void UnSearch_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Search_button->Show();
		UnSearch_button->Hide();
		Search->Clear();
	}
	private: System::Void Add_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Add_panel->Show();
	}
	private: System::Void Cancel_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Add_panel->Hide();
	}
	private: System::Void Add2_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Add_User(Contact_Name->Text, System::Convert::ToInt32(Contact_ID->Text));
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ msg = Message->Text;
		Chat2->Items->Add(msg);
		Chat1->Items->Add("");
		Send_Message(msg, get_id(name));
		Message->Clear();
		Message->Focus();
	}		  
	private: System::Void Message_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	   if (e->KeyCode == Keys::Enter)
	   {
		   button2->PerformClick();
	   }
	   Special_contact->Enabled = true;
	}
    public: Boolean Menu2_hide = true;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Menu2_hide) {
			Menu2->Show();
			Menu2_hide = false;
		}
		else
		{
			Menu2->Hide();
			Menu2_hide = true;

		}
	}
	private: System::Void Favorit_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		//favoritemessage= Chat1->SelectedItem->ToString();
	}
	//String^ FavMessage="";
	//String^ FavMessage2="";
	//if (Chat2->SelectedItems->Count > 0) {
	//	FavMessage2 = Chat2->SelectedItem->ToString();
	//	Put_Message_Favorite(FavMessage2);
	//	Console::WriteLine(FavMessage2);
	//}
	//if (Chat1->SelectedItems->Count > 0) {
	//	FavMessage = Chat1->SelectedItem->ToString();
	//	Put_Message_Favorite(FavMessage);
	//	Console::WriteLine(FavMessage);
	//}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Chat1->Items->Clear();
		Chat2->Items->Clear();
		Chat_Name->Text = "Sent Messages";
		name = "";
		Display_Messages();
	}
	private: System::Void Special_contact_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Search_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			Search_button->PerformClick();
		}
	}
};
}