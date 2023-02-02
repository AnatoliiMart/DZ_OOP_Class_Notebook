#include<iostream>
using namespace std;

class GraphCard
{
public:
	GraphCard() :model("No model"), GramCapacity(int()) {}
	GraphCard(int fake) { this->InputDataGC(); }
	void InputDataGC()
	{
		cout << "Enter the model of grapphics card: ";
		cin >> this->model;
		cout << endl;

		cout << "Emter the capacity of graphic RAM in Gb: ";
		cin >> this->GramCapacity;
		cout << endl;
	}
	void OutputDataGC()
	{
		cout << "Graphics card model: " << model << endl;
		cout << "GRam capacity: " << GramCapacity << "Gb" << endl;
	}
	~GraphCard() { cout << "GraphCard dectructor" << endl; }

private:
	string model;
	int GramCapacity;
};
class Mouse
{
public:
	Mouse() :model("No model"), isWired(true) {}
	Mouse(int fake) { this->InputDataMouse(); }
	void InputDataMouse()
	{
		cout << "Enter the model of mouse: ";
		cin  >> this->model;
		cout << endl;

		int choose = 0;

		cout << "Does the mouse wired?\n1 - Yes\n2 - No" << endl;
		cin  >> choose;
		
		switch (choose)
		{
		case 1:
			isWired = true;
			break;
		case 2:
			isWired = false;
			break;
		}

	}
	void OutputDataMouse()
	{
		cout << "Mouse model: " << model << endl;
		cout << "Wireless: ";
		if (isWired)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	~Mouse() { cout << "Mouse dectructor" << endl; }

private:
	string model;
	bool isWired;

};
class Printer
{
public:
	Printer() :model("No model"), isWired(true) {}
	Printer(int fake) { this->InputDataPrinter(); }
	void InputDataPrinter()
	{
		cout << "Enter the model of printer: ";
		cin  >> this->model;
		cout << endl;

		int choose = 0;

		cout << "Does the printer wired?\n1 - Yes\n2 - No" << endl;
		cin  >> choose;

		switch (choose)
		{
		case 1:
			isWired = true;
			break;
		case 2:
			isWired = false;
			break;
		}

	}
	void OutputDataPrinter()
	{
		cout << "Printer model: " << model << endl;
		cout << "Wireless: ";
		if (isWired)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	~Printer() { cout << "Printer dectructor" << endl; }

private:
	string model;
	bool isWired;

};

class Notebook
{
public:
	
	Notebook()
	{
		cout << "Enter model of the notebook: ";
		cin  >> this->model;
		cout << endl;

		GCard = new GraphCard();
		mice = new Mouse();
		print = new Printer();
	}
	Notebook(int fake)
	{
		cout << "Enter model of the notebook: ";
		std::cin >> this->model;
		this->proc  .InputDataProc();
		this->ram   .InputDataRAM();
		this->wcam  .InputDataWebCam();
		GCard = new GraphCard(0);
		mice = new Mouse(0);
		print = new Printer(0);
	}
	void OutputNotebook()
	{
		cout << "Notebook model: " << this->model << endl;
		this->proc  .OutputDataProc();
		this->ram   .OutputDataRAM();
		this->wcam  .OutputDataWebCam();

		this->GCard->OutputDataGC();
		this->mice ->OutputDataMouse();
		this->print->OutputDataPrinter();
	}

	~Notebook()
	{
		cout << "Notebook dectructor" << endl;
	}

private:
	class Processor
	{
	public:
		Processor():model("No model"), frequency(double()), haveGraphic(false) {}
		void InputDataProc()
		{
			cout << "Enter the model of processor: ";
			cin  >> this->model;
			cout << endl;

			cout << "Enter the frequency of processor: ";
			cin  >> this->frequency;
			cout << endl; 

			int choose = 1;
			
			cout << "Does the processor have integrated graphics?\n1 - Yes\n2 - No" << endl;
			cin  >> choose;
			
			switch (choose)
			{
			case 1:
				haveGraphic = true;
				break;
			case 2:
				haveGraphic = false;
				break;
			}

		}
		void OutputDataProc()
		{
			cout << "Processor model: "     << model     << endl;
			cout << "Processor frequency: " << frequency << endl;
			cout << "Grahic core type: ";
			if (haveGraphic)
			{
				cout << "Integrated" << endl;
			}
			else
			{
				cout << "Discrete" << endl;
			}
		}
		~Processor() { cout << "Processor dectructor" << endl; }

	private:
		string model;
		double frequency;
		bool haveGraphic;
	};
	class RAM
	{
	public:
		 RAM(): model("No model"), RAMcapacity(int()) {}
		 void InputDataRAM()
		 {
			 cout << "Enter the model of RAM: ";
			 cin  >> this->model;
			 cout << endl;

			 cout << "Emter the capacity of RAM in Gb: ";
			 cin  >> this->RAMcapacity;
			 cout << endl;
		 }
		 void OutputDataRAM()
		 {
			 cout << "RAM model: "    << model       << endl;
			 cout << "RAM capacity: " << RAMcapacity << "Gb" << endl;
		 }
		 ~RAM() { cout << "RAM dectructor" << endl; }

	private:
		string model;
		int RAMcapacity;

	};
	class WebCam
	{
	public:
		WebCam() :cameraResolution("0/0p"), haveMicro(true) {}
		void InputDataWebCam()
		{
			cout << "Enter the resolution of camera: ";
			cin  >> this->cameraResolution;
			cout << endl;

			int choose = 0;
			cout << "Does the camera have micro?\n1 - Yes\n2 - No" << endl;
			cin >> choose;
			switch (choose)
			{
			case 1:
				haveMicro = true;
				break;
			case 2:
				haveMicro = false;
				break;
			}

		}
		void OutputDataWebCam()
		{
			cout << "Camera resolution: " << cameraResolution << endl;
			cout << "Presence of a microphone: ";
			if (haveMicro)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		~WebCam() { cout << "WebCam dectructor" << endl; }

	private:
		string cameraResolution;
		bool haveMicro;

	};
	Processor  proc;
	RAM        ram;
	WebCam     wcam;
	string     model;
	GraphCard* GCard;
	Mouse*     mice ;
	Printer*   print;
	
};
int main()
{
	Notebook notebook;
	notebook.OutputNotebook();
	system("pause");
	return 0;
}
