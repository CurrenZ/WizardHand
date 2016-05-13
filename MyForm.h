#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>
#include <time.h>

#include"IMU_SP.h"

namespace WizardHandDrive {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Text;
	using namespace System::Threading;
	/// <summary>
	/// Summary for MyForm
	/// </summary>

	clock_t clock0;
	clock_t clock1;
	clock_t deltaT;
	float dt = 0.1f;

	int progress_value = 0;

	bool DeviceEnable = false;
	bool ReadDataEnable = false;
	bool Calibrated = false;
	bool CursorEnable = true;
	bool FunctionEnable = true;

	Int16 ax, ay, az;
	Int16 gx, gy, gz;
	Int16 mx, my, mz;

	float q0 = 1.0, q1 = 0.0, q2 = 0.0, q3 = 0.0;
	float lpf_q0, lpf_q1, lpf_q2, lpf_q3;

	Int16 sp0, sp1, sp2, sp3, sp4;
	Int16 five_fingers;

	float sensitivity = -3.0;

	float x, y;

	float acclx, accly, acclz;
	float gyrox, gyroy, gyroz;
	float magnx, magny, magnz;

	float gyro_bias_x = 0.0f, gyro_bias_y = 0.0f, gyro_bias_z = 0.0f;

	float lpf_ax, lpf_ay, lpf_az;
	float lpf_mx, lpf_my, lpf_mz;

	float cursorx, cursory;

	//float qw = 1.0f, qx = 0.0f, qy = 0.0f, qz = 0.0f;

