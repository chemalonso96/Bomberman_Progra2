#pragma once
#include"Controlador.h"
#include"Arrbomba.h"
#include"arrbloque.h"
#include"arrprofesormaligno.h"
#include"Items.h"

namespace chemabomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Controlador* obj_controlador;
		arrbloque* obj_arrbloque;
		arrbomba* obj_arrbomba;
		arritems* obj_arritems;
		arrprofesormaligno* obj_arrprofesormaligno;
		Graphics^gr;
		BufferedGraphicsContext^bgc;
		BufferedGraphics^bg;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labTIEMPO;
	private: System::Windows::Forms::Label^  labVIDA;
	private: System::Windows::Forms::Label^  labPUNTAJE;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  Labbomba;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fILEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oPENToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sAVEADDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sAVEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  eXITToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nEWToolStripMenuItem;

			 botones tecla_verificar;
	public:
		MyForm(void)
		{
			obj_controlador = new Controlador();
			obj_arrbomba = new arrbomba();
			obj_arrbloque = new arrbloque();
			obj_arritems = new arritems();
			obj_arrprofesormaligno = new arrprofesormaligno();
			obj_controlador->obj_arrprofesormaligno = obj_arrprofesormaligno;
			obj_arritems->obj_upecino = obj_controlador->obj_upecino;
			obj_arrbomba->obj_arrbloques = obj_arrbloque;
			tecla_verificar = botones::ninguno;

			InitializeComponent();
			gr = this->CreateGraphics();
			bgc = BufferedGraphicsManager::Current;
			bg = bgc->Allocate(gr, this->ClientRectangle);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete obj_controlador;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labTIEMPO = (gcnew System::Windows::Forms::Label());
			this->labVIDA = (gcnew System::Windows::Forms::Label());
			this->labPUNTAJE = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Labbomba = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fILEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oPENToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sAVEADDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sAVEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eXITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nEWToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 5;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 500;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(833, 116);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TIEMPO :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(833, 214);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"VIDA :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(833, 304);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"PUNTAJE :";
			// 
			// labTIEMPO
			// 
			this->labTIEMPO->AutoSize = true;
			this->labTIEMPO->Location = System::Drawing::Point(837, 160);
			this->labTIEMPO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labTIEMPO->Name = L"labTIEMPO";
			this->labTIEMPO->Size = System::Drawing::Size(0, 17);
			this->labTIEMPO->TabIndex = 3;
			// 
			// labVIDA
			// 
			this->labVIDA->AutoSize = true;
			this->labVIDA->Location = System::Drawing::Point(837, 257);
			this->labVIDA->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labVIDA->Name = L"labVIDA";
			this->labVIDA->Size = System::Drawing::Size(0, 17);
			this->labVIDA->TabIndex = 4;
			// 
			// labPUNTAJE
			// 
			this->labPUNTAJE->AutoSize = true;
			this->labPUNTAJE->Location = System::Drawing::Point(837, 347);
			this->labPUNTAJE->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labPUNTAJE->Name = L"labPUNTAJE";
			this->labPUNTAJE->Size = System::Drawing::Size(0, 17);
			this->labPUNTAJE->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(837, 396);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"BOMBAS";
			// 
			// Labbomba
			// 
			this->Labbomba->AutoSize = true;
			this->Labbomba->Location = System::Drawing::Point(837, 448);
			this->Labbomba->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Labbomba->Name = L"Labbomba";
			this->Labbomba->Size = System::Drawing::Size(0, 17);
			this->Labbomba->TabIndex = 7;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fILEToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(979, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fILEToolStripMenuItem
			// 
			this->fILEToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->oPENToolStripMenuItem,
					this->sAVEADDToolStripMenuItem, this->sAVEToolStripMenuItem, this->eXITToolStripMenuItem, this->nEWToolStripMenuItem
			});
			this->fILEToolStripMenuItem->Name = L"fILEToolStripMenuItem";
			this->fILEToolStripMenuItem->Size = System::Drawing::Size(47, 24);
			this->fILEToolStripMenuItem->Text = L"FILE";
			// 
			// oPENToolStripMenuItem
			// 
			this->oPENToolStripMenuItem->Name = L"oPENToolStripMenuItem";
			this->oPENToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->oPENToolStripMenuItem->Text = L"OPEN";
			// 
			// sAVEADDToolStripMenuItem
			// 
			this->sAVEADDToolStripMenuItem->Name = L"sAVEADDToolStripMenuItem";
			this->sAVEADDToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->sAVEADDToolStripMenuItem->Text = L"SAVE ADD";
			// 
			// sAVEToolStripMenuItem
			// 
			this->sAVEToolStripMenuItem->Name = L"sAVEToolStripMenuItem";
			this->sAVEToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->sAVEToolStripMenuItem->Text = L"SAVE";
			// 
			// eXITToolStripMenuItem
			// 
			this->eXITToolStripMenuItem->Name = L"eXITToolStripMenuItem";
			this->eXITToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->eXITToolStripMenuItem->Text = L"EXIT";
			// 
			// nEWToolStripMenuItem
			// 
			this->nEWToolStripMenuItem->Name = L"nEWToolStripMenuItem";
			this->nEWToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->nEWToolStripMenuItem->Text = L"NEW";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 555);
			this->Controls->Add(this->Labbomba);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labPUNTAJE);
			this->Controls->Add(this->labVIDA);
			this->Controls->Add(this->labTIEMPO);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		obj_controlador->accionar(bg->Graphics, tecla_verificar);
		labVIDA->Text = obj_controlador->obj_upecino->vida.ToString();
		labTIEMPO->Text = obj_controlador->tiempoNivel.ToString();
		labPUNTAJE->Text = obj_controlador->obj_upecino->puntaje.ToString();
		Labbomba->Text = obj_controlador->obj_upecino->N_bombas.ToString();
		if (obj_controlador->obj_upecino->vida == 0){
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE PROFESOR INTENTELO NUEVAMENTE  - USTED HA FINALIZADO CON UN TIEMPO DE " +
				obj_controlador->tiempoNivel.ToString() + "   SEGUNDOS   " +
				obj_controlador->obj_upecino->vida.ToString() + "   VIDAS   " +
				obj_controlador->obj_upecino->puntaje.ToString() + "    PUNTOS    " +
				obj_controlador->obj_upecino->N_bombas.ToString() + "    BOMBAS   ");
		}
		if (obj_controlador->obj_upecino->puntaje == 150){
			timer1->Enabled = false;
			MessageBox::Show("ME MUERO GANASTE PROFESOR - USTED HA FINALIZADO CON UN TIEMPO DE " +
				obj_controlador->tiempoNivel.ToString() + "   SEGUNDOS   " +
				obj_controlador->obj_upecino->vida.ToString() + "   VIDAS   " +
				obj_controlador->obj_upecino->puntaje.ToString() + "    PUNTOS    " +
				obj_controlador->obj_upecino->N_bombas.ToString() + "    BOMBAS   ");
		}
		if (obj_controlador->tiempoNivel==150){
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE PROFESOR INTENTELO NUEVAMENTE  - USTED HA FINALIZADO CON UN TIEMPO DE " +
				obj_controlador->tiempoNivel.ToString() + "   SEGUNDOS   " +
				obj_controlador->obj_upecino->vida.ToString() + "   VIDAS   " +
				obj_controlador->obj_upecino->puntaje.ToString() + "    PUNTOS    " +
				obj_controlador->obj_upecino->N_bombas.ToString() + "    BOMBAS   ");
			obj_controlador->obj_upecino->SET_dx(5);
			obj_controlador->obj_upecino->SET_dy(5);
		}
		//=====bomba
		obj_arrbomba->mostrar_bomba(bg->Graphics);
		obj_arritems->mostrar(bg->Graphics, obj_controlador->id_escenas);
		obj_arrbloque->mostrar(bg->Graphics, obj_controlador->id_escenas);
		//=====arritems
		obj_arritems->mostrar(bg->Graphics, obj_controlador->id_escenas);
		obj_arritems->desaparecer_items(obj_controlador->id_escenas);
		obj_arrprofesormaligno->mostrar_enemigos(bg->Graphics, obj_controlador->id_escenas);
		this->Text = " y : " + obj_controlador->obj_upecino->GET_y().ToString() + " x : " + obj_controlador->obj_upecino->GET_x().ToString();
		bg->Render(gr);

	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (obj_arrbomba != NULL)
		{
			obj_arrbomba->mostrar_bomba(gr);
			obj_arrbomba->explotar_bombas(gr);
		}
		bg->Render(gr);
	}

	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter){
			tecla_verificar = botones::enter;
			void PlayBackgroundMusic(); {
				System::Media::SoundPlayer ^fondo = gcnew System::Media::SoundPlayer();
				fondo->SoundLocation = "Music\\SuperBomberman.wav";
				fondo->Load();
				fondo->Play(); }
		}
		if (e->KeyCode == Keys::D1){ 
			tecla_verificar = botones::d1; 
		}
		if (e->KeyCode == Keys::D2){
			tecla_verificar = botones::d2;

		}
		if (e->KeyCode == Keys::D3){
			tecla_verificar = botones::d3;
		}
		if (e->KeyCode == Keys::D4){
			tecla_verificar = botones::d4;
		}
		if (e->KeyCode == Keys::D5)tecla_verificar = botones::d5;
		if (e->KeyCode == Keys::I)tecla_verificar = botones::i;
		if (e->KeyCode == Keys::R)tecla_verificar = botones::r;
		if (e->KeyCode == Keys::V)tecla_verificar = botones::v;
		if (e->KeyCode == Keys::F)tecla_verificar = botones::f;
		//teclas para elegir personaje=======================
		if (e->KeyCode == Keys::G)tecla_verificar = botones::g;
		if (e->KeyCode == Keys::H)tecla_verificar = botones::h;
		if (e->KeyCode == Keys::J)tecla_verificar = botones::j;
		if (e->KeyCode == Keys::K)tecla_verificar = botones::k;
		if (e->KeyCode == Keys::L)tecla_verificar = botones::l;
		//====================================================
		if (e->KeyCode == Keys::Escape)tecla_verificar = botones::esc;
		if (e->KeyCode == Keys::Space){
			obj_arrbomba->colocar_bomba(obj_controlador->obj_upecino->GET_x(), obj_controlador->obj_upecino->GET_y());
			void PlayBackgroundMusic(); {
				System::Media::SoundPlayer ^fondo = gcnew System::Media::SoundPlayer();
				fondo->SoundLocation = "Music\\Explosion_bomba.wav";
				fondo->Load();
				fondo->Play(); }
		}
		//contrinuar
		if (e->KeyCode == Keys::C){
			tecla_verificar = botones::c;
			timer1->Enabled = true;
		}
		//pausa
		if (e->KeyCode == Keys::F2){
			timer1->Enabled = false;
			obj_controlador->mostrar_pausa(gr);
		}
		//colocar bomba
		if (e->KeyCode == Keys::Space){ obj_arrbomba->colocar_bomba(obj_controlador->obj_upecino->GET_x(), obj_controlador->obj_upecino->GET_y()); }

		//movimiento personaje
		if (e->KeyCode == Keys::Down){
			obj_controlador->mover_personaje(Direction::abajo);
		}
		if (e->KeyCode == Keys::Left){
			obj_controlador->mover_personaje(Direction::izquierda);
		}
		if (e->KeyCode == Keys::Up){
			obj_controlador->mover_personaje(Direction::arriba);
		}
		if (e->KeyCode == Keys::Right){
			obj_controlador->mover_personaje(Direction::derecha);
		}
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		gr = this->CreateGraphics();
		bgc = BufferedGraphicsManager::Current;
		bg = bgc->Allocate(gr, this->ClientRectangle);
		void PlayBackgroundMusic(); {
			System::Media::SoundPlayer ^fondo = gcnew System::Media::SoundPlayer();
			fondo->SoundLocation = "Music\\musique.wav";
			fondo->Load();
			fondo->Play();
		}
	}
};
}