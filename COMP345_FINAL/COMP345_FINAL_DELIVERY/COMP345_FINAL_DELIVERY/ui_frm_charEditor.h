#pragma once
#include "CharacterBuilder.h"
#include "BullyBuilder.h"
#include "TankBuilder.h"
#include "NimbleBuilder.h"

namespace COMP345_FINAL_DELIVERY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace d20Logic;

	/// <summary>
	/// Summary for ui_frm_charEditor
	/// </summary>
	public ref class ui_frm_charEditor : public System::Windows::Forms::Form
	{
	public:
		ui_frm_charEditor(void)
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
		~ui_frm_charEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ui_btn_bully;
	private: System::Windows::Forms::Button^  ui_btn_nimble;
	private: System::Windows::Forms::Button^  ui_btn_tank;
	private: System::Windows::Forms::Button^  ui_btn_charBuild;
	private: System::Windows::Forms::ListBox^  ui_lb_race;
	private: System::Windows::Forms::NumericUpDown^  ui_num_lvl;
	private: System::Windows::Forms::Label^  ui_lbl_lvl;
	private: System::Windows::Forms::Label^  ui_lbl_race;
	private: System::Windows::Forms::GroupBox^  ui_gb_create;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadCharacterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCharacterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  backToMainMenuToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  ui_txt_saveLoc;
	private: System::Windows::Forms::Button^  ui_btn_saveChar;


	protected: 



	protected: 

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
			this->ui_btn_bully = (gcnew System::Windows::Forms::Button());
			this->ui_btn_nimble = (gcnew System::Windows::Forms::Button());
			this->ui_btn_tank = (gcnew System::Windows::Forms::Button());
			this->ui_btn_charBuild = (gcnew System::Windows::Forms::Button());
			this->ui_lb_race = (gcnew System::Windows::Forms::ListBox());
			this->ui_num_lvl = (gcnew System::Windows::Forms::NumericUpDown());
			this->ui_lbl_lvl = (gcnew System::Windows::Forms::Label());
			this->ui_lbl_race = (gcnew System::Windows::Forms::Label());
			this->ui_gb_create = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadCharacterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCharacterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backToMainMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ui_txt_saveLoc = (gcnew System::Windows::Forms::TextBox());
			this->ui_btn_saveChar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_num_lvl))->BeginInit();
			this->ui_gb_create->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ui_btn_bully
			// 
			this->ui_btn_bully->Location = System::Drawing::Point(36, 23);
			this->ui_btn_bully->Name = L"ui_btn_bully";
			this->ui_btn_bully->Size = System::Drawing::Size(75, 23);
			this->ui_btn_bully->TabIndex = 0;
			this->ui_btn_bully->Text = L"Bully Build";
			this->ui_btn_bully->UseVisualStyleBackColor = true;
			this->ui_btn_bully->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::ui_btn_bully_Click);
			// 
			// ui_btn_nimble
			// 
			this->ui_btn_nimble->Location = System::Drawing::Point(142, 23);
			this->ui_btn_nimble->Name = L"ui_btn_nimble";
			this->ui_btn_nimble->Size = System::Drawing::Size(75, 23);
			this->ui_btn_nimble->TabIndex = 1;
			this->ui_btn_nimble->Text = L"Nimble Build";
			this->ui_btn_nimble->UseVisualStyleBackColor = true;
			this->ui_btn_nimble->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::ui_btn_nimble_Click);
			// 
			// ui_btn_tank
			// 
			this->ui_btn_tank->Location = System::Drawing::Point(251, 23);
			this->ui_btn_tank->Name = L"ui_btn_tank";
			this->ui_btn_tank->Size = System::Drawing::Size(75, 23);
			this->ui_btn_tank->TabIndex = 2;
			this->ui_btn_tank->Text = L"Tank Build";
			this->ui_btn_tank->UseVisualStyleBackColor = true;
			this->ui_btn_tank->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::ui_btn_tank_Click);
			// 
			// ui_btn_charBuild
			// 
			this->ui_btn_charBuild->Location = System::Drawing::Point(90, 135);
			this->ui_btn_charBuild->Name = L"ui_btn_charBuild";
			this->ui_btn_charBuild->Size = System::Drawing::Size(151, 23);
			this->ui_btn_charBuild->TabIndex = 3;
			this->ui_btn_charBuild->Text = L"Create Character";
			this->ui_btn_charBuild->UseVisualStyleBackColor = true;
			this->ui_btn_charBuild->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::ui_btn_charBuild_Click);
			// 
			// ui_lb_race
			// 
			this->ui_lb_race->FormattingEnabled = true;
			this->ui_lb_race->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Human", L"Dwarf", L"Elf", L"Gnome", L"Half-Elf", 
				L"Half-Orc", L"Halfling"});
			this->ui_lb_race->Location = System::Drawing::Point(194, 34);
			this->ui_lb_race->Name = L"ui_lb_race";
			this->ui_lb_race->Size = System::Drawing::Size(120, 95);
			this->ui_lb_race->TabIndex = 4;
			// 
			// ui_num_lvl
			// 
			this->ui_num_lvl->Location = System::Drawing::Point(24, 50);
			this->ui_num_lvl->Name = L"ui_num_lvl";
			this->ui_num_lvl->Size = System::Drawing::Size(120, 20);
			this->ui_num_lvl->TabIndex = 5;
			// 
			// ui_lbl_lvl
			// 
			this->ui_lbl_lvl->AutoSize = true;
			this->ui_lbl_lvl->Location = System::Drawing::Point(66, 34);
			this->ui_lbl_lvl->Name = L"ui_lbl_lvl";
			this->ui_lbl_lvl->Size = System::Drawing::Size(33, 13);
			this->ui_lbl_lvl->TabIndex = 6;
			this->ui_lbl_lvl->Text = L"Level";
			// 
			// ui_lbl_race
			// 
			this->ui_lbl_race->AutoSize = true;
			this->ui_lbl_race->Location = System::Drawing::Point(236, 18);
			this->ui_lbl_race->Name = L"ui_lbl_race";
			this->ui_lbl_race->Size = System::Drawing::Size(33, 13);
			this->ui_lbl_race->TabIndex = 7;
			this->ui_lbl_race->Text = L"Race";
			// 
			// ui_gb_create
			// 
			this->ui_gb_create->Controls->Add(this->ui_num_lvl);
			this->ui_gb_create->Controls->Add(this->ui_lbl_race);
			this->ui_gb_create->Controls->Add(this->ui_lbl_lvl);
			this->ui_gb_create->Controls->Add(this->ui_lb_race);
			this->ui_gb_create->Controls->Add(this->ui_btn_charBuild);
			this->ui_gb_create->Location = System::Drawing::Point(12, 52);
			this->ui_gb_create->Name = L"ui_gb_create";
			this->ui_gb_create->Size = System::Drawing::Size(334, 179);
			this->ui_gb_create->TabIndex = 8;
			this->ui_gb_create->TabStop = false;
			this->ui_gb_create->Text = L"New Character";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(355, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadCharacterToolStripMenuItem, 
				this->saveCharacterToolStripMenuItem, this->backToMainMenuToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadCharacterToolStripMenuItem
			// 
			this->loadCharacterToolStripMenuItem->Name = L"loadCharacterToolStripMenuItem";
			this->loadCharacterToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->loadCharacterToolStripMenuItem->Text = L"Load Character";
			this->loadCharacterToolStripMenuItem->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::loadCharacterToolStripMenuItem_Click);
			// 
			// saveCharacterToolStripMenuItem
			// 
			this->saveCharacterToolStripMenuItem->Name = L"saveCharacterToolStripMenuItem";
			this->saveCharacterToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->saveCharacterToolStripMenuItem->Text = L"Save Character";
			this->saveCharacterToolStripMenuItem->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::saveCharacterToolStripMenuItem_Click);
			// 
			// backToMainMenuToolStripMenuItem
			// 
			this->backToMainMenuToolStripMenuItem->Name = L"backToMainMenuToolStripMenuItem";
			this->backToMainMenuToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->backToMainMenuToolStripMenuItem->Text = L"Back to main menu";
			this->backToMainMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::backToMainMenuToolStripMenuItem_Click);
			// 
			// ui_txt_saveLoc
			// 
			this->ui_txt_saveLoc->Location = System::Drawing::Point(142, 246);
			this->ui_txt_saveLoc->Name = L"ui_txt_saveLoc";
			this->ui_txt_saveLoc->Size = System::Drawing::Size(100, 20);
			this->ui_txt_saveLoc->TabIndex = 10;
			// 
			// ui_btn_saveChar
			// 
			this->ui_btn_saveChar->Location = System::Drawing::Point(23, 244);
			this->ui_btn_saveChar->Name = L"ui_btn_saveChar";
			this->ui_btn_saveChar->Size = System::Drawing::Size(113, 23);
			this->ui_btn_saveChar->TabIndex = 11;
			this->ui_btn_saveChar->Text = L"Save Character";
			this->ui_btn_saveChar->UseVisualStyleBackColor = true;
			this->ui_btn_saveChar->Click += gcnew System::EventHandler(this, &ui_frm_charEditor::ui_btn_saveChar_Click);
			// 
			// ui_frm_charEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(355, 278);
			this->Controls->Add(this->ui_btn_saveChar);
			this->Controls->Add(this->ui_txt_saveLoc);
			this->Controls->Add(this->ui_gb_create);
			this->Controls->Add(this->ui_btn_tank);
			this->Controls->Add(this->ui_btn_nimble);
			this->Controls->Add(this->ui_btn_bully);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"ui_frm_charEditor";
			this->Text = L"ui_frm_charEditor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_num_lvl))->EndInit();
			this->ui_gb_create->ResumeLayout(false);
			this->ui_gb_create->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Character* theChar;
	private: System::Void ui_btn_bully_Click(System::Object^  sender, System::EventArgs^  e) {
				CharacterBuilder* bully= new BullyBuilder();
				bully->buildAttributes();
				theChar=bully->getCharacter();
			 }
