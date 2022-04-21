#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BlueSara7a::MainForm frm;
	Application::Run(% frm);

	return 0;
}