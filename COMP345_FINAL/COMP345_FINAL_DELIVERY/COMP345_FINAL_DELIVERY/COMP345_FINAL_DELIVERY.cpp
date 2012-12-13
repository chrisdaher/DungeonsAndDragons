// COMP345_FINAL_DELIVERY.cpp : main project file.

#include "stdafx.h"
#include "ui_frm_Menu.h"
using namespace COMP345_FINAL_DELIVERY;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	
	Application::Run(gcnew ui_frm_Menu());
	return 0;
}

