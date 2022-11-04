#include <SFML/Network.hpp>
#include <iostream>

#include <fstream>

using namespace std;



bool isNumber(const string& str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}


int main()
{


	int _score = 0;
	int _highScore = 100;
	//char * sending_data;
	std::string line;
	
	std::ifstream readFile;
		readFile.open("high_score.txt");

		if(readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}

	readFile.close();

	cout << "SFML Server" << endl;
	cout << "HIGH SCORE : " << _highScore << "\n";
	sf::TcpListener listener;

	// bind the listener to a port
	if (listener.listen(53000) != sf::Socket::Done)
	{
	    // error...
	}
	cout << "LISTENING ... " << endl;

	char data[100];
	while(1)
	{
		sf::TcpSocket client;

		std::size_t received;
		// accept a new connection

		sf::SocketSelector selector;

		if (listener.accept(client) != sf::Socket::Done)
		{
		    // error...
		}	
		cout << "CONNECTED!!!" << endl;
		std::cout << "New client connected: " << client.getRemoteAddress() << std::endl;

		std::ofstream LogFile("sfml_test.txt", std::ios_base::app);

		if(LogFile.is_open())
		{

			LogFile << "Log : \n";
			LogFile << "IP : ";
			LogFile << client.getRemoteAddress();
			LogFile << "\n";
		}
		LogFile.close();

		std::cout << "Writing to File" << std::endl;

		selector.add(client);

		while(1)
		{

			cout << "Incoming Message from Client \n";
			// TCP socket:
			if (client.receive(data, 100, received) != sf::Socket::Done)
			{
			    // error...
			}
			std::cout << "Received " << received << " bytes" << std::endl;
			std::cout << "Client Message " << data << std::endl;

	
			std::ofstream writeFile("sfml_test.txt", std::ios_base::app);

			if(writeFile.is_open())
			{
	
				
				if(isNumber(string(data))){
					cout << "Is Number\n";
					_score = stoi(string(data));
					//sending_data = data;
				}
				else
					cout << "Not a Number\n";

				/*
				for (char const &c : data) {
				        if (!std::isdigit(c) == 0) 
						cout << "Is a Digit!!!!!!!!!!!\n";
    				}
				*/

				if (_score > _highScore)
				{
					_highScore = _score;
				
				
					std::ofstream writeFile("high_score.txt");

					if(writeFile.is_open())
						writeFile << _highScore;
					writeFile.close();
				}
				else
				{
					std::ofstream writeFile("score_board.txt");

					if(writeFile.is_open())
						writeFile << _score;
					writeFile.close();
				}

				writeFile << "\nData Sent From Client : ";
				writeFile << data;
				writeFile << "\n";
				writeFile << "#\n";
				writeFile << _highScore;
				writeFile << "\n";
				writeFile << _score;
				writeFile << "\n";
			}
			writeFile.close();

			std::cout << "Writing to File" << std::endl;

			string server_input;
			cout << "Sending Message to client \n";
			//cin >> server_input;

			//auto sending = 

			//Sending DATA Back to Client
			//if(client.send(data, 100) != sf::Socket::Done)
			if(client.send(to_string(_highScore).c_str(), 100) != sf::Socket::Done)
			{

			}
			
			if(received <= 0)
			{
				cout << "EXITING OUT \n";
				break;
			}
		}

	}
//	//Sending DATA Back to Client
//	if(client.send("TEST 2 FROM SERVER", 100) != sf::Socket::Done)
//	{

//	}
/*

	std::ifstream readFile;


//	char data[1024];
	string s;
		readFile.open("sfml_test.txt");

		if(readFile.is_open())
		{
    			while ( getline (readFile,line) )
			{

//				std::cout << line << "\n";
				if(line.find("#") && !line.find("10"))
				{

				//	if(line.find("#"))
				//	{
					std::cout << "Reading File : " << line << "\n"; 
					std::cout << line << "\n"; 
					_highScore = std::stoi(line);
					_score = std::stoi(line);
				}
				//readFile >> _highScore;
				
			//	std::cout << readFile << std::endl;
//				return 1;
		
				s = line + "\n";
			}

		}

	readFile.close();
	

*/



        // TCP socket: t
        //if (socket.send(data, 100) != sf::Socket::Done)



	std::cout << "HighScore : " << _highScore << std::endl;
	std::cout << "Score : " << _score << std::endl;





	ifstream binaryRead;
	//Open file in binary mode
	binaryRead.open("sfml_test.txt", ios::in | ios::binary);
	if(binaryRead.fail() == 1)
	{
		binaryRead.close();
		return false;
	}

	//File Size
	//struct stat FileInfo;
	//unsigned long iFileSize = 0;
	//if(stat("sfml_test.txt", &FileInfo) == 0)
	//	iFileSize = FileInfo.st_size;

	//Start reading file form the beggining
	binaryRead.seekg(0, ios::beg);

	//Use a small buffer to copy file over the network
	char buf[1024];
	while(binaryRead.eof())
	{
		binaryRead.read(buf, sizeof(buf));
	}


        // TCP socket: t
        //if (socket.send(data, 100) != sf::Socket::Done)


	/////////////////////////////////////////////////////////////////////////////////////////////
	//
	

	
























	return 0;
}



