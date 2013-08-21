#include <random>
#include "SFML\Graphics.hpp"

using namespace std;
using namespace sf;

typedef struct cell
{
	bool isFlagged;
	bool isBomb;
	bool isRevealed;
	unsigned int totalBombNeighbors;
	bool autorevealed;
};

void main()
{
	srand(time(0));
	Texture** textures = new Texture*[13];
	for(int i = 0; i < 13; i++)
		textures[i] = new Texture();
	textures[0]->loadFromFile("Assets/tile.png");
	textures[1]->loadFromFile("Assets/1.png");
	textures[2]->loadFromFile("Assets/2.png");
	textures[3]->loadFromFile("Assets/3.png");
	textures[4]->loadFromFile("Assets/4.png");
	textures[5]->loadFromFile("Assets/5.png");
	textures[6]->loadFromFile("Assets/6.png");
	textures[7]->loadFromFile("Assets/7.png");
	textures[8]->loadFromFile("Assets/8.png");
	textures[9]->loadFromFile("Assets/fyp.png");
	textures[10]->loadFromFile("Assets/flag.png");
	textures[11]->loadFromFile("Assets/blank.png");
	textures[12]->loadFromFile("Assets/jerry.png");
	RenderWindow window = RenderWindow(VideoMode(400, 400), "I LOVE U FYP <3");
	window.setFramerateLimit(30);
	cell arr[20][20];
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			arr[i][j].isBomb = false;
			arr[i][j].isFlagged = false;
			arr[i][j].totalBombNeighbors = 0;
			arr[i][j].autorevealed = false;
			arr[i][j].isRevealed = false;
		}
	}
	int j, k; bool done;
	for(int i = 0; i < 100; i++)
	{
		done = false;
		while(!done)
		{
			j = rand()%20;
			k = rand()%20;
			if(!arr[j][k].isBomb)
			{
				arr[j][k].isBomb = true;
				arr[j][k].totalBombNeighbors = 1;
				done = true;
			}
		}
	}
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(i == 0)
			{
				if(j == 0)
				{
					if(arr[i+1][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
				else if(j == 19)
				{					
					if(arr[i+1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
				else
				{
					if(arr[i+1][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
			}
			else if(i == 19)
			{
				if(j == 0)
				{	
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
				else if(j == 19)
				{
					if(arr[i-1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
				else
				{
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j+1].isBomb)	
						arr[i][j].totalBombNeighbors++;
				}
			}
			else
			{
				if(j == 0)
				{
					if(arr[i+1][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j+1].isBomb)	
						arr[i][j].totalBombNeighbors++;
				}
				else if(j == 19)
				{
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
				}
				else
				{
					if(arr[i+1][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j+1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i+1][j-1].isBomb)
						arr[i][j].totalBombNeighbors++;
					if(arr[i-1][j+1].isBomb)	
						arr[i][j].totalBombNeighbors++;
				}
			}
		}
	}
	done = false;bool win = false;
	while (window.isOpen())
    {
		// Event handling
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
			if (event.type == Event::MouseButtonPressed && !done)
			{
				int y =event.mouseButton.y/20;
				int x= event.mouseButton.x/20;
				if(event.mouseButton.button == Mouse::Left && x >= 0 && y >=0 && x < 20 && y < 20)
				{

						arr[x][y].isRevealed = true;
					
				}
				else if ( x >= 0 && y >=0 && x < 20 && y < 20)
				{
					arr[x][y].isFlagged = !arr[x][y].isFlagged;	
				}
			}
        }	

		if(!done){
		for(int i = 0; i < 20; i++)
				{
					for(int j = 0; j < 20; j++)
					{
						if((arr[i][j].isRevealed || arr[i][j].autorevealed) && arr[i][j].totalBombNeighbors == 0)
						{
							if(i == 0)
							{
								if(j == 0)
								{
									arr[i+1][j+1].autorevealed = true;
									arr[i][j+1].autorevealed = true;
									arr[i+1][j].autorevealed = true;
									arr[i-1][j].autorevealed = true;
								}
								else if(j == 19)
								{					
									arr[i+1][j].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i+1][j-1].autorevealed = true;
								}
								else
								{
									arr[i+1][j+1].autorevealed = true;
									arr[i][j+1].autorevealed = true;
									arr[i+1][j].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i+1][j-1].autorevealed = true;
								}
							}
							else if(i == 19)
							{
								if(j == 0)
								{	
									arr[i][j+1].autorevealed = true;
									arr[i-1][j].autorevealed = true;
									arr[i-1][j+1].autorevealed = true;
								}
								else if(j == 19)
								{
									arr[i-1][j-1].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i-1][j].autorevealed = true;
								}
								else
								{
									arr[i][j+1].autorevealed = true;
									arr[i-1][j-1].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i-1][j].autorevealed = true;
									arr[i-1][j+1].autorevealed = true;
								}
							}
							else
							{
								if(j == 0)
								{
									arr[i+1][j+1].autorevealed = true;
									arr[i][j+1].autorevealed = true;
									arr[i+1][j].autorevealed = true;
									arr[i-1][j].autorevealed = true;
									arr[i-1][j+1].autorevealed = true;
								}
								else if(j == 19)
								{
									arr[i+1][j].autorevealed = true;
									arr[i-1][j-1].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i-1][j].autorevealed = true;
									arr[i+1][j-1].autorevealed = true;
								}
								else
								{
									arr[i+1][j+1].autorevealed = true;
									arr[i][j+1].autorevealed = true;
									arr[i+1][j].autorevealed = true;
									arr[i-1][j-1].autorevealed = true;
									arr[i][j-1].autorevealed = true;
									arr[i-1][j].autorevealed = true;
									arr[i+1][j-1].autorevealed = true;
									arr[i-1][j+1].autorevealed = true;
								}
							}	
						}
					}
				}
		}
		// Drawing
        window.clear();
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				RectangleShape rect = RectangleShape(Vector2f(20, 20));
				rect.move(i*20, j*20);
				if(done && arr[i][j].isBomb)
				{
					rect.setTexture(textures[9]);
				}
				else if(arr[i][j].isFlagged)
				{
					rect.setTexture(textures[10]);
				}
				else if(!arr[i][j].autorevealed && !arr[i][j].isRevealed)
				{
					rect.setTexture(textures[0]);
				}
				else if(arr[i][j].isBomb)
				{
					done = true;
				}
				else
				{
					if(arr[i][j].totalBombNeighbors == 1)
						rect.setTexture(textures[1]);
					else if(arr[i][j].totalBombNeighbors == 2)
						rect.setTexture(textures[2]);
					else if(arr[i][j].totalBombNeighbors == 3)
						rect.setTexture(textures[3]);
					else if(arr[i][j].totalBombNeighbors == 4)
						rect.setTexture(textures[4]);
					else if(arr[i][j].totalBombNeighbors == 5)
						rect.setTexture(textures[5]);
					else if(arr[i][j].totalBombNeighbors == 6)
						rect.setTexture(textures[6]);
					else if(arr[i][j].totalBombNeighbors == 7)
						rect.setTexture(textures[7]);
					else if(arr[i][j].totalBombNeighbors == 8)
						rect.setTexture(textures[8]);
					else
						rect.setTexture(textures[11]);
				}
				window.draw(rect);
			}
		}
		if(win)
		{
			RectangleShape rect = RectangleShape(Vector2f(400, 400));
			rect.setTexture(textures[12]);
			window.draw(rect);
		}
        window.display();
		win = true;
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(!(arr[i][j].isRevealed || arr[i][j].autorevealed) && !arr[i][j].isBomb)
				{
					win = false;
				}
			}
		}
		if(win)
			done = true;
    }
};