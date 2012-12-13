#pragma once
#include "Builder.h"
#include "Map.h"
#include "Block.h"
#include "FormsHelper.h"

namespace COMP345_FINAL_DELIVERY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace d20Logic;
	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  ui_group_map;
	private: System::Windows::Forms::GroupBox^  ui_gb_toolbox;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  ui_pb_wall;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  ui_pb_treasure;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  ui_pb_exit;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  ui_pb_entrance;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  ui_pb_empty;
	private: System::Windows::Forms::Button^  ui_btn_create;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ui_txt_mapHeight;
	private: System::Windows::Forms::TextBox^  ui_txt_mapWidth;
	private: System::Windows::Forms::Panel^  ui_panel_mapCreate;
	private: System::Windows::Forms::Panel^  ui_pan_load;
	private: System::Windows::Forms::Button^  ui_btn_load;
	private: System::Windows::Forms::Panel^  ui_pan_save;
	private: System::Windows::Forms::Button^  ui_btn_save;
	private: System::Windows::Forms::TextBox^  ui_txt_fileName;
	private: System::Windows::Forms::OpenFileDialog^  ui_dia_open;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  ui_btn_loadDef;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::PictureBox^  ui_pb_selected;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  backToMenuToolStripMenuItem;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PictureBox^  ui_pb_monster;



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
			this->ui_gb_toolbox = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_monster = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_selected = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ui_btn_loadDef = (gcnew System::Windows::Forms::Button());
			this->ui_pan_load = (gcnew System::Windows::Forms::Panel());
			this->ui_btn_load = (gcnew System::Windows::Forms::Button());
			this->ui_pan_save = (gcnew System::Windows::Forms::Panel());
			this->ui_btn_save = (gcnew System::Windows::Forms::Button());
			this->ui_txt_fileName = (gcnew System::Windows::Forms::TextBox());
			this->ui_panel_mapCreate = (gcnew System::Windows::Forms::Panel());
			this->ui_btn_create = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ui_txt_mapHeight = (gcnew System::Windows::Forms::TextBox());
			this->ui_txt_mapWidth = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_wall = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_treasure = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_exit = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_entrance = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ui_pb_empty = (gcnew System::Windows::Forms::PictureBox());
			this->ui_dia_open = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backToMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ui_gb_toolbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_monster))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_selected))->BeginInit();
			this->panel1->SuspendLayout();
			this->ui_pan_load->SuspendLayout();
			this->ui_pan_save->SuspendLayout();
			this->ui_panel_mapCreate->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_wall))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_treasure))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_entrance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_empty))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ui_group_map
			// 
			this->ui_group_map->AutoSize = true;
			this->ui_group_map->Location = System::Drawing::Point(55, 90);
			this->ui_group_map->Name = L"ui_group_map";
			this->ui_group_map->Size = System::Drawing::Size(333, 268);
			this->ui_group_map->TabIndex = 0;
			this->ui_group_map->TabStop = false;
			this->ui_group_map->Text = L"The Map";
			this->ui_group_map->Enter += gcnew System::EventHandler(this, &Form1::ui_group_map_Enter);
			this->ui_group_map->Resize += gcnew System::EventHandler(this, &Form1::ui_group_map_Resize);
			// 
			// ui_gb_toolbox
			// 
			this->ui_gb_toolbox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ui_gb_toolbox->Controls->Add(this->label8);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_monster);
			this->ui_gb_toolbox->Controls->Add(this->label7);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_selected);
			this->ui_gb_toolbox->Controls->Add(this->panel1);
			this->ui_gb_toolbox->Controls->Add(this->ui_pan_load);
			this->ui_gb_toolbox->Controls->Add(this->ui_pan_save);
			this->ui_gb_toolbox->Controls->Add(this->ui_panel_mapCreate);
			this->ui_gb_toolbox->Controls->Add(this->label5);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_wall);
			this->ui_gb_toolbox->Controls->Add(this->label4);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_treasure);
			this->ui_gb_toolbox->Controls->Add(this->label3);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_exit);
			this->ui_gb_toolbox->Controls->Add(this->label2);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_entrance);
			this->ui_gb_toolbox->Controls->Add(this->label1);
			this->ui_gb_toolbox->Controls->Add(this->ui_pb_empty);
			this->ui_gb_toolbox->Location = System::Drawing::Point(423, 30);
			this->ui_gb_toolbox->Name = L"ui_gb_toolbox";
			this->ui_gb_toolbox->Size = System::Drawing::Size(290, 457);
			this->ui_gb_toolbox->TabIndex = 1;
			this->ui_gb_toolbox->TabStop = false;
			this->ui_gb_toolbox->Text = L"Toolbox";
			this->ui_gb_toolbox->Enter += gcnew System::EventHandler(this, &Form1::ui_gb_toolbox_Enter);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 234);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Monster";
			// 
			// ui_pb_monster
			// 
			this->ui_pb_monster->Location = System::Drawing::Point(116, 234);
			this->ui_pb_monster->Name = L"ui_pb_monster";
			this->ui_pb_monster->Size = System::Drawing::Size(20, 20);
			this->ui_pb_monster->TabIndex = 20;
			this->ui_pb_monster->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(176, 109);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(82, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Selected Block:";
			// 
			// ui_pb_selected
			// 
			this->ui_pb_selected->Location = System::Drawing::Point(264, 103);
			this->ui_pb_selected->Name = L"ui_pb_selected";
			this->ui_pb_selected->Size = System::Drawing::Size(20, 20);
			this->ui_pb_selected->TabIndex = 18;
			this->ui_pb_selected->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->ui_btn_loadDef);
			this->panel1->Location = System::Drawing::Point(159, 372);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(99, 80);
			this->panel1->TabIndex = 17;
			// 
			// ui_btn_loadDef
			// 
			this->ui_btn_loadDef->Location = System::Drawing::Point(3, 47);
			this->ui_btn_loadDef->Name = L"ui_btn_loadDef";
			this->ui_btn_loadDef->Size = System::Drawing::Size(93, 23);
			this->ui_btn_loadDef->TabIndex = 14;
			this->ui_btn_loadDef->Text = L"Load Default";
			this->ui_btn_loadDef->UseVisualStyleBackColor = true;
			this->ui_btn_loadDef->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// ui_pan_load
			// 
			this->ui_pan_load->Controls->Add(this->ui_btn_load);
			this->ui_pan_load->Location = System::Drawing::Point(159, 286);
			this->ui_pan_load->Name = L"ui_pan_load";
			this->ui_pan_load->Size = System::Drawing::Size(99, 80);
			this->ui_pan_load->TabIndex = 16;
			// 
			// ui_btn_load
			// 
			this->ui_btn_load->Location = System::Drawing::Point(3, 47);
			this->ui_btn_load->Name = L"ui_btn_load";
			this->ui_btn_load->Size = System::Drawing::Size(93, 23);
			this->ui_btn_load->TabIndex = 14;
			this->ui_btn_load->Text = L"Load Map";
			this->ui_btn_load->UseVisualStyleBackColor = true;
			this->ui_btn_load->Click += gcnew System::EventHandler(this, &Form1::ui_btn_load_Click);
			// 
			// ui_pan_save
			// 
			this->ui_pan_save->Controls->Add(this->ui_btn_save);
			this->ui_pan_save->Controls->Add(this->ui_txt_fileName);
			this->ui_pan_save->Location = System::Drawing::Point(30, 378);
			this->ui_pan_save->Name = L"ui_pan_save";
			this->ui_pan_save->Size = System::Drawing::Size(99, 64);
			this->ui_pan_save->TabIndex = 15;
			this->ui_pan_save->Visible = false;
			// 
			// ui_btn_save
			// 
			this->ui_btn_save->Location = System::Drawing::Point(9, 41);
			this->ui_btn_save->Name = L"ui_btn_save";
			this->ui_btn_save->Size = System::Drawing::Size(79, 23);
			this->ui_btn_save->TabIndex = 14;
			this->ui_btn_save->Text = L"Save Map";
			this->ui_btn_save->UseVisualStyleBackColor = true;
			this->ui_btn_save->Click += gcnew System::EventHandler(this, &Form1::ui_btn_save_Click);
			// 
			// ui_txt_fileName
			// 
			this->ui_txt_fileName->Location = System::Drawing::Point(9, 9);
			this->ui_txt_fileName->Name = L"ui_txt_fileName";
			this->ui_txt_fileName->Size = System::Drawing::Size(81, 20);
			this->ui_txt_fileName->TabIndex = 0;
			// 
			// ui_panel_mapCreate
			// 
			this->ui_panel_mapCreate->Controls->Add(this->ui_btn_create);
			this->ui_panel_mapCreate->Controls->Add(this->label6);
			this->ui_panel_mapCreate->Controls->Add(this->ui_txt_mapHeight);
			this->ui_panel_mapCreate->Controls->Add(this->ui_txt_mapWidth);
			this->ui_panel_mapCreate->Location = System::Drawing::Point(27, 286);
			this->ui_panel_mapCreate->Name = L"ui_panel_mapCreate";
			this->ui_panel_mapCreate->Size = System::Drawing::Size(102, 80);
			this->ui_panel_mapCreate->TabIndex = 14;
			// 
			// ui_btn_create
			// 
			this->ui_btn_create->Location = System::Drawing::Point(15, 47);
			this->ui_btn_create->Name = L"ui_btn_create";
			this->ui_btn_create->Size = System::Drawing::Size(79, 23);
			this->ui_btn_create->TabIndex = 13;
			this->ui_btn_create->Text = L"Create Map";
			this->ui_btn_create->UseVisualStyleBackColor = true;
			this->ui_btn_create->Click += gcnew System::EventHandler(this, &Form1::ui_btn_create_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(47, 11);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"x";
			// 
			// ui_txt_mapHeight
			// 
			this->ui_txt_mapHeight->Location = System::Drawing::Point(65, 8);
			this->ui_txt_mapHeight->Name = L"ui_txt_mapHeight";
			this->ui_txt_mapHeight->Size = System::Drawing::Size(26, 20);
			this->ui_txt_mapHeight->TabIndex = 11;
			// 
			// ui_txt_mapWidth
			// 
			this->ui_txt_mapWidth->Location = System::Drawing::Point(15, 8);
			this->ui_txt_mapWidth->Name = L"ui_txt_mapWidth";
			this->ui_txt_mapWidth->Size = System::Drawing::Size(26, 20);
			this->ui_txt_mapWidth->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 196);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Wall Block";
			// 
			// ui_pb_wall
			// 
			this->ui_pb_wall->Location = System::Drawing::Point(116, 195);
			this->ui_pb_wall->Name = L"ui_pb_wall";
			this->ui_pb_wall->Size = System::Drawing::Size(20, 20);
			this->ui_pb_wall->TabIndex = 8;
			this->ui_pb_wall->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Treasure Block";
			// 
			// ui_pb_treasure
			// 
			this->ui_pb_treasure->Location = System::Drawing::Point(116, 153);
			this->ui_pb_treasure->Name = L"ui_pb_treasure";
			this->ui_pb_treasure->Size = System::Drawing::Size(20, 20);
			this->ui_pb_treasure->TabIndex = 6;
			this->ui_pb_treasure->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Exit Block";
			// 
			// ui_pb_exit
			// 
			this->ui_pb_exit->Location = System::Drawing::Point(116, 102);
			this->ui_pb_exit->Name = L"ui_pb_exit";
			this->ui_pb_exit->Size = System::Drawing::Size(20, 20);
			this->ui_pb_exit->TabIndex = 4;
			this->ui_pb_exit->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Entrance Block";
			// 
			// ui_pb_entrance
			// 
			this->ui_pb_entrance->Location = System::Drawing::Point(116, 59);
			this->ui_pb_entrance->Name = L"ui_pb_entrance";
			this->ui_pb_entrance->Size = System::Drawing::Size(20, 20);
			this->ui_pb_entrance->TabIndex = 2;
			this->ui_pb_entrance->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Empty Block";
			// 
			// ui_pb_empty
			// 
			this->ui_pb_empty->Location = System::Drawing::Point(116, 23);
			this->ui_pb_empty->Name = L"ui_pb_empty";
			this->ui_pb_empty->Size = System::Drawing::Size(20, 20);
			this->ui_pb_empty->TabIndex = 0;
			this->ui_pb_empty->TabStop = false;
			// 
			// ui_dia_open
			// 
			this->ui_dia_open->FileName = L"openFileDialog1";
			this->ui_dia_open->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::ui_dia_open_FileOk);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(760, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadToolStripMenuItem, 
				this->saveToolStripMenuItem, this->backToMenuToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// backToMenuToolStripMenuItem
			// 
			this->backToMenuToolStripMenuItem->Name = L"backToMenuToolStripMenuItem";
			this->backToMenuToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->backToMenuToolStripMenuItem->Text = L"Back to menu";
			this->backToMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::backToMenuToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(760, 499);
			this->Controls->Add(this->ui_gb_toolbox);
			this->Controls->Add(this->ui_group_map);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Map Editor";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ui_gb_toolbox->ResumeLayout(false);
			this->ui_gb_toolbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_monster))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_selected))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ui_pan_load->ResumeLayout(false);
			this->ui_pan_save->ResumeLayout(false);
			this->ui_pan_save->PerformLayout();
			this->ui_panel_mapCreate->ResumeLayout(false);
			this->ui_panel_mapCreate->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_wall))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_treasure))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_entrance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ui_pb_empty))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#define BLOCK_SIZE 20;
	
		PictureBox^ pbPrevious;
		Map* theMap;
		Block *selectedBlock;


	void notify(Block** theBlock, int sizeX, int sizeY){


	}
	void DisplayMap(Map* theMap){
		int width = theMap->GetX();
		int height = theMap->GetY();
		int prevX = 0;
		int prevY = 20;
		int blockSize = BLOCK_SIZE;
		array<PictureBox^, 2>^ MapGrid = gcnew array<PictureBox^, 2>(width,height);

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
				MapGrid[i,k]->MouseClick += gcnew MouseEventHandler(this, &Form1::imgMapClicked);
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

	void LoadToolBarImages(){
		WallBlock* wb = new WallBlock();
		EmptyBlock* eb = new EmptyBlock();
		EntranceBlock* entrance = new EntranceBlock();
		ExitBlock* exit = new ExitBlock();
		TreasureBlock* treasure = new TreasureBlock();
		Character* monster = new Character();

		String^ tempString;
		tempString = gcnew String(wb->getSprite());
		ui_pb_wall->Image = Image::FromFile(tempString);
		ui_pb_wall->MouseClick += gcnew MouseEventHandler(this, &Form1::imgWallClicked);

		tempString = gcnew String(eb->getSprite());
		ui_pb_empty->Image = Image::FromFile(tempString);
		ui_pb_empty->MouseClick += gcnew MouseEventHandler(this, &Form1::imgEmptyClicked);

		tempString = gcnew String(entrance->getSprite());
		ui_pb_entrance->Image = Image::FromFile(tempString);
		ui_pb_entrance->MouseClick += gcnew MouseEventHandler(this, &Form1::imgEntranceClicked);


		tempString = gcnew String(exit->getSprite());
		ui_pb_exit->Image = Image::FromFile(tempString);
		ui_pb_exit->MouseClick += gcnew MouseEventHandler(this, &Form1::imgExitClicked);

		tempString = gcnew String(treasure->getSprite());
		ui_pb_treasure->Image = Image::FromFile(tempString);
		ui_pb_treasure->MouseClick += gcnew MouseEventHandler(this, &Form1::imgTreasureClicked);

		tempString = gcnew String(monster->getSprite());
		ui_pb_monster->Image = Image::FromFile(tempString);
		ui_pb_monster->MouseClick += gcnew MouseEventHandler(this, &Form1::imgMonsterClicked);
	}

	private: System::Void imgMonsterClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new Character();
			 }

	private: System::Void imgWallClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new WallBlock();
			 }
	private: System::Void imgEmptyClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new EmptyBlock();
			  }
	private: System::Void imgEntranceClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new EntranceBlock();
			  }
	private: System::Void imgExitClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new ExitBlock();
			 }
	private: System::Void imgTreasureClicked(Object^ sender, MouseEventArgs^ e){
				 PictureBox^ pb = (PictureBox^)sender;
				 ui_pb_selected->Image = pb->Image;
				 selectedBlock = new TreasureBlock();
			 }

	private: System::Void imgMapClicked(Object^ sender, MouseEventArgs^ e){
				 if (!selectedBlock) return;
				 PictureBox^ theImg = (PictureBox^) sender;
				 System::Drawing::Point theLoc = (System::Drawing::Point)theImg->Tag;
				 if (pbPrevious){
					 pbPrevious->BorderStyle = BorderStyle::None;
				 }

				 theImg->Image = Image::FromFile(gcnew String(selectedBlock->getSprite()));
				 theMap->SetBlockValue(theLoc.X,theLoc.Y,selectedBlock);
				 pbPrevious = theImg;

				 theImg->BorderStyle = BorderStyle::FixedSingle;
			 }
	private: System::Void FormClosed(Object^ sender, EventArgs^ e){

				 
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {			 
				 this->Closed +=gcnew EventHandler(this, &Form1::FormClosed);

				 ui_group_map->Visible = false;
				 LoadToolBarImages();
				 
				 /*d20Logic::Builder* theBuilder = new d20Logic::ArenaBuilder();
				 theBuilder->BuildMap();
				 Map* theMap = theBuilder->getMap();
				 DisplayMap(theMap);*/
				 
				 //Builder* theBuilder= new ArenaBuilder();
				 /*theBuilder->BuildMap();
				 theMap=theBuilder->getMap();
				 MapObserver* observer= new CmdDisplay();
				 theMap->RegisterObserver(observer);
				 PlayGame();*/
				 
			 }
	private: System::Void ui_btn_create_Click(System::Object^  sender, System::EventArgs^  e) {
				 int mapWidth;
				 int mapHeight;
				 try{
					mapWidth = System::Convert::ToInt32(ui_txt_mapWidth->Text);
					mapHeight = System::Convert::ToInt32(ui_txt_mapHeight->Text);
				 }catch(Exception ^e){
					 MessageBox::Show("Invalid Input!");
					 return;
				 }

				 theMap = new Map(mapWidth,mapHeight);
				 DisplayMap(theMap);
				 ui_panel_mapCreate->Visible = false;
				 ui_pan_save->Visible = true;

			 }
private: System::Void ui_group_map_Resize(System::Object^  sender, System::EventArgs^  e) {
			 ui_gb_toolbox->Left = ui_group_map->Left + ui_group_map->Width + 20;
		 }

private: System::Void ui_btn_save_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveMap();
		 }
private: System::Void ui_dia_open_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 
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

			 ui_pan_save->Visible = true;
		 }

		 void saveMap(){
			 String^ fileName = ui_txt_fileName->Text;
			 if (fileName == String::Empty){
				 MessageBox::Show("Invalid filename input");
				 return;
			 }

			 theMap->saveMap(fileName);
			 MessageBox::Show("Saved!");
		 }
private: System::Void ui_btn_load_Click(System::Object^  sender, System::EventArgs^  e) {
			 loadMap();

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Builder* arena = new ArenaBuilder();
			 arena->BuildMap();
			 theMap = arena->getMap();
			 DisplayMap(theMap);

			 ui_pan_save->Visible = true;
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 loadMap();

		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveMap();
		 }


private: System::Void backToMenuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 
		 }
private: System::Void ui_gb_toolbox_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ui_group_map_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

