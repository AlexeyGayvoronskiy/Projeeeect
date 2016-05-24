#include "Project.h"
#include "iostream"
using namespace std;

// ������ ����. ������ ��������� � ������� ������ ���� 128x128 ��������
const int GRID_SIZE_X = 1024;
const int GRID_SIZE_Y = 768;

class TicTacToeScreen : public Screen
{
private:
	Input* input;
	Graphics* graphics;

	// ����������� ����, ��������� � �������
	Image* back;
	Image* packman;
	Image* kirpich;
	Image* gameback;
	Image* levelback;
	Image* life;
	Image* pobeda;
	Image* number[3];
	int cond = 0;
	int k = 0, h;
	char q = 'p';
	// ������, ������������ ����, � ������� �����

	void StartSettings()
	{
		// ����� ������� Graphics � Input � ������������� ��������� ����

		input = game->GetInput();
		graphics = game->GetGraphics();
		SDL_WM_SetCaption("SHAMAN KING", 0);
	}

	void LoadingImage()
	{
		// �������� �����������

		back = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\menu.bmp");
		packman = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\Packman.bmp");
		SDL_SetColorKey(packman->surf, SDL_SRCCOLORKEY, SDL_MapRGB(packman->surf->format, 255, 255, 255));
		kirpich = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\kirpich.bmp");
		SDL_SetColorKey(kirpich->surf, SDL_SRCCOLORKEY, SDL_MapRGB(kirpich->surf->format, 255, 255, 255));
		gameback = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\pole.bmp");
		levelback = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\LevelSelection.bmp");
		life = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\life.bmp");
		pobeda = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\pobeda.bmp");
	}

	void Reset()
	{
		// ������� ���� � ����� ����

		cond = 0;
		graphics->DrawImage(back, 0, 0);
		graphics->Flip();
	}

	int GameOver()
	{
		return 1;
	}

	void GameOverHandle(int over)
	{
		// ��������� ����� ����


		// ���������� ������������, ����� �� �� ������� ��� ���

	}

public:
	void Start()
	{
		StartSettings();
		LoadingImage();
		Reset();
	}

