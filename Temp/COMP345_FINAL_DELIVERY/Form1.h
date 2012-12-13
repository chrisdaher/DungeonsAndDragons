#pragma once
#include "Builder.h"
#include "Map.h"
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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 437);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	void DisplayMap(Map* theMap){
		int width = theMap->GetX();
		int height = theMap->GetY();
		int prevX = 0;
		int prevY = 0;
		array<PictureBox^, 2>^ MapGrid = gcnew array<PictureBox^, 2>(width,height);

		Bitmap^ theImg = gcnew Bitmap("Img\\openBlock.jpg");

		for (int i=0;i<width;i++){
			for (int k=0;k<height;k++){
				MapGrid[i,k]=gcnew PictureBox;
				MapGrid[i,k]->Location = Point(prevX, prevY);
				MapGrid[i,k]->Size = System::Drawing::Size(20,20);
				MapGrid[i,k]->BorderStyle = BorderStyle::FixedSingle;
				MapGrid[i,k]->Image = theImg;
				Controls->Add(MapGrid[i,k]);

				if (k < (height - 1)){
					prevX += MapGrid[i,k]->Width;
				}
				else{
					prevX = 0;
					prevY += MapGrid[i,k]->Height;
				}
			}
		}
	}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 d20Logic::Builder* theBuilder = new d20Logic::ArenaBuilder();
				 theBuilder->BuildMap();
				 Map* theMap = theBuilder->getMap();
				 DisplayMap(theMap);
				 //Builder* theBuilder= new ArenaBuilder();
				 /*theBuilder->BuildMap();
				 theMap=theBuilder->getMap();
				 MapObserver* observer= new CmdDisplay();
				 theMap->RegisterObserver(observer);
				 PlayGame();*/
				 
			 }
	};
}

