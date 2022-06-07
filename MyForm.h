#include <string>
#include "Poli.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

#pragma once

namespace Polinom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int n;
	int MaxSt;
	Poli p;
	Poli q;
	Poli RES;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button13;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 140);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(560, 26);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(75, 287);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(560, 26);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(28, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"P:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(28, 287);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Q:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(753, 139);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(226, 26);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(753, 287);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(226, 26);
			this->textBox4->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(985, 116);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(985, 157);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 35);
			this->button2->TabIndex = 7;
			this->button2->Text = L"DEL";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(985, 263);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 35);
			this->button3->TabIndex = 8;
			this->button3->Text = L"ADD";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(985, 304);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(97, 35);
			this->button4->TabIndex = 9;
			this->button4->Text = L"DEL";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1161, 13);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(212, 86);
			this->button5->TabIndex = 10;
			this->button5->Text = L"CLEAR";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(198, 13);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 11;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(198, 46);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 33);
			this->button6->TabIndex = 12;
			this->button6->Text = L"SET N";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(32, 13);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 26);
			this->textBox6->TabIndex = 13;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(32, 46);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 33);
			this->button7->TabIndex = 14;
			this->button7->Text = L"SET MaxSt";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 419);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 15;
			this->label3->Text = L"RES:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(75, 416);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(560, 26);
			this->textBox7->TabIndex = 16;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(753, 416);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 26);
			this->button8->TabIndex = 17;
			this->button8->Text = L"-";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(753, 384);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 26);
			this->button9->TabIndex = 18;
			this->button9->Text = L"+";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(753, 448);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 26);
			this->button10->TabIndex = 19;
			this->button10->Text = L"*";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(753, 480);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 26);
			this->button11->TabIndex = 20;
			this->button11->Text = L"*k(P)";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(753, 512);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 26);
			this->button12->TabIndex = 21;
			this->button12->Text = L"*k(Q)";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(847, 479);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 26);
			this->textBox8->TabIndex = 22;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(847, 512);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 26);
			this->textBox9->TabIndex = 23;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(1161, 550);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(212, 37);
			this->button13->TabIndex = 24;
			this->button13->Text = L"Exit";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1385, 599);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	Application::Restart();

}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox6->Text;

	MaxSt = std::stoi(msclr::interop::marshal_as<std::string>(tmp));

	p.setMaxSt(MaxSt);
	q.setMaxSt(MaxSt);
	RES.setMaxSt(MaxSt);

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox5->Text;

	n = std::stoi(msclr::interop::marshal_as<std::string>(tmp));

	p.setCountv(n);
	q.setCountv(n);
	RES.setCountv(n);

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox3->Text;

	std::string tmpMonomStr = msclr::interop::marshal_as<std::string>(tmp);

	p.add(tmpMonomStr);

	textBox1->Text = msclr::interop::marshal_as<String^>(p.polinomToString());

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox3->Text;

	std::string tmpMonomStr = msclr::interop::marshal_as<std::string>(tmp);

	p.erase(tmpMonomStr);

	textBox1->Text = msclr::interop::marshal_as<String^>(p.polinomToString());

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox4->Text;

	std::string tmpMonomStr = msclr::interop::marshal_as<std::string>(tmp);

	q.add(tmpMonomStr);

	textBox2->Text = msclr::interop::marshal_as<String^>(q.polinomToString());

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tmp = textBox4->Text;

	std::string tmpMonomStr = msclr::interop::marshal_as<std::string>(tmp);

	q.erase(tmpMonomStr);

	textBox2->Text = msclr::interop::marshal_as<String^>(q.polinomToString());

}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

	RES = Poli();

	RES = p + q;

	textBox7->Text = msclr::interop::marshal_as<String^>(RES.polinomToString());

}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	RES = Poli();

	RES = p - q;

	textBox7->Text = msclr::interop::marshal_as<String^>(RES.polinomToString());

}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	RES = Poli();

	RES = p * q;

	textBox7->Text = msclr::interop::marshal_as<String^>(RES.polinomToString());

}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {

	Poli a;

	String^ tmp = textBox8->Text;

	int k = stoi(msclr::interop::marshal_as<std::string>(tmp));

	a = p * k;

	textBox7->Text = msclr::interop::marshal_as<String^>(a.polinomToString());
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {

	Poli a;

	String^ tmp = textBox9->Text;

	int k = stoi(msclr::interop::marshal_as<std::string>(tmp));

	a = q * k;

	textBox7->Text = msclr::interop::marshal_as<String^>(a.polinomToString());

}
};
}