private: System::Void ui_btn_nimble_Click(System::Object^  sender, System::EventArgs^  e) {
			 	CharacterBuilder* nimble= new NimbleBuilder();
				nimble->buildAttributes();
				theChar=nimble->getCharacter();
		 }
private: System::Void ui_btn_tank_Click(System::Object^  sender, System::EventArgs^  e) {
			 	CharacterBuilder* tank= new TankBuilder();
				tank->buildAttributes();
				theChar=tank->getCharacter();
		 }

private: System::Void ui_btn_charBuild_Click(System::Object^  sender, System::EventArgs^  e) {
			int race = ui_lb_race->SelectedIndex;
			int lvl = (int) ui_num_lvl->Value;
			theChar= new Character(race+1, lvl);
		}
private: System::Void loadCharacterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //loadCharacter();
		 }
		
		 //void loadcharacter(){
			// string^ currdir = system::io::directory::getcurrentdirectory();
			// string^ initdir = currdir + "\\" + default_location_map_data;
			// ui_dia_open->filename="";
			// ui_dia_open->filter ="character (*.char) | *.char";// + map_file_type +")";
			// ui_dia_open->initialdirectory =initdir;
			// ui_dia_open->showdialog();
			// string^ selectedloc = ui_dia_open->filename;
			// character achar;
			// themap = achar.loadcharacter(selectedloc);
			// displaymap(themap);

			// ui_pan_save->visible = true;
		 //}
		 void saveCharacter(){
			 String^ fileName = ui_txt_saveLoc->Text;
			 if (fileName == String::Empty){
				 MessageBox::Show("Invalid filename input");
				 return;
			 }

			 //theChar->saveChar(fileName);
			 MessageBox::Show("Saved!");
		 }
private: System::Void ui_btn_saveChar_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveCharacter();
		 }
private: System::Void saveCharacterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveCharacter();
		 }
private: System::Void backToMainMenuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
		 }
};
}
