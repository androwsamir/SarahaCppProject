#pragma once

#include<cliext/map>
#include<cliext/vector>
#include<cliext/queue>
#include<cliext/stack>
#include<cliext/hash_map>
#using <system.dll>
#include "Add_Contact.h"
#include <sstream>


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
	using namespace System::Speech;
	using namespace System::Speech::Synthesis;
	using namespace System::Speech::Recognition;

	/// <summary>
	/// Summary for UserForm
	/// </summary>
	public ref class UserForm : public System::Windows::Forms::Form
	{
	private:
		int i = 1;
		int x = 10;
		bool said = 0;
		bool show_info = 0;
		hash_map<String^, String^> users_id;
		String^ name;
		String^ prev_name = "";
		Form^ mainform;
		long long ID = 0;
		map<String^, long long>Contacts;
		String^ username;
		String^ password;
		stack<String^> Messages;
		deque<String^> LifeChat;
		queue<String^> favoritemessage;
		deque<String^> temp;
		SpeechRecognitionEngine^ sre = gcnew SpeechRecognitionEngine;
		SpeechSynthesizer^ speaker = gcnew SpeechSynthesizer();

		void set_Messages_in_file() {
			String^ filename = "Data/";
			filename += username + "_" + System::Convert::ToString(ID) + "/message.txt";
			StreamWriter^ sw = gcnew StreamWriter(filename, false);
			while (!Messages.empty()) {
				sw->WriteLine(Messages.top());
				Messages.pop();
			}
			sw->Close();
			load_messages();
		}
		void set_FavoriteMessages_in_file() {
			//set_favoritemessage_size();
			String^ filename = "Data/";
			filename += username + "_" + System::Convert::ToString(ID) + "/favoritemessage.txt";
			StreamWriter^ sw = gcnew StreamWriter(filename, false);
			while (!favoritemessage.empty()) {
				sw->WriteLine(favoritemessage.front());
				favoritemessage.pop();
			}
			sw->Close();
			load_favorite();
		}
		void load_messages() {
			int count = 0;
			String^ temp = "";
			stack<String^> tmp;
			String^ filename = "Data/";
			filename += username + "_" + System::Convert::ToString(ID) + "/message.txt";    // sent messages
			while (!Messages.empty()) {
				Messages.pop();
			}
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				while ((str = din->ReadLine()) != nullptr)      // To ID :  
				{												// message
					count++;
					if (count == 2) {
						tmp.push(temp + "\n" + str);
						count = 0;
					}
					else {
						temp = str;
					}
				}
				din->Close();
				while (!tmp.empty()) {
					Messages.push(tmp.top());
					tmp.pop();
				}
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
				 Console::WriteLine("file '{0}' not found", filename);
				else
				 Console::WriteLine("problem reading file '{0}'", filename);
			}
		}
		void load_messages(long long id) {
			String^ filename = "Data/";
			filename += username + "_" + System::Convert::ToString(ID) + "/" + System::Convert::ToString(id) + ".txt";
			while (!LifeChat.empty()) {
				LifeChat.pop_front();
			}
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				while ((str = din->ReadLine()) != nullptr)
				{
					LifeChat.push_back(str);
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
			   //set_favoritemessage_size();
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
			if (!Messages.empty()) {
				Messages.pop();
				set_Messages_in_file();
			}
		}
		void Put_Message_Favorite(String^ message) {
			   favoritemessage.push(message);
			   set_FavoriteMessages_in_file();
		}
		void Remove_theOldest_Message() {
			if (!favoritemessage.empty()) {
				favoritemessage.pop();
				set_FavoriteMessages_in_file();
			}
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
		void Display_Contacts() {
			for (pair<String^, long long>pr : Contacts) {
				String^ last_message = get_last_message(pr.first, System::Convert::ToString(Contacts[pr.first]));
				Create_Contact(pr.first, last_message);
			}
		}
		void Display_Messages() {
			while (!Messages.empty())
			{
				Sent_Favorite_Chat->Items->Add(Messages.top());      // sent messages 
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
			   for (pair<String^, long long>pr : Contacts) 
			   {
				   if (pr.second == id) 
				   {
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
			   String^ temp = "to ID " + System::Convert::ToString(id) + " : \n" + message;
			   Messages.push(temp);
			   set_Messages_in_file();
		}
		void Display_Chat(long long id)
		{
			String^ msg = "";
			String^ msg2 = "";
			while (!LifeChat.empty())
			{
				msg = LifeChat.front();
				LifeChat.pop_front();
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
			load_messages(id);
		}
		String^ get_id() {
			if (!Messages.empty()) {
				String^ tmp = Messages.top();
				String^ id;
				for (int i = 6; i < tmp->Length; i++) {
					if (tmp[i] != ' ') {
						id += tmp[i];
					}
					else {
						break;
					}
				}
				return id;
			}
			/*String^ filename = "Data/" + this->username + "_" + System::Convert::ToString(ID) + "/message.txt";
			String^ id;
			String^ temp;
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				Console::WriteLine(Messages.top());
				if ((str = din->ReadLine()) != nullptr) {
					for (int i = str->Length - 4; i >= 0; i--) {
						if (str[i] != ' ') {
							id += str[i];
						}
						else {
							break;
						}
					}
					for (int i = id->Length - 1; i >= 0; i--) {
						temp += id[i];
					}
					id = temp;
				}
				din->Close();
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
			Console::WriteLine(id);*/
		}
		void set_temp_in_file(String^ id) {
			String^ name = get_username(System::Convert::ToInt32(id));
			String^ filename = "Data/" + name + "_" + id + "/" + System::Convert::ToString(ID) + ".txt";
			try {
				Console::WriteLine("tying to open file", filename);
				StreamWriter^ sw = gcnew StreamWriter(filename, false);
				while (!temp.empty()) {
					sw->WriteLine(temp.front());
					temp.pop_front();
				}
				sw->Close();
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
		}
		void set_LifeChat_in_file(String^ id) {
			String^ filename = "Data/" + this->username + "_" + System::Convert::ToString(ID) + "/" + id + ".txt";
			try {
				Console::WriteLine("tying to open file", filename);
				StreamWriter^ sw = gcnew StreamWriter(filename, false);
				while (!LifeChat.empty()) {
					sw->WriteLine(LifeChat.front());
					LifeChat.pop_front();
				}
				sw->Close();
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
		}
		String^ load_temp() {
			String^ id = get_id();
			String^ name = get_username(System::Convert::ToInt32(id));
			String^ filename = "Data/" + name + "_" + id + "/" + System::Convert::ToString(ID) + ".txt";
			try {
				Console::WriteLine("tying to open file", filename);
				StreamReader^ din = File::OpenText(filename);
				String^ str;
				while ((str = din->ReadLine()) != nullptr) {
					temp.push_back(str);
				}
				din->Close();
			}
			catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", filename);
				else
					Console::WriteLine("problem reading file '{0}'", filename);
			}
			return id;
		}
		void Undo_last_message_from_chat() {

			stack<String^> tmp;
			String^ id;
			if (!Messages.empty()) {
				id = load_temp();

				while (!temp.empty()) {
					String^ msg = temp.back();
					if (msg[0] == '2') {
						temp.pop_back();
						break;
					}
					else {
						tmp.push(temp.back());
						temp.pop_back();
					}
				}
				while (!tmp.empty()) {
					temp.push_back(tmp.top());
					tmp.pop();
				}
				set_temp_in_file(id);
				load_messages(System::Convert::ToInt32(id));
				while (!LifeChat.empty()) {
					String^ msg = LifeChat.back();
					if (msg[0] == '1') {
						LifeChat.pop_back();
						break;
					}
					else {
						tmp.push(LifeChat.back());
						LifeChat.pop_back();
					}
				}
				while (!tmp.empty()) {
					LifeChat.push_back(tmp.top());
					tmp.pop();
				}
				set_LifeChat_in_file(id);
			}
		}


	private: System::Windows::Forms::ListBox^ Chat1;
	private: System::Windows::Forms::Panel^ Sent_Favorite;
	private: System::Windows::Forms::ListBox^ Sent_Favorite_Chat;
	private: System::Windows::Forms::Panel^ Menu2;
	private: System::Windows::Forms::Button^ Favorit_Button;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ Search_Panel;
	private: System::Windows::Forms::Button^ Remove_Oldest;
	private: System::Windows::Forms::Button^ Undo_Last_Sent;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ Chat2;
	private: System::Windows::Forms::Button^ Search_button;
	private: System::Windows::Forms::Button^ info;
	private: System::Windows::Forms::Panel^ info_panel;
	private: System::Windows::Forms::Button^ ID_info;
	private: System::Windows::Forms::Button^ name_info;
	private: System::Windows::Forms::TextBox^ Search;
	private: System::Windows::Forms::Button^ UnSearch_button;
	private: System::Windows::Forms::Button^ Start_Record;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ Stop_Record;


	private:
		void Create_Contact(String^ name, String^ last_message) {
			Button^ Contact = gcnew Button;
			Contact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			Contact->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			Contact->BackColor = System::Drawing::Color::LightSeaGreen;
			Contact->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			Contact->ForeColor = System::Drawing::Color::White;
			int y;
			y = x;
			x += 60;
			Contact->Location = System::Drawing::Point(2, y);
			Contact->Name = L"Contact" + System::Convert::ToString(i);
			Contact->Size = System::Drawing::Size(292, 50);
			Contact->TabIndex = 8;
			String^ text = name + "\n" + last_message;
			Contact->Text = text;
			Contact->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			Contact->UseVisualStyleBackColor = true;
			Contact->Click += gcnew System::EventHandler(this, &UserForm::Contact_Click);
			this->panel4->Controls->Add(Contact);
			i++;
		}
		void Create_Contact_Search(String^ name, String^ last_message) {
			Button^ Contact = gcnew Button;
			Contact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			Contact->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			Contact->BackColor = System::Drawing::Color::LightSeaGreen;
			Contact->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			Contact->ForeColor = System::Drawing::Color::White;
			Contact->Location = System::Drawing::Point(2, 10);
			Contact->Name = L"Contact" + System::Convert::ToString(i);
			Contact->Size = System::Drawing::Size(292, 50);
			Contact->TabIndex = 8;
			String^ text = name + "\n" + last_message;
			Contact->Text = text;
			Contact->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			Contact->UseVisualStyleBackColor = true;
			Contact->Click += gcnew System::EventHandler(this, &UserForm::Contact_Click);
			this->Search_Panel->Controls->Add(Contact);
		}
		void Create_label_NotFound() {
			Label^ notfound = gcnew Label;
			notfound->AutoSize = true;
			notfound->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			notfound->Location = System::Drawing::Point(95, 25);
			notfound->Name = L"Not Found";
			notfound->ForeColor = System::Drawing::Color::Black;
			notfound->Size = System::Drawing::Size(35, 16);
			notfound->TabIndex = 0;
			notfound->Text = L"NOT FOUND";
			notfound->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Search_Panel->Controls->Add(notfound);
		}
	
	public:
		UserForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		UserForm(Form^ mainform, String^ username, String^ password, String^ id,hash_map <String^,String^>users_id)
		{
			this->users_id = users_id;
			this->username = username;
			this->password = password;
			for (int i = 0; i < id->Length; i++) {
				ID = 10 * ID + (id[i] - '0');
			}
			this->mainform = mainform;
			load_messages();
			load_favorite();
			InitializeComponent();
			load_contacts();
			this->UnSearch_button->Hide();
			this->Add_Button->Hide();
			this->Logout_Button->Hide();
			this->Star_Button->Hide();
			this->Back_Button->Hide();
			this->Star2_button->Hide();
			this->Menu2->Hide();
			this->button3->Hide();
			this->Sent_Favorite->Hide();
			this->Search_Panel->Hide();
			this->Stop_Record->Hide();
			this->Start_Record->Show();
			this->info_panel->Hide();
			this->info->Hide();
			speaker->Speak("Hello " + username);
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
			this->Chat2 = (gcnew System::Windows::Forms::ListBox());
			this->Chat1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Message = (gcnew System::Windows::Forms::TextBox());
			this->Menu2 = (gcnew System::Windows::Forms::Panel());
			this->Remove_Oldest = (gcnew System::Windows::Forms::Button());
			this->Undo_Last_Sent = (gcnew System::Windows::Forms::Button());
			this->Favorit_Button = (gcnew System::Windows::Forms::Button());
			this->Sent_Favorite = (gcnew System::Windows::Forms::Panel());
			this->Sent_Favorite_Chat = (gcnew System::Windows::Forms::ListBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->info = (gcnew System::Windows::Forms::Button());
			this->Star2_button = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Back_Button = (gcnew System::Windows::Forms::Button());
			this->Star_Button = (gcnew System::Windows::Forms::Button());
			this->Logout_Button = (gcnew System::Windows::Forms::Button());
			this->Add_Button = (gcnew System::Windows::Forms::Button());
			this->Menu = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Stop_Record = (gcnew System::Windows::Forms::Button());
			this->Start_Record = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Chat_Name = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->Search_Panel = (gcnew System::Windows::Forms::Panel());
			this->UnSearch_button = (gcnew System::Windows::Forms::Button());
			this->Search_button = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->info_panel = (gcnew System::Windows::Forms::Panel());
			this->ID_info = (gcnew System::Windows::Forms::Button());
			this->name_info = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->Menu2->SuspendLayout();
			this->Sent_Favorite->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->info_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel1->Controls->Add(this->Chat2);
			this->panel1->Controls->Add(this->Chat1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->Message);
			this->panel1->Location = System::Drawing::Point(396, 78);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(795, 596);
			this->panel1->TabIndex = 1;
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
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
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
			this->Message->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->Message->Location = System::Drawing::Point(7, 534);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(700, 41);
			this->Message->TabIndex = 0;
			this->Message->Text = L"Type text";
			this->Message->Click += gcnew System::EventHandler(this, &UserForm::Message_Click);
			this->Message->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserForm::Message_KeyDown);
			// 
			// Menu2
			// 
			this->Menu2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->Menu2->Controls->Add(this->Remove_Oldest);
			this->Menu2->Controls->Add(this->Undo_Last_Sent);
			this->Menu2->Controls->Add(this->Favorit_Button);
			this->Menu2->Location = System::Drawing::Point(1001, 81);
			this->Menu2->Name = L"Menu2";
			this->Menu2->Size = System::Drawing::Size(128, 149);
			this->Menu2->TabIndex = 7;
			// 
			// Remove_Oldest
			// 
			this->Remove_Oldest->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Remove_Oldest->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Remove_Oldest->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Remove_Oldest->Location = System::Drawing::Point(4, 102);
			this->Remove_Oldest->Name = L"Remove_Oldest";
			this->Remove_Oldest->Size = System::Drawing::Size(121, 42);
			this->Remove_Oldest->TabIndex = 2;
			this->Remove_Oldest->Text = L"Remove_Oldest";
			this->Remove_Oldest->UseVisualStyleBackColor = false;
			this->Remove_Oldest->Click += gcnew System::EventHandler(this, &UserForm::Remove_Oldest_Click);
			// 
			// Undo_Last_Sent
			// 
			this->Undo_Last_Sent->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Undo_Last_Sent->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Undo_Last_Sent->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Undo_Last_Sent->Location = System::Drawing::Point(3, 54);
			this->Undo_Last_Sent->Name = L"Undo_Last_Sent";
			this->Undo_Last_Sent->Size = System::Drawing::Size(121, 42);
			this->Undo_Last_Sent->TabIndex = 1;
			this->Undo_Last_Sent->Text = L"Undo_Last_Sent";
			this->Undo_Last_Sent->UseVisualStyleBackColor = false;
			this->Undo_Last_Sent->Click += gcnew System::EventHandler(this, &UserForm::Undo_Last_Sent_Click);
			// 
			// Favorit_Button
			// 
			this->Favorit_Button->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Favorit_Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Favorit_Button->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Favorit_Button->Location = System::Drawing::Point(4, 6);
			this->Favorit_Button->Name = L"Favorit_Button";
			this->Favorit_Button->Size = System::Drawing::Size(121, 42);
			this->Favorit_Button->TabIndex = 0;
			this->Favorit_Button->Text = L"Add To favorit";
			this->Favorit_Button->UseVisualStyleBackColor = false;
			this->Favorit_Button->Click += gcnew System::EventHandler(this, &UserForm::Favorit_Button_Click);
			// 
			// Sent_Favorite
			// 
			this->Sent_Favorite->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Sent_Favorite->Controls->Add(this->Sent_Favorite_Chat);
			this->Sent_Favorite->Location = System::Drawing::Point(396, 78);
			this->Sent_Favorite->Name = L"Sent_Favorite";
			this->Sent_Favorite->Size = System::Drawing::Size(785, 596);
			this->Sent_Favorite->TabIndex = 11;
			// 
			// Sent_Favorite_Chat
			// 
			this->Sent_Favorite_Chat->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Sent_Favorite_Chat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sent_Favorite_Chat->FormattingEnabled = true;
			this->Sent_Favorite_Chat->ItemHeight = 25;
			this->Sent_Favorite_Chat->Location = System::Drawing::Point(17, 29);
			this->Sent_Favorite_Chat->Name = L"Sent_Favorite_Chat";
			this->Sent_Favorite_Chat->Size = System::Drawing::Size(744, 529);
			this->Sent_Favorite_Chat->TabIndex = 10;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel2->Controls->Add(this->info);
			this->panel2->Controls->Add(this->Star2_button);
			this->panel2->Controls->Add(this->button3);
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
			// info
			// 
			this->info->BackColor = System::Drawing::Color::Transparent;
			this->info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"info.BackgroundImage")));
			this->info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->info->Cursor = System::Windows::Forms::Cursors::Hand;
			this->info->FlatAppearance->BorderSize = 0;
			this->info->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->info->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->info->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->info->ForeColor = System::Drawing::Color::Transparent;
			this->info->Location = System::Drawing::Point(330, 17);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(45, 51);
			this->info->TabIndex = 7;
			this->info->UseVisualStyleBackColor = false;
			this->info->Click += gcnew System::EventHandler(this, &UserForm::info_Click);
			// 
			// Star2_button
			// 
			this->Star2_button->BackColor = System::Drawing::Color::Transparent;
			this->Star2_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Star2_button.BackgroundImage")));
			this->Star2_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Star2_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Star2_button->FlatAppearance->BorderSize = 0;
			this->Star2_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Star2_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Star2_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Star2_button->Location = System::Drawing::Point(72, 14);
			this->Star2_button->Name = L"Star2_button";
			this->Star2_button->Size = System::Drawing::Size(45, 51);
			this->Star2_button->TabIndex = 5;
			this->Star2_button->UseVisualStyleBackColor = false;
			this->Star2_button->Click += gcnew System::EventHandler(this, &UserForm::Star2_button_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(261, 17);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 51);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserForm::button3_Click);
			// 
			// Back_Button
			// 
			this->Back_Button->BackColor = System::Drawing::Color::Transparent;
			this->Back_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Back_Button.BackgroundImage")));
			this->Back_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Back_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Back_Button->FlatAppearance->BorderSize = 0;
			this->Back_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Back_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Back_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Back_Button->Location = System::Drawing::Point(12, 21);
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
			this->Star_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Star_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Star_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Star_Button->Location = System::Drawing::Point(72, 14);
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
			this->Logout_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Logout_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Logout_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Logout_Button->Location = System::Drawing::Point(137, 16);
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
			this->Add_Button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Add_Button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Add_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add_Button->ForeColor = System::Drawing::Color::Transparent;
			this->Add_Button->Location = System::Drawing::Point(198, 16);
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
			this->Menu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Menu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
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
			this->panel3->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel3->Controls->Add(this->Stop_Record);
			this->panel3->Controls->Add(this->Start_Record);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->Chat_Name);
			this->panel3->Location = System::Drawing::Point(396, -2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(795, 79);
			this->panel3->TabIndex = 3;
			// 
			// Stop_Record
			// 
			this->Stop_Record->BackColor = System::Drawing::Color::Transparent;
			this->Stop_Record->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Stop_Record.BackgroundImage")));
			this->Stop_Record->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Stop_Record->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stop_Record->FlatAppearance->BorderSize = 0;
			this->Stop_Record->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Stop_Record->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Stop_Record->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Stop_Record->Location = System::Drawing::Point(663, 21);
			this->Stop_Record->Name = L"Stop_Record";
			this->Stop_Record->Size = System::Drawing::Size(44, 43);
			this->Stop_Record->TabIndex = 8;
			this->Stop_Record->UseVisualStyleBackColor = false;
			this->Stop_Record->Click += gcnew System::EventHandler(this, &UserForm::Stop_Record_Click);
			// 
			// Start_Record
			// 
			this->Start_Record->BackColor = System::Drawing::Color::Transparent;
			this->Start_Record->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Start_Record.BackgroundImage")));
			this->Start_Record->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Start_Record->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Start_Record->FlatAppearance->BorderSize = 0;
			this->Start_Record->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->Start_Record->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->Start_Record->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start_Record->Location = System::Drawing::Point(663, 20);
			this->Start_Record->Name = L"Start_Record";
			this->Start_Record->Size = System::Drawing::Size(44, 43);
			this->Start_Record->TabIndex = 7;
			this->Start_Record->UseVisualStyleBackColor = false;
			this->Start_Record->Click += gcnew System::EventHandler(this, &UserForm::Start_Record_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightSeaGreen;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(725, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(44, 42);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserForm::button1_Click);
			// 
			// Chat_Name
			// 
			this->Chat_Name->AutoSize = true;
			this->Chat_Name->BackColor = System::Drawing::Color::LightSeaGreen;
			this->Chat_Name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chat_Name->ForeColor = System::Drawing::Color::White;
			this->Chat_Name->Location = System::Drawing::Point(44, 20);
			this->Chat_Name->Name = L"Chat_Name";
			this->Chat_Name->Size = System::Drawing::Size(112, 32);
			this->Chat_Name->TabIndex = 0;
			this->Chat_Name->Text = L"Saraha";
			// 
			// panel4
			// 
			this->panel4->AutoScroll = true;
			this->panel4->BackColor = System::Drawing::Color::Gainsboro;
			this->panel4->Location = System::Drawing::Point(0, 115);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(397, 559);
			this->panel4->TabIndex = 4;
			// 
			// Search_Panel
			// 
			this->Search_Panel->AutoScroll = true;
			this->Search_Panel->BackColor = System::Drawing::Color::Gainsboro;
			this->Search_Panel->ForeColor = System::Drawing::Color::White;
			this->Search_Panel->Location = System::Drawing::Point(0, 115);
			this->Search_Panel->Name = L"Search_Panel";
			this->Search_Panel->Size = System::Drawing::Size(397, 559);
			this->Search_Panel->TabIndex = 5;
			// 
			// UnSearch_button
			// 
			this->UnSearch_button->BackColor = System::Drawing::Color::Transparent;
			this->UnSearch_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UnSearch_button.BackgroundImage")));
			this->UnSearch_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UnSearch_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnSearch_button->FlatAppearance->BorderSize = 0;
			this->UnSearch_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->UnSearch_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->UnSearch_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UnSearch_button->Location = System::Drawing::Point(3, 81);
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
			this->Search_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->Search_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->Search_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Search_button->Location = System::Drawing::Point(3, 78);
			this->Search_button->Name = L"Search_button";
			this->Search_button->Size = System::Drawing::Size(32, 31);
			this->Search_button->TabIndex = 6;
			this->Search_button->UseVisualStyleBackColor = false;
			this->Search_button->Click += gcnew System::EventHandler(this, &UserForm::Search_button_Click);
			// 
			// Search
			// 
			this->Search->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->Search->Location = System::Drawing::Point(34, 78);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(356, 34);
			this->Search->TabIndex = 0;
			this->Search->Text = L"Search for a contact";
			this->Search->Click += gcnew System::EventHandler(this, &UserForm::Search_Click);
			this->Search->TextChanged += gcnew System::EventHandler(this, &UserForm::Search_TextChanged);
			this->Search->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserForm::Search_KeyDown);
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel5->Controls->Add(this->button4);
			this->panel5->Location = System::Drawing::Point(399, 78);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(795, 596);
			this->panel5->TabIndex = 11;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Enabled = false;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(308, 74);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(143, 143);
			this->button4->TabIndex = 8;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// info_panel
			// 
			this->info_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->info_panel->Controls->Add(this->ID_info);
			this->info_panel->Controls->Add(this->name_info);
			this->info_panel->Location = System::Drawing::Point(359, 78);
			this->info_panel->Name = L"info_panel";
			this->info_panel->Size = System::Drawing::Size(146, 99);
			this->info_panel->TabIndex = 8;
			// 
			// ID_info
			// 
			this->ID_info->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ID_info->Enabled = false;
			this->ID_info->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_info->ForeColor = System::Drawing::Color::White;
			this->ID_info->Location = System::Drawing::Point(3, 53);
			this->ID_info->Name = L"ID_info";
			this->ID_info->Size = System::Drawing::Size(140, 42);
			this->ID_info->TabIndex = 4;
			this->ID_info->UseVisualStyleBackColor = false;
			// 
			// name_info
			// 
			this->name_info->BackColor = System::Drawing::Color::LightSeaGreen;
			this->name_info->Enabled = false;
			this->name_info->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->name_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_info->ForeColor = System::Drawing::Color::White;
			this->name_info->Location = System::Drawing::Point(3, 5);
			this->name_info->Name = L"name_info";
			this->name_info->Size = System::Drawing::Size(140, 42);
			this->name_info->TabIndex = 3;
			this->name_info->UseVisualStyleBackColor = false;
			// 
			// UserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1186, 673);
			this->Controls->Add(this->info_panel);
			this->Controls->Add(this->Search);
			this->Controls->Add(this->Menu2);
			this->Controls->Add(this->UnSearch_button);
			this->Controls->Add(this->Search_Panel);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->Sent_Favorite);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->Search_button);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"UserForm";
			this->ShowIcon = false;
			this->Text = L"UserForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->Menu2->ResumeLayout(false);
			this->Sent_Favorite->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->info_panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void Logout_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainform->Show();
		speaker->Speak("Bye " + this->username);
	}
	private: System::Void Star_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Text = "Search for a contact";
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Sent_Favorite_Chat->Items->Clear();
		Star_Button->Hide();
		Star2_button->Show();
		Sent_Favorite->Show();
		panel5->Hide();
		Chat_Name->Text = "Favorite Messages";
		while (!favoritemessage.empty())
		{
			Sent_Favorite_Chat->Items->Add(favoritemessage.front());
			favoritemessage.pop();
		}
		load_favorite();
	}
	private: System::Void Back_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Logout_Button->Hide();
		Back_Button->Hide();
		Add_Button->Hide();
		Star_Button->Hide();
		Star2_button->Hide();
		button3->Hide();
		info->Hide();
	}
	private: System::Void Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		Back_Button->Show();
		Logout_Button->Show();
		Add_Button->Show();
		Star_Button->Show();
		button3->Show();
		info->Show();
	}
	private: System::Void Contact_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Search->Text = "Search for a contact";
		Message->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Message->Text = "Type text";
		Sent_Favorite->Hide();
		panel5->Hide();
		said = 1;
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
			Display_Chat(id);
			Message->Focus();
		}
	}
	private: System::Void Star2_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Star2_button->Hide();
		Star_Button->Show();
		Sent_Favorite->Hide();
		Chat_Name->Text = name;
	}
	private: System::Void Search_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Search->Text->Length > 0) {
			Search_button->Hide();
			UnSearch_button->Show();
			Search_Panel->Show();
			int num;
			if (int::TryParse(Search->Text, num)) {
				String^ name = get_username(System::Convert::ToInt32(Search->Text));
				if (name != nullptr) {
					String^ last_mess = get_last_message(name, Search->Text);
					Create_Contact_Search(name, last_mess);
				}
				else {
					Create_label_NotFound();
				}
			}
			else {
				long long id = get_id(Search->Text);
				if (id == 0) {
					Create_label_NotFound();
				}
				else {
					String^ last_mess = get_last_message(Search->Text, System::Convert::ToString(id));
					Create_Contact_Search(Search->Text, last_mess);
				}
			}
		}
	}
	private: System::Void Search_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void UnSearch_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Clear();
		Search->Text = "Search for a contact";
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Search_button->Show();
		UnSearch_button->Hide();
		Search_Panel->Controls->Clear();
		Search_Panel->Hide();
	}
	private: System::Void Add_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Text = "Search for a contact";
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Add_Contact^ add_contact = gcnew Add_Contact(username, ID, users_id, Contacts);
		add_contact->ShowDialog();
		this->panel4->Controls->Clear();
		x = 10;
		this->load_contacts();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Text = "Search for a contact";
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		String^ msg = Message->Text;
		if (msg->Length != 0) {
			Chat2->Items->Add(msg);
			Chat1->Items->Add("");
			Send_Message(msg, get_id(name));
			load_messages(get_id(name));
			this->panel4->Controls->Clear();
			x = 10;
			this->load_contacts();
			Message->Clear();
			Message->Text = "Type text";
			Message->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			Message->Focus();
		}
	}		  
	private: System::Void Message_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	   if (e->KeyCode == Keys::Enter)
	   {
		   button2->PerformClick();
		   Message->Clear();
		   Message->ForeColor = Color::Black;
	   }
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
		String^ FavMessage = "";
		String^ FavMessage2 = "";
		if (Chat2->SelectedItems->Count > 0) {
			FavMessage2 = Chat2->SelectedItem->ToString();
			if (FavMessage2->Length != 0) {
				Put_Message_Favorite(FavMessage2);
			}
			//Console::WriteLine(FavMessage2);
		}
		if (Chat1->SelectedItems->Count > 0) {
			FavMessage = Chat1->SelectedItem->ToString();
			if (FavMessage->Length != 0) {
				Put_Message_Favorite(FavMessage);
			}
			//Console::WriteLine(FavMessage);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Text = "Search for a contact";
		panel5->Hide();
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		Star2_button->Hide();
		Star_Button->Show();
		Sent_Favorite_Chat->Items->Clear();
		Sent_Favorite->Show();
		Chat_Name->Text = "Sent Messages";
		Display_Messages();
	}
	private: System::Void Special_contact_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Search_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			Search_Panel->Controls->Clear();
			if (Search->Text->Length > 0) {
				Search_button->Hide();
				UnSearch_button->Show();
				Search_Panel->Show();
				int num;
				if (int::TryParse(Search->Text, num)) {
					String^ name = get_username(System::Convert::ToInt32(Search->Text));
					if (name != nullptr) {
						String^ last_mess = get_last_message(name, Search->Text);
						Create_Contact_Search(name, last_mess);
					}
					else {
						Create_label_NotFound();
					}
				}
				else {
					long long id = get_id(Search->Text);
					if (id == 0) {
						Create_label_NotFound();
					}
					else {
						String^ last_mess = get_last_message(Search->Text, System::Convert::ToString(id));
						Create_Contact_Search(Search->Text, last_mess);
					}
				}
			}
		}
	}
	private: System::Void Undo_Last_Sent_Click(System::Object^ sender, System::EventArgs^ e) {
		Undo_last_message_from_chat();
		Undo_last_message();
		if (Chat_Name->Text == "Sent Messages") {
			Sent_Favorite_Chat->Items->Clear();
			Sent_Favorite->Show();
			Display_Messages();
		}
		if (name!=nullptr) {
			Chat1->Items->Clear();
			Chat2->Items->Clear();
			Console::WriteLine("I am here");
			long long id = get_id(name);
			load_messages(id);
			Display_Chat(id);;
			this->panel4->Controls->Clear();
			x = 10;
			this->load_contacts();
		}
	}
	private: System::Void Remove_Oldest_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Chat_Name->Text == "Favorite Messages") {
			Remove_theOldest_Message();
			Sent_Favorite_Chat->Items->Clear();
			while (!favoritemessage.empty())
			{
				Sent_Favorite_Chat->Items->Add(favoritemessage.front());
				favoritemessage.pop();
			}
			load_favorite();
		}
		else {
			Remove_theOldest_Message();
			while (!favoritemessage.empty())
			{
				Sent_Favorite_Chat->Items->Add(favoritemessage.front());
				favoritemessage.pop();
			}
			load_favorite();
		}
	}
	private: System::Void Start_Record_Click(System::Object^ sender, System::EventArgs^ e) {
		Search->Text = "Search for a contact";
		Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
		this->Start_Record->Hide();
		this->Stop_Record->Show();

		Choices^ voice = gcnew Choices();

		for (pair<String^, long long>pr : Contacts) {
			voice->Add("Search About " + pr.first);
			voice->Add("Send a Message to " + pr.first);
		}

		voice->Add("Stop Recording");
		voice->Add("Stop Search");
		voice->Add("Add Contact");
		voice->Add("Display Sent Messages");
		voice->Add("Display Favorite Messages");
		voice->Add("Logout");
		voice->Add("HI");
		voice->Add("Hello");
		voice->Add("Sorry I am bussy");
		voice->Add("I'll call you");
		voice->Add("I Want to see you");
		voice->Add("How are you");
		voice->Add("Call me");
		voice->Add("Undo Last message");
		voice->Add("Delete Last message");
		voice->Add("Remove Last message");
		voice->Add("Undo");
		voice->Add("Delete");
		voice->Add("Remove");


		GrammarBuilder^ gb = gcnew GrammarBuilder;
		gb->Append(voice);
		Grammar^ grammer = gcnew Grammar(gb);

		sre->LoadGrammarAsync(grammer);
		sre->SetInputToDefaultAudioDevice();
		sre->SpeechRecognized += gcnew System::EventHandler<SpeechRecognizedEventArgs^>(this, &UserForm::speechrec);
		
		sre->RecognizeAsync(RecognizeMode::Multiple);
	}
	private: System::Void speechrec(System::Object^ sender, SpeechRecognizedEventArgs^ e)
	{
		String^ word;
		String^ order;
		String^ temp;
		String^ tmp;
		word = e->Result->Text;
		if (word == "Stop Recording") {
			sre->RecognizeAsyncStop();
			this->Start_Record->Show();
			this->Stop_Record->Hide();
		}
		else if (word == "Stop Search") {
			Search_button->Show();
			UnSearch_button->Hide();
			Search->Clear();
			Search_Panel->Controls->Clear();
			Search_Panel->Hide();
		}
		else if (word == "Logout") {
			this->Hide();
			mainform->Show();
			speaker->Speak("Bye " + this->username);
		}
		else if (word == "Add Contact") {
			Add_Contact^ add_contact = gcnew Add_Contact(username, ID, users_id, Contacts);
			add_contact->ShowDialog();
			this->panel4->Controls->Clear();
			x = 10;
			this->load_contacts();
		}
		else if (word == "Display Sent Messages") {
			Back_Button->Show();
			Logout_Button->Show();
			Add_Button->Show();
			Star_Button->Show();
			button3->Show();
			Star2_button->Hide();
			panel5->Hide();
			Sent_Favorite_Chat->Items->Clear();
			Sent_Favorite->Show();
			Chat_Name->Text = "Sent Messages";
			Display_Messages();
		}
		else if (word == "Display Favorite Messages") {
			Back_Button->Show();
			panel5->Hide();
			Logout_Button->Show();
			Add_Button->Show();
			button3->Show();
			Sent_Favorite_Chat->Items->Clear();
			Star_Button->Hide();
			Star2_button->Show();
			Sent_Favorite->Show();
			Chat_Name->Text = "Favorite Messages";
			while (!favoritemessage.empty())
			{
				Sent_Favorite_Chat->Items->Add(favoritemessage.front());
				favoritemessage.pop();
			}
			load_favorite();
		}	
		else if (word == "HI" && said == 1) {
			Message->Text = "HI";
			button2->PerformClick();
		}
		else if (word == "Hello" && said == 1) {
			Message->Text = "Hello";
			button2->PerformClick();
		}
		else if (word == "Sorry I am bussy" && said == 1) {
			Message->Text = "Sorry I am bussy";
			button2->PerformClick();
		}
		else if (word == "I'll call you" && said == 1) {
			Message->Text = "I'll call you";
			button2->PerformClick();
		}
		else if (word == "I Want to see you" && said == 1) {
			Message->Text = "I Want to see you";
			button2->PerformClick();
		}
		else if (word == "How are you" && said == 1) {
			Message->Text = "How are you";
			button2->PerformClick();
		}
		else if (word == "Call me" && said == 1) {
			Message->Text = "Call me";
			button2->PerformClick();
		}
		else if ((word == "Undo Last message" || word == "Delete Last message" || word == "Remove Last message" || word == "Undo" || word == "Delete" || word == "Remove")&& said == 1) {
			Undo_last_message_from_chat();
			Undo_last_message();
			if (Chat_Name->Text == "Sent Messages") {
				Sent_Favorite_Chat->Items->Clear();
				Sent_Favorite->Show();
				Display_Messages();
			}
			Chat1->Items->Clear();
			Chat2->Items->Clear();
			long long id = get_id(name);
			load_messages(id);
			Display_Chat(id);
			this->panel4->Controls->Clear();
			x = 10;
			this->load_contacts();
			Console::WriteLine("Done");
		}
		else {
			for (int i = 0; i < word->Length; i++) {
				if (word[i] == ' ') {
					break;
				}
				order += word[i];
			}
			for (int i = word->Length-1; i >= 0; i--) {
				if (word[i] == ' ') {
					break;
				}
				temp += word[i];
			}
			for (int i = temp->Length-1; i >= 0; i--) {
				tmp += temp[i];
			}
			if (order == "Search") {
				Search_button->Hide();
				UnSearch_button->Show();
				Search_Panel->Show();
				Search_Panel->Controls->Clear();
				long long id = get_id(tmp);
				if (id == 0) {
					Create_label_NotFound();
				}
				else {
					Search->Text = tmp;
					String^ last_mess = get_last_message(tmp, System::Convert::ToString(id));
					Create_Contact_Search(tmp, last_mess);
				}
			}
			else if (order == "Send") {
				Search->ForeColor = System::Drawing::SystemColors::InactiveCaption;
				Search->Text = "Search for a contact";
				Message->ForeColor = System::Drawing::SystemColors::InactiveCaption;
				Message->Text = "Type text";
				Sent_Favorite->Hide();
				panel5->Hide();
				said = 1;
				name = tmp;
				Chat_Name->Text = name;
				if (prev_name != name) {
					prev_name = name;
					Chat1->Items->Clear();
					Chat2->Items->Clear();
					long long id = get_id(name);
					load_messages(id);
					Display_Chat(id);
					Message->Focus();
				}
			}
		}
		Console::WriteLine(word);
	}
	private: System::Void Stop_Record_Click(System::Object^ sender, System::EventArgs^ e) {
		sre->RecognizeAsyncStop();
		this->Start_Record->Show();
		this->Stop_Record->Hide();
	}
	private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (Search->Text == "Search for a contact")
		{
			Search->Text = "";
			Search->ForeColor = Color::Black;
		}
	}
	private: System::Void Message_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Message->Text == "Type text")
		{
			Message->Text = "";
		}
		Message->ForeColor = Color::Black;
	}
	private: System::Void info_Click(System::Object^ sender, System::EventArgs^ e) {
		if (show_info) {
			info_panel->Hide();
			show_info = 0;
		}
		else {
			info_panel->Show();
			name_info->Text = this->username;
			ID_info->Text = System::Convert::ToString(this->ID);
			show_info = 1;
		}
	}
};
}