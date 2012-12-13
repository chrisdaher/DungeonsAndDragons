#pragma once
#include "Map.h"
#include "Logger.h"
namespace COMP345_FINAL_DELIVERY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace d20Logic;

	/// <summary>
	/// Summary for ui_frm_game
	/// </summary>
	public ref class ui_frm_game : public System::Windows::Forms::Form
	{
	public:
		ui_frm_game(void)
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
		~ui_frm_game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  ui_group_map;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadCharacterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  backToMainMenuToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  ui_dia_open;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  ui_lbl_currentLog;
	private: System::Windows::Forms::Panel^  ui_pan_items;
	private: System::Windows::Forms::Panel^  ui_pan_equpment;





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
			this->ui_group_map = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadMapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadCharacterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backToMainMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ui_dia_open = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ui_lbl_currentLog = (gcnew System::Windows::Forms::Label());
			this->ui_pan_items = (gcnew System::Windows::Forms::Panel());
			this->ui_pan_equpment = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ui_group_map
			// 
			this->ui_group_map->AutoSize = true;
			this->ui_group_map->Location = System::Drawing::Point(34, 32);
			this->ui_group_map->Name = L"ui_group_map";
			this->ui_group_map->Size = System::Drawing::Size(391, 244);
			this->ui_group_map->TabIndex = 1;
			this->ui_group_map->TabStop = false;
			this->ui_group_map->Text = L"The Map";
			this->ui_group_map->Resize += gcnew System::EventHandler(this, &ui_frm_game::ui_group_map_Resize);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->gameToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(854, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadMapToolStripMenuItem, 
				this->loadCharacterToolStripMenuItem, this->backToMainMenuToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// loadMapToolStripMenuItem
			// 
			this->loadMapToolStripMenuItem->Name = L"loadMapToolStripMenuItem";
			this->loadMapToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->loadMapToolStripMenuItem->Text = L"Load Map";
			this->loadMapToolStripMenuItem->Click += gcnew System::EventHandler(this, &ui_frm_game::loadMapToolStripMenuItem_Click);
			// 
			// loadCharacterToolStripMenuItem
			// 
			this->loadCharacterToolStripMenuItem->Name = L"loadCharacterToolStripMenuItem";
			this->loadCharacterToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->loadCharacterToolStripMenuItem->Text = L"Load Character";
			this->loadCharacterToolStripMenuItem->Click += gcnew System::EventHandler(this, &ui_frm_game::loadCharacterToolStripMenuItem_Click);
			// 
			// backToMainMenuToolStripMenuItem
			// 
			this->backToMainMenuToolStripMenuItem->Name = L"backToMainMenuToolStripMenuItem";
			this->backToMainMenuToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->backToMainMenuToolStripMenuItem->Text = L"Back to main menu";
			// 
			// ui_dia_open
			// 
			this->ui_dia_open->FileName = L"openFileDialog1";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->ui_lbl_currentLog);
			this->panel1->Location = System::Drawing::Point(545, 40);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(226, 236);
			this->panel1->TabIndex = 3;
			// 
			// ui_lbl_currentLog
			// 
			this->ui_lbl_currentLog->AutoSize = true;
			this->ui_lbl_currentLog->Location = System::Drawing::Point(18, 15);
			this->ui_lbl_currentLog->Name = L"ui_lbl_currentLog";
			this->ui_lbl_currentLog->Size = System::Drawing::Size(0, 13);
			this->ui_lbl_currentLog->TabIndex = 0;
			// 
			// ui_pan_items
			// 
			this->ui_pan_items->AutoSize = true;
			this->ui_pan_items->Location = System::Drawing::Point(32, 315);
			this->ui_pan_items->Name = L"ui_pan_items";
			this->ui_pan_items->Size = System::Drawing::Size(393, 107);
			this->ui_pan_items->TabIndex = 4;
			this->ui_pan_items->Resize += gcnew System::EventHandler(this, &ui_frm_game::ui_pan_items_Resize);
			// 
			// ui_pan_equpment
			// 
			this->ui_pan_equpment->AutoSize = true;
			this->ui_pan_equpment->Location = System::Drawing::Point(443, 315);
			this->ui_pan_equpment->Name = L"ui_pan_equpment";
			this->ui_pan_equpment->Size = System::Drawing::Size(393, 107);
			this->ui_pan_equpment->TabIndex = 5;
			// 
			// ui_frm_game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(854, 434);
			this->Controls->Add(this->ui_pan_equpment);
			this->Controls->Add(this->ui_pan_items);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->ui_group_map);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ui_frm_game";
			this->Text = L"ui_frm_game";
			this->Load += gcnew System::EventHandler(this, &ui_frm_game::ui_frm_game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ui_frm_game::ui_frm_game_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Map* theMap;
		Character* theChar;
		array<PictureBox^, 2>^ MapGrid;
		array<CheckBox^, 1>^ ItemGrid;
		array<Label^, 1>^ EquipGrid;
#define BLOCK_SIZE 20;
	private: System::Void ui_frm_game_Load(System::Object^  sender, System::EventArgs^  e) {
					Logger::currentLogInfo = String::Empty;
			 }
	
	private: System::Void loadMapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 loadMap();
			 }

			 void loadMap(){
				 String^ currDir = System::IO::Directory::GetCurrentDirectory();
				 String^ initDir = currDir + "\\" + DEFAULT_LOCATION_MAP_DATA;
				 ui_dia_open->FileName="";
				 ui_dia_open->Filter ="MAP (*.mph) | *.mph";// + MAP_FILE_TYPE +")";
				 ui_dia_open->InitialDirectory =initDir;
				 ui_dia_open->ShowDialog();
				 String^ selectedLoc = ui_dia_open->FileName;
				 Map aMap;
				 theMap = aMap.loadMap(selectedLoc);
				 DisplayMap(theMap);

			 }

			 void DisplayMap(Map* theMap){
				 int width = theMap->GetX();
				 int height = theMap->GetY();
				 int prevX = 0;
				 int prevY = 20;
				 int blockSize = BLOCK_SIZE;
				 MapGrid = gcnew array<PictureBox^, 2>(width,height);

				 Bitmap^ theImg = gcnew Bitmap("Img\\openBlock.jpg");
				 ui_group_map->Controls->Clear();
				 ui_group_map->Visible = true;
				 String^ tempString;
				 System::Drawing::Point pointTag;
				 for (int i=0;i<width;i++){
					 for (int k=0;k<height;k++){
						 MapGrid[i,k]=gcnew PictureBox;
						 MapGrid[i,k]->Location = Point(prevX+20, prevY);
						 MapGrid[i,k]->Size = System::Drawing::Size(blockSize,blockSize);
						 tempString = gcnew String(theMap->GetBlockAt(i,k)->getSprite());
						 MapGrid[i,k]->Image = Image::FromFile(tempString);
						 ui_group_map->Controls->Add(MapGrid[i,k]);
						 pointTag = System::Drawing::Point(i,k);
						 MapGrid[i,k]->Tag = pointTag;
						 if (k < (height - 1)){
							 prevX += MapGrid[i,k]->Width;
						 }
						 else{
							 prevX = 0;
							 prevY += MapGrid[i,k]->Height;
						 }
					 }
				 }
				 ui_group_map->AutoSize = true;
				 ui_group_map->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			 }


			 void UpdateDisplay(int x, int y){
				 Block* theBlock = theMap->GetBlockAt(y,x);
				 String^ spriteLoc = gcnew String(theBlock->getSprite());
				 Bitmap^ bmp = gcnew Bitmap(spriteLoc);
				 MapGrid[y,x]->Image = bmp;
			 }