	void Update()
	{
		if (input->IsExit())
			game->Exit();
		if (cond == 0)
		{
			graphics->DrawImage(back, 0, 0);
			graphics->Flip();
			if (input->IsMouseButtonDown(1))
			{
				// ����� ���������� ������� ������
				int x = input->GetButtonDownCoords().x / (GRID_SIZE_X / 4),
					y = input->GetButtonDownCoords().y / (GRID_SIZE_Y / 9);

				// ���� �� ������ �� ������ ������
				if (((x == 1) | (x == 2)) & (y == 1)) /*��������� ����*/
				{
					cond = 1;
				}
				if (((x == 1) | (x == 2)) & (y == 3))
				{
					cond = 6;
				}
				if (((x == 1) | (x == 2)) & (y == 5))
				{
					/*��������� ���������*/
					//cond = 3; 
				}
				if (((x == 2) | (x == 1)) & (y == 7))
				{
					game->Exit();
				}

			}
		}
		if (cond == 1)
		{
			//�������� �������� � ����� (cond = 4) ��������� �������� ����� ������ ����� ���� 
			//������� ������
			//������� ���������
			int x[10], y = 476, j;
			int lifes = 3;
			FILE *in;

			while (cond == 1){
				in = fopen("C:\\Users\\user\\Desktop\\images\\text.txt", "r");
				for (int i = 0; i < 10; i++)
					fscanf(in, "%i", (&x[0] + i));
				//huevuy comentariy
				int a = 1, jump = 0, uppoint = 0, padaet = 1;//������ ����, ��� �� � �������� ����, ������, ���������� ������� �����
				int xp = 187, yp = 476, b = 0, c = 30;; //���������� �������, ��������� ����� ����� ��� ���� � ���������


				//���� a == 1 �� �� ���������� � ����
				while (a)
				{
					if (lifes == 0){
						cond = 0;
						a = 0;
					}
					input->Update();
					for (int i = 0; i < 10; i++) {
						if (((xp + 174) >= x[i]) && ((yp + 87) >= y) && (xp + 87 <= x[i]))
						{
							lifes = lifes - 1;
							a = 0;
							cond = 1;
						}
					}
					if (input->IsExit())
					{
						game->Exit();
						a = 0;
						cond = 0;
					}
					j = 0;
					if (input->IsKeyDown('f'))
					{
						j = -10;
					}

					if (input->IsKeyDown('g'))
					{
						j = 10;
					}
					if (input->IsKeyDown(SDLK_ESCAPE))
					{
						a = 0;
						cond = 0;
					}
					if (input->IsKeyDown(SDLK_SPACE))
					{
						jump = 1;
					}
					//�����, ������� �� ��������� � ������

					while (jump == 1)
					{
						/*j = 0;
						if (input->IsKeyDown('f'))
						{
						j = -10;
						}

						if (input->IsKeyDown('g'))
						{
						j = 10;
						}
						input->Update();*/
						for (int i = 0; i < 10; i++){
							if (xp >= x[i])
							{
								padaet = 1;
							}
						}
						if (padaet == 1)
						{
							if ((yp >= 200) & (b == 0))
							{
								yp = yp - c;
								c--;
							}
							if (yp <= 200)
							{
								b = 1;
								c = 1;
								uppoint = 1;
							}
							if ((yp <= 476) & (b == 1))
							{
								yp = yp + c;
								c++;
							}
							if (yp >= 476)
							{
								b = 0;
								yp = 476;
							}
							if ((uppoint == 1) & (b == 0))
							{
								uppoint = 0;
								jump = 0;
								c = 30;
							}
						}
						graphics->DrawImage(gameback, 0, 0);
						for (int i = 0; i < 10; i++){
							if ((((xp + 174) >= x[i]) && ((yp + 87) >= y) && (xp + 87 <= x[i])) || ((((xp + 87 - x[i])*(xp + 87 - x[i]) + (yp + 87 - y)*(yp + 87 - y)) <= 7569) && ((yp + 174) < y)))
							{
								lifes = lifes - 1;
								jump = 0;
								a = 0;
							}
							if ((((xp + 87) >= x[i]) && ((yp + 174) >= y)) && (xp <= x[i]))
							{
								padaet = 0;
								c = 1;
								yp = 304;
							}
							if (((xp - x[i])*(xp - x[i]) + (yp + 87 - y)*(yp + 87 - y)) <= 7569)
							{
								padaet = 0;
								c = 1;
							}
							//��������� � ������


							x[i] = x[i] - 10;


							graphics->DrawImage(kirpich, x[i], y);
						}
						xp = xp + j;
						Sleep(10);
						graphics->DrawImage(packman, xp, yp);
						for (int i = 0; i < lifes; i++)
							graphics->DrawImage(life, (i * 131), 0);
						graphics->Flip();
					}



					//��������� ����� ��������� �� �����
					xp = xp + j;
					graphics->DrawImage(gameback, 0, 0);
					for (int i = 0; i < 10; i++){
						x[i] = x[i] - 10;
						graphics->DrawImage(kirpich, x[i], y);
					}
					Sleep(10);
					for (int i = 0; i < lifes; i++)
						graphics->DrawImage(life, (i * 131), 0);
					graphics->DrawImage(packman, xp, yp);
					graphics->Flip();
					if (x[9] <= 0){
						cond = 2;
						a = 0;
					}
				}
			}
		}
		if (cond == 2)
		{

			if (input->IsMouseButtonDown(1))
			{
				// ����� ���������� ������� ������
				int x = input->GetButtonDownCoords().x / (GRID_SIZE_X / 4),
					y = input->GetButtonDownCoords().y / (GRID_SIZE_Y / 7);

				// ���� �� ������ �� ������ ������
				if (((x == 1) | (x == 2)) & (y == 1)) /*��������� ����*/
				{

				}
				if (((x == 1) | (x == 2)) & (y == 3))
				{
					cond = 1;
				}
				if (((x == 1) | (x == 2)) & (y == 5))
				{
					cond = 0;
				}

			}
			graphics->DrawImage(pobeda, 0, 0);
			graphics->Flip();
			//���� 4-� �������� 
			//����� � ��������� ����
		}
		if (cond == 3)
		{

		}
		if (cond == 4)
		{

		}
		if (cond == 5)
		{

		}

		if (cond == 6)
		{
			if (k == 0)
			{
				graphics->DrawImage(levelback, 0, 0);
				graphics->Flip();
			}
			if (k < 4)
			{
				scanf_s("%c", &q);
			}

			if (q == '1')
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\one.bmp");
				k++;
				q = -1;
			}
			if (q == '2')
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\two.bmp");
				k++;
				q = -1;
			}
			if (q == 3)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\three.bmp");
				k++;
				q = -1;
			}
			if (q == 4)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\four.bmp");
				k++;
				q = -1;
			}
			if (q == 5)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\five.bmp");
				k++;
				q = -1;
			}
			if (q == 6)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\six.bmp");
				k++;
				q = -1;
			}
			if (q == 7)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\seven.bmp");
				k++;
				q = -1;
			}
			if (q == 8)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\eight.bmp");
				k++;
				q = -1;
			}
			if (q == 9)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\nine.bmp");
				k++;
				q = -1;
			}
			if (q == 0)
			{
				number[k] = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\zero.bmp");
				k++;
				q = -1;
			}
			graphics->DrawImage(levelback, 0, 0);
			if (k > 0)
			{
				for (int i = 0; i <= k - 1; i++)
				{
					h = i;
					graphics->DrawImage(number[h], 256 + 128 * h, 320);
				}
				graphics->Flip();
			}
		}
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Game game;
	return game.Execute(new TicTacToeScreen(), GRID_SIZE_X, GRID_SIZE_Y);
}

