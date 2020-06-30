#include "linkedlist.hpp" 


bool m_gameOver;
const int m_width = 20;
const int m_heigth = 20;
int m_x, m_y , m_fruitX, m_fruitY, m_score;
int m_tailx[100] , m_taily[100];
int m_tail = 1;
enum eDirection{STOP = 0, LEFT, RIGTH, UP, DOWN};
eDirection dir; //sozdanije peremennoj



int _kbhit()
{
	static const int STDIN = 0;
	static bool initialized = false;	

	if (!initialized) {
	 //use termios to turn off line buffering
	    termios term;
	    tcgetattr(STDIN, &term);
	    term.c_lflag &= ~ ICANON;
	    tcsetattr(STDIN, TCSANOW, &term);
	    setbuf(stdin, NULL);
	    initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN,FIONREAD, &bytesWaiting);
	return bytesWaiting;
}


int _getch(void)
{

	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}


void Setup()
{
	m_gameOver = false;
	dir = STOP;
	m_x = m_width/2-1;
	m_y = m_heigth/2-1;
	m_fruitY = rand() % m_width;
	m_fruitX = rand() % m_heigth;	
}

void Draw()
{
//	system("clear");//ochistit ekran
	std::cout << "\033[2J\033[1;1H";
	for(int i = 0; i < m_width; ++i){
		std::cout << "#";
	}
	std::cout << std::endl;

	for(int i = 0; i < m_heigth; ++i){
		for(int j = 0; j < m_width; ++j){
			if ( 0 == j || m_width-1 == j){
				std::cout << "#";
			}	
			if(i == m_y && j == m_x){
				std::cout << RED << "+"<< RESET ;
			} else if(m_fruitY == i && m_fruitX == j){
				std::cout << GREEN << "F" << RESET;
			} else{
				bool print = false;
				for(int k = 0; k < m_tail; k++){
					if (m_tailx[k] == j && m_taily[k] == i){
					print = true;
					std::cout << RED << "x" << RESET;
					}
				}
			 // }//
			  if (!print){
			 	 std::cout << " "; // esle
			  }
			}//avel
		}
		std::cout << std::endl;
	}
	for(int i = 0; i < m_width; ++i){
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "SCORE : = " << m_score;
	unsigned int microsec = 4000;
	usleep(microsec);
}

void Input()
{
	int p = 0;
	if (!_kbhit()){
		switch(_getch() )
		{
			case 'a': //97
			  dir = LEFT;
			  break;
			case 'd':
			  dir = RIGTH;
			  break;  
			case 'w':
			  dir = UP;
			  break;  
			case 's':
			  dir = DOWN;
			  break;  
			case 'x':
			   m_gameOver = true;
			   break;		
		}
	}
}

void Logic()
{
	int prevX = m_tailx[0];
	int prevY = m_taily[0];
	int prev2X, prev2Y;
	m_tailx[0] = m_x;
	m_taily[0] = m_y;
	
	for (int i = 1; i < m_tail; ++i){
		prev2X = m_tailx[i];
		prev2Y = m_taily[i];
		m_tailx[i] = prevX;
		m_taily[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch(dir)
	{
		case LEFT:
			m_x--;
			break;
		case RIGTH:
			m_x++;
			break;
		case UP:
			m_y--;
			break;
		case DOWN:
			m_y++;
			break;
	}
	
	if (m_x > m_width || m_x < 0 || m_y > m_heigth || m_y < 0){
		m_gameOver = true;
	}
	
	if (m_x == m_fruitX && m_y == m_fruitY){
		m_score += 10; 
		m_fruitY = rand() % m_width;
		m_fruitX = rand() % m_heigth;	
		m_tail += 1;
	}
		
}