private: System::Void ui_frm_game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 System::Drawing::Point thePt;
			 System::Drawing::Point prevPt = theMap->getCharacterPosition();
			 switch (e->KeyValue){
			 case 87:
				 thePt = theMap->MoveCharacter('w');
				 break;
			 case 65:
				 thePt = theMap->MoveCharacter('a');
				 break;
			 case 83:
				 thePt = theMap->MoveCharacter('s');
				 break;
			 case 68:
				 thePt = theMap->MoveCharacter('d');
				 break;
			 }
			 if (thePt.X == -2) return;
			 if (thePt.X == -1) {
				 FinishGame();
				 return;
			 }
			 UpdateDisplay(thePt.X,thePt.Y);
			 UpdateDisplay(prevPt.X,prevPt.Y);
			 DisplayCharacterItems(theMap->getCurrentCharacter());
			 if (Logger::currentLogInfo != String::Empty){
				 ui_lbl_currentLog->Text = Logger::currentLogInfo;
				 Logger::currentLogInfo == String::Empty;
			 }
		 }

		 void FinishGame(){
			 MessageBox::Show("DONE");
		 }
private: System::Void loadCharacterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			theChar = new Character(3,5);
			theChar->setDefaultItems();
			theMap->AddCharacter(theChar);
			UpdateDisplay(theMap->GetXStartPosition(),theMap->GetYStartPosition());
			
			DisplayCharacterItems(theChar);
			DisplayCharEquipments(theChar);
		 }