	double counter = 0;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();
			//
			//TODO: Add the constructor code here
			//
		}

		
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::GroupBox^  groupBox8;









	private: System::Windows::Forms::TextBox^  textBox18;



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage3;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;

	private: System::Windows::Forms::GroupBox^  groupBox5;


	//protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(800, 492);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage1.BackgroundImage")));
			this->tabPage1->Controls->Add(this->groupBox8);
			this->tabPage1->Controls->Add(this->checkBox6);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->progressBar1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(792, 463);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Connection";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->checkBox8);
			this->groupBox8->Controls->Add(this->checkBox7);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox8->Location = System::Drawing::Point(224, 123);
			this->groupBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox8->Size = System::Drawing::Size(357, 106);
			this->groupBox8->TabIndex = 9;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Switches";
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Checked = true;
			this->checkBox8->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox8->Location = System::Drawing::Point(208, 43);
			this->checkBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(110, 32);
			this->checkBox8->TabIndex = 8;
			this->checkBox8->Text = L"Function";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox8_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Checked = true;
			this->checkBox7->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox7->Location = System::Drawing::Point(25, 43);
			this->checkBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(93, 32);
			this->checkBox7->TabIndex = 7;
			this->checkBox7->Text = L"Mouse";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox6->Location = System::Drawing::Point(464, 73);
			this->checkBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(106, 32);
			this->checkBox6->TabIndex = 6;
			this->checkBox6->Text = L"Wireless";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(11, 384);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 31);
			this->label2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(220, 53);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Please Select COM Port";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(224, 73);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(216, 24);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(11, 418);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(764, 28);
			this->progressBar1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(413, 263);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(168, 63);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(224, 263);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(168, 63);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox7);
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->trackBar1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(792, 463);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Customize";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->textBox20);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox7->Location = System::Drawing::Point(376, 31);
			this->groupBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox7->Size = System::Drawing::Size(399, 251);
			this->groupBox7->TabIndex = 8;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Mouse Functions and Hot-Keys Monitor";
			// 
			// textBox20
			// 
			this->textBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox20->ForeColor = System::Drawing::SystemColors::Highlight;
			this->textBox20->Location = System::Drawing::Point(8, 92);
			this->textBox20->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(383, 39);
			this->textBox20->TabIndex = 0;
			this->textBox20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->checkBox1);
			this->groupBox6->Controls->Add(this->checkBox5);
			this->groupBox6->Controls->Add(this->checkBox2);
			this->groupBox6->Controls->Add(this->checkBox4);
			this->groupBox6->Controls->Add(this->checkBox3);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox6->Location = System::Drawing::Point(21, 31);
			this->groupBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox6->Size = System::Drawing::Size(301, 251);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Fingers Monitor";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox1->Location = System::Drawing::Point(8, 48);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(82, 24);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Thumb";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Enabled = false;
			this->checkBox5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox5->Location = System::Drawing::Point(8, 176);
			this->checkBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(120, 24);
			this->checkBox5->TabIndex = 6;
			this->checkBox5->Text = L"Little Finger";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Enabled = false;
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox2->Location = System::Drawing::Point(8, 80);
			this->checkBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(136, 24);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Pointer Finger";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Enabled = false;
			this->checkBox4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox4->Location = System::Drawing::Point(8, 144);
			this->checkBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(117, 24);
			this->checkBox4->TabIndex = 5;
			this->checkBox4->Text = L"Ring Finger";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox3->Location = System::Drawing::Point(8, 112);
			this->checkBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(132, 24);
			this->checkBox3->TabIndex = 4;
			this->checkBox3->Text = L"Middle Finger";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(16, 342);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Sensitivity";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(21, 370);
			this->trackBar1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(753, 56);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Controls->Add(this->groupBox2);
			this->tabPage3->Controls->Add(this->groupBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Size = System::Drawing::Size(792, 463);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Debug";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBox19);
			this->groupBox5->Controls->Add(this->textBox15);
			this->groupBox5->Controls->Add(this->textBox16);
			this->groupBox5->Controls->Add(this->textBox17);
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Location = System::Drawing::Point(435, 224);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Size = System::Drawing::Size(256, 209);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Debug";
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::Color::White;
			this->textBox19->Enabled = false;
			this->textBox19->Location = System::Drawing::Point(8, 154);
			this->textBox19->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(185, 22);
			this->textBox19->TabIndex = 12;
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::White;
			this->textBox15->Enabled = false;
			this->textBox15->Location = System::Drawing::Point(8, 26);
			this->textBox15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(185, 22);
			this->textBox15->TabIndex = 11;
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::Color::White;
			this->textBox16->Enabled = false;
			this->textBox16->Location = System::Drawing::Point(8, 58);
			this->textBox16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(185, 22);
			this->textBox16->TabIndex = 10;
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::Color::White;
			this->textBox17->Enabled = false;
			this->textBox17->Location = System::Drawing::Point(8, 90);
			this->textBox17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(185, 22);
			this->textBox17->TabIndex = 9;
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::Color::White;
			this->textBox18->Enabled = false;
			this->textBox18->Location = System::Drawing::Point(8, 122);
			this->textBox18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(185, 22);
			this->textBox18->TabIndex = 8;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox13);
			this->groupBox4->Controls->Add(this->textBox14);
			this->groupBox4->Controls->Add(this->textBox10);
			this->groupBox4->Controls->Add(this->textBox11);
			this->groupBox4->Controls->Add(this->textBox12);
			this->groupBox4->Location = System::Drawing::Point(435, 23);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Size = System::Drawing::Size(256, 193);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"SoftPots";
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::Color::White;
			this->textBox13->Enabled = false;
			this->textBox13->Location = System::Drawing::Point(8, 119);
			this->textBox13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(185, 22);
			this->textBox13->TabIndex = 7;
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::Color::White;
			this->textBox14->Enabled = false;
			this->textBox14->Location = System::Drawing::Point(8, 151);
			this->textBox14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(185, 22);
			this->textBox14->TabIndex = 6;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::White;
			this->textBox10->Enabled = false;
			this->textBox10->Location = System::Drawing::Point(8, 23);
			this->textBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(185, 22);
			this->textBox10->TabIndex = 5;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::White;
			this->textBox11->Enabled = false;
			this->textBox11->Location = System::Drawing::Point(8, 55);
			this->textBox11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(185, 22);
			this->textBox11->TabIndex = 4;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::White;
			this->textBox12->Enabled = false;
			this->textBox12->Location = System::Drawing::Point(8, 87);
			this->textBox12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(185, 22);
			this->textBox12->TabIndex = 3;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Location = System::Drawing::Point(103, 302);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(256, 132);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Magnetometer";
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(8, 23);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(185, 22);
			this->textBox7->TabIndex = 2;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::White;
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(8, 55);
			this->textBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(185, 22);
			this->textBox8->TabIndex = 1;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::White;
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(8, 87);
			this->textBox9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(185, 22);
			this->textBox9->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Location = System::Drawing::Point(103, 162);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(256, 132);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Gyroscope";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(8, 23);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(185, 22);
			this->textBox4->TabIndex = 2;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(8, 55);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(185, 22);
			this->textBox5->TabIndex = 1;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::White;
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(8, 87);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(185, 22);
			this->textBox6->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(103, 23);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(256, 132);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Accelerometer";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(8, 23);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(185, 22);
			this->textBox1->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(8, 87);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(185, 22);
			this->textBox3->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(8, 55);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(185, 22);
			this->textBox2->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(793, 479);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximumSize = System::Drawing::Size(811, 526);
			this->MinimumSize = System::Drawing::Size(811, 526);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WizardHand";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		// find available ports
	private: 
		
	void findPorts(void)
	{
		// get port names
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		// add string array to combobox
		this->comboBox1->Items->AddRange(objectArray);
	}
	
	bool ReadData() {
		Byte buffer[2];

		//this->serialPort1->Write("d");

		////	IMU Data
		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//ax = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//ay = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//az = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//gx = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//gy = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//gz = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//mx = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//my = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//mz = -System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		////SoftPots Data
		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//sp4 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//sp3 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//sp2 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//sp1 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

		//for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
		//sp0 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));
		//sp0 = 1023;

		//return true;

		this->serialPort1->Write("d");
		int count = 0;
		while (true) {
			if (count == 0)
			{
				if (this->serialPort1->ReadChar() == 35)	count++;
			}
			else if (count == 1)
			{
				if (this->serialPort1->ReadChar() == 35)
					count++;
				else	count--;
			}
			else	break;
		}
		if (count == 2)
		{
			//	IMU Data
			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			ax = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			ay = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			az = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			gx = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			gy = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			gz = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			mx = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			my = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			mz = - System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			//SoftPots Data
			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			sp4 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			sp3 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			sp2 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			sp1 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));

			for (int i = 0; i < 2; i++) { buffer[i] = this->serialPort1->ReadByte(); }
			sp0 = System::Convert::ToInt32(((buffer[1] << 8) | (buffer[0])));
			sp0 = 1023;

			return(true);
		}
		else
		{
			return(false);
		}
	}

	void TextBoxUpdate() {
		this->textBox1->Text = System::Convert::ToString(lpf_ax);
		this->textBox2->Text = System::Convert::ToString(lpf_ay);
		this->textBox3->Text = System::Convert::ToString(lpf_az);

		this->textBox4->Text = System::Convert::ToString(gyrox);
		this->textBox5->Text = System::Convert::ToString(gyroy);
		this->textBox6->Text = System::Convert::ToString(gyroz);

		this->textBox7->Text = System::Convert::ToString(lpf_mx);
		this->textBox8->Text = System::Convert::ToString(lpf_my);
		this->textBox9->Text = System::Convert::ToString(lpf_mz);

		this->textBox10->Text = System::Convert::ToString(sp0);
		this->textBox11->Text = System::Convert::ToString(sp1);
		this->textBox12->Text = System::Convert::ToString(sp2);
		this->textBox13->Text = System::Convert::ToString(sp3);
		this->textBox14->Text = System::Convert::ToString(sp4);

		this->textBox15->Text = System::Convert::ToString(q0);
		this->textBox16->Text = System::Convert::ToString(q1);
		this->textBox17->Text = System::Convert::ToString(q2);
		this->textBox18->Text = System::Convert::ToString(q3);

		this->textBox19->Text = System::Convert::ToString(five_fingers, 2);

	}

	void Calibration_Notification() {
		this->label2->ForeColor = Color::Blue;
		this->label2->Text = "Calibrating... Keep the Device Still";
		this->progressBar1->Value = progress_value;
		if (progress_value == 100) {
			this->label2->ForeColor = Color::Black;
			this->label2->Text = "You Are Good to Go";
			this->progressBar1->Value = 100;
		}
	}

	void Finger_Monitor() {
		this->checkBox1->Checked = false;
		this->checkBox2->Checked = false;
		this->checkBox3->Checked = false;
		this->checkBox4->Checked = false;
		this->checkBox5->Checked = false;
		if (sp0 < 100) {
			this->checkBox1->Checked = true;
		}
		if (sp1 < 100) {
			this->checkBox2->Checked = true;
		}
		if (sp2 < 100) {
			this->checkBox3->Checked = true;
		}
		if (sp3 < 100) {
			this->checkBox4->Checked = true;
		}
		if (sp4 < 100) {
			this->checkBox5->Checked = true;
		}

	}

	void MF_HK_Monitor() {
		this->textBox20->Text = "";
		if (five_fingers == 15) {
			this->textBox20->Text = "Open";
		}
		if (five_fingers == 8) {
			this->textBox20->Text = "Left Mouse Button";
		}
		if (five_fingers == 4) {
			this->textBox20->Text = "Right Mouse Button";
		}
		if (five_fingers == 6) {
			this->textBox20->Text = "Copy";
		}
		if (five_fingers == 7) {
			this->textBox20->Text = "Paste";
		}
		if (five_fingers == 3) {
			this->textBox20->Text = "Cut";
		}
	}

	void key_capture() {

		if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x45) & 0x8000)		//if ctrl+E is pressed
		{
			if (DeviceEnable) {
				DeviceEnable = false;
			}
			if (!DeviceEnable) {
				DeviceEnable = true;
			}
		}
	}
	
	void DataThread() {
		
		if (Calibrated == false) {
			for (int i = 0; i < 100; i++) {
				if (ReadData()) {
					gyro_bias_x += gx / 131.0;
					gyro_bias_y += gy / 131.0;
					gyro_bias_z += gz / 131.0;
					progress_value++;
				}
				this->Invoke(gcnew MethodInvoker(this, &MyForm::Calibration_Notification));
			}

			gyro_bias_x /= 100;
			gyro_bias_y /= 100;
			gyro_bias_z /= 100;

			Calibrated = true;
		}

		while (ReadDataEnable) {
			clock0 = clock();

			if (ReadData()) {
				acclx = accl_num(ax);
				accly = accl_num(ay);
				acclz = accl_num(az);

				lpf_ax = roundby2(lpf(acclx, lpf_ax));
				lpf_ay = roundby2(lpf(accly, lpf_ay));
				lpf_az = roundby2(lpf(acclz, lpf_az));

				gyrox = Deg_Rad(round(gx / 131.0 - gyro_bias_x));
				gyroy = Deg_Rad(round(gy / 131.0 - gyro_bias_y));
				gyroz = Deg_Rad(round(gz / 131.0 - gyro_bias_z));

				magnx = magn_num(mx);
				magny = magn_num(my);
				magnz = magn_num(mz);

				lpf_mx = lpf(magnx, lpf_mx);
				lpf_my = lpf(magny, lpf_my);
				lpf_mz = lpf(magnz, lpf_mz);


					if (five_fingers != finger_case(sp0, sp1, sp2, sp3, sp4)) {
						five_fingers = finger_case(sp0, sp1, sp2, sp3, sp4);
						if (FunctionEnable) {
							function_case(five_fingers);
						}
						
						this->Invoke(gcnew MethodInvoker(this, &MyForm::Finger_Monitor));
						this->Invoke(gcnew MethodInvoker(this, &MyForm::MF_HK_Monitor));
						
					}


					QuaternionUpdate(q0, q1, q2, q3, gyrox, gyroy, gyroz, lpf_ax, lpf_ay, lpf_az, dt);

					//MahonyQuatUpdate(q0, q1, q2, q3, gyrox, gyroy, gyroz, lpf_ax, lpf_ay, lpf_az, dt);
					if (CursorEnable) {
						Quat_to_Screen(q0, q1, q2, q3, sensitivity);		//update cursor coordinate position
					}
					

					

				this->Invoke(gcnew MethodInvoker(this, &MyForm::TextBoxUpdate));
			}
			clock1 = clock();
			deltaT = clock1 - clock0;
			dt = ((float)deltaT) / CLOCKS_PER_SEC;
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->comboBox1->Text == String::Empty){
			this->label2->ForeColor = Color::Red;
			this->label2->Text = "Please Select Port Settings";
		}
		else{
			try{
				if (!this->serialPort1->IsOpen) {
					this->serialPort1->PortName = this->comboBox1->Text;
					this->serialPort1->Open();
					this->button1->Enabled = false;
					this->button2->Enabled = true;
					
					
				}
				else if (ReadDataEnable == false) {
					ReadDataEnable = true;
					this->label2->ForeColor = Color::Black;
					this->label2->Text = "You Are Good to Go";
					this->progressBar1->Value = 100;
					this->button1->Enabled = false;
					this->button2->Enabled = true;
				}
				else {
					this->label2->ForeColor = Color::Black;
					this->label2->Text = "Serial Port Is Already Open";
				}
			}

			
			catch(UnauthorizedAccessException^){
				this->label2->Text = "UnauthorizedAccess";
			}
			
			ReadDataEnable = true;
			
			//Thread-Call
			Thread^ theThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::DataThread));
			theThread->Start();

		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		this->serialPort1->Close();
		this->serialPort1->PortName = this->comboBox1->Text;
		this->button1->Enabled = true;
		this->label2->Text = "";
		this->progressBar1->Value = 0;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (ReadDataEnable == true) {
			ReadDataEnable = false;
			//this->serialPort1->Close();
			this->label2->ForeColor = Color::Black;
			this->label2->Text = "Successfully Stopped Revieving Data";
			this->progressBar1->Value = 0;
			this->button1->Enabled = true;
			this->button2->Enabled = false;
		}
		else {
			this->label2->ForeColor = Color::Red;
			this->label2->Text = "Serial Port Is Not Yet Opened";
		}

		
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		sensitivity = -3.0f;
		sensitivity += 0.3333 * (this->trackBar1->Value);
	}
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBox6->Checked == false) {
		this->serialPort1->BaudRate = 115200;
	}
	else if (this->checkBox6->Checked == true) {
		this->serialPort1->BaudRate = 9600;
	}
}
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	CursorEnable = this->checkBox7->Checked;
}
private: System::Void checkBox8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	FunctionEnable = this->checkBox8->Checked;
}
};
}