private: System::Void ui_group_map_Resize(System::Object^  sender, System::EventArgs^  e) {
			 ui_pan_items->Top = ui_group_map->Top + ui_group_map->Height + 20;
		 }

		 void DisplayCharEquipments(Character* toDisp){
			 int prevX = 20;
			 EquipGrid = gcnew array<Label^, 1>(8);
			 ui_pan_equpment->Controls->Clear();
			 toDisp = theMap->getCurrentCharacter();
			 for (int i=0;i<8;i++){
				 EquipGrid[i] = gcnew Label();
				 EquipGrid[i]->Location = System::Drawing::Point(prevX, 20);
				 ui_pan_equpment->Controls->Add(EquipGrid[i]);
				 prevX += EquipGrid[i]->Width+10;
			 }
			 EquipGrid[0]->Text = gcnew String(toDisp->belt->getType().c_str());
			 EquipGrid[1]->Text = gcnew String(toDisp->boots->getType().c_str());
			 EquipGrid[2]->Text = gcnew String(toDisp->bracers->getType().c_str());
			 EquipGrid[3]->Text=gcnew String(toDisp->helmet->getType().c_str());
			 EquipGrid[4]->Text=gcnew String(toDisp->armor->getType().c_str());
			 EquipGrid[5]->Text=gcnew String(toDisp->weapon->getType().c_str());
			 EquipGrid[6]->Text=gcnew String(toDisp->ring->getType().c_str());
			 EquipGrid[7]->Text=gcnew String(toDisp->shield->getType().c_str());
		 }

		 void DisplayCharacterItems(Character* toDisp){
			 vector<Item> theItems = toDisp->getListOfItems();
			 int prevX = 20;
			 ItemGrid = gcnew array<CheckBox^, 1>(theItems.size());
			 System::String^ temp;
			 std::string tempChar;
			 for (int i=0;i<theItems.size();i++){
				 ItemGrid[i] = gcnew CheckBox();
				 tempChar = theItems[i].getType();
				 temp = gcnew System::String(tempChar.c_str());
				 ItemGrid[i]->Text = temp;
				 
				 ItemGrid[i]->Location = System::Drawing::Point(prevX, 20);
				 ItemGrid[i]->Tag = i;
				 ItemGrid[i]->CheckedChanged += gcnew EventHandler(this,&ui_frm_game::itemsChecked); 
				 ui_pan_items->Controls->Add(ItemGrid[i]);

				 prevX += ItemGrid[i]->Width + 10;
			 }
		 }
		 private: System::Void itemsChecked(Object^  sender, EventArgs^  e) {
					 CheckBox^ chk = (CheckBox^)sender;
					 Character* aChar = theMap->getCurrentCharacter();
					 int theIndex = (int)chk->Tag;
					 aChar->equip(theIndex);
					 DisplayCharacterItems(aChar);
					 DisplayCharEquipments(aChar);
					 
				 }
private: System::Void ui_pan_items_Resize(System::Object^  sender, System::EventArgs^  e) {
			 ui_pan_equpment->Left = ui_pan_items->Left + ui_pan_items->Width + 20;
		 }
};
}
